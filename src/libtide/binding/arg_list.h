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

#ifndef _ARG_LISTT_H_
#define _ARG_LISTT_H_

#include <vector>
#include <string>
#include <map>
#include "callback.h"

namespace tide
{
    /**
     * An argument list
     *
     * This class is only used for argument lists. For a list implementation to be
     *  used as a value in the binding layer, take a look at KList and StaticBoundList.
     */
    class TIDE_API ArgList
    {
        public:
        ArgList();
        ArgList(KValueRef);
        ArgList(KValueRef, KValueRef);
        ArgList(KValueRef, KValueRef, KValueRef);
        ArgList(KValueRef, KValueRef, KValueRef, KValueRef);
        ArgList(const ArgList&);
        ~ArgList() {};

        bool Verify(std::string& argSpec) const;
        void VerifyException(const char* name, std::string argSpec) const;

        public:
        void push_back(KValueRef value);
        size_t size() const;
        const KValueRef& at(size_t) const;
        const KValueRef& operator[](size_t) const;

        KValueRef GetValue(size_t index, KValueRef defaultValue=Value::Undefined) const;
        int GetInt(size_t index, int defaultValue=0) const;
        double GetDouble(size_t index, double defaultValue=0.0) const;
        double GetNumber(size_t index, double defaultValue=0.0) const;
        bool GetBool(size_t index, bool defaultValue=false) const;
        std::string GetString(size_t index, std::string defaultValue="") const;
        KObjectRef GetObject(size_t index, KObjectRef defaultValue=NULL) const;
        KMethodRef GetMethod(size_t index, KMethodRef defaultValue=NULL) const;
        KListRef GetList(size_t index, KListRef defaultValue=NULL) const;

        private:
        SharedPtr<std::vector<KValueRef> > args;

        static inline bool VerifyArg(KValueRef arg, char t);
        static std::string GenerateSignature(const char* name, std::string& argSpec);
    };

}
#endif
