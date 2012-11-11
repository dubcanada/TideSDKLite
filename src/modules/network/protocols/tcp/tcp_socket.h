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

#ifndef _TINET_TCP_SOCKET_H_
#define _TINET_TCP_SOCKET_H_

#include <queue>
#include <string>

#include <Poco/Net/StreamSocket.h>
#include <Poco/Thread.h>
#include <Poco/Mutex.h>

#include <tide/tide.h>

namespace ti
{
    class TCPSocket : public KEventObject
    {
    public:
        TCPSocket(std::string& host, int port);
        virtual ~TCPSocket();

        void Connect();
        bool Close();
        void Write(BytesRef data);
        void SetKeepAlive(bool enable);
        void SetTimeout(long milliseconds);

        void ReadThread();
        void WriteThread();

    private:
        void HandleError(Poco::Exception& e);

        void _Connect(const ValueList& args, KValueRef result);
        void _SetTimeout(const ValueList& args, KValueRef result);
        void _Close(const ValueList& args, KValueRef result);
        void _IsClosed(const ValueList& args, KValueRef result);
        void _Write(const ValueList& args, KValueRef result);
        void _OnRead(const ValueList& args, KValueRef result);
        void _OnReadComplete(const ValueList& args, KValueRef result);
        void _OnError(const ValueList& args, KValueRef result);
        void _OnTimeout(const ValueList& args, KValueRef result);

        Poco::Net::SocketAddress address;
        Poco::Net::StreamSocket socket;
        enum { CONNECTING, READONLY, WRITEONLY, DUPLEX, CLOSING, CLOSED } state;
        Poco::Thread readThread;
        Poco::RunnableAdapter<TCPSocket> reader, writer;
        std::queue<BytesRef> writeQueue;
        Poco::FastMutex mutex;
    };
}

#endif
