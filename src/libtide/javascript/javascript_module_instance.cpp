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

#include "javascript_module.h"
#include <iostream>
#include <fstream>
#include <string>

namespace tide
{
    static std::vector<JSGlobalContextRef> instanceContexts;

    JavaScriptModuleInstance::JavaScriptModuleInstance(Host* host, std::string path, std::string dir, std::string name) :
        Module(host, dir.c_str(), name.c_str(), "0.1"),
        path(path),
        context(0)
    {
        this->context = JSUtil::CreateGlobalContext();
        JSUtil::ProtectGlobalContext(context);

        try
        {
            this->Run();
        }
        catch (ValueException& e)
        {
            SharedString ss = e.GetValue()->DisplayString();
            Logger *logger = Logger::Get("JavaScript");
            logger->Error("Could not execute %s because %s", path.c_str(), (*ss).c_str());
        }

        instanceContexts.push_back(this->context);
    }

    void JavaScriptModuleInstance::Stop()
    {
        JSUtil::UnregisterGlobalContext(context);
        JSUtil::UnprotectGlobalContext(context);

        std::vector<JSGlobalContextRef>::iterator i = instanceContexts.begin();
        while (i != instanceContexts.end())
        {
            if (*i == this->context)
            {
                instanceContexts.erase(i);
                break;
            }
            i++;
        }

        this->context = 0;
    }

    void JavaScriptModuleInstance::Run()
    {
        std::string code(FileUtils::ReadFile(this->path));

        // Check the script's syntax.
        JSValueRef exception;
        JSStringRef jsCode = JSStringCreateWithUTF8CString(code.c_str());
        bool syntax = JSCheckScriptSyntax(context, jsCode, NULL, 0, &exception);
        if (!syntax)
        {
            KValueRef e = JSUtil::ToTiValue(exception, context, NULL);
            JSStringRelease(jsCode);
            throw ValueException(e);
        }

        JSUtil::Evaluate(context, code.c_str());
    }

    /*static*/
    void JavaScriptModuleInstance::GarbageCollect()
    {
        for (size_t i = 0; i < instanceContexts.size(); i++)
            JSGarbageCollect(instanceContexts[i]);
    }
}
