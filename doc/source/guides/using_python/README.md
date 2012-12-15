#Using Python in TideSDK

__Author:__ David Pratt

## Preface

This documentation applies to TideSDK 1.3.1. If you have not yet upgraded to TideSDK 1.3.1, please review the [CHANGES](https://github.com/TideSDK/TideSDK/blob/1.3.1-beta/CHANGES)

## Overview

Python is a remarkably powerful dynamic programming language that is used in a wide variety of application domains. Python is often compared to Tcl, Perl, Ruby, Scheme or Java. Some of its key distinguishing features include:

* very clear, readable syntax
* strong introspection capabilities
* intuitive object orientation
* natural expression of procedural code
* full modularity, supporting hierarchical packages
* exception-based error handling
* very high level dynamic data types
* extensive standard libraries and third party modules for virtually every task
* extensions and modules easily written in C, C++ (or Java for Jython, or .NET languages for IronPython)
* embeddable within applications as a scripting interface

This guide demonstrates how to use the python module in TideSDK. The python module in TideSDK allows you run python in your app in two ways:

* Embedding python code within the DOM (Document Object Model)
* Call to scripts included in your application

## Using the Python module

To use python in your app, you must include the python module in your app's manifest. The manifest is located in the root of your project. The following is structure of our HelloWorld app to illustrate the location:


    ├── CHANGELOG.txt
    ├── LICENSE.txt
    ├── README.md
    ├── Resources
    │   ├── app.js
    │   ├── default_app_logo.png
    │   └── index.html
    ├── manifest
    └── tiapp.xml


### App Manifest

The manifest contains information about the runtime modules used by the project. 


  #appname:HelloWorld
  #appid:com.example.helloworld
  #publisher:prattd
  #image:default_app_logo.png
  #url:http://example
  #guid:845e9c3c-c9ff-4ad4-afdf-9638092f044f
  #desc:No description provided
  #type:desktop
  runtime:1.3.1
  app:1.3.1
  filesystem:1.3.1
  platform:1.3.1
  ui:1.3.1
  codec:1.3.1
  database:1.3.1
  media:1.3.1
  monkey:1.3.1
  network:1.3.1
  process:1.3.1
  worker:1.3.1


Once the module is added as illustrated below, python can be used now in the application with the addition of the language module:


  #appname:HelloWorld
  #appid:com.example.helloworld
  #publisher:prattd
  #image:default_app_logo.png
  #url:http://example
  #guid:845e9c3c-c9ff-4ad4-afdf-9638092f044f
  #desc:No description provided
  #type:desktop
  runtime:1.3.1
  app:1.3.1
  filesystem:1.3.1
  platform:1.3.1
  ui:1.3.1
  codec:1.3.1
  database:1.3.1
  media:1.3.1
  monkey:1.3.1
  network:1.3.1
  process:1.3.1
  worker:1.3.1
  python:1.3.1

## A quick demonstration

### Embedding python in the DOM


  <script type="text/python">
    def my_python_function(l):
        return [x+2 for x in l]
  </script>
   
  <script>
      alert(my_python_function([1, 2, 3, 4]));
  </script>


Calling out to python:

  <html>
  <head>
  </head>
  <body style="background-color:#1c1c1c;margin:0">
      <script>
      function use_my_python_data(val) {
         window.alert(val)
      }
      Titanium.include("test.py");
      </script>
      </div>
  </body>
  </html>

test.py for the above example:


    #!/usr/bin/env python
     
    import os
    import sys
    import fnmatch
    import glob
     
    file_mask = window.prompt("Please enter the file mask to search on", "*.js");
     
    source_dir = "/Users/aland/apps/tweetanium-appstore/Resources"
    sdk_dir = "~/Library/Application\ Support/Titanium/sdk/osx/1.1.0/"
    filepaths = [] 
    contents = "/tmp/Contents"
     
    for dirpath, dirnames, filenames in os.walk (source_dir): 
        filepaths.extend (os.path.join (dirpath, f) for f in fnmatch.filter (filenames, file_mask))
     
    for file_name in filepaths:
        if os.path.isfile(file_name):
            head, tail = file_name.split("Resources/")
            compiler_jar = os.path.join(sdk_dir, "compiler.jar")
            output_file = os.path.join(contents, "Resources", tail)
            # print output_file
            source_file = os.path.join(source_dir, file_name)
            exec_cmd = "java -jar " + compiler_jar + " --js " + source_file +
                    " --compilation_level ADVANCED_OPTIMIZATION --js_output_file " + output_file
            my_data = file_name + "\n\n" + exec_cmd;
            use_my_python_data(file_name + "\n\n" + exec_cmd);
            # print (file_name + "\n\n" + exec_cmd);
     
    window.alert("Done!");


The Python module currently uses the following version of Python depending on your platform:
* Windows: Python 2.7
* OS X (Lion): Python 2.7
* OS X (Mountain Lion): Python 2.7
* Linux (all distributions): Python 2.7

## Including Python in your application
There are a few ways to include Python scripts on your Titanium pages. As demonstrated above, you can include a script tag with type="text/python." If you have a Python source file that you want to include you can also do this:


  <script type="text/python" src="myfile.py"/>


As well as using <tt>script</tt> tags to include Python, you can use Python <tt>import</tt>. By default your application's Resources directory is on the Python import path, so this is the recommended place to include Python source files in your application.

  <script type="text/python">
  import myfile
  </script>


## TideSDK's Object Bridge
libtide is the underlying object bridge in TideSDK. It has its own object system, including its own types. Whenever you call Python from JavaScript or JavaScript from Python, your data will flow through libtide.

#### Numbers

Since all JavaScript Numeric variables are floating-point, when they are passed into Python, they will be converted into Python floats. JavaScript Numerics are converted by value rather than converted by reference.

  <script>
      var globalNumber = 23;
  </script>
  <script type="text/python">
      globalNumber = 13; # globalNumber will change
   
      def changeNumber(number):
          number = 10; # globalNumber will not change
          changeNumber(globalNumber)
  </script>

One important result of libtide using floating point numbers is that if you send a Python integer into JavaScript and then back into Python, that number will always be a Python float.

#### Booleans

JavaScript Booleans are also converted by value directly to a Python bool and vice-versa.

#### Objects

Passing a JavaScript object to Python involves wrapping the JavaScript object in a Python object. This means that if you change a JavaScript object in Python, that change will be reflected in the original object. When dealing with objects that flow from one language context to another, it suffices to think of them as the same object.

  <script>
      var globalObject = new Object();
      globalObject.foo = "string";
  </script>
  <script type="text/python">
     globalObject.foo = "string2"; # globalObject will change
   
     def changeNumber(obj):
         # obj is passed by reference so globalObject will change
         obj.foo = "string3";
     changeNumber(globalObject)
  </script>


Python objects work the same way when moving to JavaScript. Here's an example:


  <script type="text/python">
  class MyObject:
      def __init__(self):
          self.property = "prop"
   
      def foo(self):
          return "foo!"
   
  globalObject = MyObject()
  </script>
  <script>
      alert(globalObject.property);
      alert(globalObject.foo());
   
      globalObject.property = "propagain"
      alert(globalObject.property);
  </script>

_Note: If you attempt to modify a read-only libtide object, an exception will be thrown._

#### Dicts

Python dicts can be passed to JavaScript. They will be Objects whose properties are just dict accesses. For instance:


  <script type="text/python">
  globalObject = {}
  globalObject['foo'] = "string"
  </script>
  <script>
      alert(globalObject.foo);
      globalObject.property = "propagain"
  </script>


#### Arrays / Lists

JavaScript arrays in are wrapped in a list-like object in Python. Be aware that this object just operates much like a Python list, but is not a true Python list. You should be able to use it just like a list in most situations though.

  <script>
       var globalArray = [1, 2, 3, 4];
  </script>
  <script type="text/python">
  for item in globalArray:
      Titanium.API.debug(item)
  </script>

Passing Python lists to JavaScript will result in a true JavaScript array. That means that the JavaScript object wraps the Python object will have an Array prototype and the full complement of JavaScript array methods.

  <script type="text/python">
  globalArray = [1, 2, 3, 4];
  </script>
  <script>
      globalArray.push(5);
      globalArray.push(6);
      var elem = gloalArray.pop(); // should be 6
  </script>

#### Exceptions

Exceptions that are thrown in either Python or JavaScript will be converted using the same rules as normal variables when bubbling up into different languages. This means that if an exception is thrown in Python, you should be able to catch it in JavaScript and vice-versa.

#### DOM Manipulation

TideSDK lets you share and access objects and variables independent of the language. This allows you to access the Javascript objects _document_ and _window_ in Python, hence we can manipulate the DOM from within Python.

#### Quickstart
Lets set up a very basic demonstration.

* Create a new project. Be sure to tick the "Python" select box. I'm going to be using jQuery later on in this tutorial. Include your favorite javascript library.
{@img python-switch.png Python select box}
* Navigate to your project and open up the <em>Resources/index.html</em> file. I've created a simple style sheet which just makes everything easier to see, it's not necessary but will come with the tutorial files.

    <b>index.html</b>
    <link type="text/css" rel="stylesheet" href="style.css"/>
    <input type="submit" id="button" value="Click Me" onclick="change()" />
    <div id="output">
        This will get replaced when the button is clicked.
    </div>


For our basic example we will have a button which, when clicked, will change the contents of a <em>div</em>. As mentioned at the start of this tutorial the <em>document</em> object and all associated methods are available for us to use in Python. Any class, function or variable that you want to pass from Python back to Javascript must be declared in the window object.
Add the following code to <em>index.html</em>

    <script type="text/python">
        def change():
            document.getElementById('output').innerHTML='Manipulation via Python'
     
        window.change = change 
    </script>

And as you can expect, we get something like...

    <object width="400" height="300"><param name="allowfullscreen" value="true" />
        <param name="allowscriptaccess" value="always" />
        <param name="movie" value="http://vimeo.com/moogaloop.swf?clip_id=6441734&server=vimeo.com&show_title=1&show_byline=1&show_portrait=0&color=&fullscreen=1" />
        <embed src="http://vimeo.com/moogaloop.swf?clip_id=6441734&server=vimeo.com&show_title=1&show_byline=1&show_portrait=0&color=&fullscreen=1" type="application/x-shockwave-flash" allowfullscreen="true" allowscriptaccess="always" width="400" height="300"></embed>
    </object>


####jQuery in Python
Javascript frameworks (such as jQuery) make JavasScript coding a great deal easier. We can use jQuery (and potentially any other Javascript framework) in our Python code. As you can probably guess we can't use jQuery's <em>$</em> alias. It errors out. Instead you need to use the full <em>jQuery</em> function. Everything works out of the box - animations (which are very smooth on Titanium) and method chaining.

    <script type="text/javascript" src="jquery-1.8.2.js"></script>
    <link type="text/css" rel="stylesheet" href="style.css"/>
     
    <script type="text/python">
    def jqchange():
        jQuery("#output").hide().text("Manipulation in jQuery via Python").fadeIn("slow").animate({"font-size" : "20px"})
     
    window.jqchange = jqchange
    </script>
     
    <input type="submit" id="jqbutton" value="jqchange()" onclick="jqchange()" />
     
    <div id="output">
        This will get replaced when the button is clicked.
    </div>
