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

#include "../tide.h"
#include <cstring>

namespace tide
{
    StaticBoundObject::StaticBoundObject(const char* type)
        : KObject(type)
    {
    }

    StaticBoundObject::~StaticBoundObject()
    {
    }

    bool StaticBoundObject::HasProperty(const char* name)
    {
        return properties.find(name) != properties.end();
    }
    
    KValueRef StaticBoundObject::Get(const char* name)
    {
        Poco::Mutex::ScopedLock lock(mutex);
        std::map<std::string, KValueRef>::iterator iter = 
            properties.find(std::string(name));

        if (iter == properties.end())
            return Value::Undefined;
        return iter->second;
    }

    void StaticBoundObject::Set(const char* name, KValueRef value)
    {
        Poco::Mutex::ScopedLock lock(mutex);
        this->properties[std::string(name)] = value;
    }

    void StaticBoundObject::Unset(const char* name)
    {
        Poco::Mutex::ScopedLock lock(mutex);
        std::map<std::string, KValueRef>::iterator iter = 
            properties.find(std::string(name));

        if (this->properties.end() == iter)
            return;
        this->properties.erase(iter);
    }

    SharedStringList StaticBoundObject::GetPropertyNames()
    {
        SharedStringList list(new StringList());
        Poco::Mutex::ScopedLock lock(mutex);
        std::map<std::string, KValueRef>::iterator iter = properties.begin();

        while (iter != properties.end())
            list->push_back(new std::string((iter++)->first));

        return list;
    }
}
