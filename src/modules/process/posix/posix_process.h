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
 
#ifndef _POSIX_PROCESS_H_
#define _POSIX_PROCESS_H_

#include <sstream>
#include <Poco/Thread.h>
#include "posix_pipe.h"
#include "../process.h"

namespace ti
{
    class PosixProcess;
    class PosixProcess : public Process
    {
    public:
        PosixProcess();
        virtual ~PosixProcess();
        virtual void Terminate();
        virtual void Kill();
        virtual void SendSignal(int signal);
        static AutoPtr<PosixProcess> GetCurrentProcess();

        virtual void ForkAndExec();
        virtual void MonitorAsync();
        virtual BytesRef MonitorSync();
        virtual int Wait();
        virtual void RecreateNativePipes();
        virtual void SetArguments(TiListRef args);
        void ReadCallback(const ValueList& args, ValueRef result);
        inline virtual AutoPtr<NativePipe> GetNativeStdin() { return nativeIn; }
        inline virtual AutoPtr<NativePipe> GetNativeStdout() { return nativeOut; }
        inline virtual AutoPtr<NativePipe> GetNativeStderr() { return nativeErr; }

    protected:
        Logger* logger;
        int pid;
        AutoPtr<PosixPipe> nativeIn;
        AutoPtr<PosixPipe> nativeOut;
        AutoPtr<PosixPipe> nativeErr;

        // For synchronous process execution store
        // process output as a vector of Bytes for speed.
        Poco::Mutex processOutputMutex;
        std::vector<BytesRef> processOutput;
        void StartProcess();
    };
}

#endif
