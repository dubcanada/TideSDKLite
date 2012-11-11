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

#ifndef _HTTP_SERVER_REQUEST_H_
#define _HTTP_SERVER_REQUEST_H_

#include <tide/tide.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

namespace ti
{
    class HttpServerRequest : public StaticBoundObject
    {
    public:
        HttpServerRequest(Poco::Net::HTTPServerRequest& request);
        virtual ~HttpServerRequest();

    private:
        Poco::Net::HTTPServerRequest& request;

        void GetMethod(const ValueList& args, KValueRef result);
        void GetVersion(const ValueList& args, KValueRef result);
        void GetURI(const ValueList& args, KValueRef result);
        void GetContentType(const ValueList& args, KValueRef result);
        void GetContentLength(const ValueList& args, KValueRef result);
        void GetHeader(const ValueList& args, KValueRef result);
        void GetHeaders(const ValueList& args, KValueRef result);
        void HasHeader(const ValueList& args, KValueRef result);
        void Read(const ValueList& args, KValueRef result);
    };
}

#endif
