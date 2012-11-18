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

#ifndef _CLIPBOARD_H_
#define _CLIPBOARD_H_

#include <tide/tide.h>

namespace ti
{
    class Clipboard : public AccessorObject
    {
        public:
        Clipboard();
        ~Clipboard();

        enum DataType { TEXT, URI_LIST, IMAGE, UNKNOWN };
        void _GetData(const ValueList& args, ValueRef result);
        void _SetData(const ValueList& args, ValueRef result);
        void _ClearData(const ValueList& args, ValueRef result);
        void _HasData(const ValueList& args, ValueRef result);
        void _GetText(const ValueList& args, ValueRef result);
        void _SetText(const ValueList& args, ValueRef result);
        void _ClearText(const ValueList& args, ValueRef result);
        void _HasText(const ValueList& args, ValueRef result);
        bool HasData(DataType type);
        void ClearData(DataType type);

        std::string& GetText();
        void SetText(std::string& newText);
        bool HasText();
        void ClearText();
        BytesRef GetImage(std::string& mimeType);
        void SetImage(std::string& mimeType, BytesRef newImage);
        bool HasImage();
        void ClearImage();
        std::vector<std::string>& GetURIList();
        void SetURIList(std::vector<std::string>& newURIList);
        bool HasURIList();
        void ClearURIList();

        std::string& GetTextImpl();
        void SetTextImpl(std::string& newText);
        bool HasTextImpl();
        void ClearTextImpl();
        BytesRef GetImageImpl(std::string& mimeType);
        void SetImageImpl(std::string& mimeType, BytesRef image);
        bool HasImageImpl();
        void ClearImageImpl();
        std::vector<std::string>& GetURIListImpl();
        void SetURIListImpl(std::vector<std::string>& uriList);
        bool HasURIListImpl();
        void ClearURIListImpl();
    };
}
#endif
