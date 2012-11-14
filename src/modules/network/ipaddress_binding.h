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

#ifndef _IPADDRESS_BINDING_H_
#define _IPADDRESS_BINDING_H_

#include <tide/tide.h>
#include <Poco/Net/IPAddress.h>
#include "Poco/Net/NetException.h"

using Poco::Net::IPAddress;
using Poco::Net::InvalidAddressException;

namespace ti
{
    class IPAddressBinding : public KAccessorObject
    {
    public:
        IPAddressBinding(std::string);
        IPAddressBinding(IPAddress);
        virtual ~IPAddressBinding();
        const bool IsInvalid() const { return invalid; }
        const IPAddress* GetAddress() const { return address; }


    private:
        bool invalid;
        SharedPtr<IPAddress> address;
        void Init();
        void ToString(const ValueList& args, KValueRef result);
        void IsInvalid(const ValueList& args, KValueRef result);
        void IsIPV4(const ValueList& args, KValueRef result);
        void IsIPV6(const ValueList& args, KValueRef result);
        void IsWildcard(const ValueList& args, KValueRef result);
        void IsBroadcast(const ValueList& args, KValueRef result);
        void IsLoopback(const ValueList& args, KValueRef result);
        void IsMulticast(const ValueList& args, KValueRef result);
        void IsUnicast(const ValueList& args, KValueRef result);
        void IsLinkLocal(const ValueList& args, KValueRef result);
        void IsSiteLocal(const ValueList& args, KValueRef result);
        void IsWellKnownMC(const ValueList& args, KValueRef result);
        void IsNodeLocalMC(const ValueList& args, KValueRef result);
        void IsLinkLocalMC(const ValueList& args, KValueRef result);
        void IsSiteLocalMC(const ValueList& args, KValueRef result);
        void IsOrgLocalMC(const ValueList& args, KValueRef result);
        void IsGlobalMC(const ValueList& args, KValueRef result);
    };
}

#endif