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

#ifndef _WORKER_CONTEXT_H_
#define _WORKER_CONTEXT_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>
#include <Poco/Event.h>
#include <Poco/Mutex.h>
#include <JavaScriptCore/JSBase.h>
#include <queue>

namespace ti
{
    class Worker;
    class WorkerContext : public EventObject
    {
    public:
        WorkerContext(Worker* worker);
        ~WorkerContext();
        virtual ValueRef Get(const char*);
        virtual void Set(const char*, ValueRef);
        void StartWorker(const std::string& code);
        void Terminate();
        void SendMessageToWorker(ValueRef message);
        void _PostMessage(const ValueList &args, ValueRef result);
        void _ImportScripts(const ValueList &args, ValueRef result);
        void _Sleep(const ValueList &args, ValueRef result);

    private:
        Worker* worker;
        JSGlobalContextRef jsContext;
        bool running;
        std::queue<ValueRef> inbox;
        Poco::Mutex inboxLock;
        Poco::Event messageEvent;
        Poco::Event terminateEvent;

        void DeliverMessage(ValueRef message);
        void MessageLoop();
    };
}

#endif
