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

#ifndef _K_RUBY_METHOD_H_
#define _K_RUBY_METHOD_H_

namespace kroll {

class KRubyMethod : public KMethod
{
    public:
    KRubyMethod(VALUE method);
    KRubyMethod(VALUE method, const char*);
    KRubyMethod(VALUE method, VALUE arg);
    virtual ~KRubyMethod();
    KValueRef Call(const ValueList& args);
    virtual void Set(const char *name, KValueRef value);
    virtual KValueRef Get(const char *name);
    virtual SharedStringList GetPropertyNames();
    virtual SharedString DisplayString(int);
    VALUE ToRuby();

    /*
     * Determine if the given Ruby object equals this one
     * by comparing these objects's identity e.g. equals?()
     *  @param other the object to test
     *  @returns true if objects have reference equality, false otherwise
     */
    virtual bool Equals(KObjectRef);

    private:
    VALUE method;
    VALUE arg;
    AutoPtr<KRubyObject> object;
    char* name;
};

}

#endif