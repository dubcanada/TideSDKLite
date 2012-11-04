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

#import "sound_delegate.h"
#import "osx_sound.h"

@implementation SoundDelegate

-(void)setOSXSound:(OSXSound*)newSound
{
    sound = newSound;
}

-(void)dealloc
{
    sound = nil;
    [super dealloc];
}

-(void)completed:(id) unused
{
    if (sound)
        sound->SoundCompletedIteration();
}

-(void)sound:(NSSound*)s didFinishPlaying:(BOOL)finished
{
    if (finished)
    {
        [self performSelectorOnMainThread:@selector(completed:)
            withObject:nil waitUntilDone:NO];
    }
}

@end