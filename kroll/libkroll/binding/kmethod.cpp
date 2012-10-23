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

#include "../kroll.h"
#include <sstream>
#include <cmath>

namespace kroll
{

    SharedString KMethod::DisplayString(int levels)
    {
        std::ostringstream oss;
        oss << "<" << this->GetType() << " at " << this << ">";
        return new std::string(oss.str());
    }

    KValueRef KMethod::Call(KObjectRef thisObject, const ValueList& args)
    {
        return this->Call(args);
    }

    KValueRef KMethod::Call()
    {
        return this->Call(ValueList());
    }

    KValueRef KMethod::Call(const char* one, KValueRef two, KValueRef three,
        KValueRef four)
    {
        ValueList args;
        args.push_back(Value::NewString(one));
        args.push_back(two);
        args.push_back(three);
        args.push_back(four);
        return this->Call(args);
    }

    KValueRef KMethod::Call(KValueRef one)
    {
        ValueList args;
        args.push_back(one);
        return this->Call(args);
    }

    KValueRef KMethod::Call(KValueRef one, KValueRef two)
    {
        ValueList args;
        args.push_back(one);
        args.push_back(two);
        return this->Call(args);
    }

    KValueRef KMethod::Call(KValueRef one, KValueRef two, KValueRef three)
    {
        ValueList args;
        args.push_back(one);
        args.push_back(two);
        args.push_back(three);
        return this->Call(args);
    }

    KValueRef KMethod::Call(const char* one)
    {
        ValueList args;
        args.push_back(Value::NewString(one));
        return this->Call(args);
    }

    KValueRef KMethod::Call(const char* one, KValueRef two)
    {
        ValueList args;
        args.push_back(Value::NewString(one));
        args.push_back(two);
        return this->Call(args);
    }

    KValueRef KMethod::Call(const char* one, KValueRef two, KValueRef three)
    {
        ValueList args;
        args.push_back(Value::NewString(one));
        args.push_back(two);
        args.push_back(three);
        return this->Call(args);
    }

    KMethodRef KMethod::Unwrap(KMethodRef o)
    {
        AutoPtr<ProfiledBoundMethod> pmeth = o.cast<ProfiledBoundMethod>();
        if (pmeth.isNull())
        {
            return o;
        }
        else
        {
            return pmeth->GetDelegate();
        }
    }
}