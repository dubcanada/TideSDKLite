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

#ifndef _TCP_SERVER_CONNECTION_BINDING_H_
#define _TCP_SERVER_CONNECTION_BINDING_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketReactor.h>
#include <Poco/Net/SocketAcceptor.h>
#include <Poco/Net/SocketNotification.h>
#include <Poco/NObserver.h>
#include <Poco/RunnableAdapter.h>
#include <queue>

namespace ti
{
    class TCPServerConnectionBinding : public StaticBoundObject
    {
    public:
        TCPServerConnectionBinding(Poco::Net::StreamSocket& s, Poco::Net::SocketReactor & reactor_);
        virtual ~TCPServerConnectionBinding();

    private:
        enum
        {
            BUFFER_SIZE = 1024
        };
        Poco::Net::StreamSocket socket;
        Poco::Net::SocketReactor& reactor;
        bool closed;
        TiMethodRef onRead;
        TiMethodRef onWrite;
        TiMethodRef onError;
        TiMethodRef onReadComplete;
        std::queue<BytesRef> sendData;
        Poco::Mutex sendDataMutex;
        size_t currentSendDataOffset;
        bool readStarted;
        bool writeReadyHandlerInstalled;

        void onReadable (const Poco::AutoPtr<Poco::Net::ReadableNotification>&);
        void onShutdown (const Poco::AutoPtr<Poco::Net::ShutdownNotification>&);
        void onWritable (const Poco::AutoPtr<Poco::Net::WritableNotification>&);
        void onErrored(const Poco::AutoPtr<Poco::Net::ErrorNotification>&);

        void Write(const ValueList& args, ValueRef result);
        void Close(const ValueList& args, ValueRef result);
        void IsClosed(const ValueList& args, ValueRef result);
        void SetOnRead(const ValueList& args, ValueRef result);
        void SetOnWrite(const ValueList& args, ValueRef result);
        void SetOnError(const ValueList& args, ValueRef result);
        void SetOnReadComplete(const ValueList& args, ValueRef result);

    };
    
}

#endif
