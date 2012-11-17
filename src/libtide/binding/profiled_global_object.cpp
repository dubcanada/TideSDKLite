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
#include <iostream>
#include <sstream>
#include <Poco/Stopwatch.h>
#include <Poco/ScopedLock.h>

namespace tide
{
    ProfiledGlobalObject::ProfiledGlobalObject(TiObjectRef global) :
        profiledObject(new ProfiledBoundObject(global))
    {
    }

    ProfiledGlobalObject::~ProfiledGlobalObject()
    {
    }

    void ProfiledGlobalObject::Set(const char* name, ValueRef value)
    {
        profiledObject->Set(name, value);
    }

    ValueRef ProfiledGlobalObject::Get(const char* name)
    {
        return profiledObject->Get(name);
    }

    SharedStringList ProfiledGlobalObject::GetPropertyNames()
    {
        return profiledObject->GetPropertyNames();
    }

    SharedString ProfiledGlobalObject::DisplayString(int levels)
    {
        return profiledObject->DisplayString(levels);
    }

    bool ProfiledGlobalObject::HasProperty(const char* name)
    {
        return profiledObject->HasProperty(name);
    }

    bool ProfiledGlobalObject::Equals(TiObjectRef other)
    {
        return profiledObject->Equals(other);
    }
}
