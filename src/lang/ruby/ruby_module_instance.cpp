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

#include "ruby_module_instance.h"

namespace kroll
{
    // TODO: Implement real method metadata and lifecycle events for
    // scripting language-based modules
    RubyModuleInstance::RubyModuleInstance(Host* host, std::string path, std::string dir, std::string name) :
        Module(host, dir.c_str(), name.c_str(), "0.1"), path(path)
    {
    }

    RubyModuleInstance::~RubyModuleInstance()
    {
    }

    void RubyModuleInstance::Initialize () 
    {
    }

    void RubyModuleInstance::Destroy () 
    {
    }
}