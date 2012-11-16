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

#include "script.h"
#include <Poco/File.h>
#include <Poco/TemporaryFile.h>

namespace tide
{
    /*static*/
    SharedPtr<Script> Script::instance = 0;
    
    /*static*/
    SharedPtr<Script> Script::GetInstance()
    {
        return instance;
    }
    
    /*static*/
    void Script::Initialize()
    {
        instance = new Script();
    }
    
    /*static*/
    bool Script::HasExtension(const char *script, const char *extension)
    {
        std::string scriptStr(script);
        std::string extStr(".");
        extStr += extension;
        
        return scriptStr.size() >= extStr.size() && scriptStr.substr(scriptStr.size()-extStr.size()) == extStr;
    }
    
    /*static*/
     std::string Script::GetExtension(const char *script)
    {
        std::string scriptStr(script);
        return scriptStr.substr(scriptStr.rfind("."));
    }
    
    void Script::AddScriptEvaluator(TiObjectRef evaluator)
    {
        evaluators->Append(Value::NewObject(evaluator));
    }
    
    void Script::RemoveScriptEvaluator(TiObjectRef evaluator)
    {
        int index = -1;
        for (unsigned int i = 0; i < evaluators->Size(); i++)
        {
            if (evaluators->At(i)->ToObject()->Equals(evaluator))
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            evaluators->Remove(index);
        }
    }
    
    TiObjectRef Script::FindEvaluatorWithMethod(const char *method, const char *arg)
    {
        ValueList args;
        args.push_back(Value::NewString(arg));
        
        for (unsigned int i = 0; i < evaluators->Size(); i++)
        {
            TiMethodRef finder = evaluators->At(i)->ToObject()->GetMethod(method);
            if (!finder.isNull())
            {
                KValueRef result = finder->Call(args);
                if (result->IsBool() && result->ToBool())
                {
                    return evaluators->At(i)->ToObject();
                }
            }
        }
        return 0;
    }
    
    bool Script::CanEvaluate(const char *mimeType)
    {
        return !this->FindEvaluatorWithMethod("canEvaluate", mimeType).isNull();
    }
    
    bool Script::CanPreprocess(const char *url)
    {
        return !this->FindEvaluatorWithMethod("canPreprocess", url).isNull();
    }
    
    KValueRef Script::Evaluate(const char *mimeType, const char *name, const char *code, TiObjectRef scope)
    {
        TiObjectRef evaluator = this->FindEvaluatorWithMethod("canEvaluate", mimeType);
        if (!evaluator.isNull())
        {
            TiMethodRef evaluate = evaluator->GetMethod("evaluate");
            if (!evaluate.isNull())
            {
                ValueList args;
                args.push_back(Value::NewString(mimeType));
                args.push_back(Value::NewString(name));
                args.push_back(Value::NewString(code));
                args.push_back(Value::NewObject(scope));
                return evaluate->Call(args);
            }
            else
            {
                throw ValueException::FromFormat(
                    "Error evaluating: No \"evaluate\" method found on evaluator for mimeType: \"%s\"", mimeType);
            }
        }
        else
        {
            throw ValueException::FromFormat("Error evaluating: No evaluator found for mimeType: \"%s\"", mimeType);
        }
    }
    
    AutoPtr<PreprocessData> Script::Preprocess(const char *url, TiObjectRef scope)
    {
        TiObjectRef evaluator = this->FindEvaluatorWithMethod("canPreprocess", url);
        if (!evaluator.isNull())
        {
            TiMethodRef preprocess = evaluator->GetMethod("preprocess");
            if (!preprocess.isNull())
            {
                ValueList args;
                args.push_back(Value::NewString(url));
                args.push_back(Value::NewObject(scope));
                
                KValueRef result = preprocess->Call(args);
                
                if (result->IsObject())
                {
                    TiObjectRef object = result->ToObject();
                    AutoPtr<PreprocessData> data = new PreprocessData();
                    if (object->HasProperty("data"))
                    {
                        KValueRef objectData = object->Get("data");
                        if (objectData->IsObject())
                        {
                            BytesRef blobData = objectData->ToObject().cast<Bytes>();
                            if (!blobData.isNull())
                            {
                                data->data = blobData;
                            }
                        }
                        else if (objectData->IsString())
                        {
                            data->data = new Bytes(objectData->ToString(), strlen(objectData->ToString()));
                        }
                    }
                    else
                    {
                        throw ValueException::FromString("Preprocessor didn't return any data");
                    }
                    if (object->HasProperty("mimeType"))
                    {
                        data->mimeType = object->Get("mimeType")->ToString();
                    }
                    else
                    {
                        throw ValueException::FromString("Preprocessor didn't return a mimeType");
                    }
                    
                    return data;
                }
            }
            else
            {
                throw ValueException::FromFormat(
                    "Error preprocessing: No \"preprocess\" method found on evaluator for url: \"%s\"", url);
            }
        }
        else
        {
            throw ValueException::FromFormat("Error preprocessing: No evaluator found for url: \"%s\"", url);
        }
        return 0;
    }
}
