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

#include "python_method.h"

namespace tide
{
    KPythonMethod::KPythonMethod(PyObject *method) :
        KMethod("Python.KMethod"),
        method(method),
        object(new KPythonObject(method))
    {
        PyLockGIL lock;
        Py_INCREF(this->method);
    }

    KPythonMethod::~KPythonMethod()
    {
        PyLockGIL lock;
        Py_DECREF(this->method);
    }

    KValueRef KPythonMethod::Call(const ValueList& args)
    {
        PyLockGIL lock;
        PyObject *arglist = NULL;

        if (args.size() > 0)
        {
            arglist = PyTuple_New(args.size());
            for (size_t i = 0; i < args.size(); i++)
            {
                PyObject *pv = PythonUtils::ToPyObject(args[i]);
                PyTuple_SetItem(arglist, i, pv);
            }
        }

        PyObject *response = PyObject_CallObject(this->method, arglist);
        Py_XDECREF(arglist);

        KValueRef value = Value::Undefined;
        if (response == NULL && PyErr_Occurred() != NULL)
        {
            THROW_PYTHON_EXCEPTION
        }
        else if (response != NULL)
        {
            value = PythonUtils::ToTiValue(response);
            Py_DECREF(response);
        }

        return value;
    }

    void KPythonMethod::Set(const char *name, KValueRef value)
    {
        this->object->Set(name, value);
    }

    KValueRef KPythonMethod::Get(const char *name)
    {
        return this->object->Get(name);
    }

    SharedStringList KPythonMethod::GetPropertyNames()
    {
        return this->object->GetPropertyNames();
    }

    PyObject* KPythonMethod::ToPython()
    {
        return this->object->ToPython();
    }

    bool KPythonMethod::Equals(KObjectRef other)
    {
        AutoPtr<KPythonMethod> pyOther = other.cast<KPythonMethod>();

        // This is not a Python object
        if (pyOther.isNull())
            return false;

        return pyOther->ToPython() == this->ToPython();
    }

}
