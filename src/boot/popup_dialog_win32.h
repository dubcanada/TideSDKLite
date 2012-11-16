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

#ifndef KRBOOT_POPUP_DIALOG_H_
#define KRBOOT_POPUP_DIALOG_H_

#include <windows.h>
#include <string>
#include <map>

#define MAX_INPUT_LENGTH 1024

namespace TideBoot {

    class Win32PopupDialog {
    
    public:
        Win32PopupDialog(HWND _windowHandle);
        virtual ~Win32PopupDialog();

        void SetShowInputText(bool flag) { this->showInputText = flag; }
        void SetTitle(std::string _title) { this->title = _title; }
        void SetMessage(std::string _message) { this->message = _message; }
        void SetInputText(std::string _inputText) { this->inputText = _inputText; }
        std::string GetInputText() { return this->inputText; }
        void SetShowCancelButton(bool flag) { this->showCancelButton = flag; }

        int Show();
    
    private:
        HWND windowHandle;

        bool showInputText;
        std::string title;
        std::string message;
        std::string inputText;
        bool showCancelButton;
        int result;

        BOOL ShowMessageBox(HWND hwnd);

        static std::map<DWORD, Win32PopupDialog*> popups;

        static void HandleOKClick(HWND hDlg);
        static INT_PTR CALLBACK CALLBACK Callback(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
    };

}

#endif /* TI_POPUP_DIALOG_H_ */
