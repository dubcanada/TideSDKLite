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

#include <tideutils/platform_utils.h>
#include <tideutils/osx/osx_utils.h>

#include <Foundation/Foundation.h>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/network/IOEthernetInterface.h>
#include <IOKit/network/IONetworkInterface.h>
#include <IOKit/network/IOEthernetController.h>

namespace TideUtils
{
    void PlatformUtils::GetFirstMACAddressImpl(MACAddress& address)
    {
        CFMutableDictionaryRef matcher = IOServiceMatching(kIOEthernetInterfaceClass);
        if (!matcher)
            return;

        // Create a dictionary to match only the primary network interface.
        CFRef<CFMutableDictionaryRef> propertyMatcher(
            CFDictionaryCreateMutable(kCFAllocatorDefault, 0,
            &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks));
        if (!propertyMatcher.get())
            return;
        CFDictionarySetValue(matcher, CFSTR(kIOPropertyMatchKey), propertyMatcher);

        io_iterator_t serviceIterator;
        if (IOServiceGetMatchingServices(kIOMasterPortDefault, matcher, &serviceIterator) != KERN_SUCCESS)
            return;

        // Grab the first result, which should be the primary interface.
        io_object_t service = IOIteratorNext(serviceIterator);
        if (!service)
            return;

        // Grab the parent of the first result, which should be the actual IONetworkController.
        io_object_t controller;
        if (IORegistryEntryGetParentEntry(service, kIOServicePlane, &controller) != KERN_SUCCESS)
            return;

        CFDataRef addressData = (CFDataRef) IORegistryEntryCreateCFProperty(
            controller, CFSTR(kIOMACAddress), kCFAllocatorDefault, 0);
        if (!addressData)
        {
            IOObjectRelease(controller);
            IOObjectRelease(service);
            return;
        }

        UInt8 addressInts[kIOEthernetAddressSize];
        bzero(addressInts, sizeof(addressInts));

        CFDataGetBytes(addressData, CFRangeMake(0, MAC_ADDRESS_SIZE), addressInts);
        CFRelease(addressData);

        for (size_t i = 0; i < kIOEthernetAddressSize && i < MAC_ADDRESS_SIZE; i++)
            address[i] = addressInts[i];

        IOObjectRelease(controller);
        IOObjectRelease(service);
    }

    std::string PlatformUtils::GetUsername()
    {
        return std::string([NSUserName() UTF8String]);
    }

    int PlatformUtils::GetProcessorCount()
    {
        if (![NSProcessInfo instancesRespondToSelector:@selector(processorCount)])
            return 1; // Shucks!
    
        return [[NSProcessInfo processInfo] processorCount];
    }
}
