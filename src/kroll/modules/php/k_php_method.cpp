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

#include "php_module.h"

namespace kroll {

    KPHPMethod::KPHPMethod(zval* object, const char* methodName) :
        KMethod("PHP.KPHPMethod"),
        object(object),
        methodName(strdup(methodName)),
        globalObject(PHPUtils::GetCurrentGlobalObject())
    {
        zval_addref_p(object);
    }

    KPHPMethod::~KPHPMethod()
    {
        if (object)
        {
            zval_delref_p(object);
        }
        
        free(methodName);
    }

    KValueRef KPHPMethod::Call(const ValueList& args)
    {
        TSRMLS_FETCH();

        zval* zReturnValue = NULL;
        zend_class_entry* classEntry =  Z_OBJCE_P(object);

        // Zendify method name.
        zval zMethodName;
        ZVAL_STRINGL(&zMethodName, methodName, strlen(methodName), 0);

        // Convert the arguments to PHP zvals.
        zval*** zargs = new zval**[args.size()];
        zval** zargsStore = new zval*[args.size()];
        for (int i = 0; i < args.size(); i++)
        {
            KValueRef value = args.at(i);

            zval* zargument;
            ALLOC_INIT_ZVAL(zargsStore[i]);
            zargs[i] = &zargsStore[i];

            PHPUtils::ToPHPValue(args[i], zargs[i]);
        }

        // Construct a zend_fcall_info structure which describes
        // the method call we are about to invoke.
        zend_fcall_info callInfo;
        callInfo.size = sizeof(zend_fcall_info);
        callInfo.object_ptr = object;
        callInfo.function_name = &zMethodName;
        callInfo.retval_ptr_ptr = &zReturnValue;
        callInfo.param_count = args.size();
        callInfo.params = zargs;
        callInfo.no_separation = 1;
        callInfo.symbol_table = NULL;
        callInfo.function_table = &classEntry->function_table;

        KObjectRef previousGlobal(PHPUtils::GetCurrentGlobalObject());
        PHPUtils::SwapGlobalObject(this->globalObject, &EG(symbol_table) TSRMLS_CC);

        int result = zend_call_function(&callInfo, NULL TSRMLS_CC);

        PHPUtils::SwapGlobalObject(previousGlobal, &EG(symbol_table) TSRMLS_CC);

        for (int i = 0; i < args.size(); i++)
        {
            Z_DELREF_P(zargsStore[i]);
        }
        delete [] zargs;
        delete [] zargsStore;

        if (result == FAILURE)
        {
            throw ValueException::FromFormat("Couldn't execute method %s::%s", 
                classEntry->name, methodName);
            return Value::Undefined;
        }
        else if (zReturnValue)
        {
            KValueRef returnValue(PHPUtils::ToKrollValue(zReturnValue TSRMLS_CC));
            zval_ptr_dtor(&zReturnValue);
            return returnValue;
        }
        else
        {
            return Value::Undefined;
        }
    }

    void KPHPMethod::Set(const char *name, KValueRef value)
    {
        // TODO: PHP methods do not have properties. Should we should set
        // them on a StaticBoundObject here?
    }

    KValueRef KPHPMethod::Get(const char *name)
    {
        // TODO: PHP methods do not have properties. Should we should get
        // them from a StaticBoundObject here?
        return Value::Undefined;
    }

    bool KPHPMethod::Equals(KObjectRef other)
    {
        AutoPtr<KPHPMethod> phpOther = other.cast<KPHPMethod>();
        if (phpOther.isNull())
            return false;
        
        TSRMLS_FETCH();
        return PHPUtils::PHPObjectsEqual(this->ToPHP(), phpOther->ToPHP() TSRMLS_CC);
    }

    SharedString KPHPMethod::DisplayString(int levels)
    {
        std::string* displayString = new std::string("KPHPMethod: ");
        displayString->append(methodName);
        return displayString;
    }

    SharedStringList KPHPMethod::GetPropertyNames()
    {
        return new StringList();
    }

    zval* KPHPMethod::ToPHP()
    {
        return this->object;
    }
}