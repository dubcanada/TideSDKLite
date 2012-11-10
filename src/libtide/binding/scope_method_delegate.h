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

#ifndef _KR_SCOPE_METHOD_DELEGATE_H_
#define _KR_BOUND_METHOD_DELEGATE_H_

namespace tide {

    enum MethodDelegateType
    {
        GET, /**< Getter method */
        SET /**< Setter method */
    };

    /**
     * class that can be used to change the delegation of a method
     * call's Get or Set method to first check to see if the key has
     * namespace dots (such as ti.foo.bar) and if so, delegate to a
     * differently supplied scope object for delegation.
     */
    class TIDE_API ScopeMethodDelegate : public KMethod
    {
    
    public:
        ScopeMethodDelegate(MethodDelegateType type, KObjectRef global,
                            KObjectRef scope, KMethodRef delegate);
        virtual ~ScopeMethodDelegate();


        void Set(const char *name, KValueRef value);
        KValueRef Get(const char *name);
        SharedStringList GetPropertyNames();


        bool IsGlobalKey(std::string& key);
        KValueRef Call(const ValueList& args);

        /**
         * create a delegate from a KObject to a wrapped
         * StaticBoundObject and delegate set/get to the new
         * static bound object
         */
        static AutoPtr<StaticBoundObject> CreateDelegate(KObjectRef global, KObjectRef bo);

    private:
        MethodDelegateType type;
        KObjectRef global;
        KObjectRef scope;
        KMethodRef delegate;

    private:
        DISALLOW_EVIL_CONSTRUCTORS(ScopeMethodDelegate);
    };

}

#endif
