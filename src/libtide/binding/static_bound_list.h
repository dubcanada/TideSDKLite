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

#ifndef _STATIC_BOUND_LIST_H_
#define _STATIC_BOUND_LIST_H_

namespace tide
{

    class TIDE_API StaticBoundList : public TiList
    {
    public:

        StaticBoundList(const char *type = "StaticBoundList");
        virtual ~StaticBoundList();
        static TiListRef FromStringVector(std::vector<std::string>&);

        /**
         * Append a value to this list
         * Errors will result in a thrown ValueException
         */
        virtual void Append(ValueRef value);

        /**
         * Get the length of this list.
         */
        virtual unsigned int Size();

        /**
         * @return the value at the given index.
         * Errors will result in a thrown ValueException
         */
        virtual ValueRef At(unsigned int index);

        /**
         * Set a property on this object to the given value
         * Errors will result in a thrown ValueException
         */
        virtual void Set(const char *name, ValueRef value);

        /**
         * Remove the list entry at the given index.
         * Errors will result in a thrown ValueException
         * @return true if found and removed, false otherwise
         */
        virtual bool Remove(unsigned int index);

        /**
         * Set the value at the given index. If the index is greater
         * than the current list length, the list will be lengenthed
         * by appending Value::Undefined;
         * Errors will result in a thrown ValueException
         */
        virtual void SetAt(unsigned int index, ValueRef value);

        /**
         * @return the property with the given name or Value::Undefined
         * if the property is not found.
         * Errors will result in a thrown ValueException
         */
        virtual ValueRef Get(const char *name);

        /**
         * @return a list of this object's property names.
         */
        virtual SharedStringList GetPropertyNames();

    protected:
        AutoPtr<StaticBoundObject> object;
        unsigned int length;

    private:
        DISALLOW_EVIL_CONSTRUCTORS(StaticBoundList);
    };
}

#endif
