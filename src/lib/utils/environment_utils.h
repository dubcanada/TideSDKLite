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

#ifndef _ENVIRONMENT_UTILS_H_
#define _ENVIRONMENT_UTILS_H_
#include <string>
#include <tideutils/base.h>

namespace TideUtils
{
    namespace EnvironmentUtils
    {
        /*
         * @returns whether or not the named environment variable exists.
         */
        TIDE_UTILS_API bool Has(std::string name);

        /*
         * @returns the given environment variable or empty string if it does
         * not exist.
         */
        TIDE_UTILS_API std::string Get(std::string name);

        /*
         * Set an environment variable given a value and a name
         */
        TIDE_UTILS_API void Set(std::string name, std::string value);

        /*
         * Unset an environment variable given a name
         */
        TIDE_UTILS_API void Unset(std::string name);

#if defined(USE_POCO_LIB)
        /*
         * Get the environment
         */
        TIDE_UTILS_API std::map<std::string, std::string> GetEnvironment();
#endif
    };
}

#endif
