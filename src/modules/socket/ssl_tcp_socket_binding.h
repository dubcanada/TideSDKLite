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

#ifndef _SSL_TCP_SOCKET_H_
#define _SSL_TCP_SOCKET_H_


#include "tcp_socket_binding.h"
#include <boost/asio/ssl.hpp>


namespace ti
{
	class SecureTCPSocket
		: public Socket<boost::asio::ssl::stream<tcp::socket&> >
	{
	public:
		SecureTCPSocket(Host *host, TCPSocketBinding * tcp_socket_binding);
		virtual ~SecureTCPSocket();

	protected:

		virtual bool CompleteClose()
		{
			// Log  ->Debug("Closing socket to: %s:%d ", this->hostname.c_str(), this->port.c_str());
			if ((this->sock_state == SOCK_CONNECTED)
				|| (this->sock_state == SOCK_CONNECTING))
			{
				this->sock_state = SOCK_CLOSING;
				if (socket)
				{
					socket->lowest_layer().close();
				}
				this->sock_state = SOCK_CLOSED;
				return true;
			}
			return false;
		}

	private:
		KMethodRef onHandshake;

		void SetOnHandshake(const ValueList& args, KValueRef result);

		void async_handshake(const ValueList& args, KValueRef result);
		void registerAsyncHandshake();
		void handleAsyncHandshake(const boost::system::error_code& error);
		void on_handshake();


    boost::asio::ssl::context ctx;
		tcp::socket * tcp_socket;
		//ctx.set_verify_mode(boost::asio::ssl::context::verify_peer);
	};
}
#endif // _SSL_TCP_SOCKET_H_
