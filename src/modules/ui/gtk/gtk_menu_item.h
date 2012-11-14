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

#ifndef _GTK_MENU_ITEM_H_
#define _GTK_MENU_ITEM_H_
namespace ti
{
    class GtkMenuItem : public MenuItem
    {
    public:
        GtkMenuItem(MenuItemType type);
        virtual ~GtkMenuItem();

        void SetLabelImpl(std::string newLabel);
        void SetIconImpl(std::string newIconPath);
        void SetStateImpl(bool newState);
        void SetCallbackImpl(KMethodRef callback);
        void SetSubmenuImpl(AutoMenu newSubmenu);
        void SetEnabledImpl(bool enabled);

        void ReplaceNativeItem(::GtkMenuItem* nativeItem, ::GtkMenuItem* newNativeItem);
        void SetNativeItemIcon(::GtkMenuItem* nativeItem, std::string& newIconPath);
        void SetNativeItemSubmenu(::GtkMenuItem* nativeItem, AutoMenu newSubmenu);
        ::GtkMenuItem* CreateNative(bool registerNative);
        void DestroyNative(::GtkMenuItem* nativeItem);

    private:
        std::vector< ::GtkMenuItem* > nativeItems;
        AutoPtr<GtkMenu> oldSubmenu;
    };
}

#endif