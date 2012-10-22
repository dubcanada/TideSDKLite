/**
* This file has been modified from its orginal sources.
*
* (c) 2012 David Pratt
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
* (c) 2008-2012 Appcelerator Inc.
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


@interface Downloader :  NSObject {
	NSString* suggestedFilename;
	NSString* userAgent;
	NSMutableURLRequest* downloadRequest;
	NSURLConnection* downloadConnection;
	NSProgressIndicator* progress;
	NSMutableData* data;

	long long expectedBytes;
	BOOL completed;
}
-(id)initWithURL:(NSURL*)url progress:(NSProgressIndicator*)p;
-(BOOL)isDownloadComplete;
-(BOOL)completed;
-(void)setCompleted:(BOOL)value;
-(NSString*)suggestedFilename;
-(NSData*)data;
@end