/**
 * Appcelerator Titanium - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2009 Appcelerator, Inc. All Rights Reserved.
 */

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
