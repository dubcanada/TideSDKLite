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

#ifndef _JAVASCRIPT_MODULE_H
#define _JAVASCRIPT_MODULE_H

#include <JavaScriptCore/JSObjectRef.h>
#include <JavaScriptCore/JSStringRef.h>
#include <JavaScriptCore/JSContextRef.h>
#include <cstring>
#include <map>
#include <tide/tide.h>

/* KJS <-> TideSDK bindings */
namespace tide 
{
    class KKJSObject;
    class KKJSMethod;
    class KKJSList;
    class JavaScriptModule;
    class JavaScriptModuleInstance;
}

#include "js_object.h"
#include "js_method.h"
#include "js_list.h"
#include "js_util.h"
#include "javascript_module_instance.h"
#include "javascript_methods.h"

namespace tide
{
    class TIDE_API JavaScriptModule : public Module, public ModuleProvider
    {
    public:
        JavaScriptModule(Host* host, const char* path) :
            Module(host, path, STRING(MODULE_NAME), STRING(MODULE_VERSION))
        {

        }

        ~JavaScriptModule()
        {

        }

        void Initialize();
        void Stop();
        virtual bool IsModule(std::string& path);
        virtual Module* CreateModule(std::string& path);

        Host* GetHost()
        {
            return host;
        }

        static JavaScriptModule* Instance()
        {
            return instance;
        }


    private:
        static JavaScriptModule *instance;
    };
}

#endif
