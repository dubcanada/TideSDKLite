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

#ifndef _KR_COM_REFERENCE_COUNTED_H_
#define _KR_COM_REFERENCE_COUNTED_H_
#include <Unknwn.h>
/*
 * This is a COM-specific wrapper of ReferenceCounted. 
 */
namespace tide
{
    class KROLL_API COMReferenceCounted : public ReferenceCounted, public IUnknown
    {
    public:
        // IUnknown
        virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject)
        {
            *ppvObject = 0;
            if (IsEqualGUID(riid, IID_IUnknown))
            {
                *ppvObject = static_cast<IUnknown*>(this);
            }
            else
            {
                return E_NOINTERFACE;
            }
            return S_OK;
        }
        
        virtual ULONG STDMETHODCALLTYPE AddRef(void)
        {
            duplicate();
            return referenceCount();
        }
        
        virtual ULONG STDMETHODCALLTYPE Release(void)
        {
            release();
            return referenceCount();
        }
    };
}

#endif
