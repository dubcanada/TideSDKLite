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

#ifndef _CODEC_BINDING_H_
#define _CODEC_BINDING_H_

#include <kroll/kroll.h>

#include <Poco/Zip/Zip.h>
#include <Poco/Zip/Compress.h>
#include <Poco/Zip/Decompress.h>
#include <Poco/Path.h>

namespace ti
{
    class CodecBinding : public StaticBoundObject
    {
    public:
        CodecBinding(KObjectRef);
    protected:
        virtual ~CodecBinding();
    private:
        KObjectRef global;

        void EncodeBase64(const ValueList& args, KValueRef result);
        void DecodeBase64(const ValueList& args, KValueRef result);
        void DigestToHex(const ValueList& args, KValueRef result);
        void DigestHMACToHex(const ValueList& args, KValueRef result);
        void EncodeHexBinary(const ValueList& args, KValueRef result);
        void DecodeHexBinary(const ValueList& args, KValueRef result);
        void Checksum(const ValueList& args, KValueRef result);
        void CreateZip(const ValueList& args, KValueRef result);
        void ExtractZip(const ValueList& args, KValueRef result);
        
        static KValueRef CreateZipAsync(const ValueList& args);
        static KValueRef ExtractZipAsync(const ValueList& args);
    };
}

#endif