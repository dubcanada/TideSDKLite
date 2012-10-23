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

#ifndef _KR_FUNCTION_PTR_METHOD_H_
#define _KR_FUNCTION_PTR_METHOD_H_

namespace kroll
{
    typedef KValueRef (*KFunctionPtrCallback) (const ValueList& args);
    class KROLL_API KFunctionPtrMethod : public KMethod
    {
        public:
        KFunctionPtrMethod(KFunctionPtrCallback);
        virtual ~KFunctionPtrMethod();

        /**
         * @see KMethod::Call
         */
        virtual KValueRef Call(const ValueList& args);

        /**
         * @see KObject::Set
         */
        virtual void Set(const char *name, KValueRef value);

        /**
         * @see KObject::Get
         */
        virtual KValueRef Get(const char *name);

        /**
         * @see KObject::GetPropertyNames
         */
        virtual SharedStringList GetPropertyNames();
        

        protected:
        KFunctionPtrCallback callback;
        KObjectRef object;

        private:
        DISALLOW_EVIL_CONSTRUCTORS(KFunctionPtrMethod);
    };
}

#endif