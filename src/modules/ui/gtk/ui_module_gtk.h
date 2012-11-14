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

#ifndef _UI_MODULE_GTK_H_
#define _UI_MODULE_GTK_H_

#include <tide/tide.h>

using tide::Value;
using tide::KObject;
using tide::StaticBoundObject;
using tide::KMethod;
using tide::StaticBoundMethod;
using tide::KList;
using tide::StaticBoundList;

#include <gdk/gdk.h>
#include <gdk/gdkx.h>
#include <webkit/webkit.h>
#include <webkit/webkittitanium.h>

// X11 defines this again for some reason
#undef DisplayString

#include "gtk_menu.h"
#include "gtk_menu_item.h"
#include "gtk_user_window.h"
#include "gtk_tray_item.h"
#include "gtk_ui_binding.h"

#endif
