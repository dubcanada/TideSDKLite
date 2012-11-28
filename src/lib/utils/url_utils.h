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

#ifndef _URL_UTILS_H_
#define _URL_UTILS_H_

#include <tideutils/base.h>

namespace TideUtils
{
    namespace URLUtils
    {
        /**
         * Encodes a URI value
         */
        TIDE_UTILS_API std::string EncodeURIComponent(std::string value);

        /**
         * Decodes a URI value
         */
        TIDE_UTILS_API std::string DecodeURIComponent(std::string value);

        /**
         * Convert a file URL to an absolute path
         */
        TIDE_UTILS_API std::string FileURLToPath(std::string url);

        /**
         * Convert an path to a file URL
         */
        TIDE_UTILS_API std::string PathToFileURL(std::string path);
    };
}

#endif
