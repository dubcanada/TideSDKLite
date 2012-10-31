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
namespace tide
{
    AutoPtr<GlobalObject> GlobalObject::instance;

    GlobalObject::GlobalObject() :
        KEventObject(PRODUCT_NAME)
    {
        // @tiapi(method=True,type=String,name=getVersion,since=0.8)
        // @tiapi Return the Titanium runtime version.
        // @tiresult[String] The runtime version.
        this->SetMethod("getVersion", &GlobalObject::GetVersion);

        // @tiapi(method=True,type=String,name=getPlatform,since=0.8)
        // @tiapi Return the current platform, usually one of
        // @tiapi 'osx', 'win32', or 'linux'.
        // @tiresult[String] The current platform.
        this->SetMethod("getPlatform", &GlobalObject::GetPlatform);

        Event::SetEventConstants(this);
        Script::Initialize();
    }

    GlobalObject::~GlobalObject()
    {

    }

    void GlobalObject::GetVersion(const ValueList& args, KValueRef result)
    {
        result->SetString(PRODUCT_VERSION);
    }

    void GlobalObject::GetPlatform(const ValueList& args, KValueRef result)
    {
        result->SetString(OS_NAME);
    }

    /*static*/
    void GlobalObject::TurnOnProfiling()
    {
        instance = new ProfiledGlobalObject(instance);
    }
}
