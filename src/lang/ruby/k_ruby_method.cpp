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

namespace tide
{
    KRubyMethod::KRubyMethod(VALUE method) :
        KMethod("Ruby.KRubyMethod"),
        method(method),
        arg(Qnil),
        object(new KRubyObject(method)),
        name(strdup(""))
    {
        rb_gc_register_address(&method);
    }

    KRubyMethod::KRubyMethod(VALUE method, VALUE arg) :
        method(method),
        arg(arg),
        object(new KRubyObject(method)),
        name(strdup(""))
    {
        rb_gc_register_address(&method);
    }

    KRubyMethod::KRubyMethod(VALUE method, const char* name) :
        method(method),
        arg(Qnil),
        object(new KRubyObject(method)),
        name(strdup(name))
    {
        rb_gc_register_address(&method);
    }

    KRubyMethod::~KRubyMethod() {
        rb_gc_unregister_address(&method);
    }

    static int MethodArity(VALUE method)
    {
        static VALUE aritySymbol = rb_intern("arity");
        if (!rb_obj_respond_to(method, aritySymbol, 0))
            return 0;

        return NUM2INT(rb_apply(method, aritySymbol, rb_ary_new()));
    }

    static VALUE DoMethodCall(VALUE args)
    {
        VALUE method = rb_ary_shift(args);
        VALUE rargs = rb_ary_shift(args);
        return rb_apply(method, rb_intern("call"), rargs);
    }

    KValueRef KRubyMethod::Call(const ValueList& args)
    {
        // Bloody hell, Ruby will segfault if we try to pass a number
        // of args to a method that is greater than its arity
        int arity = MethodArity(this->method);
        VALUE ruby_args = rb_ary_new();

        if (this->arg != Qnil)
            rb_ary_push(ruby_args, this->arg);

        // A negative arity means that this method can take a
        // variable number of arguments, so pass all args
        if (arity < 0)
            arity = args.size();

        for (size_t i = 0; i < args.size() && (int) i < arity; i++)
            rb_ary_push(ruby_args, RubyUtils::ToRubyValue(args[i]));

        int error;
        VALUE do_call_args = rb_ary_new();
        rb_ary_push(do_call_args, this->method);
        rb_ary_push(do_call_args, ruby_args);
        VALUE result = rb_protect(DoMethodCall, do_call_args, &error);

        if (error != 0)
        {
            ValueException e = RubyUtils::GetException();
            SharedString ss = e.DisplayString();
            std::cout << "Error: " << *ss << std::endl;
            throw e;
        }

        return RubyUtils::ToTiValue(result);
    }

    void KRubyMethod::Set(const char *name, KValueRef value)
    {
        object->Set(name, value);
    }

    KValueRef KRubyMethod::Get(const char *name)
    {
        return object->Get(name);
    }

    SharedStringList KRubyMethod::GetPropertyNames()
    {
        return object->GetPropertyNames();
    }

    SharedString KRubyMethod::DisplayString(int levels)
    {
        return this->object->DisplayString(levels);
    }

    VALUE KRubyMethod::ToRuby()
    {
        return this->object->ToRuby();
    }

    bool KRubyMethod::Equals(KObjectRef other)
    {
        AutoPtr<KRubyMethod> methodOther = other.cast<KRubyMethod>();
        if (methodOther.isNull())
            return false;
        return methodOther->ToRuby() == this->ToRuby();
    }
}
