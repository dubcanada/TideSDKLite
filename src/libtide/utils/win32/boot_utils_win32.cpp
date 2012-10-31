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

#include "../utils.h"
#include <sstream>

using std::wstring;

namespace UTILS_NS
{
namespace BootUtils
{
    static bool IsWindowsXP()
    {
        OSVERSIONINFO osVersion;
        osVersion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
        ::GetVersionEx(&osVersion);
        return osVersion.dwMajorVersion == 5;
    }
    
    vector<string>& GetComponentSearchPaths()
    {
        static std::vector<std::string> componentSearchPaths;
        if (componentSearchPaths.empty())
        {
            // Allow the user to force an override to the runtime home by setting the
            // appropriate environment variable -- this will be the first path searched
            if (EnvironmentUtils::Has("KR_SEARCH_PATH"))
                componentSearchPaths.push_back(EnvironmentUtils::Get("KR_SEARCH_PATH"));

            componentSearchPaths.push_back(FileUtils::GetUserRuntimeHomeDirectory());
            componentSearchPaths.push_back(FileUtils::GetSystemRuntimeHomeDirectory());
        }
        return componentSearchPaths;
    }

    bool RunInstaller(vector<SharedDependency> missing,
        SharedApplication application, string updateFile,
        string installerPath, bool quiet, bool forceInstall)
    {
        if (installerPath.empty())
            installerPath = application->path;
        string exec(FileUtils::Join(installerPath.c_str(), "installer",
             "installer.exe", 0));
        if (!FileUtils::IsFile(exec))
            return false;

        vector<string> args;
        args.push_back("-app");
        args.push_back(application->path);

        if (!updateFile.empty())
        {
            args.push_back("-update");
            args.push_back(updateFile);
        }

        string jobsString;
        vector<SharedDependency>::iterator mi = missing.begin();
        while (mi != missing.end())
        {
            SharedDependency d = *mi;
            if (mi != missing.begin())
                jobsString.append(",");
            jobsString.append(d->name);
            jobsString.append(":");
            jobsString.append(d->version);
            mi++;
        }
        if (!jobsString.empty())
            args.push_back(jobsString);

        string paramString("");
        for (size_t i = 0; i < args.size(); i++)
        {
            paramString.append(" \"");
            paramString.append(args.at(i));
            paramString.append("\"");
        }

        SHELLEXECUTEINFO ShExecInfo = {0};
        ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
        ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_DDEWAIT;
        ShExecInfo.hwnd = NULL;

        // This magic causes Vista and Windows 7 to pop open
        // the UAC dialog when this application is launched.
        if (!IsWindowsXP())
            ShExecInfo.lpVerb = L"runas";

        wstring wideExec(UTF8ToWide(exec));
        wstring wideParamString = UTF8ToWide(paramString);
        ShExecInfo.lpFile = wideExec.c_str();
        ShExecInfo.lpParameters = wideParamString.c_str();
        ShExecInfo.lpDirectory = NULL;
        ShExecInfo.nShow = SW_SHOW;
        ShExecInfo.hInstApp = NULL;
        ShellExecuteExW(&ShExecInfo);
        WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
        DWORD returnCode;
        GetExitCodeProcess(ShExecInfo.hProcess, &returnCode);

        return returnCode == 0;
    }
}
}