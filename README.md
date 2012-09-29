TideSDK
=======

TideSDK (formerly Titanium Desktop) is a remarkable project inherited from Appcelerator. It is now managed as community open source project by group dedicated to the availability of this unique solution. 

The ability to deploy a Webkit-based desktop application across all three major desktop operating systems, with privileged access to native APIs, has empowered web developers to escape the browser and deliver rich, "always on" desktop apps. 

Users create applications using familiar HTML5, JavaScript and CSS technologies. Beyond this, the unique support for Python, PHP and Ruby extend the capabilities of TideSDK beyond the realm of any competitive framework. Further, our plans include the expansion and extension TideSDK's API's for even better, more complex, and reliable user experiences on the desktop as we move forward.

## Tide MicroKernel

TideSDK has a compact microkernel written in C++ for running pluggable
modules. The microKernel supports a cross-language, cross-platform 'binding' and invocation framework which supports mixing and matching code. This means you can pass a Javascript object to a Python function and so on.

Tide currently supports the following languages:

- C/C++
- Python
- Ruby
- PHP
- JavaScript

That said, any C/C++ exposed language that supports embedding can
be supported without much effort. Possibilities for the future include:

- Lua
- Falcon
- C# (maybe through Mono)
- Java

## The Module API

The Module API is simple but powerful. Modules to extend the api may be written in C++ or even in the supported languages like Python. Once the module
is loaded, you can can do anything you wish with its functionality.

## The Binding API

A Module communicates to other modules through 'binding'. Binding is the process of either adding values (primitive, objects, functions etc) to the SDK runtime or retrieving them.  There are also a small number of other utility functions such as logging etc that are exposed through the API module.

The binding implementation for each language knows how to exchange values between the SDK runtime and the native language runtime. This is the some of the magic of TideSDK.

As an extreme example, you could invoke a function from Ruby which might take a Python function as a reference and return a Javascript object.


Getting and Using TideSDK
-------------------------

Downloads are available for the previous Titanium Desktop 1.2.0.RC4 in the interim while we prepare for our 1.3.0-beta release.

* [https://github.com/TideSDK/TideSDK/downloads](https://github.com/TideSDK/TideSDK/downloads)

APIs will remain compatible between 1.2.0.RC4 and 1.3.x however the JavaScript namespace will be shortened to 'Ti' as opposed to the former 'Titanium'.

Our enhanced documentation efforts are in progress. The link below with take your to the most current docs. Additional support is available though our Wiki. Our future efforts will be on creating focused guides to assist users.


Building TideSDK (Developers)
-----------------------------

This instruction applies to developers only. If you are a user, will will only need to download and install TideSDK to use it. Please refer to https://github.com/TideSDK/TideSDK/wiki/Building-tidesdk
for up to date instructions on how to build this TideSDK.

Support
-------
- Documentation: [http://tidesdk.multipart.net/docs/user-dev/generated](http://tidesdk.multipart.net/docs/user-dev/generated)
- Source Code: [https://github.com/TideSDK/TideSDK](https://github.com/TideSDK/TideSDK)
- Tutorials: Get started easily [http://tidesdk.multipart.net/docs/user-dev/generated/#!/guide](http://tidesdk.multipart.net/docs/user-dev/generated/#!/guide)
- Wiki: Access additional resources in our wiki [https://github.com/TideSDK/TideSDK/wiki](https://github.com/TideSDK/TideSDK/wiki) 
- Report a Bug: Help us improve [https://github.com/TideSDK/TideSDK/issues](https://github.com/TideSDK/TideSDK/issues).
- IRC: Chat with us on #tidesdk on freenode.net
- Twitter: Follow TideSDK [@tidesdk](http://twitter.com/tidesdk).
- Blog: Read our blog at [http://tidesdk.org/blog](http://tidesdk.org/blog).
- Mailing List: Join our mailing list at [https://groups.google.com/forum/#!forum/tidesdk](https://groups.google.com/forum/#!forum/tidesdk).

Legal
-----
TideSDK is licensed under a liberal Apache 2.0 license.
Please see LICENSE for more details.