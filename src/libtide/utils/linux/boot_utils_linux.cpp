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

namespace UTILS_NS
{
namespace BootUtils
{
    vector<string>& GetComponentSearchPaths()
    {
        static std::vector<std::string> componentSearchPaths;
        if (componentSearchPaths.empty())
        {
            // Allow the user to force an override to the runtime home by setting the
            // appropriate environment variable -- this will be the first path searched
            if (EnvironmentUtils::Has("KR_SEARCH_PATH"))
                componentSearchPaths.push_back(EnvironmentUtils::Get("KR_SEARCH_PATH"));

            // Kroll runtime and modules will located by searching the following paths in order:
            // 1. ~/.PRODUCT_NAME (eg. ~/.titanium)
            // 2. /opt/PRODUCT_NAME (default runtime base path for system-wide installation)
            // 3. /usr/local/lib/PRODUCT_NAME
            // 4. /usr/lib/PRODUCT_NAME
            string pname = PRODUCT_NAME;
            std::transform(pname.begin(), pname.end(), pname.begin(), tolower);
            componentSearchPaths.push_back(FileUtils::GetUserRuntimeHomeDirectory());
            componentSearchPaths.push_back(string("/opt/") + pname);
            componentSearchPaths.push_back(string("/usr/local/lib/") + pname);
            componentSearchPaths.push_back(string("/usr/lib/") + pname);
        }
        return componentSearchPaths;
    }

    bool RunInstaller(
        vector<SharedDependency> missing,
        SharedApplication application,
        std::string updateFile,
        std::string installerPath,
        bool quiet,
        bool forceInstall)
    {
        if (installerPath.empty())
        {
            installerPath = application->path;
        }

        string exec = FileUtils::Join(
            installerPath.c_str(), "installer", "installer", NULL);

        if (!FileUtils::IsFile(exec))
        {
            return false;
        }

        vector<string> args;
        args.push_back("--apppath");
        args.push_back(application->path);

        if (!updateFile.empty())
        {
            args.push_back("--updatefile");
            args.push_back(updateFile);
        }
        // The Linux installer has no quiet mode

        std::vector<SharedDependency>::iterator di = missing.begin();
        while (di != missing.end())
        {
            SharedDependency d = *di++;
            string url = application->GetURLForDependency(d);
            args.push_back(url);
        }

        FileUtils::RunAndWait(exec, args);
        return true;
    }
}
}