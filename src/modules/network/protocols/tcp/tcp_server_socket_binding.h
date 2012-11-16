/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
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
***
* Copyright (c) 2008-2012 Appcelerator Inc.
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
**/

#ifndef _TCP_SERVER_SOCKET_BINDING_H_
#define _TCP_SERVER_SOCKET_BINDING_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketReactor.h>
#include <Poco/Net/SocketAcceptor.h>
#include <Poco/Net/SocketNotification.h>
#include <Poco/NObserver.h>
#include <Poco/RunnableAdapter.h>
#include "tcp_server_connection_binding.h"

/**
 *   Ti.Network.createTCPServer(function(c)
 *      {
 *        c.onread = function(data){
 *
 *      };
 *   }).listen(1000);
 *
 */
namespace ti
{
    class TCPServerSocketConnector
    {
    public:
        TCPServerSocketConnector(TiMethodRef callback,Poco::Net::ServerSocket& socket,Poco::Net::SocketReactor& reactor);
        virtual ~TCPServerSocketConnector();
        void onAccept(Poco::Net::ReadableNotification* pNotification);
    private:
        TiMethodRef callback;
        Poco::Net::ServerSocket& socket;
        Poco::Net::SocketReactor& reactor;
    };

    class TCPServerSocketBinding : public StaticBoundObject
    {
    public:
        TCPServerSocketBinding(Host *ti_host, TiMethodRef callback);
        virtual ~TCPServerSocketBinding();
    private:
        enum
        {
            BUFFER_SIZE = 1024
        };
        TiMethodRef onCreate;
        Poco::Net::ServerSocket* socket;
        Poco::Net::SocketReactor reactor;
        TCPServerSocketConnector* acceptor;
        Poco::Thread listenThread;
        Poco::RunnableAdapter<TCPServerSocketBinding>* listenAdapter;
        bool listening;
        
        void ListenThread();
        void Listen(const ValueList& args, KValueRef result);
        void Close(const ValueList& args, KValueRef result);
    };
    
}

#endif
