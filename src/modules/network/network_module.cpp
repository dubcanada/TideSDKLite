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

#include <tideutils/file_utils.h>
using namespace TideUtils;

#include "network_module.h"
#include <Poco/Mutex.h>

using namespace tide;
using namespace ti;
namespace ti
{
    TIDE_MODULE(NetworkModule, STRING(MODULE_NAME), STRING(MODULE_VERSION));
    static std::string modulePath;
    static CURLSH* curlShareHandle = 0;

    static Poco::Mutex* SharedResourceMutex(curl_lock_data data)
    {
        static Poco::Mutex cookieMutex;
        static Poco::Mutex dnsMutex;
        static Poco::Mutex shareMutex;

        switch (data) {
            case CURL_LOCK_DATA_COOKIE:
                return &cookieMutex;
            case CURL_LOCK_DATA_DNS:
                return &dnsMutex;
            case CURL_LOCK_DATA_SHARE:
                return &shareMutex;
            default:
                return NULL;
        }
    }

    static void CurlLockCallback(CURL* handle, curl_lock_data data, curl_lock_access, void*)
    {
        if (Poco::Mutex* mutex = SharedResourceMutex(data))
            mutex->lock();
    }

    static void CurlUnlockCallback(CURL* handle, curl_lock_data data, void* userPtr)
    {
        if (Poco::Mutex* mutex = SharedResourceMutex(data))
            mutex->unlock();
    }

    void NetworkModule::Initialize()
    {
        curl_global_init(CURL_GLOBAL_ALL);

        modulePath = GetPath();

        this->networkBinding = new NetworkBinding(host);
        this->analyticsBinding = new AnalyticsBinding();
        GlobalObject::GetInstance()->SetObject("Network", this->networkBinding);
        GlobalObject::GetInstance()->SetObject("Analytics", this->analyticsBinding);

        curlShareHandle = curl_share_init();
        curl_share_setopt(curlShareHandle, CURLSHOPT_SHARE, CURL_LOCK_DATA_COOKIE);
        curl_share_setopt(curlShareHandle, CURLSHOPT_SHARE, CURL_LOCK_DATA_DNS);
        curl_share_setopt(curlShareHandle, CURLSHOPT_LOCKFUNC, CurlLockCallback);
        curl_share_setopt(curlShareHandle, CURLSHOPT_UNLOCKFUNC, CurlUnlockCallback);
    }

    void NetworkModule::Stop()
    {
        analyticsBinding->Shutdown();
    }

    /*static*/
    std::string& NetworkModule::GetRootCertPath()
    {
        static std::string path;
        if (path.empty())
        {
            SharedApplication app(Host::GetInstance()->GetApplication());
            path = FileUtils::Join(app->runtime->path.c_str(), "rootcert.pem", 0);
        }
        return path;
    }

    /*static*/
    CURLSH* NetworkModule::GetCurlShareHandle()
    {
        return curlShareHandle;
    }
}
