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

#ifndef _KR_SCRIPT_H_
#define _KR_SCRIPT_H_

#include <tide/tide.h>

namespace tide
{
    class TIDE_API PreprocessData : public ReferenceCounted
    {
    public:
        BytesRef data;
        std::string mimeType;
    };
    
    class TIDE_API Script
    {
    public:
        static SharedPtr<Script> GetInstance();
        static void Initialize();
        static bool HasExtension(const char *url, const char *ext);
        static std::string GetExtension(const char *url);
        
        void AddScriptEvaluator(TiObjectRef evaluator);
        void RemoveScriptEvaluator(TiObjectRef evaluator);

        bool CanEvaluate(const char *mimeType);
        bool CanPreprocess(const char *url);
        TiListRef GetEvaluators() { return evaluators; }

        KValueRef Evaluate(const char *mimeType, const char *name, const char *code, TiObjectRef scope);
        AutoPtr<PreprocessData> Preprocess(const char *url, TiObjectRef scope);
        
    protected:
        TiListRef evaluators;
        static SharedPtr<Script> instance;
        
        Script() : evaluators(new StaticBoundList()) { }
        TiObjectRef FindEvaluatorWithMethod(const char *method, const char *arg);
    };
}

#endif
