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

#include "../ui_module.h"

namespace ti
{
Win32WebKitResourceLoadDelegate::Win32WebKitResourceLoadDelegate(Win32UserWindow* userWindow) :
    userWindow(userWindow),
    refCount(1)
{

}

ULONG STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::AddRef()
{
    return ++refCount;
}

ULONG STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::Release()
{
    ULONG newCount = --refCount;
    if (!newCount)
        delete(this);
    return newCount;
}

HRESULT STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::QueryInterface(
    REFIID riid, void **ppvObject)
{
    *ppvObject = 0;
    if (IsEqualGUID(riid, IID_IUnknown))
        *ppvObject = static_cast<IWebResourceLoadDelegate*>(this);
    else if (IsEqualGUID(riid, IID_IWebResourceLoadDelegate))
        *ppvObject = static_cast<IWebResourceLoadDelegate*>(this);
    else
        return E_NOINTERFACE;

    AddRef();
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::identifierForInitialRequest(
    /* [in] */ IWebView *webView,
    /* [in] */ IWebURLRequest *request,
    /* [in] */ IWebDataSource *dataSource,
    /* [in] */ unsigned long identifier)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::willSendRequest(
    /* [in] */ IWebView *webView,
    /* [in] */ unsigned long identifier,
    /* [in] */ IWebURLRequest *request,
    /* [in] */ IWebURLResponse *redirectResponse,
    /* [in] */ IWebDataSource *dataSource,
    /* [retval][out] */ IWebURLRequest **newRequest)
{
    BSTR u;
    request->URL(&u);
    std::wstring u2(u);
    std::string url(::WideToUTF8(u2));
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::didReceiveAuthenticationChallenge(
    /* [in] */ IWebView *webView,
    /* [in] */ unsigned long identifier,
    /* [in] */ IWebURLAuthenticationChallenge *challenge,
    /* [in] */ IWebDataSource *dataSource)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::didCancelAuthenticationChallenge(
    /* [in] */ IWebView *webView,
    /* [in] */ unsigned long identifier,
    /* [in] */ IWebURLAuthenticationChallenge *challenge,
    /* [in] */ IWebDataSource *dataSource)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::didReceiveResponse(
    /* [in] */ IWebView *webView,
    /* [in] */ unsigned long identifier,
    /* [in] */ IWebURLResponse *response,
    /* [in] */ IWebDataSource *dataSource)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::didReceiveContentLength(
    /* [in] */ IWebView *webView,
    /* [in] */ unsigned long identifier,
    /* [in] */ UINT length,
    /* [in] */ IWebDataSource *dataSource)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::didFinishLoadingFromDataSource(
    /* [in] */ IWebView *webView,
    /* [in] */ unsigned long identifier,
    /* [in] */ IWebDataSource *dataSource)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::didFailLoadingWithError(
    /* [in] */ IWebView *webView,
    /* [in] */ unsigned long identifier,
    /* [in] */ IWebError *error,
    /* [in] */ IWebDataSource *dataSource)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Win32WebKitResourceLoadDelegate::plugInFailedWithError(
    /* [in] */ IWebView *webView,
    /* [in] */ IWebError *error,
    /* [in] */ IWebDataSource *dataSource)
{
    return E_NOTIMPL;
}
}
