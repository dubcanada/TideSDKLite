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

#include "../ui_module.h"
namespace ti
{
    OSXTrayItem::OSXTrayItem(std::string& iconURL, TiMethodRef cb) :
        TrayItem(iconURL),
        nativeMenu(0),
        menu(0),
        callback(cb),
        nativeItem(0)
    {
        OSXTrayItemDelegate* delegate = [[OSXTrayItemDelegate alloc] initWithTray:this];
        NSStatusBar *statusBar = [NSStatusBar systemStatusBar];
        nativeItem = [statusBar statusItemWithLength:NSVariableStatusItemLength];
        [nativeItem retain];
        [nativeItem setTarget:delegate];
        [nativeItem setAction:@selector(invoke:)];
        [nativeItem setHighlightMode:YES];

        this->SetIcon(this->iconPath);
    }

    OSXTrayItem::~OSXTrayItem()
    {
        if (!this->menu.isNull() && this->nativeMenu) {
            this->menu->DestroyNative(this->nativeMenu);
        }
    }

    void OSXTrayItem::SetIcon(std::string& iconPath)
    {
        NSImage* image = ti::OSXUIBinding::MakeImage(iconPath);
        [nativeItem setImage:image];
    }

    void OSXTrayItem::SetMenu(AutoMenu menu)
    {
        if (menu.get() == this->menu.get()) {
            return;
        }

        AutoPtr<OSXMenu> newMenu = menu.cast<OSXMenu>();
        NSMenu* newNativeMenu = nil;
        if (!newMenu.isNull()) {
            newNativeMenu = newMenu->CreateNativeNow(true);
        }

        if (!this->menu.isNull() && this->nativeMenu) {
            this->menu->DestroyNative(this->nativeMenu);
        }

        this->menu = newMenu;
        this->nativeMenu = newNativeMenu;
    }

    void OSXTrayItem::SetHint(std::string& hint)
    {
        if (hint.empty()) {
            [nativeItem setToolTip:@""];
        } else {
            [nativeItem setToolTip:[NSString stringWithUTF8String:hint.c_str()]];
        }
    }

    void OSXTrayItem::Remove()
    {
        [[NSStatusBar systemStatusBar] removeStatusItem:nativeItem];
        [[nativeItem target] release];
        [nativeItem release];
    }

    void OSXTrayItem::InvokeCallback()
    {
        if (nativeMenu != nil)
        {
            [nativeItem popUpStatusItemMenu:nativeMenu];
        }

        if (callback.isNull())
            return;

        try {
            callback->Call(ValueList());
        } catch (ValueException& e) {
            Logger* logger = Logger::Get("UI.OSXTrayItem");
            SharedString ss = e.DisplayString();
            logger->Error("Tray icon callback failed: %s", ss->c_str());
        }
    }
}
