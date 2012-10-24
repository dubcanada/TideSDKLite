/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
***
* Copyright (c) 2008-2012 Appcelerator Inc.
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

#include <kroll/kroll.h>
#include "javascript_methods.h"
#include <Poco/Timer.h>

namespace kroll
{
    // Common javascript functions that are re-implemented
    //  in the global scope so they are available without a window
    namespace JavaScriptMethods
    {
        void Bind(KObjectRef global)
        {
            global->SetMethod("setTimeout", new KFunctionPtrMethod(&SetTimeout));
            global->SetMethod("clearTimeout", new KFunctionPtrMethod(&ClearTimeout));
            global->SetMethod("setInterval", new KFunctionPtrMethod(&SetInterval));
            global->SetMethod("clearInterval", new KFunctionPtrMethod(&ClearInterval));
        }
        
        class MainThreadCaller
        {
        public:
            KMethodRef method;
            ValueList args;
            
            void OnTimer(Poco::Timer& timer)
            {
                Host::GetInstance()->RunOnMainThread(method, 0, args, true);
            }
        };
        
        static int currentTimerId = 0;
        static std::map<int, Poco::Timer*> timers;
        static std::map<int, MainThreadCaller*> callers;
        static Poco::Mutex timersMutex;
        
        static KValueRef CreateTimer(const ValueList& args, bool interval)
        {
            KMethodRef method = 0;
            if (args.at(0)->IsMethod())
            {
                method = args.GetMethod(0);
            }
            else if (args.at(0)->IsString())
            {
                // TODO -- create a function from evaluatable code
            }
            
            long duration = (long)args.at(1)->ToDouble();
            ValueList methodArgs;
            for (size_t i = 2; i < args.size(); i++)
            {
                methodArgs.push_back(args.at(i));
            }
            
            if (!method.isNull())
            {
                Poco::ScopedLock<Poco::Mutex> l(timersMutex);
                int id = currentTimerId;
                timers[id] = new Poco::Timer(duration, interval ? duration : 0);
                callers[id] = new MainThreadCaller();
                callers[id]->method = method;
                callers[id]->args = methodArgs;
                
                Poco::TimerCallback<MainThreadCaller> callback(*callers[id], &MainThreadCaller::OnTimer);
                timers[id]->start(callback);
                
                currentTimerId++;
                return Value::NewInt(id);
            }
            else
            {
                throw ValueException::FromString("Unable to get method for executing on timeout");
            }
        }
        
        // this gets called on the main thread to avoid deadlock during the thread callback
        static KValueRef StopTimer(const ValueList& args)
        {
            int id = args.GetInt(0);
            Poco::ScopedLock<Poco::Mutex> l(timersMutex);
            
            std::map<int, Poco::Timer*>::iterator timerIter = timers.find(id);
            std::map<int, MainThreadCaller*>::iterator callerIter = callers.find(id);
            if (timerIter != timers.end() && callerIter != callers.end())
            {
                MainThreadCaller* caller = callerIter->second;
                Poco::Timer* timer = timerIter->second;
                
                // same as stop() but safe to be called from within the Timer callback
                timer->restart(0);
                callers.erase(callerIter);
                timers.erase(timerIter);
                delete caller;
                delete timer;
                
                return Value::NewBool(true);
            }
            return Value::NewBool(false);
        }
        
        KValueRef SetTimeout(const ValueList& args)
        {
            args.VerifyException("setTimeout", "m|s i");
            return CreateTimer(args, false);
        }
        
        KValueRef SetInterval(const ValueList& args)
        {
            args.VerifyException("setInterval", "m|s i");
            return CreateTimer(args, true);
        }
        
        KValueRef ClearTimeout(const ValueList& args)
        {
            args.VerifyException("clearTimeout", "i");
            return Host::GetInstance()->RunOnMainThread(new KFunctionPtrMethod(&StopTimer), 0, args, false);
        }
        
        KValueRef ClearInterval(const ValueList& args)
        {
            args.VerifyException("clearInterval", "i");
            return Host::GetInstance()->RunOnMainThread(new KFunctionPtrMethod(&StopTimer), 0, args, false);
        }
    }
}