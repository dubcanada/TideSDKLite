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

#include "../utils.h"
#include <Foundation/Foundation.h>

namespace UTILS_NS
{

std::string CFStringToUTF8(CFStringRef cfstring)
{
    CFIndex length = CFStringGetLength(cfstring);
    if (length == 0)
        return std::string();

    CFRange wholeString = CFRangeMake(0, length);
    CFIndex outSize;
    CFIndex converted = CFStringGetBytes(cfstring,
        wholeString,
        kCFStringEncodingUTF8,
        0,      // lossByte
        false,  // isExternalRepresentation
        NULL,   // buffer
        0,      // maxBufLen
        &outSize);

    if (converted == 0 || outSize == 0)
        return std::string();

    // outSize is the number of UInt8-sized units needed in the destination.
    // A buffer allocated as UInt8 units might not be properly aligned to
    // contain elements of std::string::value_type.  Use a container for the
    // proper value_type, and convert outSize by figuring the number of
    // value_type elements per UInt8.  Leave room for a NUL terminator.
    std::string::size_type elements = outSize + 1;

    std::vector<std::string::value_type> outBuffer(elements);
    converted = CFStringGetBytes(cfstring,
        wholeString,
        kCFStringEncodingUTF8,
        0,      // lossByte
        false,  // isExternalRepresentation
        reinterpret_cast<UInt8*>(&outBuffer[0]),
        outSize,
        NULL);  // usedBufLen

    if (converted == 0)
        return std::string();

    outBuffer[elements - 1] = '\0';
    return std::string(&outBuffer[0], elements - 1);
}

CFStringRef UTF8ToCFString(const std::string& input)
{
    std::string::size_type length = input.length();
    if (length == 0)
        return CFSTR("");

    return CFStringCreateWithBytes(kCFAllocatorDefault,
        reinterpret_cast<const UInt8*>(input.data()),
        length * sizeof(std::string::value_type),
        kCFStringEncodingUTF8, false);
}

std::string CFErrorToString(CFErrorRef cferror)
{
    CFStringRef cferrorString = CFErrorCopyDescription(cferror);
    std::string errorString("Could not get error string");
    if (cferrorString)
    {
        errorString = CFStringToUTF8(cferrorString);
        CFRelease(cferrorString);
    }
    CFRelease(cferror);

    return errorString;
}

}