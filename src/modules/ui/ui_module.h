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

#ifndef _UI_MODULE_H_
#define _UI_MODULE_H_

#include <tide/tide.h>

namespace ti {
    class UIBinding;
    class Menu;
    class MenuItem;
    class TrayItem;
    class UserWindow;

    typedef AutoPtr<UserWindow> AutoUserWindow;
    typedef AutoPtr<UIBinding> AutoUIBinding;
    typedef AutoPtr<Menu> AutoMenu;
    typedef AutoPtr<MenuItem> AutoMenuItem;
    typedef AutoPtr<TrayItem> AutoTrayItem;
}

#include <JavaScriptCore/JSObjectRef.h>
#include <JavaScriptCore/JSStringRef.h>
#include <JavaScriptCore/JSContextRef.h>

#include <iostream>
#include <tide/javascript/javascript_module.h>
#include "window_config.h"
#include "user_window.h"
#include "menu.h"
#include "menu_item.h"
#include "tray_item.h"
#include "ui_binding.h"

#ifndef TIDE_LITE
#include "lang_binding/script_evaluator.h"
#endif

#include "clipboard.h"

#ifdef OS_LINUX
#include "gtk/ui_module_gtk.h"
#elif defined(OS_OSX)
#include "osx/ui_module_osx.h"
#elif defined(OS_WIN32)
#include "win32/ui_module_win32.h"
#endif

#include "url/url.h"

namespace ti {

    class UIModule : public tide::Module
    {
        TIDE_MODULE_CLASS(UIModule)

        public:
        static UIModule* GetInstance() { return instance_; }
        AutoUIBinding GetUIBinding() { return uiBinding; }
        void Start();
        static bool IsResourceLocalFile(std::string string);

        protected:
        DISALLOW_EVIL_CONSTRUCTORS(UIModule);
        static UIModule* instance_;
        AutoUIBinding uiBinding;

    };
}

#endif
