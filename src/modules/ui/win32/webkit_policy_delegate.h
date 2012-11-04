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

#ifndef _TI_WEB_KIT_POLICY_DELEGATE_H_
#define _TI_WEB_KIT_POLICY_DELEGATE_H_
#include <windows.h>
namespace ti {

class Win32UserWindow;

class Win32WebKitPolicyDelegate : public IWebPolicyDelegate {
public:
    Win32WebKitPolicyDelegate(Win32UserWindow *window_);

    // These function declarations copied from WebKit source (PolicyDelegate.cpp)

    // IUnknown
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject);
    virtual ULONG STDMETHODCALLTYPE AddRef(void);
    virtual ULONG STDMETHODCALLTYPE Release(void);

    // IWebPolicyDelegate
    virtual HRESULT STDMETHODCALLTYPE decidePolicyForNavigationAction(
        /* [in] */ IWebView *webView,
        /* [in] */ IPropertyBag *actionInformation,
        /* [in] */ IWebURLRequest *request,
        /* [in] */ IWebFrame *frame,
        /* [in] */ IWebPolicyDecisionListener *listener);

    virtual HRESULT STDMETHODCALLTYPE decidePolicyForNewWindowAction(
        /* [in] */ IWebView *webView,
        /* [in] */ IPropertyBag *actionInformation,
        /* [in] */ IWebURLRequest *request,
        /* [in] */ BSTR frameName,
        /* [in] */ IWebPolicyDecisionListener *listener);

    virtual HRESULT STDMETHODCALLTYPE decidePolicyForMIMEType(
        /* [in] */ IWebView *webView,
        /* [in] */ BSTR type,
        /* [in] */ IWebURLRequest *request,
        /* [in] */ IWebFrame *frame,
        /* [in] */ IWebPolicyDecisionListener *listener);

    virtual HRESULT STDMETHODCALLTYPE unableToImplementPolicyWithError(
        /* [in] */ IWebView *webView,
        /* [in] */ IWebError *error,
        /* [in] */ IWebFrame *frame);

    // PolicyDelegate
    void setPermissive(bool permissive) { m_permissiveDelegate = permissive; }

private:
    ULONG m_refCount;
    Win32UserWindow *window;
    bool m_permissiveDelegate;
};

}

#endif /* _TI_WEB_KIT_POLICY_DELEGATE_H_ */
