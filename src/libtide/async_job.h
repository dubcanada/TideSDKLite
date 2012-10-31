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

#ifndef _KR_ASYNC_JOB_H_
#define _KR_ASYNC_JOB_H_
#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>

namespace tide
{
    class KROLL_API AsyncJob : public StaticBoundObject
    {
        public:
        /*
         * Create an AsyncJob and initialize its binding-layer properties.
         */
        AsyncJob(KMethodRef job=0);

        /*
         * Destroy an AsyncJob and release its callbacks.
         */
        virtual ~AsyncJob();

        /*
         * Run an async job synchronously (on the same thread).
         */
        void Run();

        /*
         * Run an async job asynchronously (on the different thread).
         */
        void RunAsynchronously();

        /*
         * The target method of an asynchronous job execution. This does
         * whatever bookkeeping is necessary at the start of a new thread
         * and then calls Run().
         */
        void RunThreadTarget();

        /*
         * Cancel a job.
         */
        void Cancel();

        /**
         * The result of the execution of this job. On an execution
         * error and before the job is completed this will be Undefined;
         */
        KValueRef GetResult();

        /**
         * The progress of this job, which is a number in
         * the range [0, 1] where 1 represents fully complete
         */
        double GetProgress();

        /**
         * Set progress of this job, which is a number in
         * the range [0, 1] where 1 represents fully complete.
         * Calling this method will trigger progress callbacks
         * unless the second argument is false.
         */
        void SetProgress(double, bool callbacks = false);

        /**
         * A built-in progress changed callback. This will be called
         * in the same situations as KMethod-style progress callbacks
         */
        virtual void OnProgressChanged() {}

        /**
         * Add a callback to be executed when the progress of
         * this job changes
         */
        void AddProgressCallback(KMethodRef);

        /**
         * A built-in completion callback. This will be called  in the
         *  same situations as KMethod-style completed callbacks
         */
        virtual void OnCompleted() {};

        /**
         * Add a callback to be executed when the progress of
         * this job changes
         */
        void AddCompletedCallback(KMethodRef);

        /**
         * A built-in error callback. This will be called  in the
         *  same situations as KMethod-style error callbacks
         */
        virtual void OnError(ValueException& e) {};

        /**
         * Add a callback to be when an error happes during the
         * course of this job, whether in the job itself or a callback
         * related to that job.
         */
        void AddErrorCallback(KMethodRef);
        
        /**
         * Set arguments for this job.
         * This allows the job method to take in custom arguments
         */
        void SetArguments(ValueList args) { this->arguments = args; }

        /**
         * Get the arguments for this job.
         */
        ValueList& GetArguments() { return arguments; }
        
        protected:
        KMethodRef job;
        ValueList arguments;
        double progress;
        bool completed;
        KValueRef result;
        bool hadError;
        bool cancelled;
        void Error(ValueException&);

        /*
         * Execute the "work" part of this async job. This is generally not
         * called directly, as it does not call any callbacks or necessarily
         * modify the progress -- Run or RunAsynchronously are better
         * choices. It can be overridden to create custom job types which
         * do something other than just execute a KMethod.
         */
        virtual KValueRef Execute();

        void _Cancel(const ValueList&, KValueRef);
        void _GetProgress(const ValueList&, KValueRef);
        void _IsComplete(const ValueList& args, KValueRef result);

        private:
        std::vector<KMethodRef> progressCallbacks;
        std::vector<KMethodRef> completedCallbacks;
        std::vector<KMethodRef> errorCallbacks;

        Poco::Thread* thread;
        Poco::RunnableAdapter<AsyncJob>* adapter;
        void DoCallback(KMethodRef, bool reportErrors=false);
    };
}

#endif
