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

describe("Notification tests", {

  test_notification_object: function () {
    var wnd = Titanium.UI.createNotification(parent.window);

    value_of(wnd.hide).should_be_function();
    value_of(wnd.setDelay).should_be_function();
    value_of(wnd.setIcon).should_be_function();
    value_of(wnd.setMessage).should_be_function();
    value_of(wnd.setTitle).should_be_function();
    value_of(wnd.show).should_be_function();
    value_of(wnd).should_be_object();
  },

  test_it_with_old_icon_as_async: function (callback) {
    value_of(Titanium.UI.createNotification).should_be_function();

    // create a notification object
    var parent = Titanium.UI.getCurrentWindow();
    var wnd = Titanium.UI.createNotification(parent.window);
    wnd.setTitle("title");
    wnd.setMessage("this is a message with the old drillbit icon");
    wnd.setIcon("app://logo_large.png");
    wnd.setDelay(5000);


    Titanium.API.debug("attempting to show the notification");
    wnd.show();

    timer = setTimeout(function () {
      try {
        Titanium.API.debug("hiding the notification");
        wnd.hide();
        callback.passed();
      } catch (e) {
        Titanium.API.debug("hiding the notification failed with an exception");
        callback.failed();
      }
    }, 1000);
  },

  test_it_with_new_icon_as_async: function (callback) {
    value_of(Titanium.UI.createNotification).should_be_function();

    // create a notification object
    var parent = Titanium.UI.getCurrentWindow();
    var wnd = Titanium.UI.createNotification(parent.window);
    wnd.setTitle("title");
    wnd.setMessage("this is a message with the new tidesdk icon");
    wnd.setIcon("app://logo_small.png");
    wnd.setDelay(5000);


    Titanium.API.debug("attempting to show the notification");
    wnd.show();

    timer = setTimeout(function () {
      try {
        Titanium.API.debug("hiding the notification");
        wnd.hide();
        callback.passed();
      } catch (e) {
        Titanium.API.debug("hiding the notification failed with an exception");
        callback.failed();
      }
    }, 1000);
  },

  test_non_utf8_as_async: function (callback) {
    value_of(Titanium.UI.createNotification).should_be_function();

    // create a notification object
    var parent = Titanium.UI.getCurrentWindow();
    var wnd = Titanium.UI.createNotification(parent.window);
    wnd.setTitle("title");
    wnd.setMessage("Стоял он, дум великих полн");
    wnd.setIcon("app://logo_small.png");
    wnd.setDelay(5000);


    Titanium.API.debug("attempting to show the notification");
    wnd.show();

    timer = setTimeout(function () {
      try {
        Titanium.API.debug("hiding the notification");
        wnd.hide();
        callback.passed();
      } catch (e) {
        Titanium.API.debug("hiding the notification failed with an exception");
        callback.failed();
      }
    }, 1000);
  }
});