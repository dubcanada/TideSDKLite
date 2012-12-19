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

#ifndef _SOCKET_EXCEPTIONS_H_
#define _SOCKET_EXCEPTIONS_H_

#include <exception>

class SocketException : public std::exception
{
public:
	virtual const char * what() const throw()
	{ return "Socket Exception"; }
};

class TCPSocketException : public SocketException
{
public:
	virtual const char * what() const throw()
	{ return "TCPSocket: Exception"; }
};

class TCPSocketConnectedException : public TCPSocketException
{
public:
	virtual const char * what() const throw()
	{ return "TCPSocket: either socket is connected or connecting."; }
};

class TCPSocketWriteException : public TCPSocketException
{
public:
	virtual const char * what() const throw()
	{ return "TCPSocket: socket is not open for write."; }
};

class TCPSocketReadNotOpenException : public TCPSocketException
{
public:
	virtual const char * what() const throw()
	{ return "TCPSocket: socket is not open for read."; }
};

class TCPSocketReadException : public TCPSocketException
{
public:
	virtual const char * what() const throw()
	{ return "TCPSocket: socket error while reading from socket."; }
};

#endif
