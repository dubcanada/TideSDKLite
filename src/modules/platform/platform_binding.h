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

#ifndef _PLATFORM_BINDING_H_
#define _PLATFORM_BINDING_H_
#include <tide/tide.h>

namespace ti
{
    class PlatformBinding : public AccessorObject
    {
    public:
        PlatformBinding();

    private:
        virtual ~PlatformBinding();
        std::string GetVersionImpl();
        bool OpenApplicationImpl(const std::string& path);
        bool OpenURLImpl(const std::string& url);
        void TakeScreenshotImpl(const std::string& targetFile);

        void _GetType(const ValueList& args, ValueRef result);
        void _GetName(const ValueList& args, ValueRef result);
        void _GetProcessorCount(const ValueList& args, ValueRef result);
        void _GetVersion(const ValueList& args, ValueRef result);
        void _GetArchitecture(const ValueList& args, ValueRef result);
        void _GetMachineId(const ValueList& args, ValueRef result);
        void _GetUsername(const ValueList& args, ValueRef result);
        void _CreateUUID(const ValueList& args, ValueRef result);
        void _OpenURL(const ValueList& args, ValueRef result);
        void _OpenApplication(const ValueList& args, ValueRef result);
        void _TakeScreenshot(const ValueList& args, ValueRef result);
    };
}

#endif
