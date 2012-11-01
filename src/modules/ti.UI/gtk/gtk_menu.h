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

#ifndef _GTK_MENU_H_
#define _GTK_MENU_H_
namespace ti
{
    class GtkMenu : public Menu
    {
    public:
        GtkMenu();
        ~GtkMenu();

        void AppendItemImpl(AutoMenuItem item);
        void InsertItemAtImpl(AutoMenuItem item, unsigned int index);
        void RemoveItemAtImpl(unsigned int index);
        void ClearImpl();

        void ClearNativeMenu(::GtkMenuShell* nativeMenu);
        void RemoveItemAtFromNativeMenu(::GtkMenuShell* nativeMenu, unsigned int index);
        void DestroyNative(::GtkMenuShell* nativeMenu);
        GtkMenuShell* CreateNativeBar(bool registerNative);
        ::GtkMenuShell* CreateNative(bool registerNative);
        void AddChildrenToNativeMenu(::GtkMenuShell* nativeMenu, bool registerNative);
        void RegisterNativeMenuItem(AutoMenuItem item, ::GtkMenuItem* nativeItem);
        void DestroyNativeMenuItem(::GtkMenuItem* nativeItem);

    private:
        std::vector<AutoMenuItem> oldChildren;
        std::vector< ::GtkMenuShell* > nativeMenus;
    };
}

#endif
