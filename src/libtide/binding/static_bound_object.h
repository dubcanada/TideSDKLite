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

#ifndef _STATIC_BOUND_OBJECT_H_
#define _STATIC_BOUND_OBJECT_H_

#include <vector>
#include <string>
#include <map>

#include <Poco/Mutex.h>

namespace tide
{
    /**
     * Extending this class is the easiest way to get started with your own
     * TiObject implementation. In your sub-class' constructor, you can bind
     * properties and methods, i.e:
     * \code
     * MyObject::MyObject() {
     *   this->Set("x", Value::NewInt(100));
     *   this->Set("description", Value::NewString("my object"));
     *   this->SetMethod("add", &MyObject::Add);
     * }
     *
     * void MyObject::Add(const ValueList& args, KValueRef result) {
     *   result->SetInt(args[0]->ToInt() + args[1]->ToInt());
     * }
     * \endcode
     *
     * And a supported language would access your object ala:
     * \code
     * var myObject = //..
     * alert(myObject.x); // 100
     * alert(myObject.description); // "my object"
     * alert(myObject.add(10, 15)); // 25
     * \endcode
     */
    class TIDE_API StaticBoundObject : public TiObject
    {
    public:
        StaticBoundObject(const char* type = "StaticBoundObject");
        virtual ~StaticBoundObject();

        virtual bool HasProperty(const char* name);
        virtual KValueRef Get(const char* name);
        virtual SharedStringList GetPropertyNames();
        virtual void Set(const char* name, KValueRef value);
        virtual void Unset(const char* name);

        /**
         * Set a property on this object to the given method. When an error
         * occurs will throw an exception of type ValueException.
         */
        template <typename T>
        void SetMethod(const char* name, void (T::*method)(const ValueList&, KValueRef))
        {
            this->Set(name, Value::NewMethod(new StaticBoundMethod(
                NewCallback<T, const ValueList&, KValueRef>(static_cast<T*>(this), method))));
        }


    protected:
        std::map<std::string, KValueRef> properties;
        Poco::Mutex mutex;

    private:
        DISALLOW_EVIL_CONSTRUCTORS(StaticBoundObject);
    };

}

#endif
