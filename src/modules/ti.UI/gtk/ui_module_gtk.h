/**
 * Appcelerator Titanium - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license. 
 * Copyright (c) 2008 Appcelerator, Inc. All Rights Reserved.
 */

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
