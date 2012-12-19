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

#include <tideutils/file_utils.h>
#include <Cocoa/Cocoa.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/network/IOEthernetInterface.h>
#include <IOKit/network/IONetworkInterface.h>
#include <IOKit/network/IOEthernetController.h>
#include <sys/utsname.h>
#include <libgen.h>

namespace TideUtils
{
    std::string FileUtils::GetUserRuntimeHomeDirectory()
    {
        // As of Mac 10.7 /Library/ is no longer writable by anyone but root
        // We are going to install it into ~/Library/
        NSString* nsPath = [NSSearchPathForDirectoriesInDomains(
            NSApplicationSupportDirectory, NSUserDomainMask, YES) objectAtIndex: 0];
        nsPath = [nsPath stringByAppendingPathComponent:
            [NSString stringWithUTF8String:PRODUCT_NAME]];
        return [[nsPath stringByExpandingTildeInPath] UTF8String];
    }
    
    std::string FileUtils::GetSystemRuntimeHomeDirectory()
    {
        NSString* nsPath = [NSSearchPathForDirectoriesInDomains(
            NSApplicationSupportDirectory, NSUserDomainMask, NO) objectAtIndex: 0];
        nsPath = [nsPath stringByAppendingPathComponent:
                  [NSString stringWithUTF8String:PRODUCT_NAME]];
        return [[nsPath stringByExpandingTildeInPath] UTF8String];
    }

    std::string FileUtils::ReadFile(const std::string& path)
    {
        NSError* error = NULL;
        NSString* nsPath = [NSString stringWithUTF8String:path.c_str()];
        NSString* nsContents = [NSString stringWithContentsOfFile:nsPath
            encoding:NSUTF8StringEncoding error:&error];

        if (error)
        {
            fprintf(stderr, "Could not read file: %s: %s\n",
                path.c_str(), [[error localizedDescription] UTF8String]);
            return "";
        }

        return [nsContents UTF8String];
    }

    void FileUtils::WriteFile(const std::string& path, const std::string& content)
    {
        NSError* error = NULL;
        NSString* nsContents = [NSString stringWithUTF8String:content.c_str()];
        NSString* nsPath = [NSString stringWithUTF8String:path.c_str()];
        [nsContents writeToFile:nsPath
            atomically:YES encoding:NSUTF8StringEncoding error:&error];

        if (error)
        {
            fprintf(stderr, "Could not write file: %s: %s\n",
                path.c_str(), [[error localizedDescription] UTF8String]);
        }
    }
}
