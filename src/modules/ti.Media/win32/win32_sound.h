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

#ifndef _MEDIA_WIN32_SOUND_H_
#define _MEDIA_WIN32_SOUND_H_

#include <kroll/kroll.h>
#include <vector>
#include <dshow.h>
#include "../sound.h"

using namespace kroll;

namespace ti
{
    class Win32Sound : public Sound
    {
        public:
        Win32Sound(std::string& url);
        virtual ~Win32Sound();
        virtual void LoadImpl();
        virtual void UnloadImpl();
        virtual void PlayImpl();
        virtual void PauseImpl();
        virtual void StopImpl();
        virtual void SetVolumeImpl(double volume);
        virtual double GetVolumeImpl();

        static UINT graphNotifyMessage;
        bool GraphCallback(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
        static bool StaticGraphCallback(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

        private:
        std::wstring widePath;
        IGraphBuilder* graphBuilder;
        IMediaControl* mediaControl;
        IMediaEventEx* mediaEventEx;
        IMediaSeeking* mediaSeeking;
        IBasicAudio* basicAudio;
    };
}

#endif