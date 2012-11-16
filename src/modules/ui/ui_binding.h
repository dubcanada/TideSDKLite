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

#ifndef _UI_BINDING_H_
#define _UI_BINDING_H_

#include <tide/tide.h>
#include "menu_item.h"
#include "notification.h"

namespace ti
{
    class UIBinding : public AccessorObject
    {

    public:
        UIBinding(Host *host);
        virtual ~UIBinding();
        Host* GetHost();

        void CreateMainWindow(AutoPtr<WindowConfig> config);
        AutoUserWindow GetMainWindow();
        std::vector<AutoUserWindow>& GetOpenWindows();
        void AddToOpenWindows(AutoUserWindow);
        void RemoveFromOpenWindows(AutoUserWindow);
        void ClearTray();
        void UnregisterTrayItem(TrayItem*);
        void _GetOpenWindows(const ValueList& args, KValueRef result);
        void _GetMainWindow(const ValueList& args, KValueRef result);
        void _CreateWindow(const ValueList& args, KValueRef result);
        void _CreateNotification(const ValueList& args, KValueRef result);
        void _CreateMenu(const ValueList& args, KValueRef result);
        void _CreateMenuItem(const ValueList& args, KValueRef result);
        void _CreateCheckMenuItem(const ValueList& args, KValueRef result);
        void _CreateSeparatorMenuItem(const ValueList& args, KValueRef result);
        AutoMenu __CreateMenu(const ValueList& args);
        AutoMenuItem __CreateMenuItem(const ValueList& args);
        AutoMenuItem __CreateCheckMenuItem(const ValueList& args);
        AutoMenuItem __CreateSeparatorMenuItem(const ValueList& args);
        void _SetMenu(const ValueList& args, KValueRef result);
        void _GetMenu(const ValueList& args, KValueRef result);
        void _SetContextMenu(const ValueList& args, KValueRef result);
        void _GetContextMenu(const ValueList& args, KValueRef result);
        void _SetIcon(const ValueList& args, KValueRef result);
        void _SetIcon(std::string iconURL);
        void _AddTray(const ValueList& args, KValueRef result);
        void _ClearTray(const ValueList& args, KValueRef result);
        void _GetIdleTime(const ValueList& args, KValueRef result);

        /* OS X specific callbacks */
        void _SetDockIcon(const ValueList& args, KValueRef result);
        void _SetDockMenu(const ValueList& args, KValueRef result);
        void _SetBadge(const ValueList& args, KValueRef result);
        void _SetBadgeImage(const ValueList& args, KValueRef result);

        virtual AutoMenu CreateMenu() = 0;
        virtual AutoMenuItem CreateMenuItem() = 0;;
        virtual AutoMenuItem CreateCheckMenuItem() = 0;
        virtual AutoMenuItem CreateSeparatorMenuItem() = 0;
        virtual void SetMenu(AutoMenu) = 0;
        virtual void SetContextMenu(AutoMenu) = 0;
        virtual void SetIcon(std::string& iconPath) = 0;
        virtual AutoTrayItem AddTray(std::string& iconPath, TiMethodRef cbSingleClick) = 0;
        virtual AutoMenu GetMenu() = 0;
        virtual AutoMenu GetContextMenu() = 0;
        virtual long GetIdleTime() = 0;

        /* These have empty impls, because are OS X-only for now */
        virtual void SetDockIcon(std::string& icon_path) {}
        virtual void SetDockMenu(AutoMenu) {}
        virtual void SetBadge(std::string& badgeLabel) {}
        virtual void SetBadgeImage(std::string& badgeImagePath) {}

        static void ErrorDialog(std::string);
        static inline UIBinding* GetInstance() { return instance; }

    protected:
        static UIBinding* instance;
        Host* host;
        AutoUserWindow mainWindow;
        std::vector<AutoUserWindow> openWindows;
        std::vector<AutoTrayItem> trayItems;
        std::string iconURL;

        static void Log(Logger::Level level, std::string& message);
    };
}

#endif
