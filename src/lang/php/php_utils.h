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

#ifndef _PHP_TYPES_H_
#define _PHP_TYPES_H_

#include "php_module.h"

namespace tide
{
    typedef struct
    {
        zend_object std;
        ValueRef kvalue;
    } PHPTiObject;
    extern zend_class_entry *PHPTiObjectClassEntry;
    extern zend_class_entry *PHPTiMethodClassEntry;
    extern zend_class_entry *PHPTiListClassEntry;
    extern zend_object_handlers PHPTiObjectHandlers;

    namespace PHPUtils
    {
        ValueRef ToTiValue(zval* value TSRMLS_DC);
        zval* ToPHPValue(ValueRef value);
        void ToPHPValue(ValueRef value, zval** returnValue);
        std::string ZvalToPropertyName(zval* property);
        TiListRef PHPArrayToTiList(zval* array TSRMLS_DC,
            bool ignoreGlobals=false);
        TiListRef PHPHashTableToTiList(HashTable* hashtable TSRMLS_DC,
             bool ignoreGlobals=false);
        SharedStringList GetHashKeys(HashTable* hash);
        void TiObjectToKPHPObject(ValueRef objectValue, zval** returnValue);
        void TiMethodToKPHPMethod(ValueRef methodValue, zval** returnValue);
        void TiListToKPHPArray(ValueRef listValue, zval** returnValue);
        void InitializePHPTideClasses();
        bool PHPObjectsEqual(zval* val1, zval* val2 TSRMLS_DC);
        int HashZvalCompareCallback(const zval** one, const zval** two TSRMLS_DC);
        SharedStringList GetClassMethods(zend_class_entry* ce TSRMLS_DC);
        TiListRef GetClassVars(zend_class_entry* ce TSRMLS_DC);
        zend_function* GetGlobalFunction(const char *name TSRMLS_DC);
        void GenerateCaseMap(string code TSRMLS_DC);

        TiObjectRef GetCurrentGlobalObject();
        void PushPHPSymbolsIntoGlobalObject(HashTable* symbolTable, TiObjectRef global TSRMLS_DC);
        void PushGlobalObjectMembersIntoPHPSymbolTable(HashTable* symbolTable, TiObjectRef global TSRMLS_DC);
        void SwapGlobalObject(TiObjectRef newGlobal, HashTable* symbolTable TSRMLS_DC);
    }
}

#endif
