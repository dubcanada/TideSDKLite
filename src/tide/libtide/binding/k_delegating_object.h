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

#ifndef _KR_K_DELEGATING_OBJECT_H_
#define _KR_K_DELEGATING_OBJECT_H_

#include <vector>
#include <string>
#include <map>

#include <Poco/Mutex.h>

namespace kroll
{
    /**
     * The KDelegatingObject lets you wrap a globally accessible
     * object in such a way as it appears to have special properties in
     * in local contexts. When a Get(...) occurs, the object searches a local
     * delegate and then a global one. When a Set(...) occurs, the object
     * performs it on both the local and the global version. Thus this object
     * is most useful if the local properties are assigned to the local object
     * in an initial setup phase.
     */
    class KROLL_API KDelegatingObject : public KObject
    {
        public:
        KDelegatingObject(KObjectRef global);
        KDelegatingObject(KObjectRef global, KObjectRef local);
        virtual ~KDelegatingObject();
        virtual KValueRef Get(const char *name);
        virtual SharedStringList GetPropertyNames();
        virtual void Set(const char *name, KValueRef value);
        virtual bool HasProperty(const char* name);

        virtual inline KObjectRef GetGlobal() { return this->global; }
        virtual inline KObjectRef GetLocal() { return this->local; }

        private:
        /**
         * The global part of this delegate object. This object
         * is used to find properties if they are not found in
         * the local object.
         */
        KObjectRef global;

        /**
         * The local part of this delegate object. This object
         * is the first in line for property retrieval. 
         */
        KObjectRef local;

        DISALLOW_EVIL_CONSTRUCTORS(KDelegatingObject);

    protected:
        Poco::Mutex mutex;
    };
}

#endif