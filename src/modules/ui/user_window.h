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

#ifndef _USER_WINDOW_H_
#define _USER_WINDOW_H_

#include <string>
#include <vector>
#include <map>
#include <tide/tide.h>

#ifdef OS_WIN32
#undef CreateWindow
#endif

#include "../app/app_config.h"
#include "../app/window_config.h"

namespace ti
{
    typedef struct {
        double x;
        double y;
        double width;
        double height;
    } Bounds;

    class UserWindow : public EventObject
    {
        public:
            // Platform-specific implementation.
            static AutoUserWindow CreateWindow(AutoPtr<WindowConfig> config, AutoUserWindow parent);

            virtual SharedString DisplayString(int levels=3);
            virtual ~UserWindow();
            void UpdateWindowForURL(std::string url);
            void RegisterJSContext(JSGlobalContextRef);
            void InsertAPI(TiObjectRef frameGlobal);
            void PageLoaded(TiObjectRef scope, std::string &url, JSGlobalContextRef context);
            inline TiObjectRef GetDOMWindow() { return this->domWindow; }
            inline Host* GetHost() { return this->host; }
            inline bool IsToolWindow() {return this->config->IsToolWindow(); }
            inline void SetToolWindow(bool toolWindow) {this->config->SetToolWindow(toolWindow); }
            inline bool HasTransparentBackground() { return this->config->HasTransparentBackground(); }
            inline void SetTransparentBackground(bool transparentBackground) { this->config->SetTransparentBackground(transparentBackground); }
            inline std::string GetId() { return this->config->GetID(); }

            void _GetCurrentWindow(const tide::ValueList&, tide::ValueRef);
            void _GetDOMWindow(const tide::ValueList&, tide::ValueRef);
            void _InsertAPI(const tide::ValueList&, tide::ValueRef);
            void _Hide(const tide::ValueList&, tide::ValueRef);
            void _Show(const tide::ValueList&, tide::ValueRef);
            void _Minimize(const tide::ValueList&, tide::ValueRef);
            void _Maximize(const tide::ValueList&, tide::ValueRef);
            void _Unminimize(const tide::ValueList&, tide::ValueRef);
            void _Unmaximize(const tide::ValueList&, tide::ValueRef);
            void _IsMaximized(const tide::ValueList&, tide::ValueRef);
            void _IsMinimized(const tide::ValueList&, tide::ValueRef);
            void _Focus(const tide::ValueList&, tide::ValueRef);
            void _Unfocus(const tide::ValueList&, tide::ValueRef);
            void _IsUsingChrome(const tide::ValueList&, tide::ValueRef);
            void _SetUsingChrome(const tide::ValueList&, tide::ValueRef);
            void _IsToolWindow(const tide::ValueList&, tide::ValueRef);
            void _SetToolWindow(const tide::ValueList&, tide::ValueRef);
            void _HasTransparentBackground(const tide::ValueList&, tide::ValueRef);
            void _SetTransparentBackground(const tide::ValueList&, tide::ValueRef);
            void _IsUsingScrollbars(const tide::ValueList&, tide::ValueRef);
            void _IsFullscreen(const tide::ValueList&, tide::ValueRef);
            void _SetFullscreen(const tide::ValueList&, tide::ValueRef);
            void _GetId(const tide::ValueList&, tide::ValueRef);
            void _Open(const tide::ValueList&, tide::ValueRef);
            void _Close(const tide::ValueList&, tide::ValueRef);
            void _GetX(const tide::ValueList&, tide::ValueRef);
            double _GetX();
            void _SetX(const tide::ValueList&, tide::ValueRef);
            void _SetX(double x);
            void _GetY(const tide::ValueList&, tide::ValueRef);
            double _GetY();
            void _SetY(const tide::ValueList&, tide::ValueRef);
            void _SetY(double y);
            void _MoveTo(const tide::ValueList&, tide::ValueRef);
            void _SetSize(const tide::ValueList&, tide::ValueRef);
            void _GetWidth(const tide::ValueList&, tide::ValueRef);
            double _GetWidth();
            void _SetWidth(const tide::ValueList&, tide::ValueRef);
            void _SetWidth(double width);
            void _GetMaxWidth(const tide::ValueList&, tide::ValueRef);
            void _SetMaxWidth(const tide::ValueList&, tide::ValueRef);
            void _GetMinWidth(const tide::ValueList&, tide::ValueRef);
            void _SetMinWidth(const tide::ValueList&, tide::ValueRef);
            void _GetHeight(const tide::ValueList&, tide::ValueRef);
            double _GetHeight();
            void _SetHeight(const tide::ValueList&, tide::ValueRef);
            void _SetHeight(double height);
            void _GetMaxHeight(const tide::ValueList&, tide::ValueRef);
            void _SetMaxHeight(const tide::ValueList&, tide::ValueRef);
            void _GetMinHeight(const tide::ValueList&, tide::ValueRef);
            void _SetMinHeight(const tide::ValueList&, tide::ValueRef);
            void _GetBounds(const tide::ValueList&, tide::ValueRef);
            void _SetBounds(const tide::ValueList&, tide::ValueRef);
            void _GetTitle(const tide::ValueList&, tide::ValueRef);
            void _SetTitle(const tide::ValueList&, tide::ValueRef);
            void _GetURL(const tide::ValueList&, tide::ValueRef);
            void _SetURL(const tide::ValueList&, tide::ValueRef);
            void _IsResizable(const tide::ValueList&, tide::ValueRef);
            void _SetResizable(const tide::ValueList&, tide::ValueRef);
            void _IsMaximizable(const tide::ValueList&, tide::ValueRef);
            void _SetMaximizable(const tide::ValueList&, tide::ValueRef);
            void _IsMinimizable(const tide::ValueList&, tide::ValueRef);
            void _SetMinimizable(const tide::ValueList&, tide::ValueRef);
            void _IsCloseable(const tide::ValueList&, tide::ValueRef);
            void _SetCloseable(const tide::ValueList&, tide::ValueRef);
            void _IsVisible(const tide::ValueList&, tide::ValueRef);
            void _IsActive(const tide::ValueList&, tide::ValueRef);
            void _SetVisible(const tide::ValueList&, tide::ValueRef);
            void _GetTransparency(const tide::ValueList&, tide::ValueRef);
            void _SetTransparency(const tide::ValueList&, tide::ValueRef);
            void _GetMenu(const tide::ValueList&, tide::ValueRef);
            void _SetMenu(const tide::ValueList&, tide::ValueRef);
            void _GetContextMenu(const tide::ValueList&, tide::ValueRef);
            void _SetContextMenu(const tide::ValueList&, tide::ValueRef);
            void _GetIcon(const tide::ValueList&, tide::ValueRef);
            void _SetIcon(const tide::ValueList&, tide::ValueRef);
            void _GetParent(const tide::ValueList&, tide::ValueRef);
            void _GetChildren(const tide::ValueList&, tide::ValueRef);
            void _CreateWindow(const tide::ValueList&, tide::ValueRef);
            void _OpenFileChooserDialog(const ValueList& args, ValueRef result);
            void _OpenFolderChooserDialog(const ValueList& args, ValueRef result);
            void _OpenSaveAsDialog(const ValueList& args, ValueRef result);
            void _IsTopMost(const tide::ValueList&, tide::ValueRef);
            void _SetTopMost(const tide::ValueList&, tide::ValueRef);
            virtual void _ShowInspector(const ValueList& args, ValueRef result);
            void _SetContents(const ValueList& args, ValueRef result);
            void SetContents(const std::string& content, const std::string& baseURL);
            void _SetPluginsEnabled(const ValueList& args, ValueRef result);
            virtual void OpenFileChooserDialog(TiMethodRef callback, bool multiple,
                std::string& title, std::string& path, std::string& defaultName,
                std::vector<std::string>& types, std::string& typesDescription) = 0;
            virtual void OpenFolderChooserDialog( TiMethodRef callback,
                bool multiple, std::string& title, std::string& path,
                std::string& defaultName) = 0;
            virtual void OpenSaveAsDialog(TiMethodRef callback, std::string& title,
                std::string& path, std::string& defaultName,
                std::vector<std::string>& types, std::string& typesDescription) = 0;
            void _SetDocumentEdited(const ValueList &args, ValueRef result);
            void _IsDocumentEdited(const ValueList &args, ValueRef result);

            // TODO: make these methods non-virtual
            virtual void Hide() = 0;
            virtual void Show() = 0;
            virtual void Minimize() = 0;
            virtual void Maximize() = 0;
            virtual void Unminimize() = 0;
            virtual void Unmaximize() = 0;
            virtual bool IsMaximized() = 0;
            virtual bool IsMinimized() = 0;
            virtual void Focus() = 0;
            virtual void Unfocus() = 0;
            virtual bool IsUsingChrome() = 0;
            virtual bool IsUsingScrollbars() = 0;
            virtual bool IsFullscreen() = 0;
            virtual void Open();
            virtual bool Close();
            void Closed();
            virtual double GetX() = 0;
            virtual void SetX(double x) = 0;
            virtual double GetY() = 0;
            virtual void SetY(double y) = 0;
            virtual void MoveTo(double x, double y) = 0;

            virtual double GetWidth() = 0;
            virtual void SetWidth(double width) = 0;
            virtual double GetMaxWidth() = 0;
            virtual void SetMaxWidth(double width) = 0;
            virtual double GetMinWidth() = 0;
            virtual void SetMinWidth(double width) = 0;
            virtual double GetHeight() = 0;
            virtual void SetHeight(double height) = 0;
            virtual double GetMaxHeight() = 0;
            virtual void SetMaxHeight(double height) = 0;
            virtual double GetMinHeight() = 0;
            virtual void SetMinHeight(double height) = 0;
            virtual void SetSize(double width, double height) = 0;
            virtual Bounds GetBounds();
            virtual Bounds GetBoundsImpl() = 0;
            void SetBounds(Bounds bounds);
            virtual void SetBoundsImpl(Bounds bounds) = 0;
            virtual std::string GetTitle() = 0;
            virtual void SetTitle(const std::string& title);
            virtual void SetTitleImpl(const std::string& title) = 0;
            virtual std::string GetURL() = 0;
            virtual void SetURL(std::string &url) = 0;
            virtual bool IsResizable() = 0;
            virtual void SetResizable(bool resizable);
            virtual void SetResizableImpl(bool resizable) = 0;
            virtual bool IsMaximizable() = 0;
            virtual void SetMaximizable(bool maximizable) = 0;
            virtual bool IsMinimizable() = 0;
            virtual void SetMinimizable(bool minimizable) = 0;
            virtual bool IsCloseable() = 0;
            virtual void SetCloseable(bool closeable) = 0;
            virtual bool IsVisible() = 0;
            virtual double GetTransparency() = 0;
            virtual void SetTransparency(double transparency) = 0;
            virtual void SetFullscreen(bool fullscreen) = 0;
            virtual void SetUsingChrome(bool chrome) = 0;
            virtual void SetMenu(AutoMenu menu) = 0;
            virtual AutoMenu GetMenu() = 0;
            virtual void SetContextMenu(AutoMenu menu) = 0;
            virtual AutoMenu GetContextMenu() = 0;
            virtual void SetIcon(std::string& iconPath) = 0;
            virtual std::string& GetIcon() = 0;
            virtual bool IsTopMost() = 0;
            virtual void SetTopMost(bool topmost) = 0;
            virtual void ShowInspector(bool console=false) = 0;
            virtual void AppIconChanged() {};
            virtual void AppMenuChanged() {};
            virtual void SetContentsImpl(const std::string& content,  const std::string& baseURL) = 0;
            virtual void SetPluginsEnabled(bool enabled) = 0;
            
            // OS X only
            virtual void SetDocumentEdited(bool edited) {}
            virtual bool IsDocumentEdited() { return false; }

        protected:
            Logger* logger;
            AutoUIBinding binding;
            TiObjectRef domWindow;
            Host* host;
            AutoPtr<WindowConfig> config;
            AutoUserWindow parent;
            std::vector<AutoUserWindow> children;
            bool active;
            bool initialized;
            std::string iconURL;

            UserWindow(AutoPtr<WindowConfig> config, AutoUserWindow parent);
            virtual AutoUserWindow GetParent();
            virtual void AddChild(AutoUserWindow);
            virtual void RemoveChild(AutoUserWindow);
            void ReadChooserDialogObject(TiObjectRef o, bool& multiple,
                std::string& title, std::string& path, std::string& defaultName,
                std::vector<std::string>& types, std::string& typesDescription);
            static void LoadUIJavaScript(JSGlobalContextRef context);

        private:
            DISALLOW_EVIL_CONSTRUCTORS(UserWindow);
    };
}
#endif
