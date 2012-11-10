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

#ifndef _SOCKET_UTILS_H_
#define _SOCKET_UTILS_H_

#include "SocketService.h"
#include "SocketExceptions.h"


#include <boost/system/error_code.hpp>

#include <string>
#include <deque>

#define BUFFER_SIZE 1024   // choose a reasonable size to send back to JS

namespace ti
{
	template <class T>
	class Socket
		: public StaticBoundObject
	{
	public:
		Socket<T>(Host *host, const std::string & name);
		virtual ~Socket();

	protected:
		Host* ti_host;
		T *socket;

    boost::asio::detail::mutex write_mutex;
		std::deque<std::string> write_buffer;
		char read_data_buffer[BUFFER_SIZE + 1];
		bool non_blocking;
		enum SOCK_STATE_en { SOCK_CLOSED,
			SOCK_CONNECTING,
			SOCK_CONNECTED,
			SOCK_HANDSHAKE_IN_PROGRESS,
			SOCK_CLOSING
		} sock_state;

		void on_read(char * data, int size);
		void on_error(const std::string& error_text);
		void on_close();

		inline static tide::Logger* GetLogger()
		{
			return tide::Logger::Get("Socket.TCPSocket");
		}

		void registerHandleRead();
		virtual bool CompleteClose()=0;

		template<typename> friend class Socket;
		template <class T1>
		void copyHandlers(Socket<T1> *b)
		{
			this->onRead = b->onRead;
			this->onError = b->onError;
			this->onClose = b->onClose;
		}

	private:

		KMethodRef onRead;
		KMethodRef onError;
		KMethodRef onClose;

		void SetOnRead(const ValueList& args, KValueRef result)
		{
			this->onRead = args.at(0)->ToMethod();
		}

		void SetOnError(const ValueList& args, KValueRef result)
		{
			this->onError = args.at(0)->ToMethod();
		}

		void SetOnClose(const ValueList& args, KValueRef result)
		{
			this->onClose = args.at(0)->ToMethod();
		}
		void Write(const ValueList& args, KValueRef result);
		void Read(const ValueList& args, KValueRef result);
		void Close(const ValueList& args, KValueRef result);
		void IsClosed(const ValueList& args, KValueRef result);

		void registerHandleWrite();
		void handleWrite(const boost::system::error_code& error, std::size_t bytes_transferred);
		void writeAsync(const std::string &data);

		bool writeSync(const std::string &data);
		bool write(const std::string &data);
		std::string read();

		void handleRead(const boost::system::error_code& error, std::size_t bytes_transferred);
	};


	template <class T>
	Socket<T>::Socket(Host *host, const std::string & name)
		: StaticBoundObject(name.c_str()),
	ti_host(host),
	socket(NULL),
	non_blocking(false),
	sock_state(SOCK_CLOSED)
	{
		this->SetMethod("onRead",&Socket::SetOnRead);
		this->SetMethod("onError",&Socket::SetOnError);
		this->SetMethod("onClose",&Socket::SetOnClose);

		this->SetMethod("read",&Socket::Read);
		this->SetMethod("write",&Socket::Write);

		this->SetMethod("isClosed",&Socket::IsClosed);
		this->SetMethod("close",&Socket::Close);
	}

	template <class T>
	Socket<T>::~Socket()
	{
		if (socket)
		{
			delete socket;
			socket = NULL;
		}
	}


	template <class T>
	void Socket<T>::on_read(char * data, int size)
	{
		if(!this->onRead.isNull()) 
		{
			BytesRef bytes(new Bytes(data, size));
			ValueList args (Value::NewObject(bytes));
			RunOnMainThread(this->onRead, args, false);
			return;
		}
		GetLogger()->Warn("Socket::onRead: not read subscriber registered:  " + string(data));
	}

	template <class T>
	void Socket<T>::on_error(const std::string& error_text)
	{
		if(!this->onError.isNull()) 
		{
			ValueList args (Value::NewString(error_text.c_str()));
			RunOnMainThread(this->onError, args, false);
		}
	}

	template <class T>
	void Socket<T>::on_close()
	{
		if(!this->onClose.isNull()) 
		{
			ValueList args;
			RunOnMainThread(this->onClose, args, false);
		}
	}

	template <class T>
	void Socket<T>::Write(const ValueList& args, KValueRef result)
	{
		try
		{
			std::string data = args.at(0)->ToString();
			result->SetBool(this->write(data));
		}
		catch(SocketException &e)
		{
			throw ValueException::FromString(e.what());
		}
	}

	template <class T>
	void Socket<T>::Read(const ValueList& args, KValueRef result)
	{
		try
		{
			std::string data = this->read();
			BytesRef bytes(new Bytes(data.c_str(), data.size()));
			result->SetValue(Value::NewObject(bytes));
		}
		catch(SocketException &e)
		{
			throw ValueException::FromString(e.what());
		}
	}

	template <class T>
	void Socket<T>::Close(const ValueList& args, KValueRef result)
	{
		result->SetBool(this->CompleteClose());
	}

	template <class T>
	void Socket<T>::IsClosed(const ValueList& args, KValueRef result)
	{
		return result->SetBool(this->sock_state == SOCK_CLOSED);
	}

	

	template <class T>
	void Socket<T>::registerHandleWrite()
	{
    boost::asio::async_write(*socket,
			boost::asio::buffer(write_buffer.front().c_str(), write_buffer.front().size()),
			boost::bind(&Socket::handleWrite, this,
			boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

	}

	template <class T>
	void Socket<T>::handleWrite(const boost::system::error_code& error, std::size_t bytes_transferred)
	{
		if (error)
		{
			if (error == boost::asio::error::operation_aborted)
			{
				GetLogger()->Warn("Socket::handleWrite: operation aborted.");
				return;
			}
			this->on_error(error.message());
			return;
		}
    boost::asio::detail::mutex::scoped_lock lock(write_mutex);
		write_buffer.pop_front();
		if (!write_buffer.empty())
		{
			this->registerHandleWrite();
		}
	}

	template <class T>
	void Socket<T>::writeAsync(const std::string &data)
	{
    boost::asio::detail::mutex::scoped_lock lock(write_mutex);
		bool write_in_progress = !write_buffer.empty();
		write_buffer.push_back(data);
		if (!write_in_progress)
		{
			this->registerHandleWrite();
		}
	}

	template <class T>
	bool Socket<T>::writeSync(const std::string &data)
	{
		try
		{
      boost::asio::write(*socket, boost::asio::buffer(data.c_str(), data.size()));
		}
		catch(boost::system::system_error & e)
		{
			this->CompleteClose();
			this->on_error(e.what());
			return false;
		}
		return true;
	}

	template <class T>
	bool Socket<T>::write(const std::string &data)
	{
		if (this->sock_state != SOCK_CONNECTED)
		{
			throw TCPSocketWriteException();
		}
		if(non_blocking)
		{
			writeAsync(data);
			return true;
		}
		return writeSync(data);
	}

	template <class T>
	void Socket<T>::handleRead(const boost::system::error_code& error, std::size_t bytes_transferred)
	{
		if (error)
		{
			if (error == boost::asio::error::operation_aborted)
			{
				GetLogger()->Warn("Socket::handleRead: operation aborted.");
				return;
			}
			this->on_error(error.message());
			return;
		}
		this->on_read(read_data_buffer, bytes_transferred);
		this->registerHandleRead();
	}


	template <class T>
	void Socket<T>::registerHandleRead()
	{
    boost::asio::async_read(*socket,
			boost::asio::buffer(read_data_buffer, BUFFER_SIZE),
			boost::asio::transfer_at_least(1),
			boost::bind(&Socket::handleRead, this,
			boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}

	template <class T>
	std::string Socket<T>::read()
	{
		if (this->sock_state != SOCK_CONNECTED)
		{
			throw TCPSocketReadNotOpenException();
		}
		// TODO: implement sync read
		size_t size = 0;
		try
		{
			size = boost::asio::read(*socket, boost::asio::buffer(read_data_buffer, BUFFER_SIZE),
				boost::asio::transfer_at_least(1));
		}
		catch(boost::system::system_error & e)
		{
			this->CompleteClose();
			this->on_error(e.what());
			throw TCPSocketReadException();
		}
		if (size > 0)
		{
			return std::string(read_data_buffer, size);
		}
		return std::string("");
	}

}
#endif
