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

#ifndef _APPLICATION_BINDING_H_
#define _APPLICATION_BINDING_H_

#include <tide/tide.h>
#include <map>
#include <vector>
#include <string>

namespace tide
{
    class ApplicationBinding : public AccessorObject
    {
        public:
        ApplicationBinding(SharedApplication application, bool current = false);

        private:
        SharedApplication application;
        bool current;

        void _GetID(const ValueList& args, ValueRef value);
        void _GetGUID(const ValueList& args, ValueRef value);
        void _GetName(const ValueList& args, ValueRef result);
        void _GetVersion(const ValueList& args, ValueRef value);
        void _GetPath(const ValueList& args, ValueRef value);
        void _GetExecutablePath(const ValueList& args, ValueRef value);
        void _GetResourcesPath(const ValueList& args, ValueRef value);
        void _GetDataPath(const ValueList& args, ValueRef value);
        void _GetManifestPath(const ValueList& args, ValueRef value);
        void _GetManifest(const ValueList& args, ValueRef value);
        void _GetProperties(const ValueList& args, ValueRef value);
        void _IsCurrent(const ValueList& args, ValueRef value);
        void _GetPID(const ValueList& args, ValueRef value);
        void _GetArguments(const ValueList& args, ValueRef value);
        void _HasArgument(const ValueList& args, ValueRef value);
        void _GetArgumentValue(const ValueList& args, ValueRef value);
        void _GetDependencies(const ValueList& args, ValueRef value);
        void _ResolveDependencies(const ValueList& args, ValueRef value);
        void _GetComponents(const ValueList& args, ValueRef value);
        void _GetModules(const ValueList& args, ValueRef value);
        void _GetRuntime(const ValueList& args, ValueRef value);
        void _GetAvailableComponents(const ValueList& args, ValueRef value);
        void _GetAvailableModules(const ValueList& args, ValueRef value);
        void _GetAvailableRuntimes(const ValueList& args, ValueRef value);
        void _GetBundledComponents(const ValueList& args, ValueRef value);
        void _GetBundledModules(const ValueList& args, ValueRef value);
        void _GetBundledRuntimes(const ValueList& args, ValueRef value);
    };
}
#endif
