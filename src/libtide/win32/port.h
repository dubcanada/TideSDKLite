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

#ifndef BASE_PORT_H_
#define BASE_PORT_H_

#include <stdarg.h>
#define COMPILER_MSVC

#ifdef COMPILER_MSVC
#define GG_LONGLONG(x) x##I64
#define GG_ULONGLONG(x) x##UI64
#else
#define GG_LONGLONG(x) x##LL
#define GG_ULONGLONG(x) x##ULL
#endif

// Per C99 7.8.14, define __STDC_CONSTANT_MACROS before including <stdint.h>
// to get the INTn_C and UINTn_C macros for integer constants.  It's difficult
// to guarantee any specific ordering of header includes, so it's difficult to
// guarantee that the INTn_C macros can be defined by including <stdint.h> at
// any specific point.  Provide GG_INTn_C macros instead.

#define GG_INT8_C(x)    (x)
#define GG_INT16_C(x)   (x)
#define GG_INT32_C(x)   (x)
#define GG_INT64_C(x)   GG_LONGLONG(x)

#define GG_UINT8_C(x)   (x ## U)
#define GG_UINT16_C(x)  (x ## U)
#define GG_UINT32_C(x)  (x ## U)
#define GG_UINT64_C(x)  GG_ULONGLONG(x)

namespace base {

// It's possible for functions that use a va_list, such as StringPrintf, to
// invalidate the data in it upon use.  The fix is to make a copy of the
// structure before using it and use that copy instead.  va_copy is provided
// for this purpose.  MSVC does not provide va_copy, so define an
// implementation here.  It is not guaranteed that assignment is a copy, so the
// StringUtil.VariableArgsFunc unit test tests this capability.
inline void va_copy(va_list& a, va_list& b) {
#if defined(COMPILER_GCC)
  ::va_copy(a, b);
#elif defined(COMPILER_MSVC)
  a = b;
#endif
}

}  // namespace base

// Define an OS-neutral wrapper for shared library entry points
#if defined(OS_WIN32)
#define API_CALL __stdcall
#elif defined(OS_LINUX) || defined(OS_OSX)
#define API_CALL
#endif

#endif // BASE_PORT_H_