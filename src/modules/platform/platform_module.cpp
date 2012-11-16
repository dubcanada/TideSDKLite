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

#include <tide/tide.h>
#include "platform_module.h"
#include "platform_binding.h"

using namespace tide;
using namespace ti;

namespace ti
{
    TIDE_MODULE(PlatformModule, STRING(MODULE_NAME), STRING(MODULE_VERSION));

    void PlatformModule::Initialize()
    {
        this->binding = new PlatformBinding();
        host->GetGlobalObject()->SetObject("Platform", this->binding);
        host->GetGlobalObject()->SetObject("Desktop", this->binding);
    }

    void PlatformModule::Start()
    {
        // Duplicate the network module address, macaddress and interfaces here for
        // backward compatibility. The network module should be initialized when
        // Start() is called.
        if (!GlobalObject::GetInstance()->GetObject("Network").isNull())
        {
            TiObjectRef network = GlobalObject::GetInstance()->GetObject("Network");
            this->binding->Set("getAddress", network->Get("getAddress"));
            this->binding->Set("getMACAddress", network->Get("getMACAddress"));
            this->binding->Set("getInterfaces", network->Get("getInterfaces"));
        }
    }

    void PlatformModule::Stop()
    {
        host->GetGlobalObject()->SetNull("Platform");
        host->GetGlobalObject()->SetNull("Desktop");
    }
    
}
