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

#ifndef _MENU_H_
#define _MENU_H_
#include <tide/tide.h>
namespace ti
{
    class Menu : public AccessorObject
    {
    public:
        // Platform-independent implementation
        Menu();
        ~Menu();

        void _AppendItem(const ValueList& args, ValueRef result);
        void _GetItemAt(const ValueList& args, ValueRef result);
        void _InsertItemAt(const ValueList& args, ValueRef result);
        void _RemoveItemAt(const ValueList& args, ValueRef result);
        void _GetLength(const ValueList& args, ValueRef result);
        void _Clear(const ValueList& args, ValueRef result);

        void _AddItem(const ValueList& args, ValueRef result);
        void _AddSeparatorItem(const ValueList& args, ValueRef result);
        void _AddCheckItem(const ValueList& args, ValueRef result);

        void AppendItem(AutoMenuItem item);
        AutoMenuItem GetItemAt(int index);
        void InsertItemAt(AutoMenuItem item, size_t index);
        void RemoveItemAt(size_t index);
        bool ContainsItem(MenuItem* item);
        bool ContainsSubmenu(Menu* submenu);

        // Platform-specific implementation
        virtual void AppendItemImpl(AutoMenuItem item) = 0;
        virtual void InsertItemAtImpl(AutoMenuItem item, unsigned int index) = 0;
        virtual void RemoveItemAtImpl(unsigned int index) = 0;
        virtual void ClearImpl() = 0;

    protected:
        std::vector<AutoMenuItem> children;
    };
}
#endif
