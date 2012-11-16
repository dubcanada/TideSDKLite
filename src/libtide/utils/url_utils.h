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

#ifndef _KR_URL_UTILS_H_
#define _KR_URL_UTILS_H_
#include <string>
namespace UTILS_NS
{
    namespace URLUtils
    {
        /**
         * Encodes a URI value
         */
        TIDE_API std::string EncodeURIComponent(std::string value);

        /**
         * Decodes a URI value
         */
        TIDE_API std::string DecodeURIComponent(std::string value);

        /**
         * Convert a file URL to an absolute path
         */
        TIDE_API std::string FileURLToPath(std::string url);

        /**
         * Convert an path to a file URL
         */
        TIDE_API std::string PathToFileURL(std::string path);

// These functions are not available outside a TideSDK application
#if defined(TIDE_API_EXPORT) || defined(_TIDE_H_)
        /**
         * Normalize a URL. If this url is an app:// URL, ensure that it
         * has the app id as the hostname
         */
        TIDE_API std::string NormalizeURL(const std::string& url);

        /**
         * Convert a URL to a path if it is an app://, ti:// or file://
         * URL. If this URL cannot be converted to a path, return the original URL
         */
        TIDE_API std::string URLToPath(const string& url);

        /**
         * Path portion of URL which is guauranteed to be a local and * blank file.
         */
        TIDE_API std::string& BlankPageURL();

        TIDE_API std::string TiURLToPath(const std::string& url);
        TIDE_API std::string AppURLToPath(const std::string& url);
#endif
    };
}

#endif
