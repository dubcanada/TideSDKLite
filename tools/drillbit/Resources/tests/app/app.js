/**
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

describe("App Tests", {
  validate_app: function () {
    value_of(Ti.platform)
      .should_be_one_of(['win32', 'osx', 'linux']);
    value_of(Ti.version)
      .should_be_string();

    value_of(Ti.App.getID())
      .should_be('com.titaniumapp.unittest');
    value_of(Ti.App.getName())
      .should_be('foobar');
    value_of(Ti.App.getVersion())
      .should_be('1.2');
    value_of(Ti.App.getPublisher())
      .should_be('yoy');
    value_of(Ti.App.getURL())
      .should_be('blah.com');
    value_of(Ti.App.getCopyright())
      .should_be('2010');
    value_of(Ti.App.getDescription())
      .should_be('cool like dat');
    value_of(Ti.App.getGUID())
      .should_be('CF0D2CB7-B4BD-488F-9F8E-669E6B53E0C4');

    // No default icon set for the application.
    var icon = Ti.App.getIcon();
    value_of(icon)
      .should_be_null();

    value_of(Ti.App.exit)
      .should_be_function();
    value_of(Ti.App.loadProperties)
      .should_be_function();
    value_of(Ti.App.path)
      .should_not_be_null();
    value_of(Ti.App.arguments)
      .should_not_be_null();
    value_of(Ti.App.Properties)
      .should_be_object();

    value_of(Ti.App.home)
      .should_not_be_null();
    value_of(Ti.App.stdout)
      .should_be_function();
    value_of(Ti.App.stderr)
      .should_be_function();

    // this should be the default stream if not specified in the manifest
    value_of(Ti.App.getStreamURL())
      .should_be('https://api.appcelerator.net/p/v1');
    // test passing arg
    value_of(Ti.App.getStreamURL('foo'))
      .should_be('https://api.appcelerator.net/p/v1/foo');
    // test passing multiple args
    value_of(Ti.App.getStreamURL('foo', 'bar'))
      .should_be('https://api.appcelerator.net/p/v1/foo/bar');
  },

  //comment out for now, this test function causes the app test to timeout in win32,
  test_system_properties: function () {
    // test type conversion and parsing of system properties embedded in tiapp.xml
    value_of(Ti.App.getSystemProperties())
      .should_be_object();
    var sysProps = Ti.App.getSystemProperties();

    value_of(sysProps.getString("teststring"))
      .should_be("stringvalue");
    value_of(sysProps.getInt("testint"))
      .should_be(1);
    value_of(sysProps.getDouble("testdouble"))
      .should_be(1.23);
    value_of(sysProps.getString("testdefaultstring"))
      .should_be("stringvalue");
    value_of(sysProps.getInt("badint"))
      .should_be(0);
    value_of(sysProps.getDouble("baddouble"))
      .should_be(0);
  },

  test_create_properties_object: function () {
    var props = Ti.App.createProperties();
    value_of(props)
      .should_be_object();

    value_of(props.getBool)
      .should_be_function();
    value_of(props.getInt)
      .should_be_function();
    value_of(props.getList)
      .should_be_function();
    value_of(props.getDouble)
      .should_be_function();
    value_of(props.setString)
      .should_be_function();
    value_of(props.setBool)
      .should_be_function();
    value_of(props.setInt)
      .should_be_function();
    value_of(props.setList)
      .should_be_function();
    value_of(props.setDouble)
      .should_be_function();
    value_of(props.setString)
      .should_be_function();
    value_of(props.hasProperty)
      .should_be_function();
    value_of(props.listProperties)
      .should_be_function();
    value_of(props.saveTo)
      .should_be_function();
  },

  test_create_properties: function () {
    var props2 = Ti.App.createProperties({
      "val1": true,
      "val2": 1.1,
      "val3": ['a', 'b', 'c'],
      "val4": "123"
    });

    value_of(props2)
      .should_be_object();

    value_of(props2.listProperties())
      .should_match_array(["val1", "val2", "val3", "val4"]);
    value_of(props2.getBool("val1"))
      .should_be_true();
    value_of(props2.getDouble("val2"))
      .should_be(1.1);

    var val3 = props2.getList("val3");
    value_of(val3)
      .should_not_be_null();
    value_of(val3)
      .should_be_array();

    value_of(props2.getList("val3"))
      .should_match_array(['a', 'b', 'c']);
    value_of(props2.getString("val4"))
      .should_be("123");

    var TFS = Ti.Filesystem;
    var sep = TFS.getSeparator();
    var appdir = TFS.getApplicationDataDirectory();
    var path = appdir + sep + "_testing.properties";

    props2.saveTo(path);
    value_of(TFS.getFile(path)
      .exists())
      .should_be_true();
  },

  test_remove_properties: function () {
    var props = Ti.App.createProperties({
      "val1": true,
      "val2": 1.1,
      "val3": ['a', 'b', 'c'],
      "val4": "123"
    });

    value_of(props.hasProperty('val1'))
      .should_be_true();
    props.removeProperty('val1');
    value_of(props.hasProperty('val1'))
      .should_be_false();
    props.setInt('val1', 42);
    value_of(props.hasProperty('val1'))
      .should_be_true();
    value_of(props.getInt('val1'))
      .should_be(42);
  },

  test_app_URLToPath: function () {
    // get the fully qualified absolute path to the properties.
    var path = Ti.App.appURLToPath("app://app.properties");
    value_of(path)
      .should_be_string();

    // get the application object
    var app = Ti.API.getApplication();
    value_of(app)
      .should_not_be_null();

    // the application object will give us the exe path
    var exePath = app.getExecutablePath();
    value_of(exePath)
      .should_be_string();

    // for this test, the exe path should be a substring of the path
    // returned by appURLToPath()
    var index = path.indexOf(exePath);
    value_of(index)
      .should_not_be(-1);

    // Lighthouse issue #90: Make sure app URLs with the appid in the host are stripped
    var url = Ti.UI.currentWindow.getURL();
    var urlNoHost = "app://index.html";
    var urlPath = Ti.App.appURLToPath(url);
    value_of(urlPath)
      .should_be(Ti.App.appURLToPath(urlNoHost));
  },

  test_app_loadproperties: function () {
    var props = Ti.App.loadProperties(Ti.App.appURLToPath("app://app.properties"));
    value_of(props)
      .should_be_object();
    value_of(props.getBool("trueval"))
      .should_be_true();
    value_of(props.getBool("falseval"))
      .should_be_false();
    value_of(props.getInt("numval"))
      .should_be(1);
    value_of(props.getString("stringval"))
      .should_be("hey this is just a string");
    value_of(props.getDouble("doubleval"))
      .should_be(1.1);
    value_of(props.getList("listval"))
      .should_match_array(["entry1", "entry2", "entry3"]);
  },

  test_app_arguments: function () {
    value_of(Ti.App.arguments)
      .should_be_array();
    // this is specific to the test harness args
    value_of(Ti.App.arguments.length)
      .should_be(6);

    Ti.API.debug("arguments[0] " + Ti.App.arguments[0]);

    // get the application object
    var app = Ti.API.getApplication();
    value_of(app)
      .should_not_be_null();

    var argv = app.getArguments();
    value_of(argv)
      .should_be_array();

    // find "a" shared part of the path string so we can search for it inside 
    // the Ti.App.arguments.  These arguments ARE NOT the same as ti.api.application.argv[][]
    // we can't hard code any paths due to the differences in platforms.
    var subPath = argv[0].substr(0, argv[0].search(app.getName()));

    // argv[0] is the fully qualified name and path to the exe
    var index = Ti.App.arguments[0].indexOf(subPath);
    value_of(index)
      .should_not_be(-1);
  },

  test_app_home_property: function () {
    value_of(Ti.App.home)
      .should_not_be_null();
    Ti.API.debug("home is " + Ti.App.home);
    Ti.API.debug("Ti.App.arguments[0] is " + Ti.App.arguments[0]);

    // get the application object
    var app = Ti.API.getApplication();
    value_of(app)
      .should_not_be_null();

    var argv = app.getArguments();
    value_of(argv)
      .should_be_array();

    // find "a" shared part of the path string so we can search for it inside 
    // the Ti.App.arguments.  These arguments ARE NOT the same as ti.api.application.argv[][]
    // we can't hard code any paths due to the differences in platforms.
    var subPath = argv[0].substr(0, argv[0].search(app.getName()));

    // argv[0] is the fully qualified name and path to the exe
    var index = Ti.App.home.indexOf(subPath);
    value_of(index)
      .should_not_be(-1);
  },

  test_app_path_property: function () {
    value_of(Ti.App.path)
      .should_not_be_null();
    Ti.API.debug("path is " + Ti.App.path);

    var index = Ti.App.path.indexOf(Ti.App.home);
    value_of(index)
      .should_not_be(-1);
  }
});