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

#ifndef _API_BINDING_H_
#define _API_BINDING_H_

#include <tide/tide.h>
#include <map>
#include <vector>
#include <string>
#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>

namespace tide
{
    class APIBinding : public AccessorObject
    {
        public:
        APIBinding(Host* host);
        virtual ~APIBinding();

        void Log(int severity, KValueRef);
        static TiListRef ComponentVectorToTiList(
            vector<SharedComponent>&,
            KComponentType filter = UNKNOWN);
        static TiListRef DependencyVectorToTiList(
            std::vector<SharedDependency>&);
        static TiListRef ManifestToTiList(
            vector<pair<string, string> >&);

        private:
        Host* host;
        TiObjectRef global;
        Logger* logger;

        // Use a FastMutex to protect the installer, because we are
        // always trying to lock it in the same thread.
        Poco::FastMutex installerMutex;
        Poco::Thread* installerThread;
        Poco::RunnableAdapter<APIBinding>* installerThreadAdapter;
        vector<SharedDependency> installerDependencies;
        TiMethodRef installerCallback;

        void RunInstaller();

        void _Set(const ValueList& args, KValueRef result);
        void _Get(const ValueList& args, KValueRef result);
        void _AddEventListener(const ValueList& args, KValueRef result);
        void _RemoveEventListener(const ValueList& args, KValueRef result);
        void _FireEvent(const ValueList& args, KValueRef result);

        Logger::Level ValueToLevel(KValueRef v);
        void _SetLogLevel(const ValueList& args, KValueRef result);
        void _GetLogLevel(const ValueList& args, KValueRef result);
        void _RunOnMainThread(const ValueList& args, KValueRef result);
        void _RunOnMainThreadAsync(const ValueList& args, KValueRef result);

        void _Print(const ValueList& args, KValueRef result);
        void _Log(const ValueList& args, KValueRef result);
        void _LogTrace(const ValueList& args, KValueRef result);
        void _LogDebug(const ValueList& args, KValueRef result);
        void _LogInfo(const ValueList& args, KValueRef result);
        void _LogNotice(const ValueList& args, KValueRef result);
        void _LogWarn(const ValueList& args, KValueRef result);
        void _LogError(const ValueList& args, KValueRef result);
        void _LogCritical(const ValueList& args, KValueRef result);
        void _LogFatal(const ValueList& args, KValueRef result);

        void _GetInstalledComponentsImpl(KComponentType type, const ValueList& args, KValueRef result);
        void _GetApplication(const ValueList& args, KValueRef value);
        void _GetInstalledComponents(const ValueList& args, KValueRef value);
        void _GetInstalledModules(const ValueList& args, KValueRef value);
        void _GetInstalledSDKs(const ValueList& args, KValueRef value);
        void _GetInstalledMobileSDKs(const ValueList& args, KValueRef value);
        void _GetInstalledRuntimes(const ValueList& args, KValueRef value);
        void _GetComponentSearchPaths(const ValueList& args, KValueRef value);
        void _ReadApplicationManifest(const ValueList& args, KValueRef value);
        void _ComponentGUIDToComponentType(const ValueList& args, KValueRef value);
        void _GetEnvironment(const ValueList& args, KValueRef value);
        
        void _CreateDependency(const ValueList& args, KValueRef value);
        void _InstallDependencies(const ValueList& args, KValueRef value);

        void _CreateTiObject(const ValueList& args, KValueRef result);
        void _CreateTiMethod(const ValueList& args, KValueRef result);
        void _CreateTiList(const ValueList& args, KValueRef result);
        void _CreateBytes(const ValueList& args, KValueRef result);
    };

    /**
     * An wrapper for a TiObject which encapsulates another one for testing
     */
    class TiObjectWrapper : public TiObject
    {
    public:
        TiObjectWrapper(TiObjectRef object);
        void Set(const char *name, KValueRef value);
        KValueRef Get(const char *name);
        bool HasProperty(const char *name);
        SharedStringList GetPropertyNames();
        SharedString DisplayString(int levels);
        bool Equals(TiObjectRef other);

    private:
        TiObjectRef object;
    };

    /**
     * An wrapper for a TiMethod which encapsulates another one for testing
     */
    class TiMethodWrapper : public TiMethod
    {
    public:
        TiMethodWrapper(TiMethodRef method);
        KValueRef Call(const ValueList& args);
        void Set(const char *name, KValueRef value);
        KValueRef Get(const char *name);
        bool HasProperty(const char *name);
        SharedStringList GetPropertyNames();
        SharedString DisplayString(int levels);
        bool Equals(TiObjectRef other);

    private:
        TiMethodRef method;
    };

    /**
     * An wrapper for a TiList which encapsulates another one for testing
     */
    class TiListWrapper : public TiList
    {
    public:
        TiListWrapper(TiListRef list);
        void Append(KValueRef value);
        unsigned int Size();
        KValueRef At(unsigned int index);
        void SetAt(unsigned int index, KValueRef value);
        bool Remove(unsigned int index);
        void Set(const char *name, KValueRef value);
        KValueRef Get(const char *name);
        bool HasProperty(const char *name);
        SharedStringList GetPropertyNames();
        SharedString DisplayString(int levels=3);
        bool Equals(TiObjectRef other);
    private:
        TiListRef list;
    };
}
#endif
