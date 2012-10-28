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

#include "../kroll.h"
#include "net.h"
#include <libproxy/proxy.h>
using std::string;
using std::wstring;
using std::vector;
using Poco::URI;
using Poco::StringTokenizer;

namespace kroll
{
    static pxProxyFactory* GetProxyFactory()
    {
        // TODO: We should free this on exit.
        static pxProxyFactory* factory = NULL;
        if (!factory)
        {
            factory = px_proxy_factory_new();
        }
        return factory;
    }

    namespace ProxyConfig
    {
        SharedPtr<Proxy> GetProxyForURLImpl(Poco::URI& uri)
        {
            std::string url(uri.toString());
            char* urlC = strdup(url.c_str());
            char** proxies = px_proxy_factory_get_proxies(GetProxyFactory(), urlC);
            free(urlC);

            // TODO(mrobinson): Instead of just returning the first applicable proxy, this
            // should return a list of them.
            const char* proxyChars = proxies[0];
            if (!proxyChars)
                return 0;

            // Do not pass in an entryScheme here (third argument), because it will
            // override the host scheme, which is the most important in this case.
            SharedProxy proxy(ProxyConfig::ParseProxyEntry(
                proxyChars, uri.getScheme(), string()));

            for (int i = 0; proxies[i]; i++)
                free(proxies[i]);
            free(proxies);

            return proxy;
        }
    }
}