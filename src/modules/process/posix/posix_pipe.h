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

#ifndef _POSIX_PIPE_H_
#define _POSIX_PIPE_H_

#include <tide/tide.h>
#include "../native_pipe.h"

namespace ti
{
    class PosixPipe : public NativePipe
    {
    public:
        PosixPipe(bool isReader);
        virtual void CreateHandles();
        virtual void Close();
        virtual void CloseNativeRead();
        virtual void CloseNativeWrite();
        inline int GetReadHandle() { return readHandle; }
        inline int GetWriteHandle() { return writeHandle; }

    protected:
        int readHandle;
        int writeHandle;
        virtual int RawRead(char *buffer, int size);
        virtual int RawWrite(const char *buffer, int size);
    };
}

#endif
