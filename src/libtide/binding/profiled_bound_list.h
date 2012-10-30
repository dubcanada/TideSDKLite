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

#ifndef _KR_PROFILED_BOUND_LIST_H_
#define _KR_PROFILED_BOUND_LIST_H_

namespace tide
{
    /**
     * The ProfiledBoundList is a wrapped KList that does profiling
     */
    class ProfiledBoundList : public ProfiledBoundObject, public KList
    {
    public:
        ProfiledBoundList(KListRef delegate);
        virtual ~ProfiledBoundList();

        // @see KList::Append
        virtual void Append(KValueRef value);
        // @see KList::Size
        virtual unsigned int Size();
        // @see KList::At
        virtual KValueRef At(unsigned int index);
        // @see KList::SetAt
        virtual void SetAt(unsigned int index, KValueRef value);
        // @see KList::Remove
        virtual bool Remove(unsigned int index);
        // @See KList::Set
        virtual void Set(const char *name, KValueRef value);
        // @see KList::Get
        virtual KValueRef Get(const char *name);
        // @see KList::GetPropertyNames
        virtual SharedStringList GetPropertyNames();

        bool HasProperty(const char* name);

        /**
         * @return the delegate of this profiled bound object
         */
        KListRef GetDelegate() { return list; }
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
        KListRef list;
        Poco::AtomicCounter count;

    };
}

#endif
