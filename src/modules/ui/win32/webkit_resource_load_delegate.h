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

#ifndef _TI_WEBKIT_RESOURCE_LOAD_DELEGATE_H_
#define _TI_WEBKIT_RESOURCE_LOAD_DELEGATE_H_

namespace ti
{

class Win32WebKitResourceLoadDelegate : public IWebResourceLoadDelegate
{
public:
    Win32WebKitResourceLoadDelegate(Win32UserWindow* userWindow);

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject);
    virtual ULONG STDMETHODCALLTYPE AddRef(void);
    virtual ULONG STDMETHODCALLTYPE Release(void);

    virtual HRESULT STDMETHODCALLTYPE identifierForInitialRequest(
        /* [in] */ IWebView *webView,
        /* [in] */ IWebURLRequest *request,
        /* [in] */ IWebDataSource *dataSource,
        /* [in] */ unsigned long identifier);

    virtual HRESULT STDMETHODCALLTYPE willSendRequest(
        /* [in] */ IWebView *webView,
        /* [in] */ unsigned long identifier,
        /* [in] */ IWebURLRequest *request,
        /* [in] */ IWebURLResponse *redirectResponse,
        /* [in] */ IWebDataSource *dataSource,
        /* [retval][out] */ IWebURLRequest **newRequest);

    virtual HRESULT STDMETHODCALLTYPE didReceiveAuthenticationChallenge(
        /* [in] */ IWebView *webView,
        /* [in] */ unsigned long identifier,
        /* [in] */ IWebURLAuthenticationChallenge *challenge,
        /* [in] */ IWebDataSource *dataSource);

    virtual HRESULT STDMETHODCALLTYPE didCancelAuthenticationChallenge(
        /* [in] */ IWebView *webView,
        /* [in] */ unsigned long identifier,
        /* [in] */ IWebURLAuthenticationChallenge *challenge,
        /* [in] */ IWebDataSource *dataSource);

    virtual HRESULT STDMETHODCALLTYPE didReceiveResponse(
        /* [in] */ IWebView *webView,
        /* [in] */ unsigned long identifier,
        /* [in] */ IWebURLResponse *response,
        /* [in] */ IWebDataSource *dataSource);

    virtual HRESULT STDMETHODCALLTYPE didReceiveContentLength(
        /* [in] */ IWebView *webView,
        /* [in] */ unsigned long identifier,
        /* [in] */ UINT length,
        /* [in] */ IWebDataSource *dataSource);

    virtual HRESULT STDMETHODCALLTYPE didFinishLoadingFromDataSource(
        /* [in] */ IWebView *webView,
        /* [in] */ unsigned long identifier,
        /* [in] */ IWebDataSource *dataSource);

    virtual HRESULT STDMETHODCALLTYPE didFailLoadingWithError(
        /* [in] */ IWebView *webView,
        /* [in] */ unsigned long identifier,
        /* [in] */ IWebError *error,
        /* [in] */ IWebDataSource *dataSource);

    virtual HRESULT STDMETHODCALLTYPE plugInFailedWithError(
        /* [in] */ IWebView *webView,
        /* [in] */ IWebError *error,
        /* [in] */ IWebDataSource *dataSource);

private:
    Win32UserWindow* userWindow;
    int refCount;
};

}

#endif
