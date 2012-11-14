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

#include "http_server_request.h"
#include "http_server_response.h"
#include "http_server_request_factory.h"

namespace ti
{
    class HTTPRequestHandler : public Poco::Net::HTTPRequestHandler {
        public:
            HTTPRequestHandler(KMethodRef callback)
                : m_callback(callback)
            {
            }

            virtual void handleRequest(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&);

        private:
            KMethodRef m_callback;
    };

    void HTTPRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        // XXX(Josh): The request and response object's lifetime is limited to this functions call.
        // If the developer should keep a reference to these around past the callback lifetime and then
        // attempts to access it may result in a crash!
        ValueList args;
        args.push_back(Value::NewObject(new HttpServerRequest(request)));
        args.push_back(Value::NewObject(new HttpServerResponse(response)));
        RunOnMainThread(m_callback, args);
    }

    HttpServerRequestFactory::HttpServerRequestFactory(Host *host, KMethodRef callback) :
        host(host),
        callback(callback)
    {
    }

    HttpServerRequestFactory::~HttpServerRequestFactory()
    {
    }

    Poco::Net::HTTPRequestHandler* HttpServerRequestFactory::createRequestHandler(
            const Poco::Net::HTTPServerRequest& request)
    {
        return new HTTPRequestHandler(callback);
    }
}
