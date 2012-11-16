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

#include "python_list.h"

namespace tide
{
    KPythonTuple::KPythonTuple(PyObject *tuple) :
        KList("Python.KPythonTuple"),
        tuple(tuple),
        object(new KPythonObject(tuple, true))
    {
        PyLockGIL lock;
        Py_INCREF(this->tuple);
    }

    KPythonTuple::~KPythonTuple()
    {
        PyLockGIL lock;
        Py_DECREF(this->tuple);
    }

    void KPythonTuple::Append(KValueRef value)
    {
        throw ValueException::FromString("Cannot modify the size of a Python tuple.");
    }

    unsigned int KPythonTuple::Size()
    {
        PyLockGIL lock;
        return PyTuple_Size(this->tuple);
    }

    bool KPythonTuple::Remove(unsigned int index)
    {
        throw ValueException::FromString("Cannot modify the size of a Python tuple.");
        return false;
    }

    KValueRef KPythonTuple::At(unsigned int index)
    {
        PyLockGIL lock;
        if (index >= 0 && index < this->Size())
        {
            PyObject *p = PyTuple_GetItem(this->tuple, index);
            KValueRef v = PythonUtils::ToTiValue(p);
            return v;
        }
        else
        {
            return Value::Undefined;
        }
    }

    void KPythonTuple::Set(const char *name, KValueRef value)
    {
        throw ValueException::FromString("Cannot modify a Python tuple.");
    }

    void KPythonTuple::SetAt(unsigned int index, KValueRef value)
    {
        throw ValueException::FromString("Cannot modify a Python tuple.");
    }

    KValueRef KPythonTuple::Get(const char *name)
    {
        if (KList::IsInt(name))
        {
            return this->At(KList::ToIndex(name));
        }
        else
        {
            return object->Get(name);
        }
    }

    SharedStringList KPythonTuple::GetPropertyNames()
    {
        SharedStringList property_names = object->GetPropertyNames();
        for (size_t i = 0; i < this->Size(); i++)
        {
            std::string name = KList::IntToChars(i);
            property_names->push_back(new std::string(name));
        }
        return property_names;
    }

    PyObject* KPythonTuple::ToPython()
    {
        return this->object->ToPython();
    }

    bool KPythonTuple::Equals(KObjectRef other)
    {
        AutoPtr<KPythonTuple> pyOther = other.cast<KPythonTuple>();
        if (pyOther.isNull())
        {
            return false;
        }
        else
        {
            return pyOther->ToPython() == this->ToPython();
        }
    }
}
