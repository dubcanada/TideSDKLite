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

#ifndef _KR_PROXY_CONFIG_H_
#define _KR_PROXY_CONFIG_H_
namespace tide
{
    class KROLL_API BypassEntry
    {
    public:
        BypassEntry() : port(0) {}
        std::string scheme;
        std::string host;
        unsigned short port;
    };

    enum ProxyType { HTTP, HTTPS, FTP, SOCKS };
    class KROLL_API Proxy
    {
    public:
        ProxyType type;
        std::string host;
        unsigned port;
        std::string username;
        std::string password;
        std::string ToString();
        static ProxyType SchemeToProxyType(std::string);
    };

    namespace ProxyConfig
    {
        KROLL_API void SetHTTPProxyOverride(SharedProxy);
        KROLL_API void SetHTTPSProxyOverride(SharedProxy);
        KROLL_API SharedProxy GetHTTPProxyOverride();
        KROLL_API SharedProxy GetHTTPSProxyOverride();
        KROLL_API SharedProxy GetProxyForURL(std::string& url);
        KROLL_API SharedProxy ParseProxyEntry(std::string proxyEntry,
            const std::string& urlScheme, const std::string& entryScheme);

        SharedProxy GetProxyForURLImpl(Poco::URI& uri);
        bool ShouldBypass(Poco::URI& uri,
            std::vector<SharedPtr<BypassEntry> >& bypassList);
        SharedPtr<BypassEntry> ParseBypassEntry(std::string entry);
        void ParseProxyList(std::string proxyListString,
            std::vector<SharedProxy>& proxyList, const std::string& scheme="");
        Logger* GetLogger();
    };
}

#endif
