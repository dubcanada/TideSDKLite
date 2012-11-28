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
#include <tideutils/url_utils.h>
#ifdef OS_WIN32
#include <tideutils/win/win32_utils.h>
#else
#include <tideutils/posix/posix_utils.h>
#endif
using namespace TideUtils;

namespace TideUtils
{
namespace URLUtils
{
    namespace
    {
        const char HEX2DEC[256] =
        {
            /*       0  1  2  3   4  5  6  7   8  9  A  B   C  D  E  F */
            /* 0 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* 1 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* 2 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* 3 */  0, 1, 2, 3,  4, 5, 6, 7,  8, 9,-1,-1, -1,-1,-1,-1,
    
            /* 4 */ -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* 5 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* 6 */ -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* 7 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    
            /* 8 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* 9 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* A */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* B */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    
            /* C */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* D */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* E */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
            /* F */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1
        };

        // Only alphanum is safe.
        const char SAFE[256] =
        {
            /*      0 1 2 3  4 5 6 7  8 9 A B  C D E F */
            /* 0 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
            /* 1 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
            /* 2 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,1,0,
            /* 3 */ 1,1,1,1, 1,1,1,1, 1,1,0,0, 0,0,0,0,
    
            /* 4 */ 0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
            /* 5 */ 1,1,1,1, 1,1,1,1, 1,1,1,0, 0,0,0,1,
            /* 6 */ 0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1,
            /* 7 */ 1,1,1,1, 1,1,1,1, 1,1,1,0, 0,0,0,0,
    
            /* 8 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
            /* 9 */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
            /* A */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
            /* B */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
    
            /* C */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
            /* D */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
            /* E */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
            /* F */ 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0
        };
    }

    std::string EncodeURIComponent(std::string src)
    {
        const char DEC2HEX[16 + 1] = "0123456789ABCDEF";
        const unsigned char *pSrc = (const unsigned char *)src.c_str();
        const int SRC_LEN = (int) src.length();
        unsigned char * const pStart = new unsigned char[SRC_LEN * 3];
        unsigned char * pEnd = pStart;
        const unsigned char * const SRC_END = pSrc + SRC_LEN;

        for (; pSrc < SRC_END; ++pSrc)
        {
            if (SAFE[*pSrc])
                *pEnd++ = *pSrc;
            else
            {
                // escape this char
                *pEnd++ = '%';
                *pEnd++ = DEC2HEX[*pSrc >> 4];
                *pEnd++ = DEC2HEX[*pSrc & 0x0F];
            }
        }

        std::string sResult((char *)pStart, (char *)pEnd);
        delete [] pStart;

        return sResult;
    }

    std::string DecodeURIComponent(std::string src)
    {
        // Note from RFC1630: "Sequences which start with a percent
        // sign but are not followed by two hexadecimal characters
        // (0-9, A-F) are reserved for future extension"

        const unsigned char * pSrc = (const unsigned char *)src.c_str();
        const int SRC_LEN = (int) src.length();
        const unsigned char * const SRC_END = pSrc + SRC_LEN;
        // last decodable '%'
        const unsigned char * const SRC_LAST_DEC = SRC_END - 2;

        char * const pStart = new char[SRC_LEN];
        char * pEnd = pStart;

        while (pSrc < SRC_LAST_DEC)
        {
            if (*pSrc == '%')
            {
                char dec1, dec2;
                if (-1 != (dec1 = HEX2DEC[*(pSrc + 1)])
                    && -1 != (dec2 = HEX2DEC[*(pSrc + 2)]))
                {
                    *pEnd++ = (dec1 << 4) + dec2;
                    pSrc += 3;
                    continue;
                }
            }

            *pEnd++ = *pSrc++;
        }

        // the last 2- chars
        while (pSrc < SRC_END)
            *pEnd++ = *pSrc++;

        std::string sResult(pStart, pEnd);
        delete [] pStart;

        return sResult;
    }


    std::string FileURLToPath(std::string url)
    {
        size_t fileLength = 7; // file://
        if (url.find("file://") == 0)
        {
            url = url.substr(fileLength);
        }

        if ('/' != KR_PATH_SEP_CHAR)
        {
            for (size_t i = 0; i < url.size(); i++)
            {
                if (url[i] == '/')
                {
                        url[i] = KR_PATH_SEP_CHAR;
                }
            }
        }
        return url;
    }

    std::string PathToFileURL(std::string pathIn)
    {
        // We need to convert this to a Unicode string, because we'll
        // be iterating through it a character at a time. This might
        // break with UTF-8.
        std::wstring path(UTF8ToWide(pathIn));

        // Windows needs it's slashes swapped.
#if OS_WIN32
        for (size_t i = 0; i < path.size(); i++)
        {
            if (path[i] == L'\\')
            {
                path[i] = L'/';
            }
        }
#endif
        std::string url("file://");
        std::vector<std::wstring> pieces;
        FileUtils::TokenizeWide(path, pieces, L"/");
        for (size_t i = 0; i < pieces.size(); i++)
        {
            std::string piece(WideToUTF8(pieces[i]));
            url.append("/");
#if OS_WIN32
            // Don't encode the C: section.
            if (i != 0)
#endif
                piece = EncodeURIComponent(piece);

            url.append(piece);
        }
        return url;
    }
}
}
