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

// TODO - add tests for Ti.API methods and properties that are called else where in other tests.
// this test suite contains all of the missing API coverage as of 4-July-20009
describe("API Tests", {
  // test the logging functions
  test_logging_methods: function () {
    value_of(Ti.API.critical)
      .should_be_function();
    value_of(Ti.API.debug)
      .should_be_function();
    value_of(Ti.API.error)
      .should_be_function();
    value_of(Ti.API.fatal)
      .should_be_function();
    value_of(Ti.API.notice)
      .should_be_function();
    value_of(Ti.API.trace)
      .should_be_function();
    value_of(Ti.API.warn)
      .should_be_function();

    //new 1.0
    value_of(Ti.API.setLogLevel)
      .should_be_function();

    Ti.API.critical("this is a critical message");
    Ti.API.debug("this is a debug message");
    Ti.API.error("this is a error message");
    Ti.API.fatal("this is a fatal message");

    Ti.API.notice("this is a notice message");
    Ti.API.trace("this is a trace message");
    Ti.API.warn("this is a warn message");

    Ti.API.print("this is a print message to stdout");
  },
  // test the logging functions
  test_log_method: function () {
    value_of(Ti.API.log)
      .should_be_function();

    Ti.API.log(Ti.API.CRITICAL, "this is a log message with severity Ti.API.CRITICAL");
    Ti.API.log(Ti.API.DEBUG, "this is a log message with severity Ti.API.DEBUG");
    Ti.API.log(Ti.API.ERROR, "this is a log message with severity Ti.API.ERROR");
    Ti.API.log(Ti.API.FATAL, "this is a log message with severity Ti.API.FATAL");
    Ti.API.log(Ti.API.INFO, "this is a log message with severity Ti.API.INFO");
    Ti.API.log(Ti.API.NOTICE, "this is a log message with severity Ti.API.NOTICE");
    Ti.API.log(Ti.API.TRACE, "this is a log message with severity Ti.API.TRACE");
    Ti.API.log(Ti.API.WARN, "this is a log message with severity Ti.API.WARN");

  },

  // test the logging functions
  test_setLogLevel_method: function () {
    //new 1.0
    value_of(Ti.API.setLogLevel)
      .should_be_function();
    value_of(Ti.API.log)
      .should_be_function();

    Ti.API.setLogLevel(Ti.API.WARN);
    Ti.API.log(Ti.API.FATAL, "this is a log message with severity Ti.API.FATAL should be logged");
    Ti.API.log(Ti.API.CRITICAL, "this is a log message with severity Ti.API.CRITICAL should be logged");
    Ti.API.log(Ti.API.ERROR, "this is a log message with severity Ti.API.ERROR should be logged");
    Ti.API.log(Ti.API.WARN, "Logging severity set to Ti.API.WARN");
    Ti.API.log(Ti.API.NOTICE, "this is a log message with severity Ti.API.NOTICE should not be logged");
    Ti.API.log(Ti.API.INFO, "this is a log message with severity Ti.API.INFO should not be logged");
    Ti.API.log(Ti.API.DEBUG, "this is a log message with severity Ti.API.DEBUG should not be logged");
    Ti.API.log(Ti.API.TRACE, "this is a log message with severity Ti.API.TRACE should not be logged");

    Ti.API.setLogLevel(Ti.API.FATAL);
  },

  validate_properties: function () {
    value_of(Ti.API.APP_UPDATE)
      .should_not_be_null();
    value_of(Ti.API.CRITICAL)
      .should_not_be_null();
    value_of(Ti.API.DEBUG)
      .should_not_be_null();
    value_of(Ti.API.EQ)
      .should_not_be_null();
    value_of(Ti.API.ERROR)
      .should_not_be_null();
    value_of(Ti.API.FATAL)
      .should_not_be_null();
    value_of(Ti.API.GT)
      .should_not_be_null();
    value_of(Ti.API.GTE)
      .should_not_be_null();
    value_of(Ti.API.INFO)
      .should_not_be_null();
    value_of(Ti.API.LT)
      .should_not_be_null();
    value_of(Ti.API.LTE)
      .should_not_be_null();
    value_of(Ti.API.MOBILESDK)
      .should_not_be_null();
    value_of(Ti.API.NOTICE)
      .should_not_be_null();
    value_of(Ti.API.RUNTIME)
      .should_not_be_null();
    value_of(Ti.API.SDK)
      .should_not_be_null();
    value_of(Ti.API.TRACE)
      .should_not_be_null();
    value_of(Ti.API.UNKNOWN)
      .should_not_be_null();
    value_of(Ti.API.WARN)
      .should_not_be_null();

    value_of(Ti.API.createDependency)
      .should_be_function();
    value_of(Ti.API.critical)
      .should_be_function();
    value_of(Ti.API.debug)
      .should_be_function();
    value_of(Ti.API.error)
      .should_be_function();
    value_of(Ti.API.fatal)
      .should_be_function();
    value_of(Ti.API.fireEvent)
      .should_be_function();
    value_of(Ti.API.get)
      .should_be_function();
    value_of(Ti.API.getApplication)
      .should_be_function(); //done
    value_of(Ti.API.getComponentSearchPaths)
      .should_be_function();
    value_of(Ti.API.getInstalledComponents)
      .should_be_function();
    value_of(Ti.API.getInstalledMobileSDKs)
      .should_be_function();
    value_of(Ti.API.getInstalledModules)
      .should_be_function();
    value_of(Ti.API.getInstalledRuntimes)
      .should_be_function();
    value_of(Ti.API.getInstalledSDKs)
      .should_be_function();
    value_of(Ti.API.info)
      .should_be_function();
    value_of(Ti.API.installDependencies)
      .should_be_function();
    value_of(Ti.API.log)
      .should_be_function();
    value_of(Ti.API.notice)
      .should_be_function();
    value_of(Ti.API.readApplicationManifest)
      .should_be_function();
    value_of(Ti.API.addEventListener)
      .should_be_function();
    value_of(Ti.API.set)
      .should_be_function();
    value_of(Ti.API.trace)
      .should_be_function();
    value_of(Ti.API.removeEventListener)
      .should_be_function();
    value_of(Ti.API.warn)
      .should_be_function();

    //new 1.0
    value_of(Ti.API.setLogLevel)
      .should_be_function();
    value_of(Ti.API.print)
      .should_be_function();
  },
  // test the application components API
  test_components: function () {
    Ti.API.error("Ti.API.getInstalledComponents()");
    // now that the app is finished testing, test the Ti.API runtime calls.
    // this should return a valid list of runtime components installed with this app.		
    var apiInstalledComponents1 = Ti.API.getInstalledComponents();

    value_of(apiInstalledComponents1)
      .should_be_object();
    if (apiInstalledComponents1.length) {
      Ti.API.error("Ti.API.getInstalledComponents() contains:");
      for (i = 0; i < apiInstalledComponents1.length; i++) {
        var item = apiInstalledComponents1[i];
        value_of(item)
          .should_be_object();
        Ti.API.info("apiInstalledComponents[" + i + "]= name: '" + item.getName() + "' type: '" + item.getType() + "' version: '" + item.getVersion() + "' path '" + item.getPath() + "'");
      }
    } else {
      Ti.API.error("Ti.API.getInstalledComponents() returned an empty list");
    }
  },
  // test the application dependancies API
  test_dependancies: function () {
    // create a dependancy  what does this mean?  what are we trying to accomplish?
    var dep = Ti.API.createDependency(Ti.API.RUNTIME, "test", "0.0.1", Ti.API.EQ);

    value_of(dep)
      .should_be_object();
    value_of(dep.getName)
      .should_be_function();
    value_of(dep.getType)
      .should_be_function();
    value_of(dep.getVersion)
      .should_be_function();

    Ti.API.info("processing dependancy '" + dep.getName() + "' type: '" + dep.getType() + "' version: '" + dep.getVersion() + "'");
  },
  // test the installed runtime component functions
  test_installed_runtime: function () {
    Ti.API.error("Ti.API.getInstalledRuntimes()");
    // now that the app is finished testing, test the Ti.API runtime calls.
    // this should return a valid list of runtime components installed with this app.		
    var apiInstalledRuntimes1 = Ti.API.getInstalledRuntimes();

    value_of(apiInstalledRuntimes1)
      .should_be_object();
    if (apiInstalledRuntimes1.length) {
      Ti.API.error("Ti.API.getInstalledRuntimes() contains:");
      for (i = 0; i < apiInstalledRuntimes1.length; i++) {
        var item = apiInstalledRuntimes1[i];
        value_of(item)
          .should_be_object();

        Ti.API.info("apiInstalledRuntimes[" + i + "] name: '" + item.getName() + "' type: '" + item.getType() + "' version: '" + item.getVersion() + "' path '" + item.getPath() + "'");
      }
    } else {
      Ti.API.error("Ti.API.getInstalledRuntimes() returned an empty list");
    }
  },
  // test the installed modules component functions
  test_installed_modules: function () {
    Ti.API.error("Ti.API.getInstalledModules()");
    // now that the app is finished testing, test the Ti.API runtime calls.
    // this should return a valid list of runtime components installed with this app.		
    var apiInstalledModules1 = Ti.API.getInstalledModules();

    value_of(apiInstalledModules1)
      .should_be_object();
    if (apiInstalledModules1.length) {
      Ti.API.error("Ti.API.getInstalledModules() contains:");
      for (i = 0; i < apiInstalledModules1.length; i++) {
        var item = apiInstalledModules1[i];
        value_of(item)
          .should_be_object();

        Ti.API.info("apiInstalledModules[" + i + "] name: '" + item.getName() + "' type: '" + item.getType() + "' version: '" + item.getVersion() + "' path '" + item.getPath() + "'");
      }
    } else {
      Ti.API.error("Ti.API.getInstalledModules() returned an empty list");
    }
  },

  // test the API SDK functions
  test_api_sdk: function () {
    Ti.API.error("Ti.API.getInstalledSDKs()");
    // now that the app is finished testing, test the Ti.API runtime calls.
    // this should return a valid list of runtime components installed with this app.		
    var sdks = Ti.API.getInstalledSDKs();
    value_of(sdks)
      .should_be_array();
    if (sdks.length) {
      Ti.API.error("Ti.API.getInstalledSDKs() contains:");
      for (i = 0; i < sdks.length; i++) {
        var item = sdks[i];
        value_of(item)
          .should_be_object();

        Ti.API.info("apiInstalledSDKs[" + i + "] name: '" + item.getName() + "' type: '" + item.getType() + "' version: '" + item.getVersion() + "' path '" + item.getPath() + "'");
      }
    } else {
      Ti.API.error("Ti.API.getInstalledSDKs() returned an empty list");
    }

    // test the objects in API		
    var app = Ti.API.getApplication();

    value_of(app)
      .should_not_be_null();
    if (app) {
      value_of(app)
        .should_be_object();

      // every module, runtime object and SDK should have a component entry		
      var components = app.getComponents();
      value_of(components)
        .should_be_array();

      // once we have the list of components from the application 
      // object, we need to  verify that the lists are the same 
      // that we get through the application object.

      Ti.API.info("checking installed SDKs[] ");
      var bFound = false;
      for (j = 0; j < sdks.length; j++) {
        var module = sdks[j];
        Ti.API.info("processing SDK component '" + module.getName() + "' type: '" + module.getType() + "' version: '" + module.getVersion() + "' path '" + module.getPath() + "'");


        for (i = 0; i < components.length; i++) {
          var am = components[i];
          value_of(am)
            .should_not_be_null();

          Ti.API.info("processing component '" + am.getName() + "' type: '" + am.getType() + "' version: '" + am.getVersion() + "' path '" + am.getPath() + "'");

          if (module.getName() == am.getName() && module.getType() == am.getType() && module.getPath() == am.getPath()) {
            Ti.API.trace("match SDK  " + module.getName() + " to component entry");
            bFound = true;
            break;
          }
        }
      }

      if (!bFound) {
        // fail the test if we don't find a value.						
        Ti.API.fatal("failed to match SDK object to list of loaded components");
        // this is not a real bug.  this is only meant for developer environments.
      }
    }
  },

  test_api_installed_mobile_sdks: function () {
    // test the objects in API		
    var app = Ti.API.getApplication();
    value_of(app)
      .should_be_object();

    // every module, runtime object and SDK should have a component entry		
    var components = app.getComponents();
    value_of(components)
      .should_be_array();

    // once we have the list of components from the application 
    // object, we need to  verify that the lists are the same 
    // that we get through the application object.
    var mobileSDKs = Ti.API.getInstalledMobileSDKs();
    value_of(mobileSDKs)
      .should_be_array();

    var bFound = false;
    for (j = 0; j < mobileSDKs.length; j++) {
      var module = mobileSDKs[j];
      Ti.API.info("processing mobile SDK module '" + module.getName() + "' type: '" + module.getType() + "' version: '" + module.getVersion() + "' path '" + module.getPath() + "'");

      for (i = 0; i < components.length; i++) {
        if (module.getName() == components[i].getName() && module.getType() == components[i].getType() && module.getPath() == components[i].getPath()) {
          Ti.API.trace("match avialable mobile SDK  " + module.getName() + " to components entry");
          bFound = true;
          break;
        }
      }

      if (!bFound) {
        // don't fail the test if we don't find a value.  this is really just for development.
        Ti.API.warn("failed to match mobile SDK object to list of loaded components");
        // this is not a real bug.  this is only meant for developer environments.
      }
    }
  },
  // test the api arguments.
  test_api_arguments: function () {
    // test the objects in API		
    var app = Ti.API.getApplication();

    value_of(app)
      .should_not_be_null();
    if (app) {
      value_of(app)
        .should_be_object();
      var argv = app.getArguments();

      if (argv) {
        value_of(argv)
          .should_be_object();
        value_of(argv.length)
          .should_not_be(0);

        // print out all the arguments to drillbit.
        for (i = 0; i < argv.length; i++) {
          Ti.API.info("argv[" + i + "] = " + argv[i]);
        }

        var bHasit = app.hasArgument("results");
        value_of(bHasit)
          .should_be_true();

        var results = app.getArgumentValue("results");
        value_of(results)
          .should_not_be_null();
      }
    }
  },
  // test the module component functions
  test_api_module: function () {
    // test the objects in API		
    var app = Ti.API.getApplication();

    value_of(app)
      .should_not_be_null();
    if (app) {
      value_of(app)
        .should_be_object();

      var pid = app.getPID();

      // isCurrent is true when we are the currently running app
      if (app.isCurrent()) {
        // the PID should not be null when we are the current app
        value_of(pid)
          .should_not_be_null();
        Ti.API.info("Application PID = " + pid);
      } else {
        // the pid should be null when we are not the current running app.				
        // I don't think we should ever get here in the unit test since 
        // we should always be the current app.
        value_of(pid)
          .should_be_null();
      }
    }
  },
  // test the application path functions
  test_api_component_Search_Paths: function () {
    var componentSearchPaths = Ti.API.getComponentSearchPaths();

    value_of(componentSearchPaths)
      .should_be_object();
    value_of(componentSearchPaths.length)
      .should_not_be(0);


    Ti.API.info("dump component search paths");
    for (i = 0; i < componentSearchPaths.length; i++) {
      Ti.API.info(componentSearchPaths[i]);
    }
  },

  test_api_events_as_async: function (callback) {
    // create an event
    var w = Ti.API.addEventListener("foo", function () {
      callback.passed();
    });

    // make sure we have a callback for it
    value_of(w)
      .should_be_function();

    // fire it off
    Ti.API.fireEvent("foo");

    // unregister the event when we are done.
    Ti.API.removeEventListener("foo", w);

  },

  test_api_global_object: function () {
    // set a global object
    Ti.API.set("foo", "bar");

    value_of(Ti.API.foo)
      .should_be_string();
    value_of(Ti.API.foo)
      .should_be("bar");

    var str = Ti.API.get("foo");

    value_of(str)
      .should_be_string();
    value_of(str)
      .should_be("bar");
  },

  test_api_run_on_main: function () {
    function test(value) {
      Ti.API.foo = value;
    }

    Ti.API.runOnMainThread(test, "works!");
    value_of(Ti.API.foo)
      .should_be("works!");
  }
});