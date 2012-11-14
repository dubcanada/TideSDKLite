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

#include "ui_module.h"
#include <Poco/URI.h>

namespace ti
{
    TIDE_MODULE(UIModule, STRING(MODULE_NAME), STRING(MODULE_VERSION))
    UIModule* UIModule::instance_ = 0;

    void UIModule::Initialize()
    {
        // We are keeping this object in a static variable, which means
        // that we should only ever have one copy of the UI module.
        UIModule::instance_ = this;
    }

    void UIModule::Start()
    {
#ifdef OS_WIN32
        this->uiBinding = new Win32UIBinding(this, host);
#elif OS_OSX
        this->uiBinding = new OSXUIBinding(host);
#elif OS_LINUX
        this->uiBinding = new GtkUIBinding(host);
#endif
        host->GetGlobalObject()->SetObject("UI", this->uiBinding);
        host->GetGlobalObject()->SetObject("Notification", this->uiBinding);
#ifndef TIDE_LITE
        ScriptEvaluator::Initialize();
#endif
        AppConfig* config = AppConfig::Instance();
        if (!config)
        {
            std::string msg = "Error loading tiapp.xml. Your application "
                "is not properly configured or packaged.";
            this->uiBinding->ErrorDialog(msg);
            throw ValueException::FromString(msg.c_str());
            return;
        }

        // If there is no main window configuration, this just
        // AppConfig::GetMainWindow returns a default configuration.
        this->uiBinding->CreateMainWindow(config->GetMainWindow());

        try
        {
            std::string& appIcon = host->GetApplication()->image;
            if (!appIcon.empty())
                this->uiBinding->_SetIcon(appIcon);
        }
        catch (ValueException& e)
        {
            SharedString ss = e.DisplayString();
            Logger::Get("UI")->Error("Could not set default icon: %s", ss->c_str());
        }
    }

    void UIModule::Stop()
    {
        // Remove app tray icons
        uiBinding->ClearTray();
    }

    bool UIModule::IsResourceLocalFile(std::string string)
    {
        Poco::URI uri(string.c_str());
        std::string scheme = uri.getScheme();
        return (scheme == "app" || scheme == "ti" || scheme == "file");
    }
}
