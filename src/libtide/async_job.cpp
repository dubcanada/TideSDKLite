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

#include "tide.h"
#include "thread_manager.h"
#include <Poco/Bugcheck.h>

namespace kroll
{
    AsyncJob::AsyncJob(KMethodRef job) :
        StaticBoundObject(),
        job(job),
        completed(false),
        result(Value::Undefined),
        hadError(false),
        cancelled(false),
        thread(0),
        adapter(0)
    {
        this->SetProgress(0.0);
        this->SetMethod("getProgress", &AsyncJob::_GetProgress);
        this->SetMethod("cancel", &AsyncJob::_Cancel);
        this->SetMethod("isComplete", &AsyncJob::_IsComplete);
    }

    AsyncJob::~AsyncJob()
    {
        this->progressCallbacks.clear();
        this->completedCallbacks.clear();
        this->errorCallbacks.clear();
        this->job = NULL;
    }

    void AsyncJob::RunAsynchronously()
    {
        this->adapter = new Poco::RunnableAdapter<AsyncJob>(*this,
            &AsyncJob::RunThreadTarget);
        this->thread = new Poco::Thread();
        this->thread->start(*this->adapter);
    }

    void AsyncJob::RunThreadTarget()
    {
        // We are now in a new thread -- on OSX we need to do some 
        // basic bookkeeping for the reference counter, but other
        // than that, everything past here is like executing a job
        // in a synchronous fashion.
        START_KROLL_THREAD;
        this->Run();

        try
        {
            delete this->adapter;
        }
        catch (Poco::BugcheckException& bge)
        {
            std::cerr << bge.what() << std::endl;
        }

        END_KROLL_THREAD;
    }

    void AsyncJob::Run()
    {
        // Make sure this job sticks around at least until it finishes.
        KObjectRef save(this, true);

        this->result = this->Execute();
        if (!this->hadError)
        {
            this->completed = true;
            this->OnCompleted();

            std::vector<KMethodRef>::iterator i = this->completedCallbacks.begin();
            while (i != this->completedCallbacks.end())
            {
                this->DoCallback(*i++, true);
            }
        }
    }

    KValueRef AsyncJob::Execute()
    {
        try
        {
            return this->job->Call(this->arguments);
        }
        catch (ValueException& e)
        {
            this->Error(e);
            return Value::Undefined;
        }
    }

    void AsyncJob::Cancel()
    {
        this->cancelled = true;
    }

    double AsyncJob::GetProgress()
    {
        return this->progress;
    }

    void AsyncJob::DoCallback(KMethodRef method, bool reportErrors)
    {
        ValueList args(Value::NewObject(GetAutoPtr()));
        RunOnMainThread(method, args, false);
    }

    void AsyncJob::SetProgress(double progress, bool callbacks)
    {
        if (progress < 0.0)
        {
            progress = 0.0;
        }
        else if (progress > 1.0)
        {
            progress = 1.0;
        }
        this->progress = progress;

        /*
         * One can avoid an infinite loop by setting callbacks=false
         */
        if (callbacks)
        {
            this->OnProgressChanged();

            std::vector<KMethodRef>::iterator i = this->progressCallbacks.begin();
            while (i != this->progressCallbacks.end())
            {
                this->DoCallback(*i++, true);
            }
        }
    }

    void AsyncJob::Error(ValueException& e)
    {
        this->hadError = true;
        this->OnError(e);

        std::vector<KMethodRef>::iterator i = this->errorCallbacks.begin();
        while (i != this->errorCallbacks.end())
        {
            this->DoCallback(*i++, false);
        }
    }

    void AsyncJob::AddProgressCallback(KMethodRef callback)
    {
        this->progressCallbacks.push_back(callback);
    }

    void AsyncJob::AddCompletedCallback(KMethodRef callback)
    {
        this->completedCallbacks.push_back(callback);
    }

    void AsyncJob::AddErrorCallback(KMethodRef callback)
    {
        this->errorCallbacks.push_back(callback);
    }

    void AsyncJob::_Cancel(const ValueList& args, KValueRef result)
    {
        this->Cancel();
    }

    void AsyncJob::_GetProgress(const ValueList& args, KValueRef result)
    {
        result->SetDouble(this->GetProgress());
    }

    void AsyncJob::_IsComplete(const ValueList& args, KValueRef result)
    {
        result->SetBool(this->completed);
    }

}
