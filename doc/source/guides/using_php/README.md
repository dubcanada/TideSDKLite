#Using PHP in TideSDK

__Author:__ David Pratt

##Preface

This documentation applies to TideSDK 1.3.1. If you have not yet upgraded to TideSDK 1.3.1, please review the [CHANGES.txt](https://github.com/TideSDK/TideSDK/blob/1.3.1/CHANGES.txt)

##Overview

PHP (Hypertext Preprocessor) is a widely-used open source general-purpose scripting language that is especially suited for web development and can be embedded into HTML. This guide demonstrates how to use the PHP module in TideSDK.

The PHP module in TideSDK allows you run PHP within your app in three ways:

* Embedding PHP code within the DOM (Document Object Model)
* Including PHP scripts
* Linking to PHP scripts.

##Using the PHP module

To use PHP in your app, you must include the PHP module in your app's manifest. The manifest is located in the root of your project. The following is structure of our HelloWorld app to illustrate the location:


		├── CHANGELOG.txt
		├── LICENSE.txt
		├── README.md
		├── Resources
		│   ├── app.js
		│   ├── default_app_logo.png
		│   └── index.html
		├── manifest
		└── tiapp.xml


###App Manifest

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


Once the module is added as illustrated below, PHP can be used now in the application with the addition of the language module:


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
  php:1.3.1


##Using PHP in your App

The PHP module embeds the PHP language in your application. Therefore your users are not required to install any dependencies.

To use PHP in your app, you can:

* embed PHP in the DOM
* include PHP files referenced in script tags, or
* make direct reference to the php file (such as form actions)

###Embedding PHP in the Script Tag

To embed PHP within the DOM, use a script tag with text/php type.


  <script type=text/php>
  function my_php_function($item) {
    $result = array();
    for ($index = 0; $index < $item->count(); $index++) {
      $result[] = $item[$index] + 2;
    }
    return $result;
  }
  </script>
  <script>
    alert(my_php_function([1, 2, 3, 4]));
  </script>


#### Example 1


  <!DOCTYPE html>
  <html>  
    <head>
      <title>PHP Info</title>
      <script type="text/php">
        date_default_timezone_set('America/Chicago');
        ini_set('default_charset', 'utf8');
        ini_set('display_errors', 'Off');
        function getPhpInfo() {
          ob_start();
          phpinfo();
          return ob_get_clean();
        }
      </script>
    </head>
    <body>
      <script type="text/php">
        $document - > write('<pre>'.getPhpInfo()
          .'</pre>');
      </script>
    </body>
  </html>


###Including PHP Scripts in the Script Tag

To include PHP source files, there are two methods to accomplish this:

Method 1:


  <script type="text/php" src="my_file.php"/>



When including within `<script>` tags, you won't need to  `<?php ?>` tags. For example, the contents of the my_file.php script above looks like this:


  function my_php_function($item) {
    $result = array();
    for ($index = 0; $index < $item - > count(); $index++) {
      $result[] = $item[$index] + 2;
    }
    return $result;
  }


Method 2:


  <script type="text/php">
    include("my_file.php");
  </script>


External PHP code has full access to the DOM and the TideSDK object as usual. There is one important difference between the approaches described above:

* When including PHP via the include or require commands, you should surround your code with `<?php ?>` tags
* When including with `<script>` tags, you should not surround it with `<?php ?>` tags.

###Direct References and Using PHP in Forms

Direct references to php files can also be made your app can be made just like in the apache web server.


  <!DOCTYPE html>
  <html>
    <head>
      <title>Currency Converter</title>
    </head>
    <body>
      <h1>Currency Converter</h1>
      <form action="convert.php">
        <table>
          ... omitted for brevity
        </table>
      </form>
    </body>
  </html>


##PHP Preprocessing

If you do surround your PHP code with <?php ?> and place it in a file that ends in the .php extension, it will be preprocessed. Preprocessed TideSDK works is a way similar to PHP code on an Apache server. The script contents are replaced with the script output before the content is rendered by the browser.

Note that preprocessed PHP does not have access to the TideSDK object and cannot interact directly with the DOM.

For example, you have a file named `test.php` with the contents:

  <?php
    echo("PHP preprocessed output!");
  ?>

If you navigate your application to this file, the contents of the web view will be:

  PHP preprocessed output!


##Tide Object Bridge

The Tide object bridge is at the center of TideSDK. It provides the capability to pass data between PHP, JavaScript or any other supported language in TideSDK. It has its own object system and selection of types. Whenever you call PHP from JavaScript or JavaScript from PHP, your data will be flowing through Tide. The interesting thing about the Tide Object bridge 

###Numbers

Since all JavaScript Numeric variables are floating-point, when they are passed into PHP they will be converted into PHP doubles. JavaScript numerics are converted by value rather than converted by reference.

  <script>
  var globalNumber = 23;
  </script>
  <script type="text/php">
    $globalNumber = 13; // globalNumber will change

    function changeNumber($number) {
      global $globalNumber;
      $number = 10; // globalNumber will not change
      $globalNumber = 10; // globalNumber will change
    }
    changeNumber($globalNumber)
  </script>

One important result of all Kroll numbers being floating point is that if you send a number into JavaScript and then back into PHP, that number will always be a PHP double.

###Booleans

JavaScript Booleans are also converted by value directly to a PHP boolean and vice-versa.

###Null and Undefined

JavaScript `null` and `undefined` both map to `null` in PHP. PHP `null` maps to `null` in JavaScript.

###Strings

JavaScript strings map to PHP strings and PHP strings map to JavaScript strings.

###Objects

####General

Passing a JavaScript object to PHP involves wrapping the JavaScript object in a PHP object. This means that if you change a JavaScript object in PHP, that change will be reflected in the original object. When dealing with data that flows from one language context to another, it suffices to think of them as the same object.

  <script>
    var globalObject = new Object();
    globalObject.foo = "string";
  </script>

  <script type="text/php">
    $globalObject->foo = "string2"; # globalObject will change

    function changeNumber($obj) {
      # obj is passed by reference so globalObject will change
      $obj->foo = "string3";
    }
    changeNumber($globalObject)
  </script>


PHP objects work the same way when moving to JavaScript. Here's an example:

  <script type="text/php">
    class MyObject {
      public $publicVariable;

      function __construct() {
        $this->publicVariable = "bar";
      }

      public function publicMethod() {
        return "foo";
      }
    }

    $globalObject = new MyObject()
  </script>

  <script>
    alert(globalObject.publicVariable);
    alert(globalObject.publicMethod());

    globalObject.publicVariable = "propagain";
    alert(globalObject.publicVariable);
  </script>


####PHP arrays in JavaScript

PHP arrays, when passed to JavaScript, are Objects whose properties are just dict accesses. For instance:

  <script type="text/php">
    $globalObject = array();
    $globalObject['foo'] = "string";
  </script>

  <script>
    alert(globalObject.foo);
  </script>

####JavaScript arrays in PHP

JavaScript arrays in PHP are wrapped in an object similar to an [ArrayObject](http://php.net/manual/en/class.arrayobject.php).

  <script>
    var globalArray = [1, 2, 3, 4];
  </script>

  <script type="text/php">
    $globalArray->append(3);
    $globalArray->append(4);
    $window->alert($globalArray[0]);
  </script>

##Sample Apps


##Copyright and Attribution

The following copyright and attribution applies to this document:

* Copyright © 2012 Appcelerator Inc. All rights reserved.
* Copyright © 2012 David Pratt. All rights reserved.
