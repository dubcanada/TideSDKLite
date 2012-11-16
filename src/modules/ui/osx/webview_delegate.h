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

#import "../ui_module.h"
#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

#ifndef TIDE_LITE
#import <WebKit/WebViewPrivate.h>
#import <WebKit/WebInspector.h>
#import <WebKit/WebScriptDebugDelegate.h>
#import <WebKit/WebScriptObject.h>
#import <WebKit/WebPreferencesPrivate.h>

@class NativeWindow;
@interface WebViewDelegate : NSObject
{
    NativeWindow* window;
    Host* host;
    WebInspector* inspector;
    BOOL initialDisplay;
    std::map<WebFrame*, TiObjectRef>* frameToGlobalObject;
    Logger* logger;
}
-(id)initWithWindow:(NativeWindow*)window;
-(void)setupPreferences;
-(void)registerGlobalObject:(TiObjectRef) globalObject forFrame:(WebFrame *)frame;
-(TiObjectRef)registerJSContext:(JSGlobalContextRef)context forFrame:(WebFrame*)frame;
-(BOOL)isGlobalObjectRegisteredForFrame:(WebFrame*) frame;
-(TiObjectRef)globalObjectForFrame:(WebFrame*) frame;
-(void)deregisterGlobalObjectForFrame:(WebFrame *)frame;
@end
#endif

#ifdef TIDE_LITE
#import <WebKit/WebScriptObject.h>

@class NativeWindow;
@interface WebViewDelegate : NSObject
{
    NativeWindow* window;
    Host* host;
    BOOL initialDisplay;
    std::map<WebFrame*, TiObjectRef>* frameToGlobalObject;
    Logger* logger;
}
-(id)initWithWindow:(NativeWindow*)window;
-(void)setupPreferences;
-(void)registerGlobalObject:(TiObjectRef) globalObject forFrame:(WebFrame *)frame;
-(TiObjectRef)registerJSContext:(JSGlobalContextRef)context forFrame:(WebFrame*)frame;
-(BOOL)isGlobalObjectRegisteredForFrame:(WebFrame*) frame;
-(TiObjectRef)globalObjectForFrame:(WebFrame*) frame;
-(void)deregisterGlobalObjectForFrame:(WebFrame *)frame;
@end
#endif
