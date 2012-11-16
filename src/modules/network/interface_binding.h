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

#ifndef _INTERFACE_BINDING_H_
#define _INTERFACE_BINDING_H_

#include <tide/tide.h>
#include <Poco/Net/NetworkInterface.h>
#undef interface

namespace ti
{
    class InterfaceBinding : public AccessorObject
    {
    public:
        InterfaceBinding(Poco::Net::NetworkInterface&);
        virtual ~InterfaceBinding();

    private:
        Poco::Net::NetworkInterface interface;
        void _GetAddress(const ValueList& args, KValueRef result);
        void _GetIPAddress(const ValueList& args, KValueRef result);
        void _GetName(const ValueList& args, KValueRef result);
        void _GetDisplayName(const ValueList& args, KValueRef result);
        void _GetSubnetMask(const ValueList& args, KValueRef result);
        void _SupportsIPv4(const ValueList& args, KValueRef result);
        void _SupportsIPv6(const ValueList& args, KValueRef result);
    };
}

#endif
