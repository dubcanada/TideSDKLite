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
 
#ifndef _NATIVE_PIPE_H_
#define _NATIVE_PIPE_H_

#include "pipe.h"
#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>

namespace ti
{
    class NativePipe : public Pipe
    {
    public:
        NativePipe(bool isReader);
        ~NativePipe();
        void StartMonitor();
        void StartMonitor(KMethodRef readCallback);
        virtual void StopMonitors();
        virtual int Write(BytesRef bytes);
        void PollForWriteIteration();
        virtual void Close();
        virtual void CloseNative();
        virtual void CloseNativeRead() = 0;
        virtual void CloseNativeWrite() = 0;
        inline void SetReadCallback(KMethodRef cb) { this->readCallback = cb; }

    protected:
        bool closed;
        bool isReader;
        std::vector<KObjectRef> attachedObjects;
        Poco::RunnableAdapter<NativePipe>* writeThreadAdapter;
        Poco::RunnableAdapter<NativePipe>* readThreadAdapter;
        Poco::Thread writeThread;
        Poco::Thread readThread;
        KMethodRef readCallback;
        Logger* logger;
        Poco::Mutex buffersMutex;
        std::queue<BytesRef> buffers;

        void PollForReads();
        void PollForWrites();
        virtual void RawWrite(BytesRef bytes);
        virtual int RawRead(char *buffer, int size) = 0;
        virtual int RawWrite(const char *buffer, int size) = 0;
    };
}

#endif
