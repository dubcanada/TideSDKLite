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

#include "../ui_module.h"
#include "url_curl.h"
#include "url.h"
#include <cstring>

struct Curl_local_handler CurlTiURLHandler = { "ti", ti::TiURLToPathCurl };
struct Curl_local_handler CurlAppURLHandler = { "app", ti::AppURLToPathCurl };

namespace ti
{
    /* TODO: Every URL will leak in the curl handlers 
     * unless curl frees the result of these calls */
    const char* TiURLToPathCurl(const char *url)
    {
        string stURL = url;
        if (stURL.find("ti://") != 0)
        {
            stURL = string("ti://") + stURL;
        }

        std::string path = URLUtils::TiURLToPath(stURL);
        return strdup(path.c_str());
    }

    const char* AppURLToPathCurl(const char *url)
    {
        string stURL = url;
        if (stURL.find("app://") != 0)
        {
            stURL = string("app://") + stURL;
        }

        std::string path = URLUtils::AppURLToPath(stURL);
        return strdup(path.c_str());
    }
}