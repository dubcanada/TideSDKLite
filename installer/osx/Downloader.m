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

#import "Downloader.h"
#define STRING(str) #str

@implementation Downloader

-(id)initWithURL:(NSURL*)url progress:(NSProgressIndicator*)p
{
    self = [super init];

    suggestedFilename = nil;
    userAgent = nil;
    downloadRequest = nil;
    downloadConnection = nil;
    data = nil;

    if (self)
    {
        progress = [p retain];
        [progress startAnimation:self];
        [self performSelectorOnMainThread:@selector(startUrlRequest:) withObject:url waitUntilDone:YES];
    }

    userAgent = [NSString stringWithFormat:
        @"Mozilla/5.0 (compatible; Titanium_Downloader/%s; Mac)",
        STRING(_PRODUCT_VERSION)];

    return self;
}

- (void)startUrlRequest: (NSURL *)url;
{
    [data release];
    data = [[NSMutableData alloc] init];

    [downloadRequest release];
    downloadRequest = [[NSMutableURLRequest alloc] initWithURL:url];
    [downloadRequest setValue:userAgent forHTTPHeaderField:@"User-Agent"];

    downloadConnection = [[NSURLConnection alloc] initWithRequest:downloadRequest delegate:self];

    // NOTE: Do not call start!! it's automatically called and you will segfault if you call it
    [self setCompleted:NO];
}

-(void)dealloc
{
    [downloadRequest release];
    [suggestedFilename release];
    [downloadConnection release];
    [progress release];
    [data release];
    [super dealloc];
}

-(NSData*)data
{
    return data;
}

- (NSString *)suggestedFilename 
{
    return suggestedFilename;
}

- (BOOL)completed;
{
    return completed;
}

- (void)setCompleted:(BOOL)value;
{
    completed = value;
    if (completed) 
    {
        [progress stopAnimation:self];
    } 
    else 
    {
        [progress startAnimation:self];
    }
}

-(BOOL)isDownloadComplete
{
    return completed;
}

#pragma mark NSURLConnection delegate methods

//
// NSURLConnection Delegate Methods
//

// Part of this code courtesy of google mac toolkit

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response
{
    [data setLength:0];
    expectedBytes = [response expectedContentLength];

    [suggestedFilename release];
    suggestedFilename = [[response suggestedFilename] retain];

    NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*) response;
    NSLog(@"Received %i for %@ (suggested filename=%@)", 
        [httpResponse statusCode], [response URL], suggestedFilename);
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)newData
{
    [data appendData:newData];
    if (expectedBytes != 0) 
    {
        [progress setIndeterminate:NO];
        [progress setMaxValue:(double)expectedBytes];
        [progress setDoubleValue:(double)[data length]];
    }
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error
{
    NSLog(@"Connection failed with error: %@", [error localizedDescription]);
    [progress setIndeterminate:YES];
    [self setCompleted:YES];
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection;
{
    NSLog(@"Connection finished loading");
    [self setCompleted:YES];
}

-(NSURLRequest *)connection:(NSURLConnection *)connection
    willSendRequest:(NSURLRequest *)request
    redirectResponse:(NSURLResponse *)redirectResponse
{
    if (redirectResponse)
        NSLog(@"Redirecting from %@ to %@", [redirectResponse URL], [request URL]);

    return request;
}

@end
