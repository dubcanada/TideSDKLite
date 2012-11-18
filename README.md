TideSDK
=======

Current Build Status
[![Build Status](https://travis-ci.org/TideSDK/TideSDK.png)](https://travis-ci.org/TideSDK/TideSDK)
*realtime build only tests linux*

Create multi-platform desktop apps with HTML5, CSS3 and JavaScript. TideSDK is the best way to create beautiful, unique desktop apps using your web development skills. TideSDK is open source and driven by a collaborative, world wide effort involving a skilled team together with variety of open source contributors.

TideSDK supports the use of Python, PHP and Ruby. This provides capabilities beyond the realm of any competitive framework. Our plans include the expansion and extension TideSDK's API's for even better, more complex, and reliable user experiences on the desktop as we move forward.

TideSDK is a significant and substantial software project and became an 'Affiliate Project' of SPI ([Software in the Public Interest](http://spi-inc.org/projects)) as of September 2012. As an 'Affiliate Project' TideSDK in the company of other important open source projects such as Postgres, Debian, ArchLinux, Drupal, and Jenkins CI that are also non profit. Beyond recogition and credibility, our affiliation also allows us to raise funds through donations for the viability and long term future of the project.

We currently have a strong core team of talented individuals dedicated to this solution. As an open solution, we welcome code and documention contributions. Other displays of support for the project (such tweeting or blogging about TideSDK) is also greatly appreciated.

If you like or use TideSDK in your development or your business, your financial support can help our development efforts. The TideSDK codebase is more complex and requires dedicated time of programmers with deeper programming knowledge to ensure it remains available. Donations are completely tax deductible in the USA. Cloud servers for our CI (Continuous Integration) system are also a great way to say thank you. Please get in touch with us if this is something you can offer. A minimum 1GB RAM machine (or Virtual Machine) using one of the supported operating systems is sincerely appreciated.

## Tide MicroKernel

TideSDK has a compact microkernel written in C++ for running pluggable
modules. The microKernel supports a cross-language, cross-platform 'binding' and invocation framework. Simply put, the provides developers with the capability to pass objects between languages (ie. pass a JavaScript object to a Python function and so on).

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

The supported languages may be embedded in the DOM or included by reference in your application code.

## The Module API

The Module API is simple but powerful. Modules to extend the api may be written in C++ or even in the supported languages like Python. Once the module
is loaded, you can can do anything you wish with its functionality.

## The Binding API

A Module communicates to other modules through 'binding'. Binding is the process of either adding values (primitive, objects, functions etc) to the SDK runtime or retrieving them. A number of other utility functions including logging are exposed through the API module.

The binding implementation for each language knows how to exchange values between the SDK runtime and the native language runtime. This is the some of the magic of TideSDK.

Getting and Using TideSDK
-------------------------

TideSDK is available for download at:

* [http://tidesdk.org](http://tidesdk.org)

Enhanced documentation efforts are a work in progress and we are always looking to improve. The link below with take your to the most current docs. Additional support is available though our Wiki. We are also focused on the development of guides on our documentation site. Each guide serves as a tutorial on a development topic. Please consider contributing time to enhance our documentation or to contribute guide.

Building TideSDK (Developers)
-----------------------------

NOTE: If you want to develop applications with TideSDK, just download and install TideSDK to use it.

For SDK Developers, please refer to https://github.com/TideSDK/TideSDK/wiki/Building-tidesdk
for up-to-date build instructions.

Support
-------
- Documentation: [http://tidesdk.multipart.net/docs/user-dev/generated](http://tidesdk.multipart.net/docs/user-dev/generated)
- Source Code: [https://github.com/TideSDK/TideSDK](https://github.com/TideSDK/TideSDK)
- Tutorials: Get started easily [http://tidesdk.multipart.net/docs/user-dev/generated/#!/guide](http://tidesdk.multipart.net/docs/user-dev/generated/#!/guide)
- Q &amp; A on Stack Overflow: Get help [http://stackoverflow.com/questions/tagged/tidesdk](http://stackoverflow.com/questions/tagged/tidesdk)
- Report a Bug: Help us improve [https://github.com/TideSDK/TideSDK/issues](https://github.com/TideSDK/TideSDK/issues).
- IRC: Chat with us on #tidesdk on freenode.net
- Twitter: Follow TideSDK [@tidesdk](http://twitter.com/tidesdk).
- Blog: Read our blog at [http://tidesdk.org/blog](http://tidesdk.org/blog).
- Knowledge Base: Read the wiki [https://github.com/TideSDK/TideSDK/wiki](https://github.com/TideSDK/TideSDK/wiki) 
- Google Groups: Join our mailing list [https://groups.google.com/forum/#!forum/tidesdk](https://groups.google.com/forum/#!forum/tidesdk).

Legal
-----
TideSDK is licensed under the Apache 2.0 license. See LICENSE for more details.
