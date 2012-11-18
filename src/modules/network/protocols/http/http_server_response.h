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

#ifndef _HTTP_SERVER_RESPONSE_H_
#define _HTTP_SERVER_RESPONSE_H_

#include <tide/tide.h>
#include <Poco/Net/HTTPServerResponse.h>

namespace ti
{
    class HttpServerResponse : public StaticBoundObject
    {
    public:
        HttpServerResponse(Poco::Net::HTTPServerResponse &response);
        virtual ~HttpServerResponse();
        
    private:
        Poco::Net::HTTPServerResponse& response;

        void SetStatus(const ValueList& args, ValueRef result);
        void SetReason(const ValueList& args, ValueRef result);
        void SetStatusAndReason(const ValueList& args, ValueRef result);
        void SetContentType(const ValueList& args, ValueRef result);
        void SetContentLength(const ValueList& args, ValueRef result);
        void AddCookie(const ValueList& args, ValueRef result);
        void SetHeader(const ValueList& args, ValueRef result);
        void Write(const ValueList& args, ValueRef result);

    };
}

#endif
