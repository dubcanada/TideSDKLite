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

#ifndef _WORKER_H_
#define _WORKER_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>
#include <Poco/Mutex.h>
#include <Poco/ScopedLock.h>
#include <queue>

namespace ti
{
    class WorkerContext;

    class Worker : public EventObject
    {
    public:
        Worker(std::string& code);
        ~Worker();
        void Error(ValueRef value);
        void SendMessageToMainThread(ValueRef message);
        virtual void Set(const char* name, ValueRef value);

    private:
        std::string code;
        AutoPtr<WorkerContext> workerContext;
        Poco::Thread thread;
        Poco::RunnableAdapter<Worker>* adapter;
        std::queue<ValueRef> inbox;
        Poco::Mutex inboxLock;

        void Run();
        void HandleInbox();
        void DeliverMessage(ValueRef message);
        void _Start(const ValueList& args, ValueRef result);
        void _Terminate(const ValueList& args, ValueRef result);
        void _PostMessage(const ValueList& args, ValueRef result);
    };
}

#endif
