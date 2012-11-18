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

#include "environment_binding.h"

namespace tide
{
    ValueRef EnvironmentBinding::Get(const char *name)
    {
        return Value::NewString(EnvironmentUtils::Get(name));
    }
    
    SharedStringList EnvironmentBinding::GetPropertyNames()
    {
        std::map<std::string, std::string> env = EnvironmentUtils::GetEnvironment();
        SharedStringList keys = new StringList();
        
        std::map<std::string, std::string>::iterator iter = env.begin();
        for (; iter != env.end(); iter++)
        {
            keys->push_back(new std::string(iter->first));
        }
        return keys;
    }
    
    void EnvironmentBinding::Set(const char *name, ValueRef value)
    {
        if (value->IsString())
        {
            EnvironmentUtils::Set(name, value->ToString());
        }
    }
    
    SharedString EnvironmentBinding::DisplayString(int levels)
    {
        std::map<std::string, std::string> env = EnvironmentUtils::GetEnvironment();
        std::map<std::string, std::string>::iterator iter = env.begin();
        SharedString str = new std::string();
        
        for (; iter != env.end(); iter++)
        {
            (*str) += iter->first + "=" + iter->second + ",";
        }
        return str;
    }
}
