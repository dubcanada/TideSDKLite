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

#ifndef _DATABASE_RESULTSET_BINDING_H_
#define _DATABASE_RESULTSET_BINDING_H_

#include <kroll/kroll.h>
#include <Poco/Data/RecordSet.h>

namespace ti
{
    /**
     * Binding for the ResultSet (or in Poco SQLite the RecordSet)
     *
     */
    class ResultSetBinding : public StaticBoundObject
    {
    public:
        ResultSetBinding();
        ResultSetBinding(Poco::Data::RecordSet& rs);

    protected:
        virtual ~ResultSetBinding();

    private:
        SharedPtr<Poco::Data::RecordSet> rs;
        bool eof;
        
        void Bind();
        void TransformValue(size_t index, KValueRef result);
        

        void IsValidRow(const ValueList& args, KValueRef result);
        void Next(const ValueList& args, KValueRef result);
        void Close(const ValueList& args, KValueRef result);
        void RowCount(const ValueList& args, KValueRef result);
        void FieldCount(const ValueList& args, KValueRef result);
        void FieldName(const ValueList& args, KValueRef result);
        void Field(const ValueList& args, KValueRef result);
        void FieldByName(const ValueList& args, KValueRef result);
    };
}

#endif