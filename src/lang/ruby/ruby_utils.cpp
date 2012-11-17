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
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

namespace tide
{
    VALUE RubyUtils::TiObjectClass = Qnil;
    VALUE RubyUtils::TiMethodClass = Qnil;
    VALUE RubyUtils::TiListClass = Qnil;

    bool RubyUtils::KindOf(VALUE value, VALUE klass)
    {
        return rb_obj_is_kind_of(value, klass) == Qtrue;
    }

    ValueRef RubyUtils::ToTiValue(VALUE value)
    {
        ValueRef kvalue = Value::Undefined;

        int t = TYPE(value);
        if (T_NIL == t)
        {
            kvalue = Value::Null;
        }
        else if (T_FIXNUM == t || T_BIGNUM == t || T_FLOAT == t)
        {
            kvalue = Value::NewDouble(NUM2DBL(value));
        }
        else if (T_TRUE == t)
        {
            kvalue = Value::NewBool(true);
        }
        else if (T_FALSE == t)
        {
            kvalue = Value::NewBool(false);
        }
        else if (T_STRING == t)
        {
            kvalue = Value::NewString(StringValuePtr(value));
        }
        else if (T_SYMBOL == t)
        {
            kvalue = Value::NewString(rb_id2name(SYM2ID(value)));
        }
        else if (T_OBJECT == t)
        {
            TiObjectRef kobj = new KRubyObject(value);
            kvalue = Value::NewObject(kobj);
        }
        else if (T_STRUCT == t)
        {
            TiObjectRef kobj = new KRubyObject(value);
            kvalue = Value::NewObject(kobj);
        }
        else if (T_HASH == t)
        {
            TiObjectRef kobj = new KRubyHash(value);
            kvalue = Value::NewObject(kobj);
        }
        else if (T_ARRAY == t)
        {
            TiListRef tiList = new KRubyList(value);
            kvalue = Value::NewList(tiList);
        }
        else if (T_DATA == t && TiObjectClass != Qnil && KindOf(value, TiObjectClass))
        {
            ValueRef* kval = NULL;
            Data_Get_Struct(value, ValueRef, kval);
            kvalue = Value::NewObject((*kval)->ToObject());
        }
        else if (T_DATA == t && TiMethodClass != Qnil && KindOf(value, TiMethodClass))
        {
            ValueRef* kval = NULL;
            Data_Get_Struct(value, ValueRef, kval);
            kvalue = Value::NewMethod((*kval)->ToMethod());
        }
        else if (T_DATA == t && TiListClass != Qnil && KindOf(value, TiListClass))
        {
            ValueRef* kval = NULL;
            Data_Get_Struct(value, ValueRef, kval);
            kvalue = Value::NewList((*kval)->ToList());
        }
        else if (T_DATA == t && KindOf(value, rb_cMethod))
        {
            TiMethodRef method = new KRubyMethod(value);
            return Value::NewMethod(method);
        }
        else if (T_DATA == t && KindOf(value, rb_cProc))
        {
            TiMethodRef method = new KRubyMethod(value);
            return Value::NewMethod(method);
        }
        else if (T_DATA == t)
        {
            TiObjectRef object = new KRubyObject(value);
            return Value::NewObject(object);
        }

        return kvalue;
    }

    VALUE RubyUtils::ToRubyValue(ValueRef value)
    {
        if (value->IsNull() || value->IsUndefined())
        {
            return Qnil;
        }
        if (value->IsBool())
        {
            return value->ToBool() ? Qtrue : Qfalse;
        }
        else if (value->IsNumber())
        {
            return rb_float_new(value->ToNumber());
        }
        else if (value->IsString())
        {
            return rb_str_new2(value->ToString());
        }
        else if (value->IsObject())
        {
            AutoPtr<KRubyObject> ro = value->ToObject().cast<KRubyObject>();
            if (!ro.isNull())
                return ro->ToRuby();

            AutoPtr<KRubyHash> rh = value->ToObject().cast<KRubyHash>();
            if (!rh.isNull())
                return rh->ToRuby();

            return RubyUtils::TiObjectToRubyValue(value);
        }
        else if (value->IsMethod())
        {
            AutoPtr<KRubyMethod> rm = value->ToMethod().cast<KRubyMethod>();
            if (!rm.isNull())
                return rm->ToRuby();
            else
                return RubyUtils::TiMethodToRubyValue(value);
        }
        else if (value->IsList())
        {
            AutoPtr<KRubyList> rl = value->ToList().cast<KRubyList>();
            if (!rl.isNull())
                return rl->ToRuby();
            else
                return RubyUtils::TiListToRubyValue(value);
        }
        return Qnil;
    }

    static VALUE RubyTiObjectMethods(VALUE self)
    {
        ValueRef* value = NULL;
        Data_Get_Struct(self, ValueRef, value);
        TiObjectRef object = (*value)->ToObject();

        VALUE* args = NULL;
        VALUE methods = rb_call_super(0, args);

        SharedStringList props = object->GetPropertyNames();
        for (unsigned int i = 0; i < props->size(); i++)
        {
            SharedString prop_name = props->at(i);
            rb_ary_push(methods, rb_str_new2(prop_name->c_str()));
        }
        return methods;
    }

    VALUE RubyUtils::GenericTiMethodCall(TiMethodRef method, VALUE args)
    {
        ValueList kargs;
        for (int i = 0; i < RARRAY_LEN(args); i++)
        {
            VALUE rarg = rb_ary_entry(args, i);
            ValueRef arg = RubyUtils::ToTiValue(rarg);
            Value::Unwrap(arg);
            kargs.push_back(arg);
        }

        try
        {
            ValueRef result = method->Call(kargs);
            return RubyUtils::ToRubyValue(result);
        }
        catch (ValueException& e)
        {
            // TODO: Eventually wrap these up in a special exception
            // class so that we can unwrap them into ValueExceptions again
            SharedString ss = e.DisplayString();
            rb_raise(rb_eStandardError, ss->c_str());
            return Qnil;
        }
    }

    // A :method method for pulling methods off of TiObjects in Ruby
    static VALUE RubyTiObjectMethod(int argc, VALUE *argv, VALUE self)
    {
        ValueRef* dval = NULL;
        Data_Get_Struct(self, ValueRef, dval);
        TiObjectRef object = (*dval)->ToObject();

        // TODO: We should raise an exception instead
        if (object.isNull())
            return Qnil;
        if (argc < 1)
            return Qnil;

        VALUE meth_name = argv[0];
        const char* name = rb_id2name(SYM2ID(meth_name));
        ValueRef v = object->Get(name);
        if (v->IsMethod())
        {
            return RubyUtils::ToRubyValue(v);
        }
        else
        {
            return Qnil;
        }
    }

    // A :method_missing method for finding TiObject properties in Ruby
    static VALUE RubyTiObjectMethodMissing(int argc, VALUE *argv, VALUE self)
    {
        ValueRef* dval = NULL;
        Data_Get_Struct(self, ValueRef, dval);
        TiObjectRef object = (*dval)->ToObject();

        // TODO: We should raise an exception instead
        if (object.isNull())
            return Qnil;

        // This is the same error that ruby throws
        if (argc == 0 || !SYMBOL_P(argv[0]))
        {
            rb_raise(rb_eArgError, "no id given");
        }

        // We need to determine the method that was invoked:
        // store the method name and arguments in separate variables
        VALUE r_name, args;
        rb_scan_args(argc, argv, "1*", &r_name, &args);
        const char* name = rb_id2name(SYM2ID(r_name));

        // Check if this is an assignment
        ValueRef value = object->Get(name);
        if (name[strlen(name) - 1] == '=' && argc > 1)
        {
            char* mod_name = strdup(name);
            mod_name[strlen(mod_name) - 1] = '\0';
            value = RubyUtils::ToTiValue(argv[1]);
            object->Set(mod_name, value);
            free(mod_name);
            return argv[1];
        }
        else if (value->IsUndefined()) // raise a method missing error
        {
            VALUE selfString = rb_obj_as_string(self);
            rb_raise(rb_eNoMethodError, "undefined method `%s' for %s",
                name, StringValueCStr(selfString));
        }
        else if (value->IsMethod()) // actually call a method
        {
            return RubyUtils::GenericTiMethodCall(value->ToMethod(), args);
        }
        else // Plain old access
        {
            return RubyUtils::ToRubyValue(value);
        }
        return 0;
    }

    // A :responds_to? method for finding TiObject properties in Ruby
    static VALUE RubyTiObjectRespondTo(int argc, VALUE *argv, VALUE self)
    {
        ValueRef* dval = NULL;
        Data_Get_Struct(self, ValueRef, dval);
        TiObjectRef object = (*dval)->ToObject();
        VALUE mid, priv; // We ignore the priv argument

        rb_scan_args(argc, argv, "11", &mid, &priv);
        const char* name = rb_id2name(rb_to_id(mid));
        ValueRef value = object->Get(name);
        return value->IsUndefined() ? Qfalse : Qtrue;
    }

    static void RubyTiObjectFree(void *p)
    {
        ValueRef* kval = static_cast<ValueRef*>(p);
        delete kval;
    }

    static VALUE RubyTiMethodCall(VALUE self, VALUE args)
    {
        ValueRef* dval = NULL;
        Data_Get_Struct(self, ValueRef, dval);
        TiMethodRef method = (*dval)->ToMethod();

        // TODO: We should raise an exception instead
        if (method.isNull())
            return Qnil;

        return RubyUtils::GenericTiMethodCall(method, args);
    }

    VALUE RubyUtils::TiObjectToRubyValue(ValueRef obj)
    {
        // Lazily initialize the TiObject wrapper class
        if (TiObjectClass == Qnil)
        {
            TiObjectClass = rb_define_class("RubyTiObject", rb_cObject);
            rb_define_method(TiObjectClass, "method_missing",
                RUBY_METHOD_FUNC(RubyTiObjectMethodMissing), -1);
            rb_define_method(TiObjectClass, "method",
                RUBY_METHOD_FUNC(RubyTiObjectMethod), -1);
            rb_define_method(TiObjectClass, "methods",
                RUBY_METHOD_FUNC(RubyTiObjectMethods), 0);
            rb_define_method(TiObjectClass, "respond_to?",
                RUBY_METHOD_FUNC(RubyTiObjectRespondTo), -1);
        }

        VALUE wrapper = Data_Wrap_Struct(TiObjectClass, 0, RubyTiObjectFree, new ValueRef(obj));
        rb_obj_call_init(wrapper, 0, 0);
        return wrapper;
    }

    VALUE RubyUtils::TiMethodToRubyValue(ValueRef obj)
    {
        // Lazily initialize the TiMethod wrapper class
        if (TiMethodClass == Qnil)
        {
            TiMethodClass = rb_define_class("RubyTiMethod", rb_cObject);
            rb_define_method(TiMethodClass, "method_missing",
                RUBY_METHOD_FUNC(RubyTiObjectMethodMissing), -1);
            rb_define_method(TiMethodClass, "method",
                RUBY_METHOD_FUNC(RubyTiObjectMethod), -1);
            rb_define_method(TiMethodClass, "methods",
                RUBY_METHOD_FUNC(RubyTiObjectMethods), 0);
            rb_define_method(TiMethodClass, "respond_to?",
                RUBY_METHOD_FUNC(RubyTiObjectRespondTo), -1);
            rb_define_method(TiMethodClass, "call",
                RUBY_METHOD_FUNC(RubyTiMethodCall), -2);
        }

        VALUE wrapper = Data_Wrap_Struct(TiMethodClass, 0, RubyTiObjectFree, new ValueRef(obj));
        rb_obj_call_init(wrapper, 0, 0);
        return wrapper;
    }

    static VALUE RubyTiListGetElt(int argc, VALUE *argv, VALUE self)
    {
        ValueRef* dval = NULL;
        Data_Get_Struct(self, ValueRef, dval);
        TiListRef list = (*dval)->ToList();

        // TODO: We should raise an exception instead
        if (list.isNull() || argc < 1)
            return Qnil;

        int idx = -1;
        if (TYPE(argv[0]) != T_FIXNUM || ((idx = NUM2INT(argv[0])) < 0))
            return Qnil;

        if (idx >= 0 && idx < (int) list->Size())
        {
            ValueRef v = list->At(idx);
            return RubyUtils::ToRubyValue(v);
        }
        else
        {
            return Qnil;
        }
    }

    static VALUE RubyTiListSetElt(int argc, VALUE *argv, VALUE self)
    {
        ValueRef* dval = NULL;
        Data_Get_Struct(self, ValueRef, dval);
        TiListRef tiList = (*dval)->ToList();

        // TODO: We should raise an exception instead
        if (tiList.isNull() || argc < 2)
            return Qnil;
        // TODO: Maybe we should raise an exception instead
        if (TYPE(argv[0]) != T_FIXNUM)
            return Qnil;

        int idx = NUM2INT(argv[0]);
        if (idx < 0)
            return Qnil;

        ValueRef value = RubyUtils::ToTiValue(argv[1]);
        tiList->SetAt(idx, value);

        return argv[1];
    }

    static VALUE RubyTiListLength(int argc, VALUE *argv, VALUE self)
    {
        ValueRef* dval = NULL;
        Data_Get_Struct(self, ValueRef, dval);
        TiListRef tiList = (*dval)->ToList();

        // TODO: We should raise an exception instead
        if (tiList.isNull())
            return Qnil;

        if (argc > 0)
        {
            rb_raise(rb_eNoMethodError, "wrong number of arguments (%d for 0)", argc);
            return Qnil;
        }
        else
        {
            return INT2NUM(tiList->Size());
        }
    }

    static VALUE RubyTiListEach(VALUE self)
    {
        ValueRef* dval = NULL;
        Data_Get_Struct(self, ValueRef, dval);
        TiListRef list = (*dval)->ToList();

        if (list.isNull() || !rb_block_given_p())
            return Qnil;

        for (unsigned int i = 0; i < list->Size(); i++)
            rb_yield(RubyUtils::ToRubyValue(list->At(i)));

        return self;
    }

    static VALUE RubyTiListCollect(VALUE self)
    {
        ValueRef* dval = NULL;
        Data_Get_Struct(self, ValueRef, dval);
        TiListRef list = (*dval)->ToList();

        if (list.isNull() || !rb_block_given_p())
            return Qnil;

        VALUE resultArray = rb_ary_new();
        for (unsigned int i = 0; i < list->Size(); i++)
            rb_ary_push(resultArray, rb_yield(RubyUtils::ToRubyValue(list->At(i))));

        return resultArray;
    }

    VALUE RubyUtils::TiListToRubyValue(ValueRef obj)
    {
        // Lazily initialize the TiMethod wrapper class
        if (TiListClass == Qnil)
        {
            TiListClass = rb_define_class("RubyTiList", rb_cObject);
            rb_define_method(TiListClass, "method_missing",
                RUBY_METHOD_FUNC(RubyTiObjectMethodMissing), -1);
            rb_define_method(TiListClass, "method",
                RUBY_METHOD_FUNC(RubyTiObjectMethod), -1);
            rb_define_method(TiListClass, "methods",
                RUBY_METHOD_FUNC(RubyTiObjectMethods), 0);
            rb_define_method(TiListClass, "respond_to?",
                RUBY_METHOD_FUNC(RubyTiObjectRespondTo), -1);
            rb_define_method(TiListClass, "[]",
                RUBY_METHOD_FUNC(RubyTiListGetElt), -1);
            rb_define_method(TiListClass, "[]=",
                RUBY_METHOD_FUNC(RubyTiListSetElt), -1);
            rb_define_method(TiListClass, "length",
                RUBY_METHOD_FUNC(RubyTiListLength), -1);
            rb_define_method(TiListClass, "each",
                RUBY_METHOD_FUNC(RubyTiListEach), 0);
            rb_define_method(TiListClass, "collect",
                RUBY_METHOD_FUNC(RubyTiListCollect), 0);
            rb_define_method(TiListClass, "map",
                RUBY_METHOD_FUNC(RubyTiListCollect), 0);
        }

        VALUE wrapper = Data_Wrap_Struct(TiListClass, 0, RubyTiObjectFree, new ValueRef(obj));
        rb_obj_call_init(wrapper, 0, 0);
        return wrapper;
    }

    ValueException RubyUtils::GetException()
    {
        VALUE e = rb_gv_get("$!");
        ValueRef v = RubyUtils::ToTiValue(e);
        return ValueException(v);
    }
}
