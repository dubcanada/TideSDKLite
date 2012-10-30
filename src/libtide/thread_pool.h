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

#ifndef _KR_THREAD_POOL_H_
#define _KR_THREAD_POOL_H_

#include <ctime>

#include <list>
#include <queue>

#include <Poco/SharedPtr.h>
#include <Poco/Thread.h>
#include <Poco/Runnable.h>
#include <Poco/Mutex.h>
#include <Poco/Event.h>

#include "tide.h"

namespace kroll
{
    typedef Poco::SharedPtr<Poco::Runnable> SharedRunnable;
    typedef std::queue<SharedRunnable> PoolJobQueue;

    class PooledThread;
    typedef std::list<PooledThread*> PooledThreadList;

    class KROLL_API ThreadPool
    {
        friend class PooledThread;

    public:
        ThreadPool(
            int minCapacity = 2,
            int maxCapacity = 10,
            int idleSeconds = 60,
            int queueMax = -1
        );
        virtual ~ThreadPool();

        bool start(SharedRunnable target, bool queue = true);
        void pauseAll();

        int availableThreads();
        int totalThreads();
        void collect();

    protected:
        virtual bool canSpawnThread();

        int minCapacity, maxCapacity;
        int idleSeconds;
        int queueMax;

    private:
        PooledThread* getIdleThread();

        SharedRunnable getJob();
        void addJob(SharedRunnable job);

        PooledThreadList threads;
        Poco::Mutex threadsMutex;

        PoolJobQueue pendingJobs;
        Poco::Mutex jobsMutex;
    };

    class KROLL_API PooledThread : public Poco::Thread, public Poco::Runnable
    {
    public:
        PooledThread(ThreadPool* pool);
        virtual ~PooledThread();

        enum State {
            IDLE,
            PAUSING,
            RESERVED,
            WORKING,
            POWERDOWN,
            DEAD
        };

        void start();
        void shutdown();
        void assignJob(SharedRunnable job);
        void resume();
        void pause(bool wait=false);
        void reserve();

        bool idle() { return state() == IDLE; }
        bool working() { return state() == WORKING; }
        bool alive() { return state() != DEAD; }

        int idleTime();

        void run();

    private:
        State state();
        void setState(State state);
        void work();

        State _state;
        Poco::Mutex stateMutex;
        Poco::Event wakeup, sleeping;
        SharedRunnable job;
        ThreadPool* pool;
        time_t idleStartTime;
    };
}

#endif
