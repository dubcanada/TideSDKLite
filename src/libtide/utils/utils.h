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

#ifndef _KR_UTILS_H_
#define _KR_UTILS_H_
#include "../base.h"

// If this is a version of the utils which doesn't
// include libtide, we should use our simple version
// of SharedPtr -- if not use Poco's which is thread-safe.
#if defined(TIDE_API_EXPORT) || defined(_KROLL_H_)
    #ifdef OS_WIN32
        #include <winsock2.h>
        #include <windows.h>
    #endif

    #include "../tide.h"
    using Poco::SharedPtr;
    #define UTILS_NS tide
#else
    #define UTILS_NS TideUtils
    #include "poco/KSharedPtr.h"
    using KPoco::SharedPtr;
    
    namespace TideUtils
    {
        class KComponent;
        class Application;
        class Dependency;
        typedef SharedPtr<UTILS_NS::KComponent> SharedComponent;
        typedef SharedPtr<UTILS_NS::Application> SharedApplication;
        typedef SharedPtr<UTILS_NS::Dependency> SharedDependency;
    }
#endif

#include "application.h"
#include "file_utils.h"
#include "data_utils.h"
#include "platform_utils.h"
#include "environment_utils.h"
#include "boot_utils.h"
#include "url_utils.h"

// Platform specific utilities
#ifdef OS_WIN32
#include "win32/win32_utils.h"
#endif

#ifdef OS_OSX
#include "osx/osx_utils.h"
#endif

#ifndef OS_WIN32
#include "posix/posix_utils.h"
#endif

#endif
