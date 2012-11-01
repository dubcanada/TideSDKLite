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
#include "win32_pipe.h"

namespace ti
{
    Win32Pipe::Win32Pipe(bool isReader) :
        NativePipe(isReader),
        readHandle(INVALID_HANDLE_VALUE),
        writeHandle(INVALID_HANDLE_VALUE),
        logger(Logger::Get("Process.Win32Pipe"))
    {
    }

    void Win32Pipe::CreateHandles()
    {
        SECURITY_ATTRIBUTES attr;
        attr.nLength              = sizeof(attr);
        attr.lpSecurityDescriptor = NULL;
        attr.bInheritHandle       = FALSE;
        
        ::CreatePipe(&readHandle, &writeHandle, &attr, 0);
    }

    void Win32Pipe::Close()
    {
        NativePipe::Close();
    }

    int Win32Pipe::RawRead(char *buffer, int size)
    {
        if (readHandle != INVALID_HANDLE_VALUE)
        {
            DWORD bytesRead;
            BOOL ok = ReadFile(readHandle, buffer, size, &bytesRead, NULL);
            int error = GetLastError();
            if (ok)
            {
                return bytesRead;
            }
            else if (error == ERROR_BROKEN_PIPE)
            {
                return -1;
            }
            else
            {
                throw ValueException::FromString("Error writing anonymous pipe");
            }
        }
        return -1;
    }

    int Win32Pipe::RawWrite(const char *data, int size)
    {
        if (writeHandle != INVALID_HANDLE_VALUE)
        {
            DWORD bytesWritten;
            BOOL ok = WriteFile(writeHandle, (LPCVOID)data, size, &bytesWritten, NULL);
            if (ok || GetLastError() == ERROR_BROKEN_PIPE) {
                return bytesWritten;
            }
            else {
                throw ValueException::FromString("Error writing anonymous pipe");
            }
        }
        return 0;
    }

    void Win32Pipe::DuplicateRead(HANDLE process, LPHANDLE handle)
    {
        DuplicateHandle(process, readHandle, process, handle, 0, TRUE, DUPLICATE_SAME_ACCESS);
        this->CloseNativeRead();
    }

    void Win32Pipe::DuplicateWrite(HANDLE process, LPHANDLE handle)
    {
        DuplicateHandle(process, writeHandle, process, handle, 0, TRUE, DUPLICATE_SAME_ACCESS);
        this->CloseNativeWrite();
    }

    void Win32Pipe::CloseNativeRead()
    {
        if (readHandle != INVALID_HANDLE_VALUE)
        {
            CloseHandle(readHandle);
            readHandle = INVALID_HANDLE_VALUE;
        }
    }

    void Win32Pipe::CloseNativeWrite()
    {
        if (writeHandle != INVALID_HANDLE_VALUE)
        {
            CloseHandle(writeHandle);
            writeHandle = INVALID_HANDLE_VALUE;
        }
    }
}