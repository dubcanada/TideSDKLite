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

#ifndef TI_WIN32_TRAY_ITEM_H_
#define TI_WIN32_TRAY_ITEM_H_
#include <windows.h>
#include <shellapi.h>
namespace ti
{
    class Win32TrayItem: public TrayItem
    {        
        public:
        Win32TrayItem(std::string& iconURL, KMethodRef cbSingleClick);
        virtual ~Win32TrayItem();
        void SetIcon(std::string& iconPath);
        void SetMenu(AutoMenu menu);
        void SetHint(std::string& hint);
        void Remove();
        void ShowTrayMenu();
        void HandleRightClick();
        void HandleLeftClick();
        void HandleDoubleLeftClick();
        UINT GetId();
        static bool MessageHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
        
        static LRESULT CALLBACK DoubleClickTimerProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

        private:
        HMENU oldNativeMenu;
        NOTIFYICONDATA* trayIconData;
        static std::vector<AutoPtr<Win32TrayItem> > trayItems;
        static UINT trayClickedMessage;
        bool is_double_clicked;
    };
}
#endif /* TI_WIN32_TRAY_ITEM_H_ */
