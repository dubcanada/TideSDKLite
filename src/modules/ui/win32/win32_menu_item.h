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

#ifndef _WIN32_MENU_ITEM_H_
#define _WIN32_MENU_ITEM_H_
namespace ti
{
    class Win32MenuItem : public MenuItem
    {
    public:
        // Pieces of information we can use to do a reverse lookup
        // on an item's position in a parent menu.
        struct NativeItemBits
        {
            UINT id;
            HMENU parentMenu;
            HMENU submenu;
        };

        Win32MenuItem(MenuItemType type);
        virtual ~Win32MenuItem();

        void SetLabelImpl(std::string newLabel);
        void SetIconImpl(std::string newIconPath);
        void SetStateImpl(bool newState);
        void SetCallbackImpl(TiMethodRef callback);
        void SetSubmenuImpl(AutoMenu newSubmenu);
        void SetEnabledImpl(bool enabled);

        void RecreateAllNativeItems();
        void RecreateMenuItem(NativeItemBits* bits);
        void CreateNative(LPMENUITEMINFO itemInfo,
            HMENU nativeParentMenu, bool registerNative);
        void DestroyNative(NativeItemBits* bits);
        void DestroyNative(HMENU nativeParent, int position);
        static int GetNativeMenuItemPosition(NativeItemBits* bits);
        static bool HandleClickEvent(HMENU nativeMenu, UINT position);

    private:
        std::string iconPath;
        AutoPtr<Win32Menu> oldSubmenu;
        std::wstring wideOldLabel;
        std::vector<NativeItemBits*> nativeItems;

    };
}
#endif
