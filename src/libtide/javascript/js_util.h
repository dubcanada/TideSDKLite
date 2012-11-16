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
#ifndef _JS_UTIL_H_
#define _JS_UTIL_H_

namespace tide
{
namespace JSUtil
{

TIDE_API KValueRef ToTiValue(JSValueRef, JSContextRef, JSObjectRef);
TIDE_API JSValueRef ToJSValue(KValueRef, JSContextRef);
TIDE_API JSValueRef TiObjectToJSValue(KValueRef, JSContextRef);
TIDE_API JSValueRef TiMethodToJSValue(KValueRef, JSContextRef);
TIDE_API JSValueRef TiListToJSValue(KValueRef, JSContextRef);
TIDE_API std::string ToChars(JSStringRef);
TIDE_API bool IsArrayLike(JSObjectRef, JSContextRef);
TIDE_API JSGlobalContextRef CreateGlobalContext();
TIDE_API void RegisterGlobalContext(JSObjectRef, JSGlobalContextRef);
TIDE_API void UnregisterGlobalContext(JSGlobalContextRef);
TIDE_API JSGlobalContextRef GetGlobalContext(JSObjectRef);
TIDE_API void ProtectGlobalContext(JSGlobalContextRef);
TIDE_API void UnprotectGlobalContext(JSGlobalContextRef);
TIDE_API KValueRef Evaluate(JSContextRef context, const char* script,
    const char* url = "string");
TIDE_API KValueRef EvaluateFile(JSContextRef context,
    const std::string& fullPath);
TIDE_API KValueRef GetProperty(JSObjectRef, std::string name);

};
}

#endif
