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

#ifndef _KR_BASE_H_
#define _KR_BASE_H_

#ifdef __cplusplus
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#endif

#ifdef OS_WIN32
#define OS_NAME "win32"
#elif defined(OS_OSX)
#define OS_NAME "osx"
#elif defined(OS_LINUX)
#define OS_NAME "linux"
#endif

#ifdef OS_64
#define OS_TYPE "64bit"
#else
#define OS_TYPE "32bit"
#endif

#ifdef USE_NO_EXPORT
#define TIDE_API
#else
#if defined(OS_OSX) || defined(OS_LINUX)
#define EXPORT __attribute__((visibility("default")))
#define TIDE_API EXPORT
#elif defined(OS_WIN32)
# ifdef TIDE_API_EXPORT
#  define TIDE_API __declspec(dllexport)
# else
#  define TIDE_API __declspec(dllimport)
# endif
# define EXPORT __declspec(dllexport)
#endif
#endif

#ifdef OS_WIN32
#ifndef WINVER
#define WINVER 0x0502
#pragma warning(disable: 4005)  // turn off #define redefinition warnings
#pragma warning(disable: 4996)
//#define _CRT_SECURE_NO_WARNINGS  // turn off string safe warnings
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0502
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x600
#endif
#endif


#define VAL(str) #str
#define STRING(str) VAL(str)

#ifndef _PRODUCT_NAME
   #define _PRODUCT_NAME Kroll
#endif

#define PRODUCT_NAME STRING(_PRODUCT_NAME)

#ifndef GLOBAL_NS_VARNAME
  #define GLOBAL_NS_VARNAME STRING(_GLOBAL_NS_VARNAME)
#endif

#ifndef CONFIG_FILENAME
  #define CONFIG_FILENAME STRING(_CONFIG_FILENAME)
#endif

#define PRODUCT_VERSION STRING(_PRODUCT_VERSION)


// define a macro that points to the name of the enclosing function where
// referenced or if not supported on target compiler, just default to filename
#ifndef OS_WIN32
#define KR_FUNC __PRETTY_FUNCTION__
#else
#define KR_FUNC __FILE__
#endif

#ifdef DEBUG
#define KR_DUMP_LOCATION std::cout << "[" << KR_FUNC << "::" << __LINE__ << "]" << std::endl;
#else
#define KR_DUMP_LOCATION
#endif

#define KR_UNUSED(o) if (o) {}

// this was borrowed from Google Gears
// A macro to disallow the evil copy constructor and operator= functions.
// This should be used in the private: declaration for a class.
#define DISALLOW_EVIL_CONSTRUCTORS(TypeName)    \
  TypeName(const TypeName&);                    \
  void operator=(const TypeName&)


#if defined(OS_WIN32)
#ifndef WINVER
#define WINVER 0x0501
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x600
#endif
#endif

#ifdef DEBUG
#include <sstream>
#define PRINTD(x) { std::ostringstream ostr; ostr << x; tide::Logger* logger = tide::Logger::GetRootLogger(); logger->Debug(ostr.str()); };
#else
#define PRINTD(x)
#endif

#endif
