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

describe("UI Stress Tests", {
  test_user_window_title: function () {
    // get the current UserWindow object
    var w = Ti.UI.getCurrentWindow()
      .createWindow('http://www.google.com');

    var title = "blahahahahahahahahahahahahaha";
    w.setTitle(title);
    value_of(w.getTitle())
      .should_be(title);
    title = "  ___     ";
    w.setTitle(title);
    value_of(w.getTitle())
      .should_be(title);
    title = "  _¬˚∆¬˚¬∂ƒ¬∆ø´ˆ∆¬ßƒ∂ˆ__     ";
    w.setTitle(title);
    value_of(w.getTitle())
      .should_be(title);
    title = "";
    w.setTitle(title);
    value_of(w.getTitle())
      .should_be(title);

    w.open();

    title = "blahahahahahahahahahahahahaha";
    w.setTitle(title);
    value_of(w.getTitle())
      .should_be(title);
    title = "  ___     ";
    w.setTitle(title);
    value_of(w.getTitle())
      .should_be(title);
    title = "  _¬˚∆¬˚¬∂ƒ¬∆ø´ˆ∆¬ßƒ∂ˆ__     ";
    w.setTitle(title);
    value_of(w.getTitle())
      .should_be(title);
    title = "";
    w.setTitle(title);
    value_of(w.getTitle())
      .should_be(title);

    w.close();
  },

  test_user_window_url: function () {
    // get the current UserWindow object
    var w = Ti.UI.getCurrentWindow()
      .createWindow('http://www.google.com');

    var url = "http://www.google.com/";
    w.setURL(url);
    value_of(w.getURL())
      .should_be(url);
    url = "http://gmail.com/";
    w.setURL(url);
    value_of(w.getURL())
      .should_be(url);
    url = "http://www.bbc.co.uk/";
    w.setURL(url);
    value_of(w.getURL())
      .should_be(url);
    url = "http://mail.google.com/";
    w.setURL(url);
    value_of(w.getURL())
      .should_be(url);

    w.open();

    url = "http://www.google.com/";
    w.setURL(url);
    value_of(w.getURL())
      .should_be(url);
    url = "http://gmail.com/";
    w.setURL(url);
    value_of(w.getURL())
      .should_be(url);
    url = "http://www.bbc.co.uk/";
    w.setURL(url);
    value_of(w.getURL())
      .should_be(url);
    url = "http://mail.google.com/";
    w.setURL(url);
    value_of(w.getURL())
      .should_be(url);
    w.close();
  },
  test_event_name_constants: function () {
    // If these tests fail, perhaps the constant has changed. If that's
    // the case, just update the tests below and be sure that nothing
    // else in the system breaks! Hopefully apps do not rely on magic strings.
    value_of(Ti.FOCUSED)
      .should_be("focused");
    value_of(Ti.UNFOCUSED)
      .should_be("unfocused");
    value_of(Ti.OPEN)
      .should_be("open");
    value_of(Ti.OPENED)
      .should_be("opened");
    value_of(Ti.CLOSE)
      .should_be("close");
    value_of(Ti.CLOSED)
      .should_be("closed");
    value_of(Ti.HIDDEN)
      .should_be("hidden");
    value_of(Ti.SHOWN)
      .should_be("shown");
    value_of(Ti.FULLSCREENED)
      .should_be("fullscreened");
    value_of(Ti.UNFULLSCREENED)
      .should_be("unfullscreened");
    value_of(Ti.MAXIMIZED)
      .should_be("maximized");
    value_of(Ti.MINIMIZED)
      .should_be("minimized");
    value_of(Ti.RESIZED)
      .should_be("resized");
    value_of(Ti.MOVED)
      .should_be("moved");
    value_of(Ti.PAGE_INITIALIZED)
      .should_be("page.init");
    value_of(Ti.PAGE_LOADED)
      .should_be("page.load");
  },
  test_window_listener_as_async: function (callback) {
    // get the current UserWindow object
    var w = Ti.UI.getCurrentWindow()
      .createWindow('app://blahblah.html');

    var messageLog = {};
    messageLog[Ti.CLOSE] = false;
    messageLog[Ti.CLOSED] = false;
    messageLog[Ti.OPEN] = false;
    messageLog[Ti.OPENED] = false;
    messageLog[Ti.HIDDEN] = false;

    w.addEventListener(function (event) {
      messageLog[event.type] = true;
    });

    w.open();
    setTimeout(function () {
      w.close();
      if (messageLog[Ti.OPEN] !== true) {
        callback.failed("Did not detect open message");
      } else if (messageLog[Ti.OPENED] !== true) {
        callback.failed("Did not detect opened message");
      } else {
        callback.passed();
      }
    }, 1000);
  },
  test_window_maximize_fires_resize_as_async: function (callback) {
    // get the current UserWindow object
    var w = Ti.UI.getCurrentWindow()
      .createWindow('app://blahblah.html');
    w.open();

    var resizedFired = false;
    var maximizedFired = false;

    w.addEventListener(function (event) {
      if (event.type == "resized") {
        resizedFired = true;
      } else if (event.type == "maximized") {
        maximizedFired = true;
      }
    });

    var stageTwo = function () {
      w.close();
      if (!maximizedFired) {
        callback.failed("Did not detect maximized message");
      }
      if (!resizedFired) {
        callback.failed("Did not detect resized message");
      }
      callback.passed();
    };

    setTimeout(function () {
      w.maximize();
      setTimeout(function () {
        stageTwo();
      }, 300);
    }, 300);
  },

  test_constants: function () {
    value_of(Ti.UI.CENTERED)
      .should_be_number();
    value_of(Ti.FOCUSED)
      .should_be_string();
    value_of(Ti.UNFOCUSED)
      .should_be_string();
    value_of(Ti.OPEN)
      .should_be_string();
    value_of(Ti.OPENED)
      .should_be_string();
    value_of(Ti.CLOSE)
      .should_be_string();
    value_of(Ti.CLOSED)
      .should_be_string();
    value_of(Ti.HIDDEN)
      .should_be_string();
    value_of(Ti.SHOWN)
      .should_be_string();
    value_of(Ti.FULLSCREENED)
      .should_be_string();
    value_of(Ti.UNFULLSCREENED)
      .should_be_string();
    value_of(Ti.MAXIMIZED)
      .should_be_string();
    value_of(Ti.MINIMIZED)
      .should_be_string();
    value_of(Ti.RESIZED)
      .should_be_string();
    value_of(Ti.MOVED)
      .should_be_string();
    value_of(Ti.PAGE_INITIALIZED)
      .should_be_string();
    value_of(Ti.PAGE_LOADED)
      .should_be_string();
    value_of(Ti.CREATED)
      .should_be_string();
  },
  test_window_events_as_async: function (callback) {
    var eventTests = [];
    var addEventTest = function (eventTrigger, eventsToVerify, timeout) {
      eventTests.push({
        'trigger': eventTrigger,
        'events': eventsToVerify,
        'timeout': timeout === null ? 250 : timeout
      });
    };

    var observedEvents = {};
    var eventListener = function (event) {
      observedEvents[event.getType()] = "Yakko";
    };

    var w = Ti.UI.getCurrentWindow()
      .createWindow('app://test.html');
    var listener = w.addEventListener(eventListener);
    value_of(listener)
      .should_be_function();

    addEventTest(function () {
      w.open();
    }, [Ti.OPEN, Ti.OPENED, Ti.PAGE_LOADED], 2000);
    addEventTest(function () {
      w.setVisible(false);
    }, [Ti.HIDDEN]);
    addEventTest(function () {
      w.setVisible(true);
    }, [Ti.SHOWN]);
    addEventTest(function () {
      w.setFullscreen(true);
    }, [Ti.FULLSCREENED]);
    addEventTest(function () {
      w.setFullscreen(false);
    }, [Ti.UNFULLSCREENED]);
    addEventTest(function () {
      w.maximize();
    }, [Ti.MAXIMIZED]);
    addEventTest(function () {
      w.unmaximize();
      w.minimize();
    }, [Ti.MINIMIZED]);
    addEventTest(function () {
      w.unminimize();
      var b = w.getBounds();
      w.setX(b.x + 1);
    }, [Ti.MOVED]);
    addEventTest(function () {
      var b = w.getBounds();
      w.setY(b.y + 1);
    }, [Ti.MOVED]);
    addEventTest(function () {
      var b = w.getBounds();
      w.setWidth(b.width * 2);
    }, [Ti.RESIZED]);
    addEventTest(function () {
      var b = w.getBounds();
      w.setHeight(b.height + 1);
    }, [Ti.RESIZED]);
    addEventTest(function () {
      w.close();
    }, [Ti.CLOSE, Ti.CLOSED]);

    var runNextTest = function () {
      if (eventTests.length <= 0) {
        callback.passed();
        return;
      }

      var nextTest = eventTests.shift();
      setTimeout(function () {
        for (var i = 0; i < nextTest.events.length; i++) {
          var evname = nextTest.events[i];
          if (!observedEvents[evname] || observedEvents[evname] !== "Yakko") {
            callback.failed("Did not receive event:" + evname);
          }
        }
        runNextTest();
      }, nextTest.timeout);
      observedEvents = {};
      nextTest.trigger();
    };
    runNextTest();
  },
  test_set_x_sanity_as_async: function (callback) {
    var w = Ti.UI.getCurrentWindow()
      .createWindow({
      width: 500,
      height: 300
    });
    var orig_y = w.getY();
    w.setX(100);

    setTimeout(function () {
      if (w.x != 100) {
        callback.failed("X property was not correct");
      }
      if (w.y != orig_y) {
        callback.failed("Y property was not correct");
      }
      if (w.width != 500) {
        callback.failed("width property was not correct");
      }
      if (w.height != 300) {
        callback.failed("height property was not correct");
      }
      callback.passed();
    }, 250);
  },
  test_set_y_sanity_as_async: function (callback) {
    var w = Ti.UI.getCurrentWindow()
      .createWindow({
      width: 500,
      height: 300
    });
    var orig_x = w.getX();
    w.setY(100);

    setTimeout(function () {
      if (w.y != 100) {
        callback.failed("Y property was not correct");
      }
      if (w.x != orig_x) {
        callback.failed("X property was not correct");
      }
      if (w.width != 500) {
        callback.failed("width property was not correct");
      }
      if (w.height != 300) {
        callback.failed("height property was not correct");
      }
      callback.passed();
    }, 250);
  },
  test_set_width_sanity_as_async: function (callback) {
    var w = Ti.UI.getCurrentWindow()
      .createWindow({
      width: 500,
      height: 300
    });
    var orig_x = w.getX();
    var orig_y = w.getY();
    w.setWidth(400);

    setTimeout(function () {
      if (w.y != orig_y) {
        callback.failed("Y property was not correct");
      }
      if (w.x != orig_x) {
        callback.failed("X property was not correct");
      }
      if (w.width != 400) {
        callback.failed("width property was not correct");
      }
      if (w.height != 300) {
        callback.failed("height property was not correct");
      }
      callback.passed();
    }, 250);
  },
  test_set_height_sanity_as_async: function (callback) {
    var w = Ti.UI.getCurrentWindow()
      .createWindow({
      width: 500,
      height: 300
    });
    var orig_x = w.getX();
    var orig_y = w.getY();
    w.setHeight(400);

    setTimeout(function () {
      if (w.y != orig_y) {
        callback.failed("Y property was not correct");
      }
      if (w.x != orig_x) {
        callback.failed("X property was not correct");
      }
      if (w.width != 500) {
        callback.failed("width property was not correct");
      }
      if (w.height != 400) {
        callback.failed("height property was not correct");
      }
      callback.passed();
    }, 250);
  },
  test_cancel_close_with_stop_propagation_as_async: function (callback) {
    var w = Ti.UI.getCurrentWindow()
      .createWindow({
      width: 500,
      height: 300
    });
    var cancel = true;
    var sawEvent = false;
    w.addEventListener(Ti.CLOSE, function (event) {
      sawEvent = true;
      if (cancel) {
        event.stopPropagation();
      }
    });

    // Ensure this is after the window is open.
    w.open();
    setTimeout(function () {
      w.close();
      setTimeout(function () {
        Ti.API.debug("here1");
        if (!sawEvent) {
          callback.failed("Did not see CLOSE event.");
        }

        Ti.API.debug("did see the event");
        if (w.isActive()) {
          Ti.API.debug("window is active");
          callback.passed();
        } else {
          Ti.API.debug("window is not active");
          callback.failed("Window close event was not cancelled.");
        }
        cancel = false;
        w.close();
      }, 250);
    }, 150);
  },
  test_cancel_close_with_prevent_default_as_async: function (callback) {
    var w = Ti.UI.getCurrentWindow()
      .createWindow({
      width: 500,
      height: 300
    });
    var cancel = true;
    var sawEvent = false;
    w.addEventListener(Ti.CLOSE, function (event) {
      sawEvent = true;
      if (cancel) {
        event.preventDefault();
      }
    });

    // Ensure this is after the window is open.
    w.open();
    setTimeout(function () {
      w.close();
      setTimeout(function () {
        if (!sawEvent) {
          callback.failed("Did not see CLOSE event.");
        }

        if (w.isActive()) {
          callback.passed();
        } else {
          callback.failed("Window close event was not cancelled.");
        }
        cancel = false;
        w.close();
      }, 250);
    }, 150);
  }
});