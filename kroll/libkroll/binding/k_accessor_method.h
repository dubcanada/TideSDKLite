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

#ifndef _KR_ACCESSOR_BOUND_METHOD_H_
#define _KR_ACCESSOR_BOUND_METHOD_H_

namespace kroll
{
    /**
     * The KAccessorMethod allows you to expose getters and setters as property access.
     * @see KAccessorObject
     */
    class KROLL_API KAccessorMethod : public StaticBoundMethod, public KAccessor
    {
    public:
        KAccessorMethod(MethodCallback* callback, const char* type = "KAccessorMethod");
        virtual void Set(const char* name, KValueRef value);
        virtual KValueRef Get(const char* name);
        virtual bool HasProperty(const char* name);

    private:
        DISALLOW_EVIL_CONSTRUCTORS(KAccessorMethod);
    };
}

#endif
