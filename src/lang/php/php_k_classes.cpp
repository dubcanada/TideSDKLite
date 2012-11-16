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

extern "C" {
#include <spl/spl_array.h>
}

#define GET_MY_KLIST() \
    reinterpret_cast<PHPTiObject*>( \
     zend_object_store_get_object(getThis() TSRMLS_CC))->kvalue->ToList()

// FIXME: PHP does not export any of the token constants in the
// headers so we have to hardcode them here. Ick.
#define T_FUNCTION 334
#define T_STRING 307
using std::string;
using std::map;

namespace tide
{
    static map<string, string> currentCaseMap;
    zend_class_entry *PHPTiObjectClassEntry = NULL;
    zend_class_entry *PHPTiMethodClassEntry = NULL;
    zend_class_entry *PHPTiListClassEntry = NULL;
    zend_object_handlers PHPTiObjectHandlers;
    zend_object_handlers PHPTiMethodHandlers;
    zend_object_handlers PHPTiListHandlers;

    // Private data and function declarations below here
    static zend_object_value PHPTiObjectCreateObject(zend_class_entry *ce TSRMLS_DC);
    static zend_class_entry* PHPTiObjectGetClassEntry(const zval* zthis TSRMLS_DC);
    static zend_class_entry* PHPTiMethodGetClassEntry(const zval* zthis TSRMLS_DC);
    static zend_class_entry* PHPTiListGetClassEntry(const zval* zthis TSRMLS_DC);
    static void PHPTiObjectFreeStorage(void* zthis TSRMLS_DC);
    static zval* PHPTiObjectReadProperty(zval* zthis, zval* property, int type TSRMLS_DC);
    static void PHPTiObjectWriteProperty(zval* zthis, zval* property, zval* value TSRMLS_DC);
    static HashTable* PHPTiObjectGetProperties(zval* zthis TSRMLS_DC);
    static void PHPTiObjectUnsetProperty(zval* zthis, zval* property TSRMLS_DC);
    static int PHPTiObjectHasProperty(zval* zthis, zval* property, int type TSRMLS_DC);
    static int PHPTiObjectHasDimension(zval* zthis, zval* property, int type TSRMLS_DC);

    PHP_METHOD(PHPTiObject, __toString);
    PHP_METHOD(PHPTiObject, __call);
    PHP_METHOD(PHPTiMethod, __invoke);
    PHP_METHOD(PHPTiList, offsetExists);
    PHP_METHOD(PHPTiList, offsetGet);
    PHP_METHOD(PHPTiList, offsetUnset);
    PHP_METHOD(PHPTiList, offsetSet);
    PHP_METHOD(PHPTiList, count);
    PHP_METHOD(PHPTiList, append);
    PHP_METHOD(PHPTiList, getArrayCopy);
    PHP_METHOD(PHPTiList, exchangeArray);

    static ZEND_FUNCTION(krollAddFunction);

    ZEND_BEGIN_ARG_INFO_EX(KrollAddFunctionArgInfo, 0, 0, 2)
        ZEND_ARG_INFO(0, object)
        ZEND_ARG_INFO(0, fname)
    ZEND_END_ARG_INFO()
    
    static const zend_function_entry PHPFunctions[] = {
        ZEND_FE(krollAddFunction, KrollAddFunctionArgInfo)
        { NULL, NULL, NULL, NULL }
    };

    // This is our class "function" table. Right now we only implement
    // __call, because that seems to be preferred over the handler version.
    ZEND_BEGIN_ARG_INFO_EX(PHPTiObjectCallArgInfo, 0, 0, 2)
    ZEND_ARG_INFO(0, methodName)
    ZEND_ARG_INFO(0, arguments)
    ZEND_END_ARG_INFO()

    static function_entry PHPTiObjectMethods[] =
    {
        PHP_ME(PHPTiObject, __call, PHPTiObjectCallArgInfo, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiObject, __toString, NULL, ZEND_ACC_PUBLIC)
        {NULL, NULL, NULL}
    };

    static function_entry PHPTiMethodMethods[] =
    {
        PHP_ME(PHPTiMethod, __invoke, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiObject, __call, PHPTiObjectCallArgInfo, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiObject, __toString, NULL, ZEND_ACC_PUBLIC)
        {NULL, NULL, NULL}
    };

    ZEND_BEGIN_ARG_INFO_EX(PHPTiListOffsetGetArgInfo, 0, 0, 1)
        ZEND_ARG_INFO(0, index)
    ZEND_END_ARG_INFO()
    ZEND_BEGIN_ARG_INFO_EX(PHPTiListOffsetSetArgInfo, 0, 0, 2)
        ZEND_ARG_INFO(0, index)
        ZEND_ARG_INFO(0, newval)
    ZEND_END_ARG_INFO()
    ZEND_BEGIN_ARG_INFO(PHPTiListAppendArgInfo, 0)
        ZEND_ARG_INFO(0, value)
    ZEND_END_ARG_INFO()
    ZEND_BEGIN_ARG_INFO(PHPTiListExchangeArrayArgInfo, 0)
        ZEND_ARG_INFO(0, array)
    ZEND_END_ARG_INFO()
    ZEND_BEGIN_ARG_INFO(PHPTiListVoidArgInfo, 0)
    ZEND_END_ARG_INFO()

    static function_entry PHPTiListMethods[] =
    {
        PHP_ME(PHPTiObject, __call, PHPTiObjectCallArgInfo, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiObject, __toString, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiList, offsetExists, PHPTiListOffsetGetArgInfo, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiList, offsetGet, PHPTiListOffsetGetArgInfo, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiList, offsetSet, PHPTiListOffsetSetArgInfo, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiList, offsetUnset, PHPTiListOffsetGetArgInfo, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiList, count, PHPTiListVoidArgInfo, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiList, exchangeArray, PHPTiListExchangeArrayArgInfo, ZEND_ACC_PUBLIC)
        PHP_ME(PHPTiList, getArrayCopy, PHPTiListVoidArgInfo, ZEND_ACC_PUBLIC)
        {NULL, NULL, NULL}
    };

    PHP_METHOD(PHPTiObject, __toString)
    {
        KValueRef kvalue(reinterpret_cast<PHPTiObject*>(
            zend_object_store_get_object(getThis() TSRMLS_CC))->kvalue);
        SharedString ss = kvalue->DisplayString();
        ZVAL_STRINGL(return_value, (char *) ss->c_str(), ss->size(), 1);
    }

    PHP_METHOD(PHPTiObject, __call)
    {
        char* methodName;
        int methodNameLength;
        zval* zargs;

        if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sa",
            &methodName, &methodNameLength, &zargs) == FAILURE)
        {
            zend_throw_exception(zend_exception_get_default(TSRMLS_C),
                (char*) "Wrong arguments passed to __call", 666 TSRMLS_CC);
            RETVAL_NULL();
            return;
        }

        PHPTiObject* kthis = reinterpret_cast<PHPTiObject*>(
            zend_object_store_get_object(getThis() TSRMLS_CC));
        TiObjectRef TiObject = kthis->kvalue->ToObject();
        TiMethodRef method = TiObject->GetMethod(methodName, 0);

        // Find the method by its name.
        if (method.isNull())
        {
            string error("Could not find method named '");
            error.append(methodName);
            error.append("'");
            zend_throw_exception(zend_exception_get_default(TSRMLS_C),
                (char*) error.c_str(), 666 TSRMLS_CC);
            RETVAL_NULL();
            return;
        }

        // Pull out the arguments from the argument array.
        ArgList kargs;
        int numArgs = zend_hash_num_elements(Z_ARRVAL_P(zargs));
        if (numArgs > 0)
        {
            HashPosition position;
            zval** parameter;
            zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(zargs), &position);

            while (zend_hash_get_current_data_ex(Z_ARRVAL_P(zargs),
                (void **) &parameter, &position) == SUCCESS)
            {
                kargs.push_back(PHPUtils::ToTiValue(*parameter TSRMLS_CC));
                zend_hash_move_forward_ex(Z_ARRVAL_P(zargs), &position);
            }
        }

        // Do the method invocation.
        try
        {
            KValueRef returnValue = method->Call(kargs);
            PHPUtils::ToPHPValue(returnValue, &return_value);
        }
        catch (ValueException& e)
        {
            zend_throw_exception(zend_exception_get_default(TSRMLS_C),
                (char*) e.ToString().c_str(), 666 TSRMLS_CC);
            RETVAL_NULL();
            return;
        }
    }

    zend_object_value PHPTiObjectCreateObject(zend_class_entry *classEntry TSRMLS_DC)
    {
        PHPTiObject* intern;
        zend_object_value retval;

        // We're using a custom zend_object* (PHPTiObject*) so we
        // need to do the things done by zend_objects_new manually.
        intern = (PHPTiObject*) emalloc(sizeof(PHPTiObject));
        memset(intern, 0, sizeof(PHPTiObject));

        zend_object_std_init(&intern->std, classEntry TSRMLS_CC);

        // We don't have any default properties in our object
        // so just start out with a blank properties hash.
        ALLOC_HASHTABLE(intern->std.properties);
        zend_hash_init(intern->std.properties,
            0, NULL, ZVAL_PTR_DTOR, 0);

        // Use the standard object destructor, but we want to use a
        // custom memory free so that we can deference the internal
        // Tide value.
        retval.handle = zend_objects_store_put(intern,
            (zend_objects_store_dtor_t) zend_objects_destroy_object,
            (zend_objects_free_object_storage_t) PHPTiObjectFreeStorage,
            NULL TSRMLS_CC);

        // Use our special handlers for doing common object operations.
        if (classEntry == PHPTiListClassEntry)
            retval.handlers = &PHPTiListHandlers;
        else if (classEntry == PHPTiMethodClassEntry)
            retval.handlers = &PHPTiMethodHandlers;
        else
            retval.handlers = &PHPTiObjectHandlers;

        return retval;
    }

    void PHPTiObjectFreeStorage(void *zthis TSRMLS_DC)
    {
        PHPTiObject* phpTiObject = static_cast<PHPTiObject*>(zthis);
        phpTiObject->kvalue = 0;

        zend_object_std_dtor(&phpTiObject->std TSRMLS_CC);
        efree(zthis);
    }

    zval* PHPTiObjectReadProperty(zval* zthis, zval* property, int type TSRMLS_DC)
    {
        PHPTiObject* kthis = reinterpret_cast<PHPTiObject*>(
            zend_object_store_get_object(zthis TSRMLS_CC));
        TiObjectRef TiObject = kthis->kvalue->ToObject();
        string propertyName = PHPUtils::ZvalToPropertyName(property);

        try
        {
            KValueRef value = TiObject->Get(propertyName.c_str());
            return PHPUtils::ToPHPValue(value);
        }
        catch (ValueException& e)
        {
            zend_throw_exception(zend_exception_get_default(TSRMLS_C),
                (char*) e.ToString().c_str(), 666 TSRMLS_CC);
            zval* retval = NULL;
            ZVAL_NULL(retval);
            return retval;
        }
    }

    void PHPTiObjectWriteProperty(zval* zthis, zval* property, zval* value TSRMLS_DC)
    {
        PHPTiObject* kthis = reinterpret_cast<PHPTiObject*>(
            zend_object_store_get_object(zthis TSRMLS_CC));

        try
        {
            KValueRef tideValue = PHPUtils::ToTiValue(value TSRMLS_CC);
            if (!property) // A NULL property name means this is an append ([]=) operation.
            {
                // TODO: It's unclear what this should do if not called on a list.
                if (kthis->kvalue->IsList())
                {
                    kthis->kvalue->ToList()->Append(tideValue);
                }
            }
            else
            {
                TiObjectRef tiObject = kthis->kvalue->ToObject();
                string propertyName = PHPUtils::ZvalToPropertyName(property);
                    tiObject->Set(propertyName.c_str(), tideValue);
            }
        }
        catch (ValueException& e)
        {
            zend_throw_exception(
                zend_exception_get_default(TSRMLS_C), (char*) e.ToString().c_str(), 666 TSRMLS_CC);
        }
    }

    HashTable* PHPTiObjectGetProperties(zval *zthis TSRMLS_DC)
    {
        PHPTiObject *kthis = reinterpret_cast<PHPTiObject*>(
            zend_object_store_get_object(zthis TSRMLS_CC));
        TiObjectRef tiObject = kthis->kvalue->ToObject();

        try
        {
            SharedStringList propertyNames = tiObject->GetPropertyNames();
            HashTable* properties;
            ALLOC_HASHTABLE(properties);
            zend_hash_init(properties, propertyNames->size(), NULL, ZVAL_PTR_DTOR, 0);

            for (size_t i = 0; i < propertyNames->size(); i++)
            {
                const char *key = propertyNames->at(i)->c_str();
                KValueRef value = tiObject->Get(key);
                zval* zvalue = PHPUtils::ToPHPValue(value);
                zend_hash_add(properties, (char *)key, strlen(key)+1, &zvalue, sizeof(zval*), NULL);
            }
            return properties;
        }
        catch (ValueException& e)
        {
            zend_throw_exception(zend_exception_get_default(TSRMLS_C),
                (char *) e.ToString().c_str(), 666 TSRMLS_CC);
        }

        return 0;
    }

    /* Extending and Embedding PHP pg. 153
     * When isset() is called against an object property, this handler is invoked.
     * By default the standard handler will check for the property named by
     * 'property', if it's not found and -- as of PHP 4.1.0 -- if an __isset()
     * method is defined it will call that. The checkType parameter will be one of
     * three possible values. If the value is 2 the property need only exist to
     * qualify as a success. If the checkType is 0, it must exist and be of any
     * type except IS_NULL. If the value of checkType is 1, the value msut both
     * eist and evaluate to a non-false value. Note: In PHP 4.0.x the meaning of
     * checkType matched has_dimension's version of checkType (Martin: but not any
     * longer!).
     */
    int PHPTiObjectHasProperty(zval* zthis, zval* property, int checkType TSRMLS_DC)
    {
        PHPTiObject* kthis = reinterpret_cast<PHPTiObject*>(
            zend_object_store_get_object(zthis TSRMLS_CC));
        TiObjectRef tiObject = kthis->kvalue->ToObject();
        string propertyName = PHPUtils::ZvalToPropertyName(property);

        if (checkType == 0)
        {
            KValueRef value = tiObject->Get(propertyName.c_str());
            return !value->IsUndefined() && !value->IsNull();
        }
        else if (checkType == 1)
        {
            KValueRef value = tiObject->Get(propertyName.c_str());
            zval* phpValue = PHPUtils::ToPHPValue(value);
            convert_to_boolean(phpValue);
            return Z_BVAL_P(phpValue);
        }
        else // Generally this should be checkType == 2
        {
            return tiObject->HasProperty(propertyName.c_str());
        }
    }

    /* Extending and Embedding PHP pg. 154
     * When isset() is called against an object that is being treated like an
     * array, such as isset($obj['idx']), this handler is used. The standard
     * handler, if the object implements the ArrayAccess interface, will call the
     * offsetexists($idx) method first. If not found, it returns failure in the
     * form of a 0. Otherwise, if checkType is 0 it returns true (1) immediately.
     * A checkType of 1 indicates that it must also check that the value is
     * non-false by invoking the object's offsetget($idx) method as well and
     * examining the returned value.
     */
    int PHPTiObjectHasDimension(zval* zthis, zval* property, int checkType TSRMLS_DC)
    {
        PHPTiObject* kthis = reinterpret_cast<PHPTiObject*>(
            zend_object_store_get_object(zthis TSRMLS_CC));
        TiObjectRef tiObject = kthis->kvalue->ToObject();
        string propertyName = PHPUtils::ZvalToPropertyName(property);

        if (checkType == 0)
        {
            return tiObject->HasProperty(propertyName.c_str());
        }
        else
        {
            if (!tiObject->HasProperty(propertyName.c_str()))
            {
                return false;
            }
            else
            {
                KValueRef value = tiObject->Get(propertyName.c_str());
                zval* phpValue = PHPUtils::ToPHPValue(value);
                convert_to_boolean(phpValue);
                return Z_BVAL_P(phpValue);
            }
        }
    }

    zend_class_entry* PHPTiObjectGetClassEntry(const zval* zthis TSRMLS_DC)
    {
        return PHPTiObjectClassEntry;
    }

    zend_class_entry* PHPTiMethodGetClassEntry(const zval* zthis TSRMLS_DC)
    {
        return PHPTiMethodClassEntry;
    }

    zend_class_entry* PHPTiListGetClassEntry(const zval* zthis TSRMLS_DC)
    {
        return PHPTiListClassEntry;
    }

    void PHPTiObjectUnsetProperty(zval* zthis, zval* property TSRMLS_DC)
    {
        PHPTiObject* kthis = reinterpret_cast<PHPTiObject*>(
            zend_object_store_get_object(zthis TSRMLS_CC));
        TiObjectRef tiObject = kthis->kvalue->ToObject();
        string propertyName = PHPUtils::ZvalToPropertyName(property);

        try
        {
            tiObject->Set(propertyName.c_str(), Value::Undefined);
        }
        catch (ValueException& e)
        {
            zend_throw_exception(
                zend_exception_get_default(TSRMLS_C), (char*) e.ToString().c_str(), 666 TSRMLS_CC);
        }
    }

    PHP_METHOD(PHPTiMethod, __invoke)
    {
        PHPTiObject* kthis = reinterpret_cast<PHPTiObject*>(
            zend_object_store_get_object(getThis() TSRMLS_CC));
        TiMethodRef timethod = kthis->kvalue->ToMethod();

        zend_function *func = EG(current_execute_data)->function_state.function;
        zval*** arguments = (zval***) emalloc(sizeof(zval**) * ZEND_NUM_ARGS());

        if (zend_get_parameters_array_ex(ZEND_NUM_ARGS(), arguments) == FAILURE)
        {
            efree(arguments);
            zend_error(E_RECOVERABLE_ERROR, "Cannot get arguments for calling closure");
            RETVAL_FALSE;
            return;
        }

        ArgList kargs;
        for (int i = 0; i < ZEND_NUM_ARGS(); i++)
        {
            zval** zargValue = arguments[i];
            KValueRef argValue = PHPUtils::ToTiValue(*zargValue TSRMLS_CC);
            kargs.push_back(argValue);
        }
        efree(arguments);

        PHPUtils::PushPHPSymbolsIntoGlobalObject(&EG(symbol_table),
             PHPUtils::GetCurrentGlobalObject() TSRMLS_CC);

        // CAUTION: FRIGGIN SWEET METHOD INVOCATION COMING UP.
        try
        {
            KValueRef returnValue = timethod->Call(kargs);
            PHPUtils::ToPHPValue(returnValue, &return_value);
        }
        catch (ValueException& e)
        {
            // TODO: Create an exception class that can hold a KValueRef.
            zend_throw_exception(zend_exception_get_default(TSRMLS_C),
                (char*) e.ToString().c_str(), 666 TSRMLS_CC);
            RETVAL_NULL();
        }

        PHPUtils::PushGlobalObjectMembersIntoPHPSymbolTable(&EG(symbol_table),
            PHPUtils::GetCurrentGlobalObject() TSRMLS_CC);
    }

    PHP_METHOD(PHPTiList, offsetExists)
    {
        zval *index;
        if (zend_parse_parameters(ZEND_NUM_ARGS()
            TSRMLS_CC, "z", &index) == FAILURE) {
            return;
        }

        TiListRef klist(GET_MY_KLIST());
        string name(PHPUtils::ZvalToPropertyName(index));
        RETURN_BOOL((!name.empty() && klist->HasProperty(name.c_str())));
    }

    PHP_METHOD(PHPTiList, offsetGet)
    {
        zval *index;
        if (zend_parse_parameters(ZEND_NUM_ARGS()
            TSRMLS_CC, "z", &index) == FAILURE)
         {
            return;
            
        }

        TiListRef klist(GET_MY_KLIST());
        string name(PHPUtils::ZvalToPropertyName(index));
        KValueRef returnValue(klist->Get(name.c_str()));
        PHPUtils::ToPHPValue(returnValue, &return_value);
    }

    PHP_METHOD(PHPTiList, offsetSet)
    {
        zval *zindexString, *zvalue;
        if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz",
            &zindexString, &zvalue) == FAILURE)
        {
            return;
        }

        TiListRef klist(GET_MY_KLIST());
        string indexString(PHPUtils::ZvalToPropertyName(zindexString));
        KValueRef value(PHPUtils::ToTiValue(zvalue TSRMLS_CC));

        if (TiList::IsInt(indexString))
        {
            klist->SetAt(TiList::ToIndex(indexString), value);
        }
        else
        {
            klist->Set(indexString.c_str(), value);
        }
    }

    PHP_METHOD(PHPTiList, offsetUnset)
    {
        zval *zindex;
        if (zend_parse_parameters(ZEND_NUM_ARGS()
            TSRMLS_CC, "z", &zindex) == FAILURE) {
            return;
        }

        TiListRef klist(GET_MY_KLIST());
        string indexString(PHPUtils::ZvalToPropertyName(zindex));
        klist->Set(indexString.c_str(), Value::Undefined);
    }

    PHP_METHOD(PHPTiList, count)
    {
        TiListRef klist(GET_MY_KLIST());
        SharedStringList propertyList = klist->GetPropertyNames();
        RETVAL_LONG(propertyList->size());
    }

    PHP_METHOD(PHPTiList, append)
    {
        zval *zvalue;
        if (zend_parse_parameters(ZEND_NUM_ARGS()
            TSRMLS_CC, "z", &zvalue) == FAILURE)
        {
            return;
        }

        TiListRef klist(GET_MY_KLIST());
        KValueRef value(PHPUtils::ToTiValue(zvalue TSRMLS_CC));
        klist->Append(value);
    } 

    PHP_METHOD(PHPTiList, getArrayCopy)
    {
        TiListRef klist(GET_MY_KLIST());
        SharedStringList propertyList = klist->GetPropertyNames();

        array_init(return_value);
        for (size_t i = 0; i < propertyList->size(); i++)
        {
            SharedString ss(propertyList->at(i));
            zval* newValue = PHPUtils::ToPHPValue(klist->Get(ss->c_str()));
            zend_hash_next_index_insert(HASH_OF(return_value),
                (void**) &newValue, sizeof (void*), 0);
        }
    }

    PHP_METHOD(PHPTiList, exchangeArray)
    {
        // TODO: Implement
    }

    ZEND_FUNCTION(krollAddFunction)
    {
        zval *phpWindowContext;
        char *fname;
        int fnameLength;
        if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zs",
            &phpWindowContext, &fname, &fnameLength) == FAILURE)
        {
            return;
        }
        
        PHPTiObject* object = reinterpret_cast<PHPTiObject*>(
            zend_object_store_get_object(phpWindowContext TSRMLS_CC));

        // If there is a preceding namespace to this function name trim it off.
        // This is likely the namespace we use to isolate PHP executions.
        string fnameString(fname);
        size_t index = fnameString.find("\\");
        if (index != string::npos)
        {
            fnameString = fnameString.substr(index + 1);
        }

        // Convert the function name back to its original case.
        if (currentCaseMap.find(fnameString) != currentCaseMap.end())
            fnameString = currentCaseMap[fnameString];

        // Use the name without the namespace for the Window object, but use
        // the full name for the KPHPFunction.
        TiObjectRef window = object->kvalue->ToObject();
        window->Set(fnameString.c_str(),
            Value::NewMethod(new KPHPFunction(fname)));
    }

    namespace PHPUtils
    {
        void InitializePHPTideClasses()
        {
            TSRMLS_FETCH();

            // Initialize the class entry for our classes
            zend_class_entry tiObjectClassEntry;
            INIT_CLASS_ENTRY(tiObjectClassEntry, "PHPTiObject", PHPTiObjectMethods);
            PHPTiObjectClassEntry = zend_register_internal_class(&tiObjectClassEntry TSRMLS_CC);
            zend_class_entry timethodClassEntry;
            INIT_CLASS_ENTRY(timethodClassEntry, "PHPTiMethod", PHPTiMethodMethods);
            PHPTiMethodClassEntry = zend_register_internal_class(&timethodClassEntry TSRMLS_CC);
            zend_class_entry klistClassEntry;
            INIT_CLASS_ENTRY(klistClassEntry, "PHPTiList", PHPTiListMethods);
            PHPTiListClassEntry = zend_register_internal_class_ex(
                &klistClassEntry, spl_ce_ArrayObject, "ArrayObject" TSRMLS_CC);

            // PHPTiMethod has enough of the same behavior that we can use the same
            // handler table that PHPTiObject uses. This may change in the future.
            PHPTiObjectClassEntry->create_object = PHPTiObjectCreateObject;
            PHPTiMethodClassEntry->create_object = PHPTiObjectCreateObject;
            PHPTiListClassEntry->create_object = PHPTiObjectCreateObject;

            // Create our custom handlers table to override the
            // default behaviour of our PHP objects.
            PHPTiObjectHandlers = *zend_get_std_object_handlers();
            PHPTiObjectHandlers.read_property = PHPTiObjectReadProperty;
            PHPTiObjectHandlers.write_property = PHPTiObjectWriteProperty;
            PHPTiObjectHandlers.get_properties = PHPTiObjectGetProperties;
            PHPTiObjectHandlers.read_dimension = PHPTiObjectReadProperty;
            PHPTiObjectHandlers.unset_property = PHPTiObjectUnsetProperty;
            PHPTiObjectHandlers.unset_dimension = PHPTiObjectUnsetProperty;
            PHPTiObjectHandlers.write_dimension = PHPTiObjectWriteProperty;
            PHPTiObjectHandlers.has_property = PHPTiObjectHasProperty;
            PHPTiObjectHandlers.has_dimension = PHPTiObjectHasDimension;
            PHPTiObjectHandlers.get_class_entry = PHPTiObjectGetClassEntry;

            PHPTiListHandlers = PHPTiObjectHandlers;
            PHPTiListHandlers.get_class_entry = PHPTiListGetClassEntry;

            // PHPTiList mostly uses the standard handlers.
            PHPTiMethodHandlers = *zend_get_std_object_handlers();
            PHPTiMethodHandlers.get_class_entry = PHPTiMethodGetClassEntry;

            // Initialize static functions
            zend_register_functions(NULL, PHPFunctions, NULL, MODULE_PERSISTENT TSRMLS_CC);
        }

        void TiObjectToKPHPObject(KValueRef objectValue, zval** returnValue)
        {
            // Initialize our object with our pre-defined TiObject class entry.
            TSRMLS_FETCH();
            object_init_ex(*returnValue, PHPTiObjectClassEntry);

            // Place the KValue into the internal struct.
            PHPTiObject* internal = reinterpret_cast<PHPTiObject*>(
                zend_object_store_get_object(*returnValue TSRMLS_CC));
            internal->kvalue = objectValue;
        }

        void TiMethodToKPHPMethod(KValueRef methodValue, zval** returnValue)
        {
            // Initialize our object with our pre-defined TiObject class entry.
            TSRMLS_FETCH();
            object_init_ex(*returnValue, PHPTiMethodClassEntry);

            // Place the KValue into the internal struct.
            PHPTiObject* internal = reinterpret_cast<PHPTiObject*>(
                zend_object_store_get_object(*returnValue TSRMLS_CC));
            internal->kvalue = methodValue;
        }

        void TiListToKPHPArray(KValueRef listValue, zval** returnValue)
        {
            // Initialize our object with our pre-defined TiObject class entry.
            TSRMLS_FETCH();
            object_init_ex(*returnValue, PHPTiListClassEntry);

            // Place the KValue into the internal struct.
            PHPTiObject* internal = reinterpret_cast<PHPTiObject*>(
                zend_object_store_get_object(*returnValue TSRMLS_CC));
            internal->kvalue = listValue;
        }

        void GenerateCaseMap(string code TSRMLS_DC)
        {
            // HACK: Okay, so PHP stores all function names in lowercase, but
            // we need the original case, so that developers can call these
            // functions from other contexts. Here do a simple search for function
            // defintions. There are several cases where this can generate inaccurate
            // results. A true fix for this issue may require patching PHP itself.
            currentCaseMap.clear();
            size_t searchStart = 0;
            size_t functionNameStart = code.find("function ", 0);

            while (functionNameStart != string::npos)
            {
                functionNameStart += sizeof("function ");

                // Find next non-space character / beginning of function name.
                while (isspace(code[functionNameStart]))
                {
                    if (functionNameStart > code.size())
                        return;
                    functionNameStart++;
                }

                size_t functionNameEnd = functionNameStart;
                while (!isspace(code[functionNameEnd]) && code[functionNameEnd] != '(')
                {
                    if (functionNameEnd > code.size())
                        return;
                    functionNameEnd++;
                }

                string originalName(code.substr(functionNameStart - 1,
                     functionNameEnd - functionNameStart + 1).c_str());
                string lcName(originalName);
                std::transform(lcName.begin(), lcName.end(), lcName.begin(), tolower);
                currentCaseMap[lcName] = originalName;

                functionNameStart = code.find("function ", functionNameStart);
            }
        }
    }
}
