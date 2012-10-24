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

#ifndef _HOST_EVENT_WINDOW_H
#define _HOST_EVENT_WINDOW_H

#include <vector>
#include <Poco/Mutex.h>

typedef bool (*MessageHandler)(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam);

namespace kroll
{
    class Logger;
    class EventWindow
    {
    public:
        EventWindow();
        virtual ~EventWindow();
        void DestroyWindow();
        HWND AddMessageHandler(MessageHandler handler);
        LRESULT CALLBACK Handler(
            HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam);
        HWND GetHandle() { return handle; }
        
    private:
        HWND handle;
        Logger* logger;
        std::vector<MessageHandler> handlers;
        Poco::Mutex handlersMutex;
    };
}

#endif