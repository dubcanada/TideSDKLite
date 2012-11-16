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

#ifndef PYTHON_TYPES_H_
#define PYTHON_TYPES_H_

#include <typeinfo>
#include "python_module.h"

namespace tide
{
    class PythonUtils
    {
    public:
        static void InitializePythonKClasses();
        static KValueRef ToTiValue(PyObject* value);
        static PyObject* ToPyObject(KValueRef value);
        static PyObject* ToPyObject(const ValueList& list);
        static const char* ToString(PyObject* value);
        static PyObject* KObjectToPyObject(KValueRef o);
        static PyObject* KMethodToPyObject(KValueRef o);
        static PyObject* KListToPyObject(KValueRef o);
        static std::string PythonErrorToString();

    private:
        PythonUtils() {}
        ~PythonUtils () {}
    };
}

#endif
