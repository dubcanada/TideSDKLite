/**
 * This file has been modified from its orginal sources.
 *
 * Copyright (c) 2012 Software in the Public Interest Inc (SPI)
 * Copyright (c) 2012 Mital Vora
 * Copyright (c) 2012 Steven Verbeek
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
 */

#include <sstream>

#include "tcp_socket_binding.h"
#include "ssl_tcp_socket_binding.h"
#include "socket_binding.h"

namespace ti
{
	SocketBinding::SocketBinding(Host* host) :
		AccessorObject("Socket"),
		host(host),
		global(host->GetGlobalObject())
	{
		this->SetMethod("createTCPSocket",&SocketBinding::_CreateTCPSocket);
		this->SetMethod("getSSLTCPSocket",&SocketBinding::_getSSLTCPSocket);
	}

	SocketBinding::~SocketBinding()
	{
	}

	void SocketBinding::_CreateTCPSocket(const ValueList& args, ValueRef result)
	{
		args.VerifyException("createTCPSocket", "ss");
		result->SetObject(new TCPSocketBinding(host, args.GetString(0), args.GetString(1)));
	}

	void SocketBinding::_getSSLTCPSocket(const ValueList& args, ValueRef result)
	{
		TCPSocketBinding * socket = args.GetObject(0).cast<TCPSocketBinding>();
		result->SetObject(new SecureTCPSocket(host, socket));
	}

	Host* SocketBinding::GetHost()
	{
		return this->host;
	}
}
