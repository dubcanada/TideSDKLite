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

#ifndef _RUBY_HASH_H_
#define _RUBY_HASH_H_

namespace tide {

class KRubyHash : public TiObject {
public:
    KRubyHash(VALUE object);
    virtual ~KRubyHash();

    virtual void Set(const char *name, KValueRef value);
    virtual KValueRef Get(const char *name);
    virtual SharedStringList GetPropertyNames();
    virtual SharedString DisplayString(int);
    VALUE ToRuby();

    /*
     * Determine if the given Ruby object equals this one
     * by comparing these objects's identity e.g. equals?()
     *  @param other the object to test
     *  @returns true if objects have reference equality, false otherwise
     */
    virtual bool Equals(TiObjectRef);

private:
    VALUE hash;
    AutoPtr<KRubyObject> object;

};

}

#endif /* RUBY_BOUND_OBJECT_H_ */
