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

#ifndef _WIN32_UI_MODULE_H_
#define _WiN32_UI_MODULE_H_

namespace ti
{
    class Win32Menu;
    class Win32MenuItem;
}

#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <shellapi.h>
#include <shlwapi.h>
#include <cderr.h>
#include <comutil.h>
#include <commdlg.h>
#include <commctrl.h>
#include <shlobj.h>
#include <winbase.h>
#define FormatMessage FormatMessageW
#include <comdef.h>

#undef IsMaximized
#undef IsMinimized

#include <WebKit/WebKit.h>
#include <WebKit/WebKitCOMAPI.h>

#include <WebKit/WebKitTitanium.h>

#include <cairo/cairo.h>
#include <cairo/cairo-win32.h>
#include "../url/url.h"
#include "popup_dialog.h"
#include "webkit_frame_load_delegate.h"
#include "webkit_policy_delegate.h"
#include "webkit_ui_delegate.h"
#include "webkit_resource_load_delegate.h"
#include "win32_user_window.h"
#include "win32_menu.h"
#include "win32_menu_item.h"
#include "win32_tray_item.h"
#include "win32_ui_binding.h"
#endif
