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

describe("UI.Window Tests", {
  test_app_url_with_query_string_as_async: function (callback) {
    Ti.page_loaded_callback = function () {
      callback.passed();
    };

    setTimeout(function () {
      callback.failed("Could not load app:// URL with query string.");
    }, 500);

    var w = Ti.UI.createWindow("app://querystring.html?param=1");
    w.open();
  },
  test_app_url_with_fragment_as_async: function (callback) {
    Ti.page_loaded_callback = function () {
      callback.passed();
    };

    setTimeout(function () {
      callback.failed("Could not load app:// URL with URL fragment.");
    }, 500);

    var w = Ti.UI.createWindow("app://querystring.html#fooness");
    w.open();
  },
  test_app_url_with_fragment_and_query_string_as_async: function (callback) {
    Ti.page_loaded_callback = function () {
      callback.passed();
    };

    setTimeout(function () {
      callback.failed("Could not load app:// URL with URL fragment and query string.");
    }, 500);

    var w = Ti.UI.createWindow("app://querystring.html?param=1#fooness");
    w.open();
  },
  test_relative_url_with_query_string_as_async: function (callback) {
    Ti.page_loaded_callback = function () {
      callback.passed();
    };

    setTimeout(function () {
      callback.failed("Could not load app:// URL with URL fragment and query string.");
    }, 500);

    var w = Ti.UI.createWindow("app://querystring2.html");
    w.open();
  },
  test_tool_window_as_async: function (callback) {
    var w = Ti.UI.createWindow();
    var w2 = Ti.UI.createWindow();
    var w3 = Ti.UI.getCurrentWindow()
      .createWindow({
      toolWindow: true
    });
    w.setToolWindow(true);

    var verify = function () {
      try {
        value_of(w.isToolWindow())
          .should_be_true();
        value_of(w2.isToolWindow())
          .should_be_false();
        value_of(w3.isToolWindow())
          .should_be_true();
        callback.passed();
      } catch (e) {
        callback.failed(e);
      }
    };

    verify();
    w.open();
    w2.open();
    w3.open();
    verify();
    setTimeout(function () {
      verify();
      w.close();
      w2.close();
      w3.close();
    }, 500);
  },
  test_tool_window_reverse_as_async: function (callback) {
    var w = Ti.UI.createWindow();
    w.setToolWindow(true);
    w.setToolWindow(false);

    var verify = function () {
      try {
        value_of(w.isToolWindow())
          .should_be_false();
        callback.passed();
      } catch (e) {
        callback.failed(e);
      }
    };

    verify();
    w.open();
    verify();

    setTimeout(function () {
      verify();
      w.close();
    }, 500);
  },
  test_set_contents_as_async: function (callback) {
    var w = Ti.UI.createWindow();
    var one = '<html><body><div id="content">Hello.</div>' + '<script>Ti.WindowContentsTest.phaseOne(document.getElementById("content").innerText);</script>' + '</body></html>';
    var two = '<html><body><div id="content">Hello.</div>' + '<script>Ti.WindowContentsTest.success();</script>' + '</body></html>';

    Ti.WindowContentsTest = {
      phaseOne: function (text) {
        if (text != "Hello.") callback.failed("Incorrect text passed: " + text);
        w.setContents(two);
      },
      success: function () {
        callback.passed();
      }
    };

    w.setContents(one);
    w.open();

    setTimeout(function () {
      callback.failed("Test timed out");
      w.close();
    }, 5000);
  },
  test_set_self_contents_as_async: function (callback) {
    Ti.WindowContentsTest = {
      success: function () {
        callback.passed();
      },
      nextPage: "<html><body><script>Ti.WindowContentsTest.success();</script></body></html>"
    };
    var w = Ti.UI.createWindow();
    var contents = '<html><body><div id="content">Hello.</div>' + '<script>\n' + 'Ti.UI.currentWindow.setContents(Ti.WindowContentsTest.nextPage);\n' + '</script></body></html>';
    w.setContents(contents);
    w.open();

    setTimeout(function () {
      callback.failed("Test timed out");
      w.close();
    }, 5000);
  },
  test_set_contents_relative_urls_as_async: function (callback) {
    Ti.WindowContentsTest = {
      success: function (text) {
        if (text == "foo") callback.passed();
        else callback.failed("Incorrect text passed: " + text);
      }
    };

    var w = Ti.UI.createWindow();
    w.setContents('<html><head>' + '<meta http-equiv="refresh" content="1;URL=relative.html">' + '</head><body>redirect</body></html>', 'app://subdir/page.html');
    w.open();
    setTimeout(function () {
      callback.failed("Test timed out");
      w.close();
    }, 5000);
  },
  test_set_window_height_with_menu_as_async: function (callback) {

    var w = Ti.UI.createWindow();

    var checkHeight = function () {
      if (w.height != 500) callback.failed("Height was supposed to be 500, but was " + w.height);
      else callback.passed();
    };

    var changeHeight = function () {
      w.setHeight(500);
      setTimeout(checkHeight, 200);
    };

    Ti.WindowCallback = function () {
      var menu = Ti.UI.createMenu();
      menu.addItem("Foo1");
      menu.getItemAt(0)
        .addItem("Foo");
      w.setMenu(menu);
      setTimeout(changeHeight, 200);
    };

    var contents = '<html><body><div id="content">Hello.</div>' + '<script>\nTi.WindowCallback();\n' + '</script></body></html>';
    w.setContents(contents);
    w.open();

    setTimeout(function () {
      callback.failed("Test timed out");
      w.close();
    }, 5000);
  }
});