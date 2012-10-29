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

#ifndef _KR_ENVIRONMENT_UTILS_H_
#define _KR_ENVIRONMENT_UTILS_H_
#include <string>

namespace UTILS_NS
{
    namespace EnvironmentUtils
    {
        /*
         * @returns whether or not the named environment variable exists.
         */
        KROLL_API bool Has(std::string name);

        /*
         * @returns the given environment variable or empty string if it does
         * not exist.
         */
        KROLL_API std::string Get(std::string name);

        /*
         * Set an environment variable given a value and a name
         */
        KROLL_API void Set(std::string name, std::string value);

        /*
         * Unset an environment variable given a name
         */
        KROLL_API void Unset(std::string name);

#if defined(KROLL_API_EXPORT) || defined(_KROLL_H_)
        /*
         * Get the environment
         */
        KROLL_API std::map<std::string, std::string> GetEnvironment();
#endif
    };
}

#endif