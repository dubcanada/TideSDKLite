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

#include "../notification.h"
#include "SnarlInterface.h"

namespace ti
{

/*static*/
bool Notification::InitializeImpl()
{
    Snarl::SnarlInterface snarlInterface;
    WORD major, minor;
    return snarlInterface.GetVersion(&major, &minor);
}

/*static*/
void Notification::ShutdownImpl()
{
}

static UINT snarlWindowMessage = ::RegisterWindowMessageA("TitaniumSnarlMessage");
static bool MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (message != snarlWindowMessage)
        return false;
        
    return true;
}

void Notification::CreateImpl()
{
    this->notification = -1;
}

void Notification::DestroyImpl()
{
}

bool Notification::ShowImpl()
{
    Snarl::SnarlInterface snarlInterface;

    std::string iconPath;
    if (!iconURL.empty())
        iconPath = URLUtils::URLToPath(iconURL);

    HWND replyWindow = Host::GetInstance()->AddMessageHandler(&MessageHandler);
    long id = snarlInterface.ShowMessage(::UTF8ToWide(this->title).c_str(),
        ::UTF8ToWide(this->message).c_str(), this->timeout,
         ::UTF8ToWide(iconPath).c_str(), replyWindow, snarlWindowMessage);

    return true;
}

bool Notification::HideImpl()
{
    if (this->notification == -1)
        return true;

    Snarl::SnarlInterface snarlInterface;
    return snarlInterface.HideMessage(this->notification);
}
}