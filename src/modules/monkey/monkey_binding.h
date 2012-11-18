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

#ifndef _MONKEY_BINDING_H_
#define _MONKEY_BINDING_H_
#include <tide/tide.h>
#include <vector>

namespace ti
{
    struct Script
    {
        public:
        std::vector<std::string> includes;
        std::vector<std::string> excludes;
        std::string source;
        bool Matches(std::string& url);
        static bool Matches(std::vector<std::string>&, std::string& url);
        static bool Matches(const char* pattern, const char* target);
    };

    class MonkeyBinding : public tide::StaticBoundObject
    {
        public:
        MonkeyBinding(Host*, TiObjectRef);

        protected:
        virtual ~MonkeyBinding();
        void ParseFile(string filePath);
        void Callback(const ValueList &args, ValueRef result);
        void EvaluateUserScript(
            TiObjectRef, std::string&,TiObjectRef, std::string&);

        TiObjectRef global;
        Logger* logger;
        TiMethodRef callback;
        std::vector<Script*> scripts;
    };
}

#endif
