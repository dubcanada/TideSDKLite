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

#include <tideutils/posix/posix_utils.h>

namespace TideUtils
{
    std::wstring UTF8ToWide(const std::string& in)
    {
        // TODO: Eventually we want this function to convert to a non-UTF8
        // wide string, but do this for now, just so that on non-Win32 platforms
        // we can use the same code.
        std::wstring result(in.length(), L' ');
        std::copy(in.begin(), in.end(), result.begin());
        return result;
    }

    std::wstring UTF8ToWide(const char* in)
    {
        std::string inString(in);
        return UTF8ToWide(inString);
    }

    std::string WideToUTF8(const std::wstring& in)
    {
        // TODO: Eventually we want this function to convert from Unicode
        // characters to UTF-8 characters, but do this for now, just so
        // that on non-Win32 platforms we can use the same code.
        std::string result(in.length(), ' ');
        std::copy(in.begin(), in.end(), result.begin());
        return result;
    }

    std::string WideToUTF8(const wchar_t* in)
    {
        std::wstring inString(in);
        return WideToUTF8(inString);
    }

    TIDE_UTILS_API std::string UTF8ToSystem(const std::string& in)
    {
        // Assume the system character set is UTF-8 for now.
        return in;
    }

    TIDE_UTILS_API std::string UTF8ToSystem(const char* in)
    {
        // Assume the system character set is UTF-8 for now.
        return in;
    }
}
