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
     *  used as a value in the binding layer, take a look at TiList and StaticBoundList.
     */
    class TIDE_API ArgList
    {
        public:
        ArgList();
        ArgList(ValueRef);
        ArgList(ValueRef, ValueRef);
        ArgList(ValueRef, ValueRef, ValueRef);
        ArgList(ValueRef, ValueRef, ValueRef, ValueRef);
        ArgList(const ArgList&);
        ~ArgList() {};

        bool Verify(std::string& argSpec) const;
        void VerifyException(const char* name, std::string argSpec) const;

        public:
        void push_back(ValueRef value);
        size_t size() const;
        const ValueRef& at(size_t) const;
        const ValueRef& operator[](size_t) const;

        ValueRef GetValue(size_t index, ValueRef defaultValue=Value::Undefined) const;
        int GetInt(size_t index, int defaultValue=0) const;
        double GetDouble(size_t index, double defaultValue=0.0) const;
        double GetNumber(size_t index, double defaultValue=0.0) const;
        bool GetBool(size_t index, bool defaultValue=false) const;
        std::string GetString(size_t index, std::string defaultValue="") const;
        TiObjectRef GetObject(size_t index, TiObjectRef defaultValue=NULL) const;
        TiMethodRef GetMethod(size_t index, TiMethodRef defaultValue=NULL) const;
        TiListRef GetList(size_t index, TiListRef defaultValue=NULL) const;

        private:
        SharedPtr<std::vector<ValueRef> > args;

        static inline bool VerifyArg(ValueRef arg, char t);
        static std::string GenerateSignature(const char* name, std::string& argSpec);
    };

}
#endif
