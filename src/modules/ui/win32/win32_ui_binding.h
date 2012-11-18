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

#ifndef _WIN32_UI_BINDING_H_
#define _WIN32_UI_BINDING_H_

#define WEB_INSPECTOR_MENU_ITEM_ID 7500
#define NEXT_ITEM_ID_BEGIN 7501

namespace ti
{
    class Win32UIBinding : public UIBinding
    {
        public:
        Win32UIBinding(Module* uiModule, Host *host);
        ~Win32UIBinding();
        AutoMenu CreateMenu();
        AutoMenuItem CreateMenuItem();
        AutoMenuItem CreateSeparatorMenuItem();
        AutoMenuItem CreateCheckMenuItem();
        void SetMenu(AutoMenu);
        AutoTrayItem AddTray(std::string& icon_path, TiMethodRef cbSingleClick);
        void SetContextMenu(AutoMenu);
        void SetIcon(std::string& iconPath);
        long GetIdleTime();

        AutoMenu GetMenu();
        AutoMenu GetContextMenu();
        std::string& GetIcon();
        static UINT nextItemId;

        static HICON LoadImageAsIcon(std::string& path, int sizeX, int sizeY);
        static HBITMAP LoadImageAsBitmap(std::string& path, int sizeX, int sizeY);
        static HICON BitmapToIcon(HBITMAP bitmap, int sizeX, int sizeY);
        static HBITMAP IconToBitmap(HICON icon, int sizeX, int sizeY);
        static HBITMAP LoadPNGAsBitmap(std::string& path, int sizeX, int sizeY);
        static cairo_surface_t* ScaleCairoSurface(
            cairo_surface_t *oldSurface, int newWidth, int newHeight);
        static void ReleaseImage(HANDLE);
        static void SetProxyForURL(std::string& url);
        static void ErrorDialog(std::string);

        private:
        AutoPtr<Win32Menu> menu;
        AutoPtr<Win32Menu> contextMenu;
        std::string iconPath;
        static std::vector<HICON> loadedICOs;
        static std::vector<HBITMAP> loadedBMPs;
    };
}

#endif
