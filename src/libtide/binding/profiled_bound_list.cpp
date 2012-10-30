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

namespace tide
{
    ProfiledBoundList::ProfiledBoundList(KListRef delegate) :
        ProfiledBoundObject(delegate),
        list(delegate),
        count(1)
    {
    }

    ProfiledBoundList::~ProfiledBoundList()
    {
    }

    void ProfiledBoundList::Append(KValueRef value)
    {
        list->Append(value);
    }

    unsigned int ProfiledBoundList::Size()
    {
        return list->Size();
    }

    KValueRef ProfiledBoundList::At(unsigned int index)
    {
        return list->At(index);
    }

    void ProfiledBoundList::SetAt(unsigned int index, KValueRef value)
    {
        list->SetAt(index,value);
    }

    bool ProfiledBoundList::Remove(unsigned int index)
    {
        return list->Remove(index);
    }

    void ProfiledBoundList::Set(const char *name, KValueRef value)
    {
        list->Set(name, value);
    }

    KValueRef ProfiledBoundList::Get(const char *name)
    {
        return list->Get(name);
    }

    SharedStringList ProfiledBoundList::GetPropertyNames()
    {
        return list->GetPropertyNames();
    }

    bool ProfiledBoundList::HasProperty(const char* name)
    {
        return list->HasProperty(name);
    }
}
