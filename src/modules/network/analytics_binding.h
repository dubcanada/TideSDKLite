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

#ifndef _ANALYTICS_BINDING_H_
#define _ANALYTICS_BINDING_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/Runnable.h>
#include <Poco/Mutex.h>
#include <Poco/Condition.h>
#include <curl/curl.h>
#include <queue>

namespace ti
{
    class AnalyticsBinding : public EventObject, public Poco::Runnable
    {
    public:
        AnalyticsBinding();
        ~AnalyticsBinding();
        void Shutdown();

    private:
        bool running;
        std::string url;
        std::string baseData;
        CURL* curlHandle;
        Poco::Thread thread;
        std::queue<std::string> events;
        Poco::Mutex eventsLock;
        TiMethodRef startCallback;

        void run();
        void SendEventToAPIServer(std::string& eventData);
        void _SendEvent(const ValueList& args, KValueRef result);
        void _StartAnalyticsThread(const ValueList &args, KValueRef result);
    };
}

#endif
