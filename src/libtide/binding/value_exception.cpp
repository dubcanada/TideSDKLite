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
#include <cstdarg>

namespace tide
{
    ValueException::ValueException(ValueRef v) : std::exception(), value(v)
    {
    }

    ValueException::~ValueException() throw ()
    {
    }

    ValueException ValueException::FromString(const char* s)
    {
        return ValueException(Value::NewString(s));
    }

    ValueException ValueException::FromString(std::string s)
    {
        return ValueException(Value::NewString(s));
    }

    ValueException ValueException::FromFormat(const char* format, ...)
    {

        va_list args;
        va_start(args, format);
        std::string text = Logger::Format(format, args);
        va_end(args);

        return ValueException(Value::NewString(text));
    }

    ValueException ValueException::FromObject(TiObjectRef o)
    {
        return ValueException(Value::NewObject(o));
    }

    ValueRef ValueException::GetValue()
    {
        return this->value;
    }

    SharedString ValueException::DisplayString()
    {
        if (!this->value.isNull())
        {
            return this->value->DisplayString();
        }
        else
        {
            SharedString s = new std::string("<no exception>");
            return s;
        }
    }

    std::string& ValueException::ToString()
    {
        this->displayString = *this->DisplayString();
        return this->displayString;
    }
}
