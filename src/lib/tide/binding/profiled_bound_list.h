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

#ifndef _PROFILED_BOUND_LIST_H_
#define _PROFILED_BOUND_LIST_H_

namespace tide
{
    /**
     * The ProfiledBoundList is a wrapped TiList that does profiling
     */
    class ProfiledBoundList : public ProfiledBoundObject, public TiList
    {
    public:
        ProfiledBoundList(TiListRef delegate);
        virtual ~ProfiledBoundList();

        // @see TiList::Append
        virtual void Append(ValueRef value);
        // @see TiList::Size
        virtual unsigned int Size();
        // @see TiList::At
        virtual ValueRef At(unsigned int index);
        // @see TiList::SetAt
        virtual void SetAt(unsigned int index, ValueRef value);
        // @see TiList::Remove
        virtual bool Remove(unsigned int index);
        // @See TiList::Set
        virtual void Set(const char *name, ValueRef value);
        // @see TiList::Get
        virtual ValueRef Get(const char *name);
        // @see TiList::GetPropertyNames
        virtual SharedStringList GetPropertyNames();

        bool HasProperty(const char* name);

        /**
         * @return the delegate of this profiled bound object
         */
        TiListRef GetDelegate() { return list; }
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
        TiListRef list;
        Poco::AtomicCounter count;

    };
}

#endif
