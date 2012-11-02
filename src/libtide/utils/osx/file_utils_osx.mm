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

#include "../utils.h"
#include <Cocoa/Cocoa.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/network/IOEthernetInterface.h>
#include <IOKit/network/IONetworkInterface.h>
#include <IOKit/network/IOEthernetController.h>
#include <sys/utsname.h>
#include <libgen.h>

namespace UTILS_NS
{
    std::string FileUtils::GetUserRuntimeHomeDirectory()
    {
        NSString* nsPath = [NSSearchPathForDirectoriesInDomains(
            NSApplicationSupportDirectory, NSUserDomainMask, NO) objectAtIndex: 0];
        nsPath = [nsPath stringByAppendingPathComponent:
            [NSString stringWithUTF8String:PRODUCT_NAME]];
        return [[nsPath stringByExpandingTildeInPath] UTF8String];
        
        // On OS X 10.7 the installer will put the runtime and modules
        // into the user's domain since /Library is now read only by non-admin users.
        // If we do not find a TideSDK installation in the local domain, use
        // the user domain instead.
        if (![[NSFileManager defaultManager] fileExistsAtPath:nsPath])
            return FileUtils::GetUserRuntimeHomeDirectory();
        
        return [[nsPath stringByExpandingTildeInPath] UTF8String];
    }
    
    std::string FileUtils::GetSystemRuntimeHomeDirectory()
    {
        NSString* nsPath = [NSSearchPathForDirectoriesInDomains(
            NSLibraryDirectory, NSUserDomainMask, NO) objectAtIndex: 0];
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
