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

#ifndef _KR_VALUE_EXCEPTION_H_
#define _KR_VALUE_EXCEPTION_H_

#include <vector>
#include <string>
#include <map>

namespace tide
{

#ifndef OS_WIN32
    #pragma GCC visibility push(default)
#endif

    class KROLL_API ValueException : public std::exception
    {
        public:
        ValueException(KValueRef v);
        ~ValueException() throw ();

        public:
        static ValueException FromString(const char* s);
        static ValueException FromString(std::string s);
        static ValueException FromFormat(const char* format, ...);
        static ValueException FromObject(KObjectRef o);
        KValueRef GetValue();
        SharedString DisplayString();
        std::string& ToString();

        private:
        KValueRef value;
        std::string displayString;
    };

#ifndef OS_WIN32
    #pragma GCC visibility pop
#endif
}

#endif
