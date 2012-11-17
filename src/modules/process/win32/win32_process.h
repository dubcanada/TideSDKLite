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
 
#ifndef _WIN32_PROCESS_H_
#define _WIN32_PROCESS_H_

#include <sstream>
#include "win32_pipe.h"
#include "../process.h"

namespace ti
{
    class Win32Process : public Process
    {
    public:
        Win32Process();
        virtual ~Win32Process();

        inline virtual AutoPtr<NativePipe> GetNativeStdin() { return nativeIn; }
        inline virtual AutoPtr<NativePipe> GetNativeStdout() { return nativeOut; }
        inline virtual AutoPtr<NativePipe> GetNativeStderr() { return nativeErr; }

        virtual int GetPID();
        virtual void Terminate();
        virtual void Kill();
        virtual void SendSignal(int signal);
        virtual void ForkAndExec();
        virtual void MonitorAsync();
        virtual BytesRef MonitorSync();
        virtual int Wait();
        virtual std::string ArgumentsToString();
        void ReadCallback(const ValueList& args, ValueRef result);
        virtual void RecreateNativePipes();
        
    protected:
        std::string ArgListToString(TiListRef argList);
        
        Poco::Thread exitMonitorThread;
        Poco::RunnableAdapter<Win32Process>* exitMonitorAdapter;
        AutoPtr<Win32Pipe> nativeIn, nativeOut, nativeErr;
        Poco::Mutex mutex;
        
        Poco::Mutex processOutputMutex;
        std::vector<BytesRef> processOutput;
        
        int pid;
        HANDLE process;
        
        Logger* logger;
    };
}

#endif
