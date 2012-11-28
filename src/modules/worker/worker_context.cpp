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

#include <tide/url_utils.h>

#include "worker_context.h"
#include "worker.h"
#include <tide/javascript/javascript_module.h>
#include <JavaScriptCore/JSContextRef.h>

namespace ti
{
    static Logger* GetLogger()
    {
        static Logger* logger = Logger::Get("WorkerContext");
        return logger;
    }

    WorkerContext::WorkerContext(Worker* worker) :
        EventObject("Worker.WorkerContext"),
        worker(worker),
        jsContext(0),
        running(false)
    {
    }

    WorkerContext::~WorkerContext()
    {
    }

    static JSGlobalContextRef CreateGlobalContext(WorkerContext* context)
    {
        JSGlobalContextRef jsContext = JSUtil::CreateGlobalContext();
        JSGlobalContextRetain(jsContext);

        TiObjectRef global(new KKJSObject(jsContext,
            JSContextGetGlobalObject(jsContext)));

        global->SetMethod("postMessage", StaticBoundMethod::FromMethod<WorkerContext>(
            context, &WorkerContext::_PostMessage));
        global->SetMethod("importScript", StaticBoundMethod::FromMethod<WorkerContext>(
            context, &WorkerContext::_ImportScripts));
        global->SetMethod("importScripts", StaticBoundMethod::FromMethod<WorkerContext>(
            context, &WorkerContext::_ImportScripts));
        global->SetMethod("sleep", StaticBoundMethod::FromMethod<WorkerContext>(
            context, &WorkerContext::_Sleep));

        return jsContext;
    }

    static void DestroyGlobalContext(JSGlobalContextRef jsContext)
    {
        JSUtil::UnregisterGlobalContext(jsContext);
        JSGlobalContextRelease(jsContext);
    }

    void WorkerContext::StartWorker(const std::string& code)
    {
        // Stay alive until the thread is gone.
        this->duplicate();
        this->jsContext = CreateGlobalContext(this);
        this->running = true;

        try
        {
            JSUtil::Evaluate(jsContext, code.c_str());
        }
        catch (ValueException& e)
        {
            GetLogger()->Error("Error executing worker: %s\n", e.ToString().c_str());
            worker->Error(e.GetValue());
            DestroyGlobalContext(jsContext);
            return;
        }

        this->MessageLoop();

        DestroyGlobalContext(jsContext);
        this->running = false;
        this->release();
    }

    void WorkerContext::MessageLoop()
    {
        while (this->running)
        {
            while (!inbox.empty())
            {
                ValueRef message(0);
                {
                    Poco::Mutex::ScopedLock lock(inboxLock);
                    message = inbox.front();
                    inbox.pop();
                }

                this->DeliverMessage(message);
            }

            // Wait until the main thread signals us into action. This means there
            // are messages to process or this worker has been killed from the outside.
            messageEvent.wait();
        }
    }

    void WorkerContext::DeliverMessage(ValueRef message)
    {
        AutoPtr<Event> event(this->CreateEvent("worker.message"));
        event->Set("message", message);

        ValueRef callback = this->Get("onmessage");
        if (callback->IsMethod())
            callback->ToMethod()->Call(Value::NewObject(event));
    }

    void WorkerContext::Terminate()
    {
        // Wake up the worker no matter if it's in the message loop or sleeping.
        this->running = false;
        messageEvent.set();
        terminateEvent.set();
    }

    void WorkerContext::SendMessageToWorker(ValueRef message)
    {
        {
            Poco::Mutex::ScopedLock lock(inboxLock);
            inbox.push(message);
        }

        // Wake up the worker thread, if it's waiting in the message queue.
        messageEvent.set();
    }

    void WorkerContext::_PostMessage(const ValueList &args, ValueRef result)
    {
        worker->SendMessageToMainThread(args.GetValue(0));
    }

    void WorkerContext::_Sleep(const ValueList &args, ValueRef result)
    {
        args.VerifyException("sleep", "i");

        long time = args.GetInt(0);
        GetLogger()->Debug("Worker will sleep for up to %ld milliseconds", time);
        terminateEvent.tryWait(time);

        if (!this->running)
        {
            // The main thread has requested that the worker be terminated,
            // so toss an exception here to try to finish up quickly.
            throw ValueException::FromString("Worker sleep was interrupted.");
        }
    }

    void WorkerContext::_ImportScripts(const ValueList &args, ValueRef result)
    {
        for (size_t c = 0; c < args.size(); c++)
        {
            std::string path(URLUtils::URLToPath(args.GetString(c)));
            GetLogger()->Debug("Attempting to import worker script = %s", path.c_str());
            JSUtil::EvaluateFile(this->jsContext, path.c_str());
        }
    }

    ValueRef WorkerContext::Get(const char* name)
    {
        if (!jsContext)
            return Value::Undefined;

        TiObjectRef global(new KKJSObject(jsContext,
            JSContextGetGlobalObject(jsContext)));
        return global->Get(name);
    }

    void WorkerContext::Set(const char* name, ValueRef value)
    {
        if (!jsContext)
            return;

        TiObjectRef global(new KKJSObject(jsContext,
            JSContextGetGlobalObject(jsContext)));
        global->Set(name, value);
    }
}
