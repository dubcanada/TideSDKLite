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

#include "../tide.h"
#include <sstream>
#include <cstring>

namespace tide
{
    void Value::reset()
    {
        if (this->IsString() && this->stringValue)
        {
            free(this->stringValue);
            this->stringValue = 0;
        }
        this->type = UNDEFINED;
        this->objectValue = 0;
        this->stringValue = 0;
        this->numberValue = 0;
    }

    Value::Value() :
        type(UNDEFINED),
        numberValue(0),
        stringValue(0),
        objectValue(0)
    {
    }

    Value::Value(ValueRef value) :
        type(UNDEFINED),
        numberValue(0),
        stringValue(0),
        objectValue(0)
    {
        this->SetValue(value);
    }

    Value::Value(const Value& value) : type(UNDEFINED),
        numberValue(0),
        stringValue(0),
        objectValue(0)
    {
        this->SetValue((Value*) &value);
    }

    Value::~Value()
    {
        reset();
    }

    ValueRef Value::NewUndefined()
    {
        ValueRef v(new Value());
        return v;
    }

    ValueRef Value::NewNull()
    {
        ValueRef v(new Value());
        v->SetNull();
        return v;
    }

    ValueRef Value::NewInt(int value)
    {
        ValueRef v(new Value());
        v->SetInt(value);
        return v;
    }

    ValueRef Value::NewDouble(double value)
    {
        ValueRef v(new Value());
        v->SetDouble(value);
        return v;
    }

    ValueRef Value::NewBool(bool value)
    {
        ValueRef v(new Value());
        v->SetBool(value);
        return v;
    }

    ValueRef Value::NewString(const char* value)
    {
        ValueRef v(new Value());
        v->SetString(value);
        return v;
    }

    ValueRef Value::NewString(std::string value)
    {
        ValueRef v(new Value());
        v->SetString(value.c_str());
        return v;
    }

    ValueRef Value::NewString(SharedString value)
    {
        ValueRef v(new Value());
        v->SetString(value.get()->c_str());
        return v;
    }

    ValueRef Value::NewList(TiListRef value)
    {
        ValueRef v(new Value());
        v->SetList(value);
        return v;
    }

    ValueRef Value::NewMethod(TiMethodRef method)
    {
        ValueRef v(new Value());
        v->SetMethod(method);
        return v;
    }

    ValueRef Value::NewObject(TiObjectRef value)
    {
        ValueRef v(new Value());
        v->SetObject(value);
        return v;
    }

    ValueRef Value::Undefined = NewUndefined();
    ValueRef Value::Null = NewNull();

    bool Value::IsInt() const { return type == INT || (type == DOUBLE && ((int) numberValue) == numberValue); }
    bool Value::IsDouble() const { return type == DOUBLE; }
    bool Value::IsNumber() const { return type == DOUBLE || type == INT; }
    bool Value::IsBool() const { return type == BOOL; }
    bool Value::IsString() const {  return type == STRING; }
    bool Value::IsList() const { return type == LIST; }
    bool Value::IsObject() const { return this->type == OBJECT; }
    bool Value::IsMethod() const { return type == METHOD; }
    bool Value::IsNull() const { return type == NULLV; }
    bool Value::IsUndefined() const { return type == UNDEFINED; }

    int Value::ToInt() const { return (int) numberValue; }
    double Value::ToDouble() const { return numberValue; }
    double Value::ToNumber() const { return numberValue; }
    bool Value::ToBool() const { return boolValue; }
    const char* Value::ToString() const { return stringValue; }
    TiObjectRef Value::ToObject() const { return objectValue; }
    TiMethodRef Value::ToMethod() const { return objectValue.cast<TiMethod>(); }
    TiListRef Value::ToList() const { return objectValue.cast<TiList>(); }

    void Value::SetValue(ValueRef other)
    {
        SetValue(other.get());
    }

    void Value::SetValue(Value *other)
    {
        if (other->IsInt())
            this->SetInt(other->ToInt());

        else if (other->IsDouble())
            this->SetDouble(other->ToDouble());

        else if (other->IsBool())
            this->SetBool(other->ToBool());

        else if (other->IsString())
            this->SetString(other->ToString());

        else if (other->IsList())
            this->SetList(other->ToList());

        else if (other->IsMethod())
            this->SetMethod(other->ToMethod());

        else if (other->IsObject())
            this->SetObject(other->ToObject());

        else if (other->IsNull())
            this->SetNull();

        else if (other->IsUndefined())
            this->SetUndefined();

        else
            throw "Error on set. Unknown type for other";
    }

    void Value::SetInt(int value)
    {
        reset();
        this->numberValue = value;
        type = INT;
    }

    void Value::SetDouble(double value)
    {
        reset();
        this->numberValue = value;
        type = DOUBLE;
    }

    void Value::SetBool(bool value)
    {
        reset();
        this->boolValue = value;
        type = BOOL;
    }

    void Value::SetString(const char* value)
    {
        reset();
        this->stringValue = strdup(value);
        type = STRING;
    }

    void Value::SetString(std::string& value)
    {
        this->SetString(value.c_str());
    }

    void Value::SetString(SharedString value)
    {
        this->SetString(value.get()->c_str());
    }

    void Value::SetList(TiListRef value)
    {
        reset();
        this->objectValue = value;
        if (value.isNull()) {
            this->type = NULLV;
        } else {
            this->type = LIST;
        }
    }

    void Value::SetObject(TiObjectRef value)
    {
        reset();
        this->objectValue = value;
        if (value.isNull()) {
            this->type = NULLV;
        } else {
            this->type = OBJECT;
        }
    }

    void Value::SetMethod(TiMethodRef value)
    {
        reset();
        this->objectValue = value;
        if (value.isNull()) {
            this->type = NULLV;
        } else {
            this->type = METHOD;
        }
    }

    void Value::SetNull()
    {
        reset();
        type = NULLV;
    }

    void Value::SetUndefined()
    {
        reset();
        type = UNDEFINED;
    }

    bool Value::Equals(ValueRef i)
    {
        if (this->IsInt() && i->IsInt()
            && this->ToInt() == i->ToInt())
            return true;

        if (this->IsDouble() && i->IsDouble()
            && this->ToDouble() == i->ToDouble())
            return true;

        if (this->IsBool() && i->IsBool()
            && this->ToBool() == i->ToBool())
            return true;

        if (this->IsString() && i->IsString()
            && this->ToString() == i->ToString())
            return true;

        if (this->IsNull() && i->IsNull())
            return true;

        if (this->IsUndefined() && i->IsUndefined())
            return true;

        if ((this->IsList() && i->IsList())
            || (this->IsMethod() && i->IsMethod())
            || (this->IsObject() && i->IsObject()))
            return this->ToObject()->Equals(i->ToObject());

        return false;
    }

    SharedString Value::DisplayString(int levels)
    {
        std::ostringstream oss;
        switch (this->type)
        {
            case INT:
                oss << this->ToInt() << "i";
                break;

            case DOUBLE:
                oss << this->ToDouble() << "d";
                break;

            case BOOL:
                oss << (this->ToBool() ? "true" : "false");
                break;

            case STRING:
                oss << "\"" << this->ToString() << "\"";
                break;

            case LIST:
            case OBJECT:
            case METHOD:
            {
                TiObjectRef o(this->ToObject());
                if (levels == 0)
                {
                    oss << "<" << o->GetType() << " at " << o.get() << ">";
                }
                else
                {
                    SharedString ss(this->ToObject()->DisplayString(levels-1));
                    oss << *ss;
                }
                break;
            }

            case NULLV:
                oss << "<null>";
                break;

            case UNDEFINED:
                oss << "<undefined>";
                break;
        }

        return new std::string(oss.str());
    }

    std::string& Value::GetType()
    {
        static std::string numberString = "Number";
        static std::string booleanString = "Boolean";
        static std::string stringString = "String";
        static std::string nullString = "Null";
        static std::string undefinedString = "Undefined";
        static std::string unknownString = "Unknown";

        if (IsInt() || IsDouble())
            return numberString;
        else if (IsBool())
            return booleanString;
        else if (IsString())
            return stringString;
        else if (IsList() || IsObject() || IsMethod())
            return this->ToObject()->GetType();
        else if (IsNull())
            return nullString;
        else if (IsUndefined())
            return undefinedString;
        else
            return unknownString;
    }

    void Value::Unwrap(ValueRef value)
    {
        if (!Host::GetInstance()->ProfilingEnabled())
        {
            return;
        }

        if (value->IsMethod())
        {
            TiMethodRef method = TiMethod::Unwrap(value->ToMethod());
            value->SetMethod(method);
        }
        else if (value->IsList())
        {
            TiListRef list = TiList::Unwrap(value->ToList());
            value->SetList(list);
        }
        else if (value->IsObject())
        {
            TiObjectRef obj = TiObject::Unwrap(value->ToObject());
            value->SetObject(obj);
        }
    }
}
