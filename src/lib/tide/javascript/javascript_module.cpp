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

#include <iostream>
#include <signal.h>
#include "javascript_module.h"
#include <Poco/Path.h>

namespace tide
{
    JavaScriptModule* JavaScriptModule::instance = NULL;
    void JavaScriptModule::Initialize()
    {
        JavaScriptModule::instance = this;
        host->AddModuleProvider(this);
        
        TiObjectRef global(Host::GetInstance()->GetGlobalObject());
        JavaScriptMethods::Bind(global);
    }

    void JavaScriptModule::Stop()
    {
        JavaScriptModule::instance = NULL;
    }

    const static std::string jsSuffix = "module.js";
    bool JavaScriptModule::IsModule(std::string& path)
    {
        int plength = path.length();
        int slength = jsSuffix.length();
        if (path.length() > jsSuffix.length())
        {
            return (path.substr(plength - slength) == jsSuffix);
        }
        else
        {
            return false;
        }
    }

    Module* JavaScriptModule::CreateModule(std::string& path)
    {
        Poco::Path p(path);
        std::string basename = p.getBaseName();
        std::string name = basename.substr(0,basename.length()-jsSuffix.length()+3);
        std::string moduledir = path.substr(0,path.length()-basename.length()-3);

        Logger *logger = Logger::Get("JavaScript");
        logger->Info("Loading JS path=%s", path.c_str());

        JavaScriptModuleInstance* instance = new JavaScriptModuleInstance(this->host, path, moduledir, name);
        return instance;
    }
}
