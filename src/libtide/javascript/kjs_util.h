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
#ifndef _KJS_UTIL_H_
#define _KJS_UTIL_H_

namespace tide
{
namespace KJSUtil
{

KROLL_API KValueRef ToKrollValue(JSValueRef, JSContextRef, JSObjectRef);
KROLL_API JSValueRef ToJSValue(KValueRef, JSContextRef);
KROLL_API JSValueRef KObjectToJSValue(KValueRef, JSContextRef);
KROLL_API JSValueRef KMethodToJSValue(KValueRef, JSContextRef);
KROLL_API JSValueRef KListToJSValue(KValueRef, JSContextRef);
KROLL_API std::string ToChars(JSStringRef);
KROLL_API bool IsArrayLike(JSObjectRef, JSContextRef);
KROLL_API JSGlobalContextRef CreateGlobalContext();
KROLL_API void RegisterGlobalContext(JSObjectRef, JSGlobalContextRef);
KROLL_API void UnregisterGlobalContext(JSGlobalContextRef);
KROLL_API JSGlobalContextRef GetGlobalContext(JSObjectRef);
KROLL_API void ProtectGlobalContext(JSGlobalContextRef);
KROLL_API void UnprotectGlobalContext(JSGlobalContextRef);
KROLL_API KValueRef Evaluate(JSContextRef context, const char* script,
    const char* url = "string");
KROLL_API KValueRef EvaluateFile(JSContextRef context,
    const std::string& fullPath);
KROLL_API KValueRef GetProperty(JSObjectRef, std::string name);

};
}

#endif
