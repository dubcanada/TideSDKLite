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

#ifndef RUBY_TYPES_H_
#define RUBY_TYPES_H_

#include <typeinfo>
#include "ruby_module.h"

namespace kroll
{
    class RubyUtils
    {
    public:
        static KValueRef ToKrollValue(VALUE value);
        static VALUE ToRubyValue(KValueRef value);
        static VALUE KObjectToRubyValue(KValueRef value);
        static VALUE KMethodToRubyValue(KValueRef value);
        static VALUE KListToRubyValue(KValueRef value);
        static bool KindOf(VALUE value, VALUE klass);

        static ValueException GetException();
        static VALUE GenericKMethodCall(KMethodRef method, VALUE args);

    private:
        static VALUE KObjectClass;
        static VALUE KMethodClass;
        static VALUE KListClass;
        RubyUtils(){}
        ~RubyUtils(){}
    };
}

#endif