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

#include <tide/utils/utils.h>
#include "progress_dialog.h"

using std::string;
using std::wstring;

ProgressDialog::ProgressDialog() :
    dialogWindow(0)
{
    HRESULT hr = CoCreateInstance(
        CLSID_ProgressDialog,
        0,
        CLSCTX_INPROC_SERVER,
        IID_IProgressDialog, (void**) &dialog );
}

ProgressDialog::~ProgressDialog()
{
    dialog->Release();
    CoUninitialize();
}

void ProgressDialog::SetCancelMessage(const std::wstring& message)
{
    dialog->SetCancelMsg(message.c_str(), 0);
}

void ProgressDialog::SetTitle(const std::wstring& title)
{
    dialog->SetTitle(title.c_str());
}

void ProgressDialog::SetLineText(DWORD line, const std::wstring& message, bool compact)
{
    dialog->SetLine(line, message.c_str(), compact, 0);
}

void ProgressDialog::Update(DWORD value, DWORD max)
{
    dialog->SetProgress(value, max);
}

bool ProgressDialog::IsCancelled()
{
    return dialog->HasUserCancelled()==TRUE;
}

void ProgressDialog::Show()
{
    DWORD flags = PROGDLG_NORMAL | PROGDLG_NOMINIMIZE;
    HRESULT hr = dialog->StartProgressDialog(GetDesktopWindow(), 0, flags, 0);
    if (!SUCCEEDED(hr))
        return;

    dialog->Timer(PDTIMER_RESET, 0);
    IOleWindow* pIWnd = 0;
    if (dialog->QueryInterface(IID_IOleWindow, (void**)&pIWnd) != S_OK)
        return;

    HWND windowHandle;
    if (pIWnd->GetWindow(&windowHandle) != S_OK)
    {
        pIWnd->Release();
        return;
    }

    // Get the center of the screen.
    this->dialogWindow = windowHandle;
    HDC hScreenDC = CreateCompatibleDC(0);
    int screenWidth = GetDeviceCaps(hScreenDC, HORZRES);
    int screenHeight = GetDeviceCaps(hScreenDC, VERTRES);
    DeleteDC(hScreenDC);

    // Get the dialog size.
    RECT dialogRect;
    GetWindowRect(dialogWindow, &dialogRect);

    // Calculate center position for the dialog and reposition it.
    int centerX = ( screenWidth - (dialogRect.right - dialogRect.left)) / 2;
    int centerY = ( screenHeight - (dialogRect.bottom - dialogRect.top)) / 2;
    SetWindowPos(this->dialogWindow, 0, centerX, centerY-20, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void ProgressDialog::Hide()
{
    dialog->StopProgressDialog();
}

