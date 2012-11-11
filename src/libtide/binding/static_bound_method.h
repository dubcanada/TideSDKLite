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

#ifndef _STATIC_BOUND_METHOD_H_
#define _STATIC_BOUND_METHOD_H_

namespace tide
{

    class TIDE_API StaticBoundMethod : public KMethod
    {
    public:

        StaticBoundMethod(MethodCallback* callback, const char *type = "StaticBoundMethod");
        virtual ~StaticBoundMethod();

        /**
         * @see KMethod::Call
         */
        virtual KValueRef Call(const ValueList& args);

        /**
         * @see KObject::Set
         */
        virtual void Set(const char *name, KValueRef value);

        /**
         * @see KObject::Get
         */
        virtual KValueRef Get(const char *name);

        /**
         * @see KObject::GetPropertyNames
         */
        virtual SharedStringList GetPropertyNames();
        
        /**
         * Set a property on this object to the given method. When an error
         * occurs will throw an exception of type ValueException.
         */
        template <typename T>
        void SetMethod(const char *name, void (T::*method)(const ValueList&, KValueRef))
        {
            MethodCallback* callback = NewCallback<T, const ValueList&, KValueRef>(static_cast<T*>(this), method);

            KMethodRef bound_method = new StaticBoundMethod(callback);
            KValueRef method_value = Value::NewMethod(bound_method);
            this->Set(name, method_value);
        }

        template <typename T>
        static AutoPtr<StaticBoundMethod> FromMethod(T* owner, void (T::*method)(const ValueList&, KValueRef))
        {
            MethodCallback* callback = NewCallback<T, const ValueList&, KValueRef>(static_cast<T*>(owner), method);
            return new StaticBoundMethod(callback);
        }

    protected:
        SharedPtr<MethodCallback> callback;
        AutoPtr<StaticBoundObject> object;
        std::map<std::string, KValueRef > properties;

    private:
        DISALLOW_EVIL_CONSTRUCTORS(StaticBoundMethod);
    };
}

#endif
