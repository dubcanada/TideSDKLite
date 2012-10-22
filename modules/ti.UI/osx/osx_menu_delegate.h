/**
 * Appcelerator Titanium - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2008 Appcelerator, Inc. All Rights Reserved.
 */

@interface OSXMenuDelegate : NSObject <NSMenuDelegate>
{
	ti::OSXMenu* menu;
	BOOL dirty;
	BOOL registerNative;
}
- (id)initWithMenu:(ti::OSXMenu*)menu willRegister:(BOOL)willRegister;
- (NSInteger)numberOfItemsInMenu:(NSMenu *)menu;
- (void)menuNeedsUpdate:(NSMenu *)menu;
- (void)markAsDirty;
@end
