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

#ifndef _METHOD_H_
#define _METHOD_H_
#include <cstdarg>

namespace tide
{
    typedef Callback2<const ValueList&, ValueRef>::Type MethodCallback;

    /**
     * An abstract representation of a method
     */
    class TIDE_API TiMethod : public TiObject
    {

    public:

        TiMethod(const char *type = "TiMethod") : TiObject(type) {}
        virtual ~TiMethod() {}

        /**
         * Call this method with the given arguments.
         * Errors will result in a thrown ValueException
         * @return the return value of this method
         */
        virtual ValueRef Call(const ValueList& args) = 0;

        /**
         * Call this method with the given 'this' object and arguments.
         * Errors will result in a thrown ValueException
         * @return the return value of this method
         */
        virtual ValueRef Call(TiObjectRef thisObject, const ValueList& args);

        /**
         * Set a property on this object to the given value
         * Errors will result in a thrown ValueException
         */
        virtual void Set(const char* name, ValueRef value) = 0;

        /**
         * @return the property with the given name or Value::Undefined
         * if the property is not found.
         * Errors will result in a thrown ValueException
         */
        virtual ValueRef Get(const char* name) = 0;

        /**
         * @return a list of this object's property names.
         */
        virtual SharedStringList GetPropertyNames() = 0;

        /**
         * @return a string representation of this object
         */
        SharedString DisplayString(int levels);

        /**
         * Return the unwrapped version of this object
         */
        static TiMethodRef Unwrap(TiMethodRef);

        /* Convenience methods below */
        ValueRef Call(ValueRef one);
        ValueRef Call(ValueRef one, ValueRef two);
        ValueRef Call(ValueRef one, ValueRef two, ValueRef three);
        ValueRef Call();
        ValueRef Call(const char* one);
        ValueRef Call(const char* one, ValueRef two);
        ValueRef Call(const char* one, ValueRef two, ValueRef three);
        ValueRef Call(const char* one, ValueRef two, ValueRef three,
            ValueRef four);

    private:
        DISALLOW_EVIL_CONSTRUCTORS(TiMethod);
    };
}

#endif
