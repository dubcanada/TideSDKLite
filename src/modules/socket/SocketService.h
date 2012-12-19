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

#ifndef _SOCKET_SERVICE_H_
#define _SOCKET_SERVICE_H_

#include <tide/tide.h>

// TODO: This is poco UnWindows.h's curse.... to be removed with poco
#ifdef UNICODE
#define CreateEvent  CreateEventW
#else
#define CreateEvent  CreateEventA
#endif // !UNICODE

#include <string>
#include <deque>

#include <boost/asio.hpp>
#include <boost/asio/detail/mutex.hpp>

using boost::asio::ip::tcp;

#include <boost/bind.hpp>
#include <boost/thread.hpp>

namespace ti
{
	class SocketService
	{
	public:
		static void initialize();
		static void uninitialize();
		static boost::asio::io_service* getIOService()
		{
			return io_service.get();
		}

	private:
		static std::auto_ptr<boost::asio::io_service> io_service;
		static std::auto_ptr<boost::asio::io_service::work> io_idlework;
		static std::auto_ptr<boost::thread> io_thread;
	};
}
#endif
