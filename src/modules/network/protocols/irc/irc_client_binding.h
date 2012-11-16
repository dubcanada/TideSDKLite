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

#ifndef _IRC_CLIENT_BINDING_H_
#define _IRC_CLIENT_BINDING_H_

#include <tide/tide.h>
#include <Poco/Thread.h>
#ifdef OS_LINUX
#include <unistd.h>
#endif
#include "IRC.h"

namespace ti
{
    class IRCClientBinding : public StaticBoundObject
    {
    public:
        IRCClientBinding(Host*);
        virtual ~IRCClientBinding();
    private:
        Host* host;
        TiObjectRef global;
        IRC irc;
        TiMethodRef callback;
        Poco::Thread *thread;
        
        static void Run(void*);
        static int Callback(char *cmd, char* params, irc_reply_data* data, void* conn, void* pd);
        
        
        void Connect(const ValueList& args, KValueRef result);
        void Disconnect(const ValueList& args, KValueRef result);
        void Send(const ValueList& args, KValueRef result);
        void SetNick(const ValueList& args, KValueRef result);
        void GetNick(const ValueList& args, KValueRef result);
        void Join(const ValueList& args, KValueRef result);
        void Unjoin(const ValueList& args, KValueRef result);
        void IsOp(const ValueList& args, KValueRef result);
        void IsVoice(const ValueList& args, KValueRef result);
        void GetUsers(const ValueList& args, KValueRef result);

    };
}

#endif
