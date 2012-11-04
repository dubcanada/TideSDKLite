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

#ifndef _GTK_TRAY_ITEM_H_
#define _GTK_TRAY_ITEM_H_

namespace ti
{
    class GtkTrayItem : public TrayItem
    {

    public:
        GtkTrayItem(std::string& iconURL, KMethodRef cb);
        ~GtkTrayItem();

        void SetIcon(std::string& iconPath);
        void SetMenu(AutoMenu menu);
        void SetHint(std::string& hint);
        void Remove();

        GtkStatusIcon* GetWidget();
        AutoPtr<GtkMenu> GetMenu();
        KMethodRef GetCallback();

    protected:
        GtkStatusIcon* item;
        AutoPtr<GtkMenu> menu;
        KMethodRef callback;
        bool active;
    };
}

#endif
