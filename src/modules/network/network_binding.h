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

#ifndef _NETWORK_BINDING_H_
#define _NETWORK_BINDING_H_

#include <tide/tide.h>

namespace ti
{
    class NetworkBinding;
    class HostBinding;
}

namespace ti
{
    class NetworkBinding : public AccessorObject
    {
    public:
        NetworkBinding(Host*);
        virtual ~NetworkBinding();

        Host* GetHost();
        static const std::string& GetFirstIPAddress();

    private:
        Host* host;
        KObjectRef global;

        AutoPtr<HostBinding> GetHostBinding(std::string host);

        void _GetFirstMACAddress(const ValueList& args, KValueRef result);
        void _GetFirstIPAddress(const ValueList& args, KValueRef result);
        void _GetInterfaces(const ValueList& args, KValueRef result);
        void _CreateIPAddress(const ValueList& args, KValueRef result);
        void _CreateTCPSocket(const ValueList& args, KValueRef result);
        void _CreateTCPServerSocket(const ValueList& args, KValueRef result);
        void _CreateIRCClient(const ValueList& args, KValueRef result);
        void _CreateHTTPClient(const ValueList& args, KValueRef result);
        void _CreateHTTPServer(const ValueList& args, KValueRef result);
        void _CreateHTTPCookie(const ValueList& args, KValueRef result);
        void _EncodeURIComponent(const ValueList &args, KValueRef result);
        void _DecodeURIComponent(const ValueList &args, KValueRef result);
        void _GetHostByName(const ValueList& args, KValueRef result);
        void _GetHostByAddress(const ValueList& args, KValueRef result);
        void _SetHTTPProxy(const ValueList& args, KValueRef result);
        void _SetHTTPSProxy(const ValueList& args, KValueRef result);
        void _GetHTTPProxy(const ValueList& args, KValueRef result);
        void _GetHTTPSProxy(const ValueList& args, KValueRef result);
    };
}

#endif
