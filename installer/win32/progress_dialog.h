/**
* This file has been modified from its orginal sources.
*
* (c) 2012 Software in the Public Interest Inc (SPI)
* (c) 2012 David Pratt
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
* (c) 2008-2012 Appcelerator Inc.
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

#include <windows.h>
#include <shlobj.h>
#include <shlguid.h>
#include <string>

class ProgressDialog
{
public:
    ProgressDialog();
    ~ProgressDialog();

    void SetTitle(const std::wstring& title);
    void SetCancelMessage(const std::wstring& message);
    void SetLineText(DWORD line, const std::wstring& message, bool compact);
    void Update(DWORD value, DWORD max);
    void Show();
    void Hide();
    bool IsCancelled();
    HWND GetWindowHandle() { return this->dialogWindow; }

private:
    IProgressDialog* dialog;
    HWND dialogWindow;
};
