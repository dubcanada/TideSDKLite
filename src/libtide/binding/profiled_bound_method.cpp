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
#include <cstdio>
#include <cstring>
#include <Poco/Stopwatch.h>

namespace kroll
{
    ProfiledBoundMethod::ProfiledBoundMethod(KMethodRef delegate, std::string& type) :
        ProfiledBoundObject(delegate),
        method(delegate),
        fullType(type),
        count(1)
    {
    }

    ProfiledBoundMethod::~ProfiledBoundMethod()
    {
    }

    KValueRef ProfiledBoundMethod::Call(const ValueList& args)
    {
        std::string type = this->GetType();

        KValueRef value;
        Poco::Stopwatch sw;
        sw.start();
        try {
            value = method->Call(args);
        } catch (...) {
            sw.stop();
            this->Log("call", type, sw.elapsed());
            throw;
        }

        sw.stop();
        this->Log("call", type, sw.elapsed());
        return this->Wrap(value, type);
    }

    void ProfiledBoundMethod::Set(const char *name, KValueRef value)
    {
        method->Set(name,value);
    }

    KValueRef ProfiledBoundMethod::Get(const char *name)
    {
        return method->Get(name);
    }

    SharedStringList ProfiledBoundMethod::GetPropertyNames()
    {
        return method->GetPropertyNames();
    }

    bool ProfiledBoundMethod::HasProperty(const char* name)
    {
        return method->HasProperty(name);
    }

    std::string& ProfiledBoundMethod::GetType()
    {
        return fullType;
    }
}
