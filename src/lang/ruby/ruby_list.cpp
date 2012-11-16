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

#include "ruby_module.h"
#include <cstring>

namespace tide
{
    KRubyList::KRubyList(VALUE list) :
        TiList("Ruby.KRubyList"),
        list(list),
        object(new KRubyObject(list))
    {
        rb_gc_register_address(&list);
    }

    KRubyList::~KRubyList()
    {
        rb_gc_unregister_address(&list);
    }

    void KRubyList::Append(KValueRef value)
    {
        rb_ary_push(list, RubyUtils::ToRubyValue(value));
    }

    unsigned int KRubyList::Size()
    {
        return (unsigned int) RARRAY_LEN(list);
    }

    bool KRubyList::Remove(unsigned int index)
    {
        return (rb_ary_delete_at(list, index) != Qnil);
    }

    KValueRef KRubyList::At(unsigned int index)
    {
        if (index >= 0 && index < this->Size())
        {
            return RubyUtils::ToTiValue(rb_ary_entry(list, index));
        }
        else
        {
            return Value::Undefined;
        }
    }

    void KRubyList::Set(const char* name, KValueRef value)
    {
        if (TiList::IsInt(name))
        {
            this->SetAt(TiList::ToIndex(name), value);
        }
        else
        {
            this->object->Set(name, value);
        }
    }

    void KRubyList::SetAt(unsigned int index, KValueRef value)
    {
        VALUE rv = RubyUtils::ToRubyValue(value);

        // rb_ary_store will take care of sizing the list
        // appropriately in the case that index > current list size
        rb_ary_store(list, index, rv);
    }

    KValueRef KRubyList::Get(const char* name)
    {
        if (TiList::IsInt(name))
        {
            return this->At(TiList::ToIndex(name));
        }
        else
        {
            return object->Get(name);
        }
    }

    SharedStringList KRubyList::GetPropertyNames()
    {
        SharedStringList property_names = object->GetPropertyNames();
        for (size_t i = 0; i < this->Size(); i++)
        {
            std::string name = TiList::IntToChars(i);
            property_names->push_back(new std::string(name));
        }

        return property_names;
    }

    VALUE KRubyList::ToRuby()
    {
        return this->object->ToRuby();
    }

    SharedString KRubyList::DisplayString(int levels)
    {
        return this->object->DisplayString(levels);
    }

    bool KRubyList::Equals(TiObjectRef other)
    {
        AutoPtr<KRubyList> listOther = other.cast<KRubyList>();
        if (listOther.isNull())
            return false;
        return listOther->ToRuby() == this->ToRuby();
    }
}
