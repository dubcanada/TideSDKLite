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

#ifndef _KR_PROFILED_BOUND_OBJECT_H_
#define _KR_PROFILED_BOUND_OBJECT_H_
#include <Poco/FileStream.h>
#include <Poco/Mutex.h>

namespace tide
{
    /**
     * The ProfiledBoundObject is a wrapped KObject that does profiling on a 
     * wrapped KObject
     */
    class TIDE_API ProfiledBoundObject : public KObject
    {
        public:
        ProfiledBoundObject(KObjectRef delegate);
        virtual ~ProfiledBoundObject();
        static void SetStream(Poco::FileOutputStream*);

        public:
        // @see KObject::Set
        virtual void Set(const char *name, KValueRef value);
        // @see KObject::Get
        virtual KValueRef Get(const char *name);
        // @see KObject::GetPropertyNames
        virtual SharedStringList GetPropertyNames();
        // @see KObject::DisplayString
        virtual SharedString DisplayString(int levels=3);
        // @see KObject::Equals
        virtual bool Equals(KObjectRef other);

        bool HasProperty(const char* name);

        /**
         * @return the delegate of this profiled bound object
         */
        KObjectRef GetDelegate() { return delegate; }
        virtual void duplicate()
        {
            ++count;
        }

        virtual void release()
        {
            int value = --count;
            if (value <= 0) {
                delete this;
            }
        }

        virtual int referenceCount() const
        {
            return count.value();
        }

    protected:
        KObjectRef delegate;
        KValueRef Wrap(KValueRef value, std::string type);
        std::string GetSubType(std::string name);
        void Log(const char* eventType, std::string& name, Poco::Timestamp::TimeDiff);
        static bool AlreadyWrapped(KValueRef);
        static Poco::FileOutputStream *stream;
        static Poco::Mutex logMutex;
        Poco::AtomicCounter count;
    };
}

#endif
