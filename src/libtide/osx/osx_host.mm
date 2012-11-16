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

#import <iostream>
#import <vector>
#import <dlfcn.h>
#import <string>
#import <signal.h>
#import <Cocoa/Cocoa.h>
#import <openssl/crypto.h>
#import <Poco/Mutex.h>

#define MAIN_THREAD_JOB_EVENT_SUBTYPE 6666

@interface TideMainThreadCaller : NSObject
{
}
- (void)signalMainThreadJob;
@end
@implementation TideMainThreadCaller
- (void)signalMainThreadJob
{
    Host::GetInstance()->RunMainThreadJobs();
}
@end

namespace tide
{
    static NSThread* mainThread;
    static Poco::Mutex* cryptoMutexes = 0;
    static TideMainThreadCaller* mainThreadCaller = 0;

    static void CryptoLockingCallback(int mode, int n, const char* file, int line)
    {
        if (mode & CRYPTO_LOCK)
            cryptoMutexes[n].lock();
        else
            cryptoMutexes[n].unlock();
    }

    static unsigned long CryptoThreadIdCallback(void)
    {
        return ((unsigned long) pthread_self());
    }

    void Host::Initialize(int argc, const char **argv)
    {
        if (!cryptoMutexes)
        {
            cryptoMutexes = new Poco::Mutex[CRYPTO_num_locks()];
            CRYPTO_set_id_callback(CryptoThreadIdCallback);
            CRYPTO_set_locking_callback(CryptoLockingCallback);
        }

        if (!mainThreadCaller)
            mainThreadCaller = [[TideMainThreadCaller alloc] init];

        mainThread = [NSThread currentThread];
    }

    Host::~Host()
    {
        if (!cryptoMutexes)
            return;

        delete [] cryptoMutexes;
        cryptoMutexes = 0;
    }

    void Host::WaitForDebugger()
    {
        printf("Waiting for debugger (Press Any Key to Continue pid=%i)...\n", getpid());
        getchar();
    }

    bool Host::IsMainThread()
    {
        return [NSThread currentThread] == mainThread;
    }

    bool Host::RunLoop()
    {
        NSApplication* application = [NSApplication sharedApplication];

        string origPath(EnvironmentUtils::Get("KR_ORIG_DYLD_FRAMEWORK_PATH"));
        EnvironmentUtils::Set("DYLD_FRAMEWORK_PATH", origPath);
        origPath = EnvironmentUtils::Get("KR_ORIG_DYLD_LIBRARY_PATH");
        EnvironmentUtils::Set("DYLD_LIBRARY_PATH", origPath);

        [application run];
        return false;
    }

    void Host::SignalNewMainThreadJob()
    {
        [mainThreadCaller
            performSelectorOnMainThread:@selector(signalMainThreadJob)
            withObject:nil
            waitUntilDone:false];
    }

    void Host::ExitImpl(int exitcode)
    {
        // Stop the event loop, but don't terinate the application.
        // The host still needs to clean up everything.
        [[NSApplication sharedApplication] stop:nil];

        // NSApplication stop: doesn't stop the main loop until an event
        // has been processed, so push an application specific event through.
        [[NSApplication sharedApplication] postEvent:[NSEvent
            otherEventWithType:NSApplicationDefined
            location:NSZeroPoint
            modifierFlags:0
            timestamp:[[NSDate date] timeIntervalSinceNow]
            windowNumber:0
            context:nil
            subtype:MAIN_THREAD_JOB_EVENT_SUBTYPE
            data1:0
            data2:0]
            atStart:YES];
    }

    Module* Host::CreateModule(std::string& path)
    {
        void* handle = dlopen(path.c_str(), RTLD_LAZY | RTLD_GLOBAL);
        if (!handle)
        {
            throw ValueException::FromFormat("Error loading module (%s): %s\n",
                path.c_str(), dlerror());
        }

        // Get the module factory symbol.
        ModuleCreator* create = (ModuleCreator*) dlsym(handle, "CreateModule");
        if (!create)
        {
            throw ValueException::FromFormat("Cannot load CreateModule symbol from module "
                "(%s): %s\n", path.c_str(), dlerror());
        }

        std::string dir(FileUtils::GetDirectory(path));
        return create(this, dir.c_str());
    }
}
