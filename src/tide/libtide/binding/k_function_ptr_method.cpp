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
**/

#include "../kroll.h"

namespace kroll
{
    KFunctionPtrMethod::KFunctionPtrMethod(KFunctionPtrCallback callback) :
        callback(callback)
    {
        this->object = new StaticBoundObject();
    }

    KFunctionPtrMethod::~KFunctionPtrMethod()
    {
    }

    KValueRef KFunctionPtrMethod::Call(const ValueList& args)
    {
        return this->callback(args);
    }

    void KFunctionPtrMethod::Set(const char *name, KValueRef value)
    {
        this->object->Set(name, value);
    }

    KValueRef KFunctionPtrMethod::Get(const char *name)
    {
        return this->object->Get(name);
    }

    SharedStringList KFunctionPtrMethod::GetPropertyNames()
    {
        return this->object->GetPropertyNames();
    }
}