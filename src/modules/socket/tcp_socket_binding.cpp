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

#include "tcp_socket_binding.h"

namespace ti
{
	TCPSocketBinding::TCPSocketBinding(Host* host, const std::string& hostname, const std::string& port) :
// TODO: See if this breaks windows and linux, if it doesn't remove this.
#ifdef OS_OSX
		Socket<tcp::socket>(host, string("Socket.TCPSocketBinding")),
#else
        Socket(host, string("Socket.TCPSocketBinding")),
#endif
		onConnect(0),
		hostname(hostname),
		port(port),
		resolver(*SocketService::getIOService())
	{
		this->socket = new tcp::socket(*SocketService::getIOService());
		this->SetMethod("connect",&TCPSocketBinding::Connect);
		this->SetMethod("connectNB",&TCPSocketBinding::ConnectNB);


		this->SetMethod("onConnect",&TCPSocketBinding::SetOnConnect);

		// Enables/disables keepalives.
		this->SetMethod("setDisconnectionNotifications", &TCPSocketBinding::SetKeepAlives);

		// Sets the timeouts for the keepalive times, should be called before connecting the socket.
		this->SetMethod("setDisconnectionNotificationTime", &TCPSocketBinding::SetKeepAliveTimes);
	}

	TCPSocketBinding::~TCPSocketBinding()
	{
		this->CompleteClose();
	}

	tcp::socket * TCPSocketBinding::resetSocket()
	{
		tcp::socket * temp = this->socket;
		this->socket->cancel();
		this->socket = NULL;
		return temp;
	}


	void TCPSocketBinding::SetOnConnect(const ValueList& args, KValueRef result)
	{
		this->onConnect = args.at(0)->ToMethod();
	}


	void TCPSocketBinding::SetKeepAlives(const ValueList& args, KValueRef result)
	{
		// TODO: verify args
		this->setKeepAlive(args.at(0)->ToBool());
	}

	void TCPSocketBinding::SetKeepAliveTimes(const ValueList& args, KValueRef result) 
	{
		// TODO:
		//if(this->sock_state != SOCK_CLOSED)
		//	throw ValueException::FromString("You can only set the keep-alive times before connecting the socket");

		if(args.size() > 1 && args.at(0)->IsInt() && args.at(1)->IsInt()) 
		{
			//int inactivetime = args.at(0)->ToInt();
			//int resendtime = args.at(1)->ToInt();
			//this->setKeepAliveTimes(inactivetime, resendtime);
		}
		else 
		{
			throw ValueException::FromString("usage: setDisconnectionNotificationTime(int firstCheck, int subsequentChecks) -> If 9 subsequent checks fail the connection is considered lost");
		}
	}

	void TCPSocketBinding::Connect(const ValueList& args, KValueRef result)
	{
		try
		{
			long timeout = (args.size() > 0 && args.at(0)->IsInt()) ? args.at(0)->ToInt() : 10;
			GetLogger()->Debug("Connecting Blocking.");
			this->connect(timeout);
		}
		catch(SocketException & e)
		{
			throw ValueException::FromString(e.what());
		}
	}


	void TCPSocketBinding::ConnectNB(const ValueList& args, KValueRef result)
	{
		try
		{
			GetLogger()->Debug("Connecting non Blocking.");
			this->connectNB();
		}
		catch(SocketException &e)
		{
			throw ValueException::FromString(e.what());
		}
	}

	void TCPSocketBinding::on_connect()
	{
		if(!this->onConnect.isNull()) 
		{
			ValueList args;
			RunOnMainThread(this->onConnect, args, false);
		}
	}


	void TCPSocketBinding::setKeepAlive(bool keep_alives)
	{
    boost::asio::socket_base::keep_alive option(keep_alives);
		if (socket)
		{
			socket->set_option(option);
		}
	}

	//void TCPSocketBinding::setKeepAliveTimes(int inactivetime, int resendtime) 
	//{
	//	if(this->sock_state != SOCK_CLOSED) 
	//	{
	//		throw TCPSocketConnectedException();
	//	}
	//	//this->inactivetime = inactivetime;
	//	//this->resendtime = resendtime;
	//}

	tcp::resolver::iterator TCPSocketBinding::resolveHost()
	{
		tcp::resolver::query query(hostname, port);
		return resolver.resolve(query);
	}

	bool TCPSocketBinding::tryConnect(tcp::resolver::iterator endpoint_iterator)
	{
		try
		{
			if (socket)
			{
				socket->connect(*endpoint_iterator);
			}
		}
		catch(boost::system::system_error & e)
		{
			this->CompleteClose();
			return false;
		}
		return true;
	}

	bool TCPSocketBinding::connect(long timeout)
	{
		if(this->sock_state != SOCK_CLOSED)
		{
			throw TCPSocketConnectedException();
		}
		non_blocking = false;
		this->sock_state = SOCK_CONNECTING;

		//TODO: implement timeout for connect
		tcp::resolver::iterator endpoint_iterator;
		try
		{
			endpoint_iterator = this->resolveHost();
		}
		catch(boost::system::system_error & e)
		{
			this->on_error(e.what());
			this->sock_state = SOCK_CLOSED;
			return false;
		}

		bool ret;
		while(endpoint_iterator != tcp::resolver::iterator())
		{
			ret = tryConnect(endpoint_iterator);
			if (ret)
				break;
			endpoint_iterator = ++endpoint_iterator;
		}
		this->sock_state = (ret)?SOCK_CONNECTED:SOCK_CLOSED;
		return ret;
	}


	void TCPSocketBinding::connectNB()
	{
		if(this->sock_state != SOCK_CLOSED)
		{
			throw TCPSocketConnectedException();
		}
		non_blocking = true;
		this->sock_state = SOCK_CONNECTING;
		this->registerHandleResolve();
	}

	void TCPSocketBinding::registerHandleResolve()
	{
		tcp::resolver::query query(hostname, port);
		resolver.async_resolve(query,
			boost::bind(&TCPSocketBinding::handleResolve, this,
			boost::asio::placeholders::error, boost::asio::placeholders::iterator));
	}

	void TCPSocketBinding::handleResolve(const boost::system::error_code& error, tcp::resolver::iterator endpoint_iterator)
	{
		if (error)
		{
			if (error == boost::asio::error::operation_aborted)
			{
				GetLogger()->Warn("Socket::handleResolve: operation aborted.");
				return;
			}
			this->on_error(error.message());
			return;
		}
		registerHandleConnect(endpoint_iterator);
	}

	void TCPSocketBinding::registerHandleConnect(tcp::resolver::iterator endpoint_iterator)
	{
		if (endpoint_iterator != tcp::resolver::iterator() && socket)
		{
			socket->async_connect(*endpoint_iterator,
				boost::bind(&TCPSocketBinding::handleConnect, this,
				boost::asio::placeholders::error, ++endpoint_iterator));
			return;
		}
		this->on_error("TCPSocketBinding Host resolution Error");
	}

	void TCPSocketBinding::handleConnect(const boost::system::error_code& error, tcp::resolver::iterator endpoint_iterator)
	{
		if (!error)
		{
			this->sock_state = SOCK_CONNECTED;
			this->on_connect();
			this->registerHandleRead();
			return;
		}

		this->CompleteClose();
		if (endpoint_iterator != tcp::resolver::iterator())
		{
			this->registerHandleConnect(endpoint_iterator);
			return;
		}

		if (error == boost::asio::error::operation_aborted)
		{
			GetLogger()->Warn("Socket::handleWrite: operation aborted.");
			return;
		}

		this->on_error(error.message());
	}
}
