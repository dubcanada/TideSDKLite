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

#include <signal.h>
#include "ruby_module.h"
#include <Poco/Path.h>

extern "C" EXPORT RubyModule* CreateModule(Host *host, const char* path)
{
    return new RubyModule(host, path);
}

namespace tide
{
    RubyModule* RubyModule::instance_ = NULL;

    void RubyModule::Initialize()
    {
        RubyModule::instance_ = this;

        ruby_init();
        ruby_init_loadpath();

        // Add the application directoy to the Ruby include path so
        // that includes work in a intuitive way for application developers.
        ruby_incpush(UTF8ToSystem(host->GetApplication()->GetResourcesPath()).c_str());

        this->InitializeBinding();
        host->AddModuleProvider(this);
    }

    void RubyModule::Stop()
    {
        TiObjectRef global = this->host->GetGlobalObject();
        global->Set("Ruby", Value::Undefined);
        Script::GetInstance()->RemoveScriptEvaluator(this->binding);
        this->binding = NULL;
        RubyModule::instance_ = NULL;

        ruby_cleanup(0);
    }

    void RubyModule::InitializeBinding()
    {
        // Expose the Ruby evaluator into Tide
        TiObjectRef global = this->host->GetGlobalObject();
        this->binding = new RubyEvaluator();
        global->Set("Ruby", Value::NewObject(binding));
        Script::GetInstance()->AddScriptEvaluator(this->binding);
        
        // Bind the API global constant
        VALUE ruby_api_val = RubyUtils::TiObjectToRubyValue(Value::NewObject(global));
        rb_define_global_const(GLOBAL_NAMESPACE, ruby_api_val);
    }

    const static std::string ruby_suffix = "module.rb";
    bool RubyModule::IsModule(std::string& path)
    {
        return (path.substr(path.length()-ruby_suffix.length()) == ruby_suffix);
    }

    Module* RubyModule::CreateModule(std::string& path)
    {
        path = UTF8ToSystem(path);
        rb_load_file(path.c_str());
        ruby_exec();
        // TODO: Do we need to call ruby_cleanup() here?

        Poco::Path p(path);
        std::string basename = p.getBaseName();
        std::string name = basename.substr(0,basename.length()-ruby_suffix.length()+3);
        std::string moduledir = path.substr(0,path.length()-basename.length()-3);

        return new RubyModuleInstance(host, path, moduledir, name);
    }
}
