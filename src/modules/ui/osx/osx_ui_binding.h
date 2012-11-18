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

#ifndef _OSX_UI_BINDING_H_
#define _OSX_UI_BINDING_H_
#include <tide/tide.h>
#include "../ui_module.h"
namespace ti
{
    class OSXMenuItem;
    class OSXUIBinding : public UIBinding
    {

        public:
        OSXUIBinding(Host *host);
        ~OSXUIBinding();

        AutoMenu CreateMenu();
        AutoMenuItem CreateMenuItem();
        AutoMenuItem CreateCheckMenuItem();
        AutoMenuItem CreateSeparatorMenuItem();
        AutoMenu GetMenu();
        AutoMenu GetContextMenu();
        AutoMenu GetDockMenu();
        NSMenu* GetNativeDockMenu();
        void SetMenu(AutoMenu);
        void SetContextMenu(AutoMenu);
        void SetDockMenu(AutoMenu);

        AutoTrayItem AddTray(std::string& icon_path, TiMethodRef cb);
        void SetIcon(std::string& iconPath);
        virtual void SetDockIcon(std::string& iconPath);
        virtual void SetBadge(std::string& badgeLabel);
        virtual void SetBadgeImage(std::string& badgeImage);

        AutoPtr<OSXMenu> GetActiveMenu();
        void WindowFocused(AutoPtr<OSXUserWindow> window);
        void WindowUnfocused(AutoPtr<OSXUserWindow> window);
        void SetupMainMenu(bool force = false);
        void SetupAppMenuParts(NSMenu* mainMenu);
        void ReplaceMainMenu();
        NSMenu* GetDefaultMenu();
        long GetIdleTime();

        static NSImage* MakeImage(std::string&);
        static void ErrorDialog(std::string);

    protected:
        NSMenu* defaultMenu;
        AutoPtr<OSXMenu> menu;
        NSMenu* nativeMenu;
        AutoPtr<OSXMenu> contextMenu;
        AutoPtr<OSXMenu> dockMenu;
        NSMenu* nativeDockMenu;
        NSView *savedDockView;
        NSObject* application;
        AutoPtr<OSXMenu> activeMenu;
        AutoPtr<OSXUserWindow> activeWindow;

        void InstallMenu (OSXMenuItem*);
    };
}

#endif
