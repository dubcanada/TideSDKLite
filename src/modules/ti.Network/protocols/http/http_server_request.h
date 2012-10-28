/**
 * Appcelerator Titanium - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2009 Appcelerator, Inc. All Rights Reserved.
 */

#ifndef _HTTP_SERVER_REQUEST_H_
#define _HTTP_SERVER_REQUEST_H_

#include <kroll/kroll.h>
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
