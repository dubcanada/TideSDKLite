/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
* Copyright (c) 2012 Mital Vora
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

#include <tideutils/file_utils.h>
#include <cstdarg>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/utsname.h>
#include <libgen.h>

#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>

using std::string;

namespace TideUtils
{
namespace FileUtils
{
    std::string GetAppDataDirectory()
    {
        passwd *user = getpwuid(getuid());
        return std::string(user->pw_dir);
    }

    std::string GetUserRuntimeHomeDirectory()
    {
        string pname = PRODUCT_NAME;
        std::transform(pname.begin(), pname.end(), pname.begin(), tolower);
        pname = std::string(".") + pname;
    
        passwd *user = getpwuid(getuid());
        return Join(user->pw_dir, pname.c_str(), NULL);
    }

    std::string GetSystemRuntimeHomeDirectory()
    {
        // Try to be a little smart about where the system runtime home
        // is. If we can't find it, just give up and use the /opt location
        string pname = PRODUCT_NAME;
        std::transform(pname.begin(), pname.end(), pname.begin(), tolower);
        string path = Join("/opt", pname.c_str(), NULL);
        if (!IsDirectory(path))
            path = Join("/usr/local/lib", pname.c_str(), NULL);
        if (!IsDirectory(path))
            path = Join("/usr/lib", pname.c_str(), NULL);
        if (!IsDirectory(path))
            path = Join("/opt", pname.c_str(), NULL);
        return path;
    }

    void WriteFile(const std::string& path, const std::string& content)
    {
        std::ofstream f(path.c_str());
        f << content;
        f.close();
    }

    std::string ReadFile(const std::string& path)
    {
        std::ostringstream inputStream;

        std::ifstream inputFile(path.c_str());

        if (!inputFile.is_open())
            return inputStream.str();

        std::string line;
        while (!inputFile.eof())
        {
            getline(inputFile, line);
            inputStream << line << std::endl;
        }

        inputFile.close();
        return inputStream.str();
    }
}
}
