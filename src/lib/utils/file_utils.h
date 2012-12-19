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

#ifndef _FILE_UTILS_H_
#define _FILE_UTILS_H_


#include <tideutils/base.h>
#ifdef OS_WIN32
#include <windows.h>
#undef CreateDirectory
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

#ifdef OS_WIN32
#define KR_PATH_SEP_CHAR '\\'
#define WIDE_KR_PATH_SEP_CHAR L'\\'
#define KR_PATH_SEP "\\"
#define WIDE_KR_PATH_SEP L"\\"
#define KR_PATH_SEP_OTHER "/"
#define KR_LIB_SEP ";"
#else
#define KR_PATH_SEP_CHAR '/'
#define WIDE_KR_PATH_SEP_CHAR L'/'
#define KR_PATH_SEP "/"
#define WIDE_KR_PATH_SEP L"/"
#define KR_PATH_SEP_OTHER "\\"
#define KR_LIB_SEP ":"
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#endif

/**
 * An API for various file utilities (mostly centered around the TideSDK runtime)
 * Platform-dependent functions can be defined in <os>/<os>_utils.h instead of
 * behind an #ifdef in this file.
 */
namespace TideUtils
{
    namespace FileUtils
    {
        /**
         * Tokenize a string into parts given a string of delimeters characters.
         */
        TIDE_UTILS_API void Tokenize(const std::string& haystack,
            std::vector<std::string>& tokens, const std::string& delimeters,
            bool skipDuplicates=false);
        TIDE_UTILS_API void TokenizeWide(const std::wstring& haystack,
            std::vector<std::wstring>& tokens, const std::wstring& delimeters,
            bool skipDuplicates=false);

        TIDE_UTILS_API std::string Trim(std::string str);
        TIDE_UTILS_API std::wstring Trim(std::wstring str);

        TIDE_UTILS_API void ListDir(const std::string& path, std::vector<std::string>& files);
        TIDE_UTILS_API bool IsDirectory(const std::string& dir);
        TIDE_UTILS_API bool IsFile(const std::string& file);
        TIDE_UTILS_API void WriteFile(const std::string& path, const std::string& content);
        TIDE_UTILS_API std::string ReadFile(const std::string& path);
        TIDE_UTILS_API std::string Dirname(const std::string& path);
        TIDE_UTILS_API std::string Basename(const std::string& path);
        TIDE_UTILS_API bool CreateDirectory(const std::string& dir, bool recursive=false);
        TIDE_UTILS_API bool CreateDirectoryImpl(const std::string& dir);

        /**
         * Recursively delete the directory at the given path
         */
        TIDE_UTILS_API bool DeleteDirectory(const std::string& dir);

        /**
         * Delete a file at the given path
         */
        TIDE_UTILS_API bool DeleteFile(const std::string& file);

        /**
         * This function joins paths together in an OS specific way. Empty elements --
         * those which equal == "" will be ignored. Examples:
         * Join('', '/blah', '', 'whatever') => /blah/whatever
         * Join('', 'blah', 'whatever') => blah/whatever
         */
        TIDE_UTILS_API std::string Join(const char*, ...);
        TIDE_UTILS_API std::wstring Join(const wchar_t*, ...);

        /**
         * This function returns the Operating system version
         */
        TIDE_UTILS_API std::string GetOSVersion();

        /**
         * This function returns the Operating system architecture
         */
        TIDE_UTILS_API std::string GetOSArchitecture();

        /**
         * This function returns temporary directory for application
         */
        TIDE_UTILS_API std::string GetTempDirectory();

        /**
         * This function returns the path of the currently running executable.
         * @return the path for the currently running executable
        */
        TIDE_UTILS_API std::string GetExecutableDirectory();

        /**
         * @return the applications data directory
         */
        TIDE_UTILS_API std::string GetApplicationDataDirectory(std::string appname);

        /**
         * This function indirectly uses the KR_HOME environment variable
         * set by the boot process
         * @return the directory for the application's resource files
        */
        TIDE_UTILS_API std::string GetResourcesDirectory();

        /**
         * @return the directory for a given file path
         */
        TIDE_UTILS_API std::string GetDirectory(const std::string &file);

        /**
         * @return true if the given file or directory is hidden.  Otherwise, false is returned.
         */
        TIDE_UTILS_API bool IsHidden(const std::string &file);

        /**
         * Get the system-wide runtime home directory. This is just a
         * default location --  to get the  current runtime home directory
         * read the value of the runtime path from the host's current application.
         */
        TIDE_UTILS_API std::string GetSystemRuntimeHomeDirectory();

        /**
         * Get the user-specific runtime home directory. This is just a
         * default location --  to get the  current runtime home directory
         * read the value of the runtime path from the host's current application.
         */
        TIDE_UTILS_API std::string GetUserRuntimeHomeDirectory();
        TIDE_UTILS_API bool IsRuntimeInstalled();
        TIDE_UTILS_API int RunAndWait(const std::string& path, std::vector<std::string>& args);
        TIDE_UTILS_API std::string GetUsername();

#ifndef NO_UNZIP
        typedef bool (*UnzipCallback)(char* message, int current,
            int total, void* data);
        TIDE_UTILS_API bool Unzip(const std::string& source, const std::string& destination, 
            UnzipCallback callback=0, void* data=0);
#endif
    }
}

#endif
