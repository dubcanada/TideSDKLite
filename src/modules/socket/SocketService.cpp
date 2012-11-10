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

#include "SocketService.h"

namespace ti
{
	std::auto_ptr<boost::asio::io_service> SocketService::io_service(new boost::asio::io_service());

	std::auto_ptr<boost::asio::io_service::work> SocketService::io_idlework(
		new boost::asio::io_service::work(*io_service));

	std::auto_ptr<boost::thread> SocketService::io_thread(NULL);

	void SocketService::initialize()
	{
		io_thread.reset(new boost::thread(
			boost::bind(&boost::asio::io_service::run, SocketService::io_service.get())));
	}
	
	void SocketService::uninitialize()
	{
		io_service->stop();
		io_thread->join();
		io_idlework.reset();
		io_thread.reset();
		io_service.reset();
	}
}
