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

#include "notification.h"

namespace ti
{

Notification::Notification() : KAccessorObject("Notification"),
    timeout(-1)
{
    SetMethod("setTitle", &Notification::_SetTitle);
    SetMethod("setMessage", &Notification::_SetMessage);
    SetMethod("setIcon", &Notification::_SetIcon);
    SetMethod("setTimeout", &Notification::_SetTimeout);
    SetMethod("setDelay", &Notification::_SetTimeout);
    SetMethod("show", &Notification::_Show);
    SetMethod("hide", &Notification::_Hide);

    SetBool("nativeNotifications", Notification::InitializeImpl());
    this->CreateImpl();
}

Notification::~Notification()
{
    this->DestroyImpl();
}

void Notification::_SetTitle(const ValueList& args, KValueRef result)
{
    args.VerifyException("setTitle", "s");
    this->title = args.GetString(0);
}

void Notification::_SetMessage(const ValueList& args, KValueRef result)
{
    args.VerifyException("setMessage", "s");
    this->message = args.GetString(0);
}

void Notification::_SetIcon(const ValueList& args, KValueRef result)
{
    args.VerifyException("setIcon", "s");
    this->iconURL = args.GetString(0);
}

void Notification::_SetTimeout(const ValueList& args, KValueRef result)
{
    args.VerifyException("setTimeout", "i");
    this->timeout = args.GetInt(0);
}

void Notification::_Show(const ValueList& args, KValueRef result)
{
    result->SetBool(this->ShowImpl());
}

void Notification::_Hide(const ValueList& args, KValueRef result)
{
    result->SetBool(this->HideImpl());
}

void Notification::Configure(KObjectRef properties)
{
    this->title = properties->GetString("title");
    this->message = properties->GetString("message");
    this->iconURL = properties->GetString("icon");
    this->timeout = properties->GetInt("timeout", -1);
}

}
