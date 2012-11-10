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
    KDelegatingObject::KDelegatingObject(KObjectRef global) :
        global(global),
        local(new StaticBoundObject())
    {
    }

    KDelegatingObject::KDelegatingObject(
        KObjectRef global, KObjectRef local) :
        global(global),
        local(local)
    {
    }

    KDelegatingObject::~KDelegatingObject()
    {
    }

    KValueRef KDelegatingObject::Get(const char *name)
    {
        Poco::Mutex::ScopedLock lock(mutex);

        KValueRef val = local->Get(name);
        if (!val->IsUndefined())
        {
            // We want properties of the local object to
            // override // properties set on the global object.
            return val;
        }
        else
        {
            // If the property isn't found on the local object, search
            // for it in the global object.
            return this->global->Get(name);
        }
    }

    void KDelegatingObject::Set(const char *name, KValueRef value)
    {
        // We want to set the property on both
        // the local and the global object.
        Poco::Mutex::ScopedLock lock(mutex);
        local->Set(name, value);
        global->Set(name, value);
    }

    bool KDelegatingObject::HasProperty(const char* name)
    {
        return global->HasProperty(name) || local->HasProperty(name);
    }

    SharedStringList KDelegatingObject::GetPropertyNames()
    {
        Poco::Mutex::ScopedLock lock(mutex);

        SharedStringList globalList = global->GetPropertyNames();
        SharedStringList localList = local->GetPropertyNames();

        for (size_t i = 0; i < globalList->size(); i++)
        {
            bool found = false;
            for (size_t j = 0; j < localList->size(); j++)
            {
                if (globalList->at(i).get() == localList->at(j).get())
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                localList->push_back(globalList->at(i));
            }
        }
        return localList;
    }
}
