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

#ifndef _NATIVE_WINDOW_H_
#define _NATIVE_WINDOW_H_

#import "../ui_module.h"
#import <Cocoa/Cocoa.h>

#ifndef TIDE_LITE
#import <WebKit/WebInspector.h>
#endif

@class WebViewDelegate;

using namespace ti;

#ifndef TIDE_LITE
@interface NativeWindow : NSWindow <NSWindowDelegate>
{
    BOOL canReceiveFocus;
    WebView* webView;
    WebViewDelegate* delegate;
    BOOL requiresDisplay;
    AutoPtr<OSXUserWindow>* userWindow;
    WebInspector* inspector;
    BOOL fullscreen;
    BOOL focused;
    NSRect savedFrame;
}
- (void)setUserWindow:(AutoPtr<OSXUserWindow>*)inUserWindow;
- (void)setupDecorations:(AutoPtr<WindowConfig>)config;
- (void)setTransparency:(double)transparency;
- (void)setFullscreen:(BOOL)yn;
- (void)close;
- (void)finishClose;
- (void)open;
- (void)frameLoaded;
- (WebView*)webView;
- (OSXUserWindow*)userWindow;
- (void)showInspector:(BOOL)console;
@end
#else
@interface NativeWindow : NSWindow <NSWindowDelegate>
{
    BOOL canReceiveFocus;
    WebView* webView;
    WebViewDelegate* delegate;
    BOOL requiresDisplay;
    AutoPtr<OSXUserWindow>* userWindow;
    BOOL fullscreen;
    BOOL focused;
    NSRect savedFrame;
}
- (void)setUserWindow:(AutoPtr<OSXUserWindow>*)inUserWindow;
- (void)setupDecorations:(AutoPtr<WindowConfig>)config;
- (void)setTransparency:(double)transparency;
- (void)setFullscreen:(BOOL)yn;
- (void)close;
- (void)finishClose;
- (void)open;
- (void)frameLoaded;
- (WebView*)webView;
- (OSXUserWindow*)userWindow;
@end
#endif

#endif