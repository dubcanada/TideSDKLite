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

#include <kroll/kroll.h>
#include "dependency_binding.h"

namespace kroll
{
    DependencyBinding::DependencyBinding(SharedDependency dependency) :
        KAccessorObject("API.Dependency"),
        dependency(dependency)
    {
        /**
         * @tiapi(method=True,name=API.Dependency.getType,since=0.4)
         * @tiapi Get the type of this dependency (eg API.MODULE)
         * @tiresult[Number] The type of this dependency
         */
        this->SetMethod("getType", &DependencyBinding::_GetType);

        /**
         * @tiapi(method=True,name=API.Dependency.getName,since=0.4)
         * @tiapi Get the name of this dependency
         * @tiresult[String] The name of this dependency
         */
        this->SetMethod("getName", &DependencyBinding::_GetName);

        /**
         * @tiapi(method=True,name=API.Dependency.getVersion,since=0.4)
         * @tiapi Get the version of this dependency
         * @tiresult[String] The version of this dependency
         */
        this->SetMethod("getVersion", &DependencyBinding::_GetVersion);

        /**
         * @tiapi(method=True,name=API.Dependency.getRequirement,since=0.4)
         * @tiapi Get the requirement for this dependency (eg API.LTE)
         * @tiresult[String] The requirement for this dependency
         */
        this->SetMethod("getRequirement", &DependencyBinding::_GetRequirement);
    }

    SharedDependency DependencyBinding::GetDependency()
    {
        return dependency;
    }

    void DependencyBinding::_GetType(const ValueList& args, KValueRef result)
    {
        result->SetInt((int) this->dependency->type);
    }

    void DependencyBinding::_GetName(const ValueList& args, KValueRef result)
    {
        result->SetString(this->dependency->name);
    }

    void DependencyBinding::_GetVersion(const ValueList& args, KValueRef result)
    {
        result->SetString(this->dependency->version);
    }

    void DependencyBinding::_GetRequirement(const ValueList& args, KValueRef result)
    {
        result->SetInt(this->dependency->requirement);
    }
}