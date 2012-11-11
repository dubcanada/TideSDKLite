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

#include "ssl_tcp_socket_binding.h"

namespace ti
{
	SecureTCPSocket::SecureTCPSocket(Host *host, TCPSocketBinding * tcp_socket_binding)
// TODO: See if this breaks windows and linux, if it doesn't remove this.
#ifdef OS_OSX
        : Socket<boost::asio::ssl::stream<tcp::socket&> >(host, string("Socket.SecureTCPSocket")),
#else
        : Socket(host, string("Socket.SecureTCPSocket")),
#endif
		ctx(*SocketService::getIOService(), boost::asio::ssl::context::sslv23),
		tcp_socket(NULL)
	{
		if(!tcp_socket_binding)
		{
			// TODO: throw errors
			return;
		}

		tcp_socket = tcp_socket_binding->resetSocket();
		this->copyHandlers(tcp_socket_binding);

		try
		{
			ctx.set_verify_mode(boost::asio::ssl::context::verify_none);
			ctx.use_certificate_file(FileUtils::Join(
				host->GetApplication()->getRuntimePath().c_str(),
				"rootcert.pem", 0), boost::asio::ssl::context::pem);
			socket = new boost::asio::ssl::stream<tcp::socket&>(*tcp_socket, ctx);
		}
		catch (std::exception &e)
		{
			string error("SecureTCPSocket::: caught exception.");
			error += e.what();
			GetLogger()->Error(error);
		}
		this->SetMethod("onHandshake",&SecureTCPSocket::SetOnHandshake);
		this->SetMethod("async_handshake",&SecureTCPSocket::async_handshake);

	}
	SecureTCPSocket::~SecureTCPSocket()
	{
		this->CompleteClose();
		if (this->tcp_socket)
		{
			delete this->tcp_socket;
			this->tcp_socket = NULL;
		}
	}

	void SecureTCPSocket::SetOnHandshake(const ValueList& args, KValueRef result)
	{
		this->onHandshake = args.at(0)->ToMethod();
	}

	void SecureTCPSocket::async_handshake(const ValueList& args, KValueRef result)
	{
		this->registerAsyncHandshake();
	}

	void SecureTCPSocket::registerAsyncHandshake()
	{
		this->sock_state = SOCK_HANDSHAKE_IN_PROGRESS;
		socket->async_handshake(boost::asio::ssl::stream_base::client,
			boost::bind(&SecureTCPSocket::handleAsyncHandshake,
			this, boost::asio::placeholders::error));
	}

	void SecureTCPSocket::handleAsyncHandshake(const boost::system::error_code& error)
	{
		if (error)
		{
			if (error == boost::asio::error::operation_aborted)
			{
				this->sock_state = SOCK_CONNECTED;
				GetLogger()->Warn("SecureTCPSocket::handleAsyncHandshake: operation aborted.");
				return;
			}
			this->on_error(error.message());
			return;
		}
		this->sock_state = SOCK_CONNECTED;
		this->on_handshake();
		this->registerHandleRead();
	}

	void SecureTCPSocket::on_handshake()
	{
		if(!this->onHandshake.isNull())
		{
			ValueList args;
			RunOnMainThread(this->onHandshake, args, false);
			return;
		}
		GetLogger()->Warn("SecureTCPSocket::onHandshakeComplete: callback not registererd.");
	}
}
