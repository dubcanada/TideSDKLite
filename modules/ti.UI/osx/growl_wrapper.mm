/**
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 Steven Verbeek
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
**/

#import "growl_wrapper.h"

@implementation growlWrapper

// Register for Growl using tiGrowl as the application name
// TODO: Make it so the application name is the name of the application, rather then tiGrowl
-(NSDictionary *)registrationDictionaryForGrowl {
    NSArray *notifications = [NSArray arrayWithObject:@"tiGrowl"];
    return [NSDictionary dictionaryWithObjectsAndKeys: @"tiGrowl", GROWL_APP_ID, @"tiGrowl", GROWL_APP_NAME, notifications, GROWL_NOTIFICATIONS_ALL, notifications, GROWL_NOTIFICATIONS_DEFAULT, nil];
}

// Function to show growl notification
void showGrowlMessage(NSInteger priority, NSString *title, NSString *desc, CFDataRef iconData)
{
    growlWrapper *growlDelegate;
    growlDelegate = [[growlWrapper alloc] init];
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSData *icon = (NSData *)iconData;

    [GrowlApplicationBridge setGrowlDelegate:growlDelegate];
    [GrowlApplicationBridge notifyWithTitle: title
                                description: desc
                           notificationName: @"tiGrowl"
                                   iconData:icon
                                   priority:priority
                                   isSticky:NO
                               clickContext:nil];
    // TODO: Memory check, make sure this is being released properly and there isn't any memory leaks
    [pool drain];
}

@end