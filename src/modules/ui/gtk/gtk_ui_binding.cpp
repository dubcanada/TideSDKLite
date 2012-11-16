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

#include "../ui_module.h"
#include "../url/url.h"
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/scrnsaver.h>
#include <gdk/gdkx.h>
#include <Poco/Thread.h>
#include <libsoup/soup.h>
#include <libsoup/soup-gnome.h>

namespace ti
{
    GtkUIBinding::GtkUIBinding(Host *host) :
        UIBinding(host),
        menu(0),
        contextMenu(0),
        iconPath("")
    {
        // Prepare the custom URL handlers
        webkit_titanium_set_normalize_url_cb(NormalizeURLCallback);
        webkit_titanium_set_url_to_file_url_cb(URLToFileURLCallback);
        webkit_titanium_set_can_preprocess_cb(CanPreprocessURLCallback);
        webkit_titanium_set_preprocess_cb(PreprocessURLCallback);

        // Setup libsoup proxy support
        SoupSession* session = webkit_get_default_session();
        soup_session_add_feature_by_type(session, SOUP_TYPE_PROXY_RESOLVER_GNOME);

        std::string webInspectorPath(host->GetApplication()->runtime->path);
        webInspectorPath = FileUtils::Join(webInspectorPath.c_str(), "webinspector", NULL);
        webkit_titanium_set_inspector_url(webInspectorPath.c_str());

        //webkit_set_cache_model(WEBKIT_CACHE_MODEL_DOCUMENT_VIEWER);
    }

    AutoMenu GtkUIBinding::CreateMenu()
    {
        return new GtkMenu();
    }

    AutoMenuItem GtkUIBinding::CreateMenuItem()
    {
        return new GtkMenuItem(MenuItem::NORMAL);
    }

    AutoMenuItem GtkUIBinding::CreateSeparatorMenuItem()
    {
        return new GtkMenuItem(MenuItem::SEPARATOR);
    }

    AutoMenuItem GtkUIBinding::CreateCheckMenuItem()
    {
        return new GtkMenuItem(MenuItem::CHECK);
    }

    void GtkUIBinding::SetMenu(AutoMenu newMenu)
    {
        this->menu = newMenu.cast<GtkMenu>();
    }

    void GtkUIBinding::SetContextMenu(AutoMenu newMenu)
    {
        this->contextMenu = newMenu.cast<GtkMenu>();
    }

    void GtkUIBinding::SetIcon(std::string& iconPath)
    {
        this->iconPath = iconPath;
    }

    AutoTrayItem GtkUIBinding::AddTray(std::string& iconPath, TiMethodRef cb)
    {
        AutoTrayItem item = new GtkTrayItem(iconPath, cb);
        return item;
    }

    long GtkUIBinding::GetIdleTime()
    {
        Display *display = gdk_x11_get_default_xdisplay();
        if (display == NULL)
            return -1;
        int screen = gdk_x11_get_default_screen();

        XScreenSaverInfo *mit_info = XScreenSaverAllocInfo();
        XScreenSaverQueryInfo(display, RootWindow(display, screen), mit_info);
        long idle_time = mit_info->idle;
        XFree(mit_info);

        return idle_time;
    }

    AutoMenu GtkUIBinding::GetMenu()
    {
        return this->menu;
    }

    AutoMenu GtkUIBinding::GetContextMenu()
    {
        return this->contextMenu;
    }

    std::string& GtkUIBinding::GetIcon()
    {
        return this->iconPath;
    }

    /*static*/
    void GtkUIBinding::ErrorDialog(std::string msg)
    {
        GtkWidget* dialog = gtk_message_dialog_new(
            NULL,
            GTK_DIALOG_MODAL,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_OK,
            "%s",
            msg.c_str());
        gtk_dialog_run(GTK_DIALOG (dialog));
        gtk_widget_destroy(dialog);
        UIBinding::ErrorDialog(msg);
    }
}
