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

#ifndef _PLATFORM_UTILS_H_
#define _PLATFORM_UTILS_H_
#include <string>
#include "poco/KTypes.h"
#define MAC_ADDRESS_SIZE 6

namespace UTILS_NS
{
    typedef KPoco::KUInt8 MACAddress[MAC_ADDRESS_SIZE]; /// Ethernet address.

    namespace PlatformUtils
    {
        /*
         * Get the first MAC address of this computer
         * @returns the first MAC address in standard dotted format
         */
        TIDE_API std::string GetFirstMACAddress();

        /*
         * Get the first MAC address of this computer
         * @returns the first MAC address in standard dotted format
         */
        TIDE_API void GetFirstMACAddressImpl(MACAddress&);

        /**
         * Generate an ID for this machine based on it's MAC Address.
         */
        TIDE_API std::string GetMachineId();

        /**
         * Get the username of the current user.
         */
        TIDE_API std::string GetUsername();

        /**
         * Get the number of processors on this machine.
         */
        TIDE_API int GetProcessorCount();
    };
}
#endif
