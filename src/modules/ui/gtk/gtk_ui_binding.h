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

#ifndef _GTK_UI_BINDING_H_
#define _GTK_UI_BINDING_H_

#include "../ui_module.h"

namespace ti
{
    class GtkUIBinding : public UIBinding
    {

        public:
        GtkUIBinding(Host* host);

        AutoMenu CreateMenu();
        AutoMenuItem CreateMenuItem();
        AutoMenuItem CreateSeparatorMenuItem();
        AutoMenuItem CreateCheckMenuItem();
        void SetMenu(AutoMenu newMenu);
        void SetContextMenu(AutoMenu);
        void SetIcon(std::string&);
        AutoTrayItem AddTray(std::string&, TiMethodRef cb);
        long GetIdleTime();
        AutoMenu GetMenu();
        AutoMenu GetContextMenu();
        std::string& GetIcon();

        static void ErrorDialog(std::string);

        protected:
#ifndef TIDE_LITE
        SharedPtr<ScriptEvaluator> evaluator;
#endif
        AutoPtr<GtkMenu> menu;
        AutoPtr<GtkMenu> contextMenu;
        std::string iconPath;
    };
}

#endif
