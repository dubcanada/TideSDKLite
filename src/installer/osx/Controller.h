/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
* Copyright (c) 2012 Mital Vora
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

#import <Cocoa/Cocoa.h>
#import "Downloader.h"
#import <tideutils/file_utils.h>
#import <tideutils/boot_utils.h>
#import <tideutils/application.h>
using namespace TideUtils;
using TideUtils::Application;
using TideUtils::SharedApplication;
using TideUtils::KComponentType;
SharedApplication app;

@interface Job : NSObject {
    NSURL* url; 
    NSString* path; 
    BOOL isUpdate; 
}
-(Job*)init:(NSString*)pathOrURL;
-(Job*)initUpdate:(NSString*)pathOrURL;
-(NSURL*)url;
-(NSString*)path;
-(void)setPath:(NSString*)newPath;
-(BOOL)needsDownload;
-(BOOL)isUpdate;
-(int)totalDownloads;
-(int)totalJobs;
@end

@interface Controller : NSObject {
    IBOutlet NSWindow* progressWindow;
    IBOutlet NSProgressIndicator* progressBar;
    IBOutlet NSButton* progressCancelButton;
    IBOutlet NSTextField* progressText;
    IBOutlet NSImageView* progressImage;
    IBOutlet NSTextField* progressAppName;
    IBOutlet NSTextField* progressAppVersion;
    IBOutlet NSTextField* progressAppPublisher;
    IBOutlet NSTextField* progressAppURL;

    IBOutlet NSWindow* introWindow;
    IBOutlet NSTextField* introLicenseLabel;
    IBOutlet NSBox* introLicenseBox;
    IBOutlet NSTextView* introLicenseText;

    IBOutlet NSImageView* introImage;
    IBOutlet NSTextField* introAppName;
    IBOutlet NSTextField* introAppVersion;
    IBOutlet NSTextField* introAppPublisher;
    IBOutlet NSTextField* introAppURL;

    NSMutableArray *jobs;
    NSString *temporaryDirectory;
    NSString *installDirectory;
    NSString *updateFile;
    BOOL skipIntroDialog;
}

-(IBAction)cancelProgress:(id)sender;
-(IBAction)cancelIntro:(id)sender;
-(IBAction)continueIntro:(id)sender;
-(void)updateMessage:(NSString*)msg;
-(NSString*)temporaryDirectory;
-(NSString*)installDirectory;
-(void)finishInstallation;
-(void)downloadAndInstall:(Controller*)controller;
-(void)install:(Job*)job;
-(void)downloadJob:(Job*)job atIndex:(int)index;
-(void)setupDialogs;
-(void)createInstallerMenu:(NSString*)applicationName;
-(void)showIntroDialog;

@end
