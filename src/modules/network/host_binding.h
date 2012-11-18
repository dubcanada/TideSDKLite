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

#ifndef _HOST_BINDING_H_
#define _HOST_BINDING_H_

#include <tide/tide.h>
#include "Poco/Net/DNS.h"
#include "Poco/Net/HostEntry.h"
#include "Poco/Net/NetException.h"
#include "ipaddress_binding.h"

using Poco::Net::DNS;
using Poco::Net::IPAddress;
using Poco::Net::HostEntry;
using Poco::Net::InvalidAddressException;
using Poco::Net::HostNotFoundException;
using Poco::Net::ServiceNotFoundException;
using Poco::Net::NoAddressFoundException;

namespace ti
{
    class HostBinding : public StaticBoundObject
    {
    public:
        HostBinding(IPAddress);
        HostBinding(std::string);
        virtual ~HostBinding();
    protected:
        void Init();
    private:
        HostEntry host;
        std::string name;
        bool invalid;
        
    public:
        const bool IsInvalid() const { return invalid; }

    private:
        void ToString(const ValueList& args, ValueRef result);
        void IsInvalid(const ValueList& args, ValueRef result);
        void GetName(const ValueList& args, ValueRef result);
        void GetAliases(const ValueList& args, ValueRef result);
        void GetAddresses(const ValueList& args, ValueRef result);
    };
}

#endif
