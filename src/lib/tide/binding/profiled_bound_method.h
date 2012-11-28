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

#ifndef _PROFILED_BOUND_METHOD_H_
#define _PROFILED_BOUND_METHOD_H_

namespace tide
{
    /**
     * The ProfiledBoundMethod is a wrapped TiMethod that does profiling
     */
    class ProfiledBoundMethod : public ProfiledBoundObject, public TiMethod
    {
    public:
        ProfiledBoundMethod(TiMethodRef delegate, std::string& parentType);
        virtual ~ProfiledBoundMethod();

        // @see TiMethod::Call
        virtual ValueRef Call(const ValueList& args);
        // @see TiMethod::Set
        virtual void Set(const char *name, ValueRef value);
        // @see TiMethod::Get
        virtual ValueRef Get(const char *name);
        // @see TiMethod::GetPropertyNames
        virtual SharedStringList GetPropertyNames();
        // @see TiObject::GetType
        virtual std::string& GetType();

        bool HasProperty(const char* name);

        /**
         * @return the delegate of this profiled bound method
         */
        TiMethodRef GetDelegate() { return method; }
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

    private:
        TiMethodRef method;
        std::string fullType;
        Poco::AtomicCounter count;

    };
}

#endif
