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

#define _KROLL_BOOT_ 1
#ifndef _BOOT_H_

// ensure that Kroll API is never included to create
// an artificial dependency on kroll shared library
#ifdef _KROLL_H_
#error You should not have included the kroll api!
#endif

#define BOOTSTRAP_ENV "KR_BOOTSTRAPPED"
#define CRASH_REPORT_OPT "--crash_report"

#define CRASH_REPORT_URL  STRING(_CRASH_REPORT_URL)

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <utils.h>

using namespace TideUtils;
using TideUtils::Application;
using TideUtils::Dependency;
using TideUtils::KComponent;
using TideUtils::SharedApplication;
using TideUtils::SharedDependency;
using TideUtils::SharedComponent;
using std::string;
using std::vector;
using std::map;

#ifdef OS_WIN32
#define MODULE_SEPARATOR ";"
#else
#define MODULE_SEPARATOR ":"
#endif

namespace KrollBoot
{
    /**
     * Implemented platform independently
     */
    int Bootstrap();
    void FindUpdate();

    /**
     * Implemented platform specifically
     */
    void ShowError(std::string error, bool fatal=false);
    std::string GetApplicationHomePath();
    bool RunInstaller(vector<SharedDependency> missing, bool forceInstall=false);
    void BootstrapPlatformSpecific(string moduleList);
    int StartHost();
    string Blastoff();
    vector<SharedDependency> FilterForSDKInstall(
        vector<SharedDependency> dependencies);
    string GetApplicationName();
}
#endif
