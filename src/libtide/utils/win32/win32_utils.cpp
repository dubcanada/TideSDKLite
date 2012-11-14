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
namespace Win32Utils
{
    std::string QuickFormatMessage(DWORD errorCode, DWORD flags)
    {
        std::string result;
        LPWSTR errorText = NULL;
        FormatMessageW(
            flags,
            NULL, // unused with FORMAT_MESSAGE_FROM_SYSTEM
            errorCode,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPWSTR) &errorText,
            0, // minimum size for output buffer
            NULL);

        if (errorText)
        {
            result = WideToUTF8(errorText);
            LocalFree(errorText);
        }
        return result;
    }
}

    std::wstring MultiByteToWide(const std::string& in, UINT codePage)
    {
        return MultiByteToWide(in.c_str(), in.size(), codePage);
    }

    std::wstring MultiByteToWide(const char* in, size_t size, UINT codePage)
    {
        if (size == 0)
            return L"";

        wchar_t* buffer = new wchar_t[size + 1];
        buffer[size] = '\0';

        MultiByteToWideChar(codePage, 0, in, -1, buffer, (int) size);
        std::wstring out(buffer);
        delete [] buffer;
        return out;
    }

    std::string WideToMultiByte(const std::wstring& in, UINT codePage)
    {
        return WideToMultiByte(in.c_str(), in.size(), codePage);
    }

    std::string WideToMultiByte(const wchar_t* in, size_t size, UINT codePage)
    {
        if (size == 0)
            return "";

        size_t bufferSize = (4 * size) + 1;
        char* buffer = new char[4 * size + 1];
        buffer[4 * size] = '\0';
    
        WideCharToMultiByte(codePage, 0, in, -1, buffer, static_cast<int>(bufferSize - 1), NULL, NULL);
        std::string out(buffer);
        delete [] buffer;
        return out;
    }

    std::string MultiByteToMultiByte(const std::string& in, UINT codePageIn, UINT codePageOut)
    {
        std::wstring wideString(MultiByteToWide(in, codePageIn));
        return WideToMultiByte(wideString, codePageOut);
    }

    std::wstring UTF8ToWide(const std::string& in)
    {
        return MultiByteToWide(in.c_str(), CP_UTF8);
    }

    std::wstring UTF8ToWide(const char* in)
    {
        return MultiByteToWide(in, CP_UTF8);
    }

    std::string WideToUTF8(const std::wstring& in)
    {
        return WideToUTF8(in.c_str());
    }

    std::string WideToUTF8(const wchar_t* in)
    {
        return WideToMultiByte(in, CP_UTF8);
    }

    std::string UTF8ToSystem(const std::string& in)
    {
        return MultiByteToMultiByte(in, CP_UTF8, CP_ACP);
    }

    std::string UTF8ToSystem(const char* in)
    {
        return MultiByteToMultiByte(in, CP_UTF8, CP_ACP);
    }

    std::string WideToSystem(const std::wstring& in)
    {
        return WideToMultiByte(in.c_str(), in.size(), CP_ACP);
    }

    std::string WideToSystem(const wchar_t* in)
    {
        return WideToMultiByte(in, wcslen(in), CP_ACP);
    }
}