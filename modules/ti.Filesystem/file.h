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

#ifndef _TI_FILE_H_
#define _TI_FILE_H_

#include <kroll/kroll.h>
#include "file_stream.h"

#ifdef OS_WIN32
#include <windows.h>
#include <commdlg.h>
#include <shellapi.h>
#include <shlobj.h>
#elif OS_OSX
#import <Foundation/Foundation.h>
#endif

#include <string>

namespace ti
{
    class File : public StaticBoundObject
    {
    public:
        File(std::string filename);
        virtual ~File();

        std::string& GetFilename() { return this->filename; }
        virtual SharedString DisplayString(int levels=3)
        {
            return new string(GetFilename());
        }

    private:
        std::string filename;

        void Open(const ValueList& args, KValueRef result);
        void ToString(const ValueList& args, KValueRef result);
        void ToURL(const ValueList& args, KValueRef result);
        void IsFile(const ValueList& args, KValueRef result);
        void IsDirectory(const ValueList& args, KValueRef result);
        void IsHidden(const ValueList& args, KValueRef result);
        void IsSymbolicLink(const ValueList& args, KValueRef result);
        void IsExecutable(const ValueList& args, KValueRef result);
        void IsReadonly(const ValueList& args, KValueRef result);
        void IsWritable(const ValueList& args, KValueRef result);
        void Resolve(const ValueList& args, KValueRef result);
        void Copy(const ValueList& args, KValueRef result);
        void Move(const ValueList& args, KValueRef result);
        void Rename(const ValueList& args, KValueRef result);
        void Touch(const ValueList& args, KValueRef result);
        void CreateDirectory(const ValueList& args, KValueRef result);
        void DeleteDirectory(const ValueList& args, KValueRef result);
        void DeleteFile(const ValueList& args, KValueRef result);
        void Equals(const ValueList& args, KValueRef result);
        void GetDirectoryListing(const ValueList& args, KValueRef result);
        void GetParent(const ValueList& args, KValueRef result);
        void GetExists(const ValueList& args, KValueRef result);
        void GetCreateTimestamp(const ValueList& args, KValueRef result);
        void GetModificationTimestamp(const ValueList& args, KValueRef result);
        void GetName(const ValueList& args, KValueRef result);
        void GetExtension(const ValueList& args, KValueRef result);
        void GetNativePath(const ValueList& args, KValueRef result);
        void GetSize(const ValueList& args, KValueRef result);
        void GetSpaceAvailable(const ValueList& args, KValueRef result);
        void CreateShortcut(const ValueList& args, KValueRef result);
        void SetExecutable(const ValueList& args, KValueRef result);
        void SetReadonly(const ValueList& args, KValueRef result);
        void SetWritable(const ValueList& args, KValueRef result);
        void Unzip(const ValueList& args, KValueRef result);
    };
}

#endif