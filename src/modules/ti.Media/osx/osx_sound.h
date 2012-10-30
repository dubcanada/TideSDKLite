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

#ifndef _MEDIA_OSX_SOUND_H_
#define _MEDIA_OSX_SOUND_H_

#include <tide/tide.h>
#include <vector>
#include "../sound.h"
#import <Cocoa/Cocoa.h>

using namespace kroll;

namespace ti
{
    class OSXSound : public Sound
    {
        public:
        OSXSound(std::string& url);
        virtual ~OSXSound();
        virtual void LoadImpl();
        virtual void UnloadImpl();
        virtual void PlayImpl();
        virtual void PauseImpl();
        virtual void StopImpl();
        virtual void SetVolumeImpl(double volume);
        virtual double GetVolumeImpl();

        private:
        NSSound* sound;
        id delegate;
        NSURL* fileURL;
    };
}

#endif
