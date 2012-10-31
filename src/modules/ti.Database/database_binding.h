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

#ifndef _DATABASE_BINDING_H_
#define _DATABASE_BINDING_H_

#include <tide/tide.h>
#include "webkit_databases.h"
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>

namespace ti
{
    class DatabaseBinding : public KAccessorObject
    {
    public:
        DatabaseBinding(std::string& name, bool isWebKitDatabase);

    protected:
        virtual ~DatabaseBinding();
        void Open(const ValueList& args, KValueRef result);
        void Execute(const ValueList& args, KValueRef result);
        void Close(const ValueList& args, KValueRef result);
        void Remove(const ValueList& args, KValueRef result);
        void GetPath(const ValueList& args, KValueRef result);
        void Close();

        Poco::Data::Session *session;
        std::string name;
        std::string path;
        bool isWebKitDatabase;
    };
}

#endif
