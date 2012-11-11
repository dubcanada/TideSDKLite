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

#ifndef _WIN32_MENU_H_
#define _WIN32_MENU_H_
namespace ti
{
    class Win32Menu : public Menu
    {
        public:
        Win32Menu();
        ~Win32Menu();

        void AppendItemImpl(AutoMenuItem item);
        void InsertItemAtImpl(AutoMenuItem item, unsigned int index);
        void RemoveItemAtImpl(unsigned int index);
        void ClearImpl();

        void ClearNativeMenu(HMENU nativeMenu);
        void DestroyNative(HMENU nativeMenu);
        HMENU CreateNative(bool registerNative);
        HMENU CreateNativeTopLevel(bool registerNative);
        void AddChildrenToNativeMenu(HMENU nativeMenu, bool registerNative);

        static void InsertItemIntoNativeMenu(
            Win32MenuItem* menuItem, HMENU nativeMenu,
            bool registerNative, int position=-1);
        static void RemoveItemAtFromNativeMenu(
            Win32MenuItem* item, HMENU nativeMenu, int position);
        static void ApplyNotifyByPositionStyleToNativeMenu(HMENU nativeMenu);

        private:
        std::vector<AutoMenuItem> oldChildren;
        std::vector<HMENU> nativeMenus;
    };
}
#endif
