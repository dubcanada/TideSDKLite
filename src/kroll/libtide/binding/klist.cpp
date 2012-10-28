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

#include "../kroll.h"
#include <sstream>
#include <cmath>
#include <climits>

namespace kroll
{

    void KList::ResizeTo(unsigned int size)
    {
        if (size < 0 || size == this->Size())
        {
            return;
        }

        while (size < this->Size())
        {
            this->Remove(this->Size() - 1);
        }

        while (size > this->Size())
        {
            this->Append(Value::Undefined);
        }
    }

    SharedString KList::DisplayString(int levels)
    {
        std::ostringstream oss;
        oss << "(" << this->GetType() << ")" << " [";
        for (unsigned int i = 0; i < this->Size(); i++)
        {
            KValueRef list_val = this->At(i);
            SharedString list_str = list_val->DisplayString(levels-1);
            oss << " " << *list_str << ",";
        }
        //int before_last_comma = oss.tellp() - 1;
        //oss.seekp(before_last_comma);
        oss << " ]";

        return new std::string(oss.str());
    }

    /*static*/
    std::string KList::IntToChars(unsigned int value)
    {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }

    /*static*/
    bool KList::IsInt(const std::string& name)
    {
        for (size_t i = 0; i < strlen(name.c_str()); i++)
        {
            if (!isdigit(name[i]))
                return false;
        }
        return true;
    }

    /*static*/
    unsigned int KList::ToIndex(const std::string& str)
    {
        char* endPointer = 0;
        unsigned long result = strtoul(str.c_str(), &endPointer, 10);

        if ((endPointer == str.c_str() && result == 0) || result > UINT_MAX)
        {
            throw ValueException::FromFormat("Could not convert %s to an unsigned int",
                str.c_str());
        }

        return result;
    }

    /*static*/
    KListRef KList::Unwrap(KListRef o)
    {
        AutoPtr<ProfiledBoundList> plist = o.cast<ProfiledBoundList>();
        if (plist.isNull())
        {
            return o;
        }
        else
        {
            return plist->GetDelegate();
        }
    }
}