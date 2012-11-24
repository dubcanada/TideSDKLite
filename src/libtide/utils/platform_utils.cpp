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

#include "utils.h"
#include <stdio.h>
#include <string.h>


namespace UTILS_NS
{
namespace PlatformUtils
{
    std::string GetFirstMACAddress()
    {
        MACAddress address;
        memset(&address, 0, sizeof(MACAddress));

        try
        {
            PlatformUtils::GetFirstMACAddressImpl(address);
        }
        catch(...)
        {
            // Just return zeros.
        }

        char result[18];
        sprintf(result, "%02x:%02x:%02x:%02x:%02x:%02x",
            address[0], address[1], address[2], address[3],
            address[4], address[5]);
        return std::string(result);
    }

    std::string GetMachineId()
    {
        static std::string machineID;
        if (machineID.empty())
        {
            machineID = DataUtils::HexMD5(GetFirstMACAddress());
        }
        return machineID;
    }
}
}
