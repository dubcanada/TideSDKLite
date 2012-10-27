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

#ifndef _PYTHON_MODULE_H
#define _PYTHON_MODULE_H

#include <Python.h>
#include <kroll/kroll.h>
#include <string>
#include <vector>
#include <iostream>

#include "python_api.h"
#include "python_utils.h"
#include "k_python_object.h" 
#include "k_python_method.h"
#include "k_python_list.h"
#include "k_python_tuple.h"
#include "k_python_dict.h"
#include "python_evaluator.h"

#define THROW_PYTHON_EXCEPTION \
PyObject *_ptype, *_pvalue, *_trace; \
PyErr_Fetch(&_ptype, &_pvalue, &_trace); \
ValueException _ex = ValueException::FromString("Unknown"); \
if (_pvalue != NULL) \
{ \
    KValueRef _ex_val = PythonUtils::ToKrollValue(_pvalue); \
    _ex = ValueException(_ex_val); \
} \
Py_XDECREF(_ptype); \
Py_XDECREF(_pvalue); \
Py_XDECREF(_trace); \
throw _ex;

namespace kroll
{
    class KROLL_PYTHON_API PythonModule : public Module, public ModuleProvider
    {
    public:
        PythonModule(Host* host, const char* path) :
            Module(host, path, STRING(MODULE_NAME), STRING(MODULE_VERSION))
        {
        }

        ~PythonModule()
        {
        }

        void Initialize();
        void Stop();

        virtual bool IsModule(std::string& path);
        virtual Module* CreateModule(std::string& path);
        void InitializeBinding();

        Host* GetHost()
        {
            return host;
        }

        static PythonModule* Instance()
        {
            return instance_;
        }

    private:
        KObjectRef binding;
        static PythonModule *instance_;
        DISALLOW_EVIL_CONSTRUCTORS(PythonModule);
    };

    struct PyLockGIL
    {
        PyLockGIL() : gstate(PyGILState_Ensure())
        { }

        ~PyLockGIL()
        {
            PyGILState_Release(gstate);
        }

        PyGILState_STATE gstate;
    };

    struct PyAllowThreads
    {
        PyAllowThreads() : threadState(PyEval_SaveThread())
        { }

        ~PyAllowThreads()
        {
            PyEval_RestoreThread(threadState);
        }

        PyThreadState* threadState;
    };
}

#include "python_module_instance.h"

#endif