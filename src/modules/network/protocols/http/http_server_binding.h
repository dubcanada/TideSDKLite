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

#ifndef _HTTP_SERVER_BINDING_H_
#define _HTTP_SERVER_BINDING_H_

#include <tide/tide.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <Poco/Thread.h>
#include <Poco/FileStream.h>

namespace ti
{
    class HTTPServerBinding : public StaticBoundObject
    {
    public:
        HTTPServerBinding(Host* host);
        virtual ~HTTPServerBinding();

    private:
        Host* host;
        TiObjectRef global;
        TiMethodRef callback;
        std::string ipaddress;
        int port;
        Poco::Thread *thread;
        Poco::Net::ServerSocket *socket;
        Poco::Net::HTTPServer *connection;
        
        static void Run(void*);
        
        void Bind(const ValueList& args, KValueRef result);
        void Close(const ValueList& args, KValueRef result);
        void IsClosed(const ValueList& args, KValueRef result);
        
        void Close();
        
    };
}

#endif
