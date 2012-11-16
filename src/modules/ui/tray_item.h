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

#ifndef _TRAY_ITEM_H_
#define _TRAY_ITEM_H_

#include <tide/tide.h>
#include "menu_item.h"

namespace ti
{
    class TrayItem : public EventObject
    {

    public:
        TrayItem(std::string& iconURL);
        ~TrayItem();

        virtual void SetIcon(std::string& iconPath) = 0;
        virtual void SetMenu(AutoMenu menu) = 0;
        virtual void SetHint(std::string& hint) = 0;
        virtual void Remove() = 0;

        void _SetIcon(const ValueList& args, KValueRef result);
        void _SetMenu(const ValueList& args, KValueRef result);
        void _SetHint(const ValueList& args, KValueRef result);
        void _GetIcon(const ValueList& args, KValueRef result);
        void _GetMenu(const ValueList& args, KValueRef result);
        void _GetHint(const ValueList& args, KValueRef result);
        void _Remove(const ValueList& args, KValueRef result);

    protected:
        AutoMenu menu;
        std::string iconURL;
        std::string iconPath;
        std::string hint;
        bool removed;
    };
}

#endif
