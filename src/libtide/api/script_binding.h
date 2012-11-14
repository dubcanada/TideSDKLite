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

#ifndef _SCRIPT_BINDING_H
#define _SCRIPT_BINDING_H

#include <tide/tide.h>

namespace tide
{
    class TIDE_API ScriptBinding : public StaticBoundObject
    {
    public:
        ScriptBinding();
        
    protected:
        void _AddScriptEvaluator(const ValueList& args, KValueRef result);
        void _RemoveScriptEvaluator(const ValueList& args, KValueRef result);
        void _CanEvaluate(const ValueList& args, KValueRef result);
        void _CanPreprocess(const ValueList& args, KValueRef result);
        void _Evaluate(const ValueList& args, KValueRef result);
        void _Preprocess(const ValueList& args, KValueRef result);
    };
}
#endif
