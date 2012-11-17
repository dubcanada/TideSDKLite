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
    KPythonList::KPythonList(PyObject *list) :
        TiList("Python.KPythonList"),
        list(list),
        object(new KPythonObject(list, true))
    {
        PyLockGIL lock;
        Py_INCREF(this->list);
    }

    KPythonList::~KPythonList()
    {
        PyLockGIL lock;
        Py_DECREF(this->list);
    }

    void KPythonList::Append(ValueRef value)
    {
        PyLockGIL lock;
        PyObject* py_value = PythonUtils::ToPyObject(value);
        PyList_Append(this->list, py_value);
    }

    unsigned int KPythonList::Size()
    {
        PyLockGIL lock;
        return PyList_Size(this->list);
    }

    bool KPythonList::Remove(unsigned int index)
    {
        PyLockGIL lock;
        if (index < this->Size())
        {
            PyObject* emptyList = PyList_New(0);
            PyList_SetSlice(this->list, index, index + 1, emptyList);
            Py_DECREF(emptyList);
            return true;
        }
        else
        {
            return false;
        }
    }

    ValueRef KPythonList::At(unsigned int index)
    {
        PyLockGIL lock;
        if (index >= 0 && index < this->Size())
        {
            PyObject *p = PyList_GetItem(this->list, index);
            ValueRef v = PythonUtils::ToTiValue(p);
            return v;
        }
        else
        {
            return Value::Undefined;
        }
    }

    void KPythonList::Set(const char* name, ValueRef value)
    {
        if (TiList::IsInt(name))
        {
            this->SetAt(TiList::ToIndex(name), value);
        }
        else
        {
            this->object->Set(name, value);
        }
    }

    void KPythonList::SetAt(unsigned int index, ValueRef value)
    {
        PyLockGIL lock;
        while (index >= this->Size())
        {
            // Now we need to create entries between current size
            // and new size and make the entries undefined.
            Py_INCREF(Py_None);
            PyList_Append(this->list, Py_None);
        }
        PyObject* py_value = PythonUtils::ToPyObject(value);
        PyList_SetItem(this->list, index, py_value);
        return;
    }

    ValueRef KPythonList::Get(const char* name)
    {
        if (TiList::IsInt(name))
        {
            return this->At(TiList::ToIndex(name));
        }
        else
        {
            return object->Get(name);
        }
    }

    SharedStringList KPythonList::GetPropertyNames()
    {
        SharedStringList property_names = object->GetPropertyNames();
        for (size_t i = 0; i < this->Size(); i++)
        {
            std::string name = TiList::IntToChars(i);
            property_names->push_back(new std::string(name));
        }

        return property_names;
    }

    PyObject* KPythonList::ToPython()
    {
        return this->object->ToPython();
    }

    bool KPythonList::Equals(TiObjectRef other)
    {
        AutoPtr<KPythonList> pyOther = other.cast<KPythonList>();

        // This is not a Python object
        if (pyOther.isNull())
            return false;

        return pyOther->ToPython() == this->ToPython();
    }
}
