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

#ifndef _KR_MODULE_PROVIDER_H_
#define _KR_MODULE_PROVIDER_H_
#include <string>

namespace tide
{
    class Module;
    class Host;

    typedef Module* ModuleCreator(const Host *host, const char *path);

    /**
     * Module Provider implementations are responsible for determining if a file
     * contains a supportable module, and for constructing them if they
     * determine that the file is supported.
     *
     * In general, module providers will be a part of the system, but they are meant
     * as a way to provide extension points to 3rd party languages such as Python, Ruby, etc.
     *
     * Currently any language supported by Kroll includes it's own ModuleProvider
     */
    class EXPORT ModuleProvider
    {
    public:
        ModuleProvider() {}
        virtual ~ModuleProvider() {};

        /**
         * @param filename an absolute path to a file in the filesystem
         * @return if the passed-in absolute file path is a supported module or not
         */
        virtual bool IsModule(std::string& filename) = 0;

        /**
         * Create a module based on a path that was signified as "supported" by
         * ModuleProvider::IsModule. Most implementations will load this file into
         * their interpreter, or dynamically load it's contents in some way.
         *
         * @param path an absolute path to a module file in the filesystem
         * @return The module that represents this path.
         */
        virtual Module* CreateModule(std::string& path) = 0;
    };
}

#endif
