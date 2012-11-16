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

#include "javascript_module.h"

namespace tide
{
    KKJSObject::KKJSObject(JSContextRef context, JSObjectRef jsobject) :
        TiObject("JavaScript.KKJSObject"),
        context(NULL),
        jsobject(jsobject)
    {
        /* KJS methods run in the global context that they originated from
        * this seems to prevent nasty crashes from trying to access invalid
        * contexts later. Global contexts need to be registered by all modules
        * that use a KJS context. */
        JSObjectRef globalObject = JSContextGetGlobalObject(context);
        JSGlobalContextRef globalContext = JSUtil::GetGlobalContext(globalObject);

        // This context hasn't been registered. Something has gone pretty
        // terribly wrong and TideSDK will likely crash soon. Nonetheless, keep
        // the user up-to-date to keep their hopes up.
        if (globalContext == NULL)
            std::cerr << "Could not locate global context for a KJS method."  <<
            " One of the modules is misbehaving." << std::endl;

        this->context = globalContext;

        JSUtil::ProtectGlobalContext(this->context);
        JSValueProtect(this->context, this->jsobject);
    }

    KKJSObject::~KKJSObject()
    {
        JSValueUnprotect(this->context, this->jsobject);
        JSUtil::UnprotectGlobalContext(this->context);
    }

    JSObjectRef KKJSObject::GetJSObject()
    {
        return this->jsobject;
    }

    KValueRef KKJSObject::Get(const char *name)
    {
        JSStringRef jsName = JSStringCreateWithUTF8CString(name);
        JSValueRef exception = NULL;
        JSValueRef jsValue = JSObjectGetProperty(this->context, this->jsobject, jsName, NULL);
        JSStringRelease(jsName);

        if (exception != NULL) //exception thrown
        {
            KValueRef tv_exp = JSUtil::ToTiValue(exception, this->context, NULL);
            throw ValueException(tv_exp);
        }

        KValueRef kvalue = JSUtil::ToTiValue(jsValue, this->context, this->jsobject);
        return kvalue;
    }

    void KKJSObject::Set(const char *name, KValueRef value)
    {
        JSValueRef jsValue = JSUtil::ToJSValue(value, this->context);
        JSStringRef jsName = JSStringCreateWithUTF8CString(name);

        JSValueRef exception = NULL;
        JSObjectSetProperty(this->context, this->jsobject, jsName, jsValue,
            0, &exception);
        JSStringRelease(jsName);

        if (exception != NULL) // An exception was thrown.
        {
            KValueRef exceptionValue = JSUtil::ToTiValue(exception, this->context, NULL);
            throw ValueException(exceptionValue);
        }
    }

    bool KKJSObject::Equals(TiObjectRef other)
    {
        AutoPtr<KKJSObject> kjsOther = other.cast<KKJSObject>();
        if (kjsOther.isNull())
            return false;

        if (!kjsOther->SameContextGroup(this->context))
            return false;

        return JSValueIsStrictEqual(
            this->context, this->jsobject, kjsOther->GetJSObject());
    }

    SharedStringList KKJSObject::GetPropertyNames()
    {
        SharedStringList list(new StringList());

        JSPropertyNameArrayRef names =
            JSObjectCopyPropertyNames(this->context, this->jsobject);
        JSPropertyNameArrayRetain(names);

        size_t count = JSPropertyNameArrayGetCount(names);
        for (size_t i = 0; i < count; i++)
        {
            JSStringRef jsName = JSPropertyNameArrayGetNameAtIndex(names, i);
            list->push_back(new std::string(JSUtil::ToChars(jsName)));
        }

        JSPropertyNameArrayRelease(names);
        return list;
    }

    bool KKJSObject::HasProperty(const char* name)
    {
        JSStringRef jsName = JSStringCreateWithUTF8CString(name);
        bool hasProperty = JSObjectHasProperty(context, jsobject, jsName);
        JSStringRelease(jsName);
        return hasProperty;
    }

    bool KKJSObject::SameContextGroup(JSContextRef contextIn)
    {
        return JSContextGetGroup(this->context) == JSContextGetGroup(contextIn);
    }
}
