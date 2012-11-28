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

#include "../tide.h"
#include <tideutils/win/win32_utils.h>

namespace tide
{

static const wchar_t* windowClassName = L"Tide Event Window";

LRESULT CALLBACK WindowProcedure(HWND hwnd, unsigned int message, WPARAM wParam,
     LPARAM lParam)
{
    EventWindow* window =
        reinterpret_cast<EventWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (window)
        return window->Handler(hwnd, message, wParam, lParam);
    else
        return DefWindowProc(hwnd, message, wParam, lParam);
}

static void InitializeWindowClass(HINSTANCE hInstance)
{
    static bool initialized = false;
    if (initialized)
        return;

    WNDCLASSW windowClassPrivate;
    ZeroMemory(&windowClassPrivate, sizeof(WNDCLASS)); 
    windowClassPrivate.lpfnWndProc = WindowProcedure;
    windowClassPrivate.hInstance = hInstance;
    windowClassPrivate.lpszClassName = windowClassName;
    ATOM result = ::RegisterClassW(&windowClassPrivate);

    if (!result)
    {
        std::string error("Could not register event window class: ");
        error.append(Win32Utils::QuickFormatMessage(GetLastError()));
        Logger::Get("EventWindow")->Critical(error);
        return;
    }

    initialized = true;
}

EventWindow::EventWindow() :
    handle(NULL),
    logger(Logger::Get("EventWindow"))
{
    HINSTANCE instanceHandle = GetModuleHandle(NULL);
    InitializeWindowClass(instanceHandle);

    this->handle = ::CreateWindowW(
        windowClassName,
        L"Tide Event Window Instance",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        0,
        0,
        instanceHandle,
        0);

    if (!this->handle)
    {
        std::string error("Could not create event window: ");
        error.append(Win32Utils::QuickFormatMessage(GetLastError()));
        logger->Critical(error);
    }

    SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
}

EventWindow::~EventWindow()
{
    this->DestroyWindow();
}

void EventWindow::DestroyWindow()
{
    if (this->handle)
    {
        BOOL result = ::DestroyWindow(this->handle);

        if (result == 0)
        {
            // Cannot uset the Logger here, because this happens after
            // logging has completely shut down.
            std::string error("Could not destroy event window: ");
            error.append(Win32Utils::QuickFormatMessage(GetLastError()));
            fprintf(stderr, error.c_str());
        }
        this->handle = NULL;
    }
}

HWND EventWindow::AddMessageHandler(MessageHandler handler)
{
    if (this->handle)
    {
        Poco::Mutex::ScopedLock lock(handlersMutex);
        for (int i = 0; i < handlers.size(); i++)
        {
            MessageHandler h = handlers[i];
            if (h == handler)
                return this->handle;
        }

        handlers.push_back(handler);
    }

    return this->handle;
}

LRESULT CALLBACK EventWindow::Handler(
    HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam)
{
    {
        Poco::Mutex::ScopedLock lock(handlersMutex);
        for (int i = 0; i < handlers.size(); i++)
        {
            MessageHandler h = handlers[i];
            if (h(hwnd, message, wParam, lParam))
                return 0;
        }
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}
}
