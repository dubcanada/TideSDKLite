#Getting Started with TideSDK

__Author:__ David Pratt

## What is TideSDK?

TideSDK is an open source software development kit for creating multi-platform desktop apps using HTML5, CSS3, and JavaScript. With TideSDK you can also use other common scripting languages such as Python, PHP or Ruby to harness the skills you already possess as a web developer. TideSDK is the best way to create unique desktop apps using simple web technologies. 

Source code for the TideSDK project is hosted on GitHub. You can reach support resources including comprehensive API documentation by visiting our site at http://tidesdk.org. TideSDK also has an extensive global developer community. Thousands of developers use and trust our technology to develop desktop apps. Perhaps one of the most recognized applications is Wunderlist.

As a project, we have a core team of talented programmers, developers, and UI & design professionals. We welcome your contributions and other forms of support for the project.

TideSDK has recently become an 'Affiliate Project' of software in the Public Interest. As an 'Affiliate Project' we are in the company of other important open source projects such as PostgreSQL, Debian, ArchLinux, Drupal, and Jenkins CI and we are also non-profit. Beyond recogition and credibility, our affiliation also allows us to raise funds through donations for the viability and long term future of the project. If you like or use TideSDK in your development or your business, please assist with your financial support. Donations are tax deductible in the USA.

This Getting Started Guide will demonstrate simple steps to get started with the the 1.3.1-beta. Please [follow @tidesdk on twitter] for updates and announcements as continue toward the 1.4.0 stable release.

[follow @tidesdk on twitter]: http://twitter.com/tidesdk

## TideSDK 1.3.1

TideSDK 1.3.1 contains improvements, bug fixes and a few important and breaking changes with legacy code that you need to know about. Please consult the following document:

[https://github.com/TideSDK/TideSDK/blob/master/CHANGES](https://github.com/TideSDK/TideSDK/blob/master/CHANGES)

## How Do I Develop a TideSDK App?

TideSDK can be used with no more than a basic text editor. You do not need any special tools or an IDE (although many developers prefer richer tools). For the legacy 1.3.1 you can develop using the SDK in one of three ways:

1. Using the SDK with a editor and the TideSDK Developer app
2. Using the SDK with a editor and the tidebuilder CLI

At the time of writing this guide, the maintainer of Titanium Studio have not yet updated their plugin to use TideSDK.

In this Guide, we are going to get you started using using the TideSDK Developer.

TideSDK also includes a 'tidebuilder.py` CLI that you can use to run your app locally for development and debugging. You can also package it with an installer native to the platform (Windows, Mac OSX and Linux are supported). To get all the needed installers, a typical TideSDK development environment will include a physical or virtual machine for each OS.

### Alright, Let's Get Going

So enough already, let's get going. This guide walks you through the following steps:

* Downloading and Extracting the SDK
* Downloading the installing the TideSDK Developer app
* Obtain the Hello-World example app
* Importing the example app into TideSDK Developer
* Running the example app
* Packaging the example app locally with tibuild CLI

#### STEP 1: Download and extract the SDK

To get the SDK, visit [tidesdk.org] and download the right SDK version for your OS.

[tidesdk.org]: http://tidesdk.org#download

The 1.3.1 SDK must be extracted into a specific folder for your operating system:

For Mac OSX:

    ~/Library/Application Support/TideSDK

_Heads up! This is the library folder inside your user folder, NOT the global library folder._

On Linux:

    ~/.tidesdk

On Windows XP:

    C:\Documents and Settings\All Users\Application Data\TideSDK

On Windows 7:

    C:\ProgramData\TideSDK

_Heads up!_    
On windows, you also need this for packaging your apps:

* [Imagemagick]
* [Wix 3.0]

[Imagemagick]: http://www.imagemagick.org
[Wix 3.0]: http://wix.codeplex.com/releases/view/44406

The zip file will expand the contents and create/overlay some new directories for 1.3.1-beta

#### STEP 2: Download the TideSDK Developer App

While TideSDK can be used with no more than a basic text editor, using an app to create, run, and bundle your app is recommended until you learn a bit more about the SDK.

The TideSDK Developer app is suitable for this purpose. TiDev Community has been reworked to use TideSDK. The 1.5 series of TideSDK Developer will have a fresh new inteface to make your use of it much more enjoyable. Stay tuned for this in the near future.

To get TideSDK Developer, visit [tidesdk.org]

Use the same 'Download 1.3.1' button. Below the SDK downloads, you will find buttons to download the Developer App for each platform

[tidesdk.org]: http://tidesdk.org#download

#### STEP 3: Obtain the Hello World Example App

For your first app, a simple Hello World example is a good introduction. The Hello World app illustrates the following:

* The use of the API to create a menu
* Adding a menu item to a menu with a simple callback to prompt the user to exit the app
* Displaying content using HTML and CSS.

To get the TideSDK-HelloWorld app, you can either clone the app if you have git installed, or download the zip from the following location:

[https://github.com/TideSDK/TideSDK-HelloWorld](https://github.com/TideSDK/TideSDK-HelloWorld)

{@img download.jpg}

#### STEP 4: Importing the Example App into TideSDK Developer

To import the Hello World example app into TideSDK Developer, click on the 'Import' button at the top left, navigate to the folder containing the app and select it.

{@img developer_import.jpg Click the "Import Project" button}

#### STEP 5: Running the Example App

To run the Hello World app, click on 'Test & Package' button in the TideSDK Developer menu, then click on the 'Launch App' button in the lower left. The Hello World app will start and will log to the screen. Debugging statements you include in your code will appear.

{@img developer_launch.jpg Launch the Example App from the Test&Package section.}

{@img developer_running.jpg The running Hello World app}

#### STEP 6: Bundling the Example App

To bundle the Hello World app, click on 'Test & Package' button in the TideSDK Developer. Then click the 'Package with Runtime'. You distribution will be created in the 'dist' folder in your project.




##Packaging the Example App Locally with the CLI

Within the SDK you download, a small CLI called tidebuilder.py is available. You can used this tool for running your app or bundling your app for distribution. tidebuilder.py has built-in help to explain the options that be given. For sample options for using tidebuild.py, refer to the following document in the TideSDK wiki:

https://github.com/TideSDK/TideSDK/wiki/Packaging-TideSDK-apps




## How Does TideSDK Work

A TideSDK project consists of a boilerplate structure including a Resources folder that contains the core project files. Resources include HTML, JavaScript, and CSS files along with any audio, video, images, or other media and script files. In addition, you can use any Javascript or CSS frameworks that you want (such as Backbone.js, Twitter Bootstrap or others) that will work within the browser.

The following illustrates the stucture of a simple Hello World app that will run on all supported plaforms:


		├── CHANGELOG.txt
		├── LICENSE.txt
		├── README.md
		├── Resources
		│   ├── app.js
		│   ├── default_app_logo.png
		│   └── index.html
		├── manifest
		└── tiapp.xml


What follows provides some detail about the general structure of the application.

### Resources

All files included in the Resources folder are packaged and available to your app. Within your app, you can use `app://` URLs to refer to files within the Resources folder. For instance, `app://images/logo.png` will refer to `Resources/images/logo.png`.

Applications resources are used in conjunction with a WebKit client and a familiar and extensive API. The API is privileged, providing filesystem access that allows you to read and manage files. APIs are also provided to create and interact with a local database. Network API allows to create clients and servers or to interface with HTTP at a much lower level. It is also possible to open socket connections to other services.

The heart of TideSDK is an object bridge compiled into the WebKit component. The bridge allows other scripting languages - python, php or ruby - to run on the HTML page using script tags in the DOM, just like JavaScript. You can also directly call .py, .rb or .php files from within your application.

Additional functionality in your app can also be obtained using mature libraries in python, php or ruby. It is also possible to embed binaries directly into the Resources folder for advanced use cases.

TideSDK also includes wrappers around Desktop features such as notifications, tray icons, and window menus. This allows you to create applications with native features for all major operating systems.

In the example above, app.js contains the JavaScript included by reference within the HTML file. default_app_logo.png is the image that will appear by default in the dock, system tray or in the windows of your app.

The structure within the Resources file is largely up to you and is very much like developing a web app with an index.html as the starting point for the app when it is started and run. For the small hello world we've taken a very simple approach.

The following is the contents of the app.js file:


	// create and set menu
	var menu = Ti.UI.createMenu(),
	    fileItem = Ti.UI.createMenuItem('File'),
	    exitItem = fileItem.addItem('Exit', function() {
	      if (confirm('Are you sure you want to quit?')) {
	        Ti.App.exit();
	      }
	    });

	menu.appendItem(fileItem);
	Ti.UI.setMenu(menu);


Here is the HTML for the same app. It calls the script above.


	<!DOCTYPE html>
	<html>
	<head>
	  <title>Hello World</title>
	  <style type="text/css">
	    body {background: #fff;}
	  </style>
	</head>
	<body>
	  <h1>Hello World</h1>
	  <script type="text/javascript" src="app.js"></script> 
	</body>
	</html>


In less than 10 lines of JavaScript code, we create a menu, adding 'File' and 'Exit' menu items, and set it to the main window. A simple callback method is used to pop open a exit confirmation dialog. If the user confirms, the app will exit.

The Hello World app is a very basic illustration of a TideSDK app. Our TideBuilder app in GitHub is an example of an app that illustrates a modular approach to development that includes using Backbone, Bootstrap and require.js.

For TideSDK 1.4.0, CommonJS will be fully integrated to provide the highest level of modular development using JavaScript.

### CHANGLOG.txt

This file is a log or record of changes to your app including fixes, features, and updates over its release history.

### LICENSE.txt

The  LICENSE.txt file should be filled with the license you have applied to your software. When a user runs your app for the first time, the LICENSE.txt will be dispayed. This user will be given an opportunity to agree to the license to proceed.

### README.md

A README.md can provide some general information including a description of the software. Since many organizations use git and GitHub, the README.md can be used to communicate about your TideSDK project.

### Manifest and Activating a Language Module

The manifest contains information about the runtime modules used by the project. If you use the TideSDK Developer app, you don't have to modify this file manually.


	#appname:HelloWorld
	#appid:com.tidesdk.helloworld
	#publisher:Software in the Public Interest (SPI) Inc
	#image:default_app_logo.png
	#url:http//tidesdk.org
	#guid:845e9c3c-c9ff-4ad4-afdf-9638092f044f
	#desc:Sample Hello World application
	#type:desktop
	runtime:1.3.1-beta
	app:1.3.1-beta
	codec:1.3.1-beta
	database:1.3.1-beta
	filesystem:1.3.1-beta
	media:1.3.1-beta
	monkey:1.3.1-beta
	network:1.3.1-beta
	platform:1.3.1-beta
	process:1.3.1-beta
	ui:1.3.1-beta
	worker:1.3.1-beta


If you plan on use python, php or ruby support, you need to add the corresponding module. For example, Python can be used now in the application with the addition of the language module as illustrated below:


	#appname:HelloWorld
	#appid:com.tidesdk.helloworld
	#publisher:Software in the Public Interest (SPI) Inc
	#image:default_app_logo.png
	#url:http//tidesdk.org
	#guid:845e9c3c-c9ff-4ad4-afdf-9638092f044f
	#desc:Sample Hello World application
	#type:desktop
	runtime:1.3.1-beta
	app:1.3.1-beta
	codec:1.3.1-beta
	database:1.3.1-beta
	filesystem:1.3.1-beta
	media:1.3.1-beta
	monkey:1.3.1-beta
	network:1.3.1-beta
	platform:1.3.1-beta
	process:1.3.1-beta
	ui:1.3.1-beta
	worker:1.3.1-beta
	python:1.3.1-beta


Activating a language module will cause that language to be available for use in script tags. Be aware that adding a language module may add overhead to the runtime and distribution of your application.

### tiapp.xml Configuration

tiapp.xml provides app configuration using XML syntax. If you use the TideSDK Developer app it will create a generic tiapp.xml file for you. The tiapp.xml for the HelloWorld app is below:


	<?xml version='1.0' encoding='UTF-8'?>
	<ti:app xmlns:ti='http://ti.tidesdk.org'>
	<id>com.tidesdk.helloworld</id>
	<name>HelloWorld</name>
	<version>0.2.0</version>
	<publisher>Software in the Public Interest (SPI) Inc</publisher>
	<url>http//tidesdk.org</url>
	<icon>default_app_logo.png</icon>
	<copyright>2012 by David Pratt</copyright>
	<!-- Window Definition - these values can be edited -->
	<window>
	<id>initial</id>
	<title>HelloWorld</title>
	<url>app://index.html</url>
	<width>700</width>
	<max-width>3000</max-width>
	<min-width>0</min-width>
	<height>500</height>
	<max-height>3000</max-height>
	<min-height>0</min-height>
	<fullscreen>false</fullscreen>
	<resizable>true</resizable>
	<chrome scrollbars="true">true</chrome>
	<maximizable>true</maximizable>
	<minimizable>true</minimizable>
	<closeable>true</closeable>
	</window>
	</ti:app>


####Window elements 

The `tiapp.xml` file contains one or more window config elements which describe window properties. The first `window` element listed will be the main window, which is the window created when your application first starts. Here is a typical window element: 


	<window> 
	<id>initial</id> 
	<title>asdf</title> 
	<url>app://index.html</url> 
	<width>700</width> 
	<max-width>3000</max-width> 
	<min-width>0</min-width> 
	<height>500</height> 
	<max-height>3000</max-height> 
	<min-height>0</min-height> 
	<fullscreen>false</fullscreen> 
	<resizable>true</resizable> 
	<chrome scrollbars="true">true</chrome> 
	<maximizable>true</maximizable> 
	<minimizable>true</minimizable> 
	<closeable>true</closeable> 
	</window> 


### id 

This element specifies the ID of this window config. This allows you to identify windows by ID. Window using this config will return this value when you call {{Ti.UI.currentWindow.getId()}}. 

### title 

This element specifies the window title. On most systems the window title is visible on the title bar of the window. 

### url 

This element specifies the initial URL for this window. This may be an {{app://}} URL such as {{app://index.html}}, which resolves to the {{index.html}} file in the Resources directory of your application. The value of this element should contain an absolute URL. 

### url-regex 

If you specify a `url-regex` element for your window, calls to `Ti.UI.createWindow()` given only a URL (no configuration object) which matches against the URL provided wil use this config. For example if your `url-regex` element looks like: 


	<url-regex>.*special.*</url-regex> 


and then have the code: 


	Ti.UI.createWindow("app://special-window.html") 


the next window will use this window config. The value of this element should contain a valid PCRE string. 

### width and height 

The `width` and `height` attributes allow you to specify the initial width and height of your window in pixels. You may modify this setting by calling `window.setHeight()` and `window.setWidth()`. 

### x and y 

The `x` and `y` elements specify the initial screen position of windows using this configuration. All platforms use an origin that is in the top-left of the screen. 

### visible 

The value of the `visible` should either be `true` or `false`. A false value here means that the window is initially hidden i.e. the equivalent of calling `Ti.UI.currentWindow.hide()`. A hidden window may be shown by calling `Ti.UI.UserWindow.show()` or `Ti.UI.UserWindow.setVisible(true)`. 

### max-width, max-height, min-width, and min-height 

These elements allow you to specify a minimum and maximum width or height for your window. A value of `-1` in these fields is equivalent to having no value specified. These values will override manual settings. For example if you specify: 


	<max-width>300</max-width> 
	<width>400</width> 


the initial window width will be 300 pixels. 

### fullscreen 

The value of the `fullscreen` element should either be `true` or `false`. A value of `true` causes windows with this config to start in a fullscreened state. A window may modify its fullscreen state `Ti.UI.UserWindow.setFullscreen();`. 

### maximizable 

The value of the `maximizable` element should either be `true` or `false`. A value of `false` will make user interface elements allowing the user to maximize or zoom (OS X) the window hidden. It does not interfere with calls to `Ti.UI.UserWindow.maximize()` or `Ti.UI.UserWindow.unmaximize()`. 

### maximized 

The value of the `maximized` element should either be `true` or `false`. A value of `true` will cause the window to started in a maximized or zoomed state. 

### minimizable 

The value of the `maximizable` element should either be `true` or `false`. A value of `false` will make user interface elements allowing the user to minimize the window hidden. It does not interfere with calls to `Ti.UI.UserWindow.minimize()` or `Ti.UI.UserWindow.unminimize()`. 

### minimized 

The value of the `minimized` element should either be `true` or `false`. A value of `true` will cause the window to started in a minimized state. 

### closeable 

The value of the `closeable` element should either be `true` or `false`. A value of `false` will make user interface elements allowing the user to close the window hidden. It does not interfere with calls to `Ti.UI.UserWindow.close()`.

### chrome 

The value of the `chrome` element should either be `true` or `false`. A value of `false` will make create a window with no window borders and controls. A window created without chrome cannot add it later. Additionally the `chrome` element has a `srollbars` attribute which can be either `true` or `false`. A window with a `true` or undefined value for `scrollbars` property will create a scrollbar in the WebView when the content of the view extends beyond the boundaries of the window. 

### resizable 

The value of the `chrome` element should either be `true` or `false`. A value of `false` will make create a window with no window borders and controls. A window created without chrome cannot add it later. 

### transparency and transparent-background 

There are two types of transparency in TideSDK. Full window transparency specified with the `transparency` property and background transparency specified with the `transparent-background` property. The `transparent` element should contain a value between 0.0 and 1.0 and specifies the opacity of the total window. A window with a transparency value of 0.7 would look like: 

{@img transparency.png The `transparency` property}

The `transparent-background` property specifies that the WebView in a window has a background which is transparent. Elements in the WebView may specify different opacities to create non-rectangular windows. Here is an example of a non-rectangular TideSDK window with a `transparent-background` value of `true`: 

{@img transparent-background.png The transparent-background property}

Note that currently the `transparent-background` property disables all chrome and overrides the `transparency` property. If you'd like to allow your users to drag a window by its contents, you can do this via JavaScript.
