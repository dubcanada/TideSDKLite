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

#ifndef _SOCKET_MODULE_H_
#define _SOCKET_MODULE_H_

#include "socket_binding.h"

#if defined(OS_OSX) || defined(OS_LINUX)
#define EXPORT __attribute__((visibility("default")))
#define TIDE_SOCKET_API EXPORT
#elif defined(OS_WIN32)
# ifdef TIDE_SOCKET_API_EXPORT
#  define TIDE_SOCKET_API __declspec(dllexport)
# else
#  define TIDE_SOCKET_API __declspec(dllimport)
# endif
# define EXPORT __declspec(dllexport)
#endif


namespace ti 
{
	class TIDE_SOCKET_API SocketModule : public tide::Module
	{
		TIDE_MODULE_CLASS(SocketModule)

	public:
		static std::string GetRootCertPath();

	private:
		AutoPtr<SocketBinding> socketBinding;
	};

}
#endif
