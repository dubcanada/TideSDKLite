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

#ifndef _KR_K_ACCESSOR_H_
#define _KR_K_ACCESSOR_H_

namespace tide
{
    typedef std::map<std::string, KMethodRef> AccessorMap;

    class KROLL_API KAccessor
    {
    protected:
        KAccessor() {}

        inline void RecordAccessor(const std::string& name, KValueRef value)
        {
            if (name.find("set") == 0)
                DoMap(name.substr(3), value, setterMap);

            else if (name.find("get") == 0)
                DoMap(name.substr(3), value, getterMap);

            else if (name.find("is") == 0)
                DoMap(name.substr(2), value, getterMap);
        }

        bool HasGetterFor(std::string name)
        {
            return !FindAccessor(name, getterMap).isNull();
        }

        KValueRef UseGetter(std::string name, KValueRef existingValue)
        {
            if (!existingValue->IsUndefined())
                return existingValue;

            KMethodRef getter = FindAccessor(name, getterMap);
            if (getter.isNull())
                return existingValue;

            return getter->Call();
        }

        bool UseSetter(std::string name, KValueRef newValue, KValueRef existingValue)
        {
            RecordAccessor(name, newValue);

            // If a property already exists on this object with the given
            // name, just set the property and don't call the setter.
            if (!existingValue->IsUndefined())
                return false;

            KMethodRef setter = FindAccessor(name, setterMap);
            if (setter.isNull())
                return false;

            setter->Call(newValue);
            return true;
        }

    private:
        inline void DoMap(std::string name, KValueRef accessor, AccessorMap& map)
        {
            // Lower-case the name so that all comparisons are case-insensitive.
            std::transform(name.begin(), name.end(), name.begin(), tolower);

            // Null old mapping if it exists. This is so that if an accessor
            // is replaced with a non-accessor, we don't keep a copy of it around.
            if (map.find(name) != map.end())
                map[name] = 0;

            if (!accessor->IsMethod())
                return;

            map[name] = accessor->ToMethod();
        }

        inline KMethodRef FindAccessor(std::string& name, AccessorMap& map)
        {
            // Lower-case the name so that all comparisons are case-insensitive.
            std::transform(name.begin(), name.end(), name.begin(), tolower);

            if (map.find(name) == map.end())
                return 0;

            return map[name];
        }

        DISALLOW_EVIL_CONSTRUCTORS(KAccessor);
        AccessorMap getterMap;
        AccessorMap setterMap;
    };
}

#endif
