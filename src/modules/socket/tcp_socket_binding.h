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

#ifndef _TCP_SOCKET_BINDING_H_
#define _TCP_SOCKET_BINDING_H_


#include "Socket.h"
#include "SocketExceptions.h"


namespace ti
{
	class TCPSocketBinding
		: public Socket<tcp::socket>
	{
	public:
		TCPSocketBinding(Host *host,
			const std::string & hostname,
			const std::string& port);
		virtual ~TCPSocketBinding();

		tcp::socket * resetSocket();

	private:
		TiMethodRef onConnect;

		void SetOnConnect(const ValueList& args, ValueRef result);

		void Connect(const ValueList& args, ValueRef result);
		void ConnectNB(const ValueList& args, ValueRef result);
		void SetKeepAlives(const ValueList& args, ValueRef result);
		void SetKeepAliveTimes(const ValueList& args, ValueRef result);


		const std::string hostname;
		const std::string port;

		tcp::resolver resolver;

		bool connect(long timeout = 10);
		void connectNB();
		void on_connect();

		void setKeepAlive(bool keep_alives);
		//void setKeepAliveTimes(int inactivetime, int resendtime);

		tcp::resolver::iterator resolveHost();
		bool tryConnect(tcp::resolver::iterator endpoint_iterator);

		void registerHandleResolve();

		void handleResolve(const boost::system::error_code& error, tcp::resolver::iterator endpoint_iterator);
		void registerHandleConnect(tcp::resolver::iterator endpoint_iterator);
		void handleConnect(const boost::system::error_code& error, tcp::resolver::iterator endpoint_iterator);

		virtual bool CompleteClose()
		{
			// Log  ->Debug("Closing socket to: %s:%d ", this->hostname.c_str(), this->port.c_str());
			if ((this->sock_state == SOCK_CONNECTED)
				|| (this->sock_state == SOCK_CONNECTING))
			{
				this->sock_state = SOCK_CLOSING;
				if (socket)
				{
					socket->close();
				}
				this->sock_state = SOCK_CLOSED;
				return true;
			}
			return false;
		}

	};
}

#endif
