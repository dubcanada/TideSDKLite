/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
* Copyright (c) 2012 Mital Vora
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
#include "growl_wrapper.h"
#include <tideutils/url_utils.h>
#include <tide/url_utils.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <string>

using namespace std;

namespace ti
{

static CFDataRef GetAppIcon(SharedApplication app)
{
    return (CFDataRef) [[[NSApplication sharedApplication]
        applicationIconImage] TIFFRepresentation];
}

/*static*/
bool Notification::InitializeImpl()
{
    return true;
}

void Notification::ShutdownImpl()
{
}

void Notification::CreateImpl()
{
}

void Notification::DestroyImpl()
{
}

bool Notification::ShowImpl()
{
    NSInteger priority  = 0;
    NSString *gTitle    = [NSString stringWithUTF8String:this->title.c_str()];
    NSString *gMessage  = [NSString stringWithUTF8String:this->message.c_str()];

    CFDataRef icon = 0;
    if (!this->iconURL.empty())
    {
        // Convert all app:// and ti:// URLs to paths and then
        // back to file:// URLs. If a path is passed in, it
        // will not be modified by URLToPath and thus won't
        // need to be converted back to a URL.
        string iconPath(URLUtils::URLToPath(iconURL));
        string myIconURL(URLUtils::PathToFileURL(iconPath));

        NSURL* iconNSURL = [NSURL URLWithString:
            [NSString stringWithUTF8String:myIconURL.c_str()]];
        icon = (CFDataRef) [NSData dataWithContentsOfURL:iconNSURL];
    }

    if (!icon)
        icon = GetAppIcon(Host::GetInstance()->GetApplication());

    // TODO: Add back in Click Context stuff when a Linux solution is found

    // Show the growl notification
    showGrowlMessage(priority,gTitle,gMessage,icon);

    return true;
}

bool Notification::HideImpl()
{
    return false;
}

}  // namespace ti
