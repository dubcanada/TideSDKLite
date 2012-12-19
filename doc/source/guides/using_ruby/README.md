#Using Ruby in TideSDK

__Author:__ David Pratt

## Preface

This documentation applies to TideSDK 1.3.2. If you have not yet upgraded to TideSDK 1.3.2, please review the [CHANGES](https://github.com/TideSDK/TideSDK/blob/1.3.2-beta/CHANGES)

TideSDK includes a Ruby module, which allows developers to run Ruby code from within their applications.

## Overview

A dynamic, open source programming language with a focus on simplicity and productivity. It has an elegant syntax that is natural to read and easy to write.

This guide demonstrates how to use the ruby module in TideSDK. The ruby module in TideSDK allows you run ruby in your app in two ways:

* Embedding ruby code within the DOM (Document Object Model)
* Calling out to ruby scripts.

## Using the Ruby module

To use ruby in your app, you must include the ruby module in your app's manifest. The manifest is located in the root of your project. The following is structure of our HelloWorld app to illustrate the location:


    ├── CHANGELOG.txt
    ├── LICENSE.txt
    ├── README.md
    ├── Resources
    │   ├── app.js
    │   ├── default_app_logo.png
    │   └── index.html
    ├── manifest
    └── tiapp.xml


## App Manifest

The manifest contains information about the runtime modules used by the project. 


  #appname:HelloWorld
  #appid:com.example.helloworld
  #publisher:prattd
  #image:default_app_logo.png
  #url:http://example
  #guid:845e9c3c-c9ff-4ad4-afdf-9638092f044f
  #desc:No description provided
  #type:desktop
  runtime:1.3.2
  app:1.3.2
  filesystem:1.3.2
  platform:1.3.2
  ui:1.3.2
  codec:1.3.2
  database:1.3.2
  media:1.3.2
  monkey:1.3.2
  network:1.3.2
  process:1.3.2
  worker:1.3.2


Once the module is added as illustrated below, ruby can be used now in the application with the addition of the language module:


    #appname:HelloWorld
    #appid:com.example.helloworld
    #publisher:prattd
    #image:default_app_logo.png
    #url:http://example
    #guid:845e9c3c-c9ff-4ad4-afdf-9638092f044f
    #desc:No description provided
    #type:desktop
    runtime:1.3.2
    app:1.3.2
    filesystem:1.3.2
    platform:1.3.2
    ui:1.3.2
    codec:1.3.2
    database:1.3.2
    media:1.3.2
    monkey:1.3.2
    network:1.3.2
    process:1.3.2
    worker:1.3.2
    ruby:1.3.2


## Using Ruby with TideSDK
(NOTE: This documentation applies to TideSDK 1.3.2. )
The TideSDK includes a Ruby module, which allows developers to run Ruby code from within their applications. Here's a quick demonstration of what this means:

    <script type="text/ruby">
      def my_ruby_function(l)
        n = 0
        l.each { |i| n+=i }
        return n
      end
    </script>
     
    <script>
      alert(my_ruby_function([1, 2, 3, 4]));
    </script>


The Ruby module currently uses the following version of Ruby depending on your platform:
Windows: Ruby 1.8
OS X (Leopard): Ruby 1.8
OS X (Snow Leopard): Ruby 1.9
Linux (all distributions): Ruby 1.8
It's recommended that you write your code to be compatible with Ruby 1.8.


### Including Ruby in your application

There are a few ways to include Ruby scripts on your TideSDK pages. As demonstrated above, you can include a script tag with <tt>type="text/ruby"</tt>. If you have a Ruby source file that you want to include you can also do this:

    <script type="text/ruby" src="myfile.rb"/>

As well as using <tt>script</tt> tags to include Ruby, you can use Ruby <tt>require</tt>. By default your application's Resources directory is on the Ruby import path, so this is the recommended place to include Ruby source files in your application.

    <script type="text/ruby">
        require 'myfile.rb'
    </script>

## The libtide / Ruby Bridge
libtide is the underlying object and communication system in TideSDK. It has its own object system, including its own spectrum of types. Whenever you call Ruby from JavaScript or JavaScript from Ruby, your data will be flowing through libtide.

### Numbers
Since all JavaScript Numeric variables are floating-point, when they are passed into Ruby, they will be converted into Ruby Floats. JavaScript Numerics are converted by value rather than converted by reference.

    <script>
        var globalNumber = 23;
    </script>
    <script type="text/ruby">
        globalNumber = 13; # globalNumber will change
     
        def changeNumber(number)
            number = 10; # globalNumber will not change
        end
     
        changeNumber(globalNumber)
    </script>

One important result of libtide using floating point numbers is that if you send a Ruby <tt>Integer</tt> into JavaScript and then back into Ruby, that number will always be a Ruby <tt>Float</tt>.

### Booleans
JavaScript <tt>Booleans</tt> are also converted by value directly to a Ruby <tt>bool</tt> and vice-versa.

### Null, undefined and nil
JavaScript <tt>null</tt> and <tt>undefined</tt> are always converted to Ruby <tt>nil</tt>. Ruby <tt>nil</tt> is always converted to JavaScript <tt>null</tt>.

### Objects
Passing a JavaScript object to Ruby involves wrapping the JavaScript object in a Ruby object. This means that if you change a JavaScript object in Ruby, that change will be reflected in the original object. When dealing with objects that flow from one language context to another, it suffices to think of them as the same object.

    <script>
       var globalObject = new Object();
       globalObject.foo = "string";
    </script>
    <script type="text/ruby">
       window.globalObject.foo = "string2"; # globalObject will change

       def changeNumber(obj):
           # obj is passed by reference so globalObject will change
           obj.foo = "string3";    
       changeNumber(window.globalObject)
    </script>

Ruby objects work the same way when moving to JavaScript. Here's an example:

    <script type="text/ruby">
        class MyObject:
            def __init__(self):
                self.property = "prop"
     
            def foo(self):
                return "foo!"
     
        window.globalObject = MyObject()
    </script>
    <script>
        alert(globalObject.property);
        alert(globalObject.foo());
        
        globalObject.property = "prop again"
        alert(globalObject.property);
    </script>

Ruby objects have different ways to set properties. When setting a property on a Ruby object, libtide will try to set that property in a few different ways. Take this code for example:

    <script type="text/ruby">
        window.globalObject = Object.new()
    </script>
    <script>
        globalObject.foo = "property";
    </script>


When the JavaScript code attempts to set the <tt>foo</tt> property on <tt>globalObject</tt>, it will attempt several things on the Ruby object:

Setting the <tt>foo</tt> property via the <tt>foo=</tt> if that method exists.
<tt>foo=</tt> does not exist. Set the <tt>foo</tt> property via <tt>globalObject.instance_variable_set()</tt>
libtide follows a similar pattern when searching for a property.

    <script type="text/ruby">
        window.globalObject = Object.new()
    </script>
    <script>
        alert(globalObject.foo);
    </script>

1. Return the result of <tt>globalobject.foo()</tt> if it exists.
2. If <tt>@foo</tt> is defined in globalObject, return that.
3. Otherwise call <tt>globalObject.method_missing</tt> 

- Return a value if method_missing succeeds. 
- If a NoMethodError is thrown, return undefined.
 - Otherwise throw the exception <tt>globalObject.method_missing</tt> returned.

### Hashes
Ruby hashes can be passed to JavaScript. They will be Objects whose properties are just hash accesses. For instance:

    <script type="text/ruby">
        window.globalObject = {}
        window.globalObject['foo'] = 'string'
    </script>
    <script>
        alert(globalObject.foo);
        globalObject.property = "propagain"
    </script>


### Arrays
JavaScript arrays in are wrapped in an Array-like object in Ruby. Be aware that although this object operates much like a Ruby Array, it is not a true Ruby Array. You should be able to use it just like a Array in most situations though.

    <script>
        var globalArray = [1, 2, 3, 4];
    </script>
    <script type="text/ruby">
        window.globalArray.each { |item|
            Ti.API.debug(item)
        }
    </script>


Passing Ruby Arrays to JavaScript will result in a true JavaScript Array. That means that the JavaScript object which wraps the Ruby object will have an Array prototype and the full complement of JavaScript array methods.

    <script type="text/ruby">
        window.globalArray = [1, 2, 3, 4];
    </script>
    <script>
        globalArray.push(5);
        globalArray.push(6);
        var elem = gloalArray.pop(); // should be 6
    </script>


### Exceptions

Exceptions that are thrown in either Ruby or JavaScript will be converted using the same rules as normal variables when bubbling up into different languages. This means that if an exception is thrown in Ruby, you should be able to catch it in JavaScript and vice-versa.
