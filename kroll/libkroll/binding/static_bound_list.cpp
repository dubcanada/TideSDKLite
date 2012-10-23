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

#include "../kroll.h"
#include <cmath>
#include <cstdio>
#include <cstring>

namespace kroll
{
    StaticBoundList::StaticBoundList(const char *type) :
        KList(type),
        object(new StaticBoundObject()),
        length(0)
    {
    }

    StaticBoundList::~StaticBoundList()
    {
    }

    void StaticBoundList::Append(KValueRef value)
    {
        std::string name = KList::IntToChars(this->length);
        this->object->Set(name.c_str(), value);
        this->length++;
    }

    void StaticBoundList::SetAt(unsigned int index, KValueRef value)
    {
        std::string name = KList::IntToChars(index);
        this->object->Set(name.c_str(), value);
        if (index >= this->length)
            this->length = index + 1;
    }

    bool StaticBoundList::Remove(unsigned int index)
    {
        if (index >= this->length)
            return false;

        std::string name = KList::IntToChars(index);
        this->object->Unset(name.c_str());
        for (unsigned int i = index; i + 1 < this->length; i++)
            this->SetAt(i, this->At(i + 1));

        this->length--;
        return true;
    }

    unsigned int StaticBoundList::Size()
    {
        return this->length;
    }

    KValueRef StaticBoundList::At(unsigned int index)
    {
        std::string name = KList::IntToChars(index);
        KValueRef value = this->object->Get(name.c_str());
        return value;
    }

    void StaticBoundList::Set(const char *name, KValueRef value)
    {
        int index = -1;
        if (KList::IsInt(name) && (index = atoi(name)) >= 0)
        {
            this->SetAt(index, value);
        }
        else
        {
            this->object->Set(name, value);
        }
    }

    KValueRef StaticBoundList::Get(const char *name)
    {
        return this->object->Get(name);
    }

    SharedStringList StaticBoundList::GetPropertyNames()
    {
        return this->object->GetPropertyNames();
    }

    KListRef StaticBoundList::FromStringVector(std::vector<std::string>& values)
    {
        KListRef l = new StaticBoundList();
        std::vector<std::string>::iterator i = values.begin();
        while (i != values.end())
        {
            l->Append(Value::NewString(*i));
            i++;
        }
        return l;
    }
}