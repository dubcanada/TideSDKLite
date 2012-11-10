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

describe("UI.Clipboard", {
  test_clipboard_text_data_set_twice: function () {
    Ti.UI.Clipboard.setData("text/plain", "blahblah");
    var data = Ti.UI.Clipboard.getData("text/plain");
    value_of(data)
      .should_be("blahblah");

    Ti.UI.Clipboard.setData("text/plain", "blahblah");
    var data = Ti.UI.Clipboard.getData("text/plain");
    value_of(data)
      .should_be("blahblah");
  },
  test_clipboard_methods: function () {
    value_of(Ti.UI.Clipboard)
      .should_be_object();
    value_of(Ti.UI.Clipboard.setData)
      .should_be_function();
    value_of(Ti.UI.Clipboard.getData)
      .should_be_function();
    value_of(Ti.UI.Clipboard.clearData)
      .should_be_function();
    value_of(Ti.UI.Clipboard.setText)
      .should_be_function();
    value_of(Ti.UI.Clipboard.getText)
      .should_be_function();
  },
  test_clipboard_text_data: function () {
    Ti.UI.Clipboard.setData("text/plain", "blahblah");
    var data = Ti.UI.Clipboard.getData("text/plain");
    value_of(data)
      .should_be("blahblah");

    Ti.UI.Clipboard.setData("text/plain", "");
    value_of(Ti.UI.Clipboard.hasText())
      .should_be_false();
    var data = Ti.UI.Clipboard.getData("text/plain");
    value_of(data)
      .should_be("");

    Ti.UI.Clipboard.setData("text/plain", "crazy utf8 ‽‽‽ ⸮⸮⸮ woohoo");
    data = Ti.UI.Clipboard.getData("text/plain");
    value_of(data)
      .should_be("crazy utf8 ‽‽‽ ⸮⸮⸮ woohoo");
  },
  test_clipboard_text: function () {
    Ti.UI.Clipboard.setText("blahblah");
    var data = Ti.UI.Clipboard.getText();
    value_of(data)
      .should_be("blahblah");

    Ti.UI.Clipboard.setText("");
    value_of(Ti.UI.Clipboard.hasText())
      .should_be_false();
    data = Ti.UI.Clipboard.getText();
    value_of(data)
      .should_be("");

    Ti.UI.Clipboard.setText("crazy utf8 ‽‽‽ ⸮⸮⸮ woohoo");
    data = Ti.UI.Clipboard.getText();
    value_of(data)
      .should_be("crazy utf8 ‽‽‽ ⸮⸮⸮ woohoo");
  },
  test_clipboard_clear_data: function () {
    Ti.UI.Clipboard.setText("blahblah");
    Ti.UI.Clipboard.setData("text/plain", "blahblah");
    Ti.UI.Clipboard.clearData("text/plain");

    var data = Ti.UI.Clipboard.getText();
    value_of(data)
      .should_be("");

    data = Ti.UI.Clipboard.getData("text/plain");
    value_of(data)
      .should_be("");
  },
  test_clipboard_clear_text: function () {
    Ti.UI.Clipboard.setText("blahblah");
    Ti.UI.Clipboard.setData("text/plain", "blahblah");

    Ti.UI.Clipboard.clearText();

    var data = Ti.UI.Clipboard.getText();
    value_of(data)
      .should_be("");

    data = Ti.UI.Clipboard.getData("text/plain");
    value_of(data)
      .should_be("");

    // TODO: This should eventually set other data types on the
    // clipboard and ensure that they are *not* cleared.
  },
  test_clipboard_has_text: function () {
    Ti.UI.Clipboard.setText("blahblah");
    value_of(Ti.UI.Clipboard.hasText())
      .should_be_true();

    Ti.UI.Clipboard.clearData("text/plain");
    value_of(Ti.UI.Clipboard.hasText())
      .should_be_false();

    Ti.UI.Clipboard.setText("blahblah");
    value_of(Ti.UI.Clipboard.hasText())
      .should_be_true();

    Ti.UI.Clipboard.clearData("text/plain");
    value_of(Ti.UI.Clipboard.hasText())
      .should_be_false();

    Ti.UI.Clipboard.setText("");
    value_of(Ti.UI.Clipboard.hasText())
      .should_be_false();
  },
  test_clipboard_urilist_data: function () {
    if (Ti.platform == "win32") /* TODO: implement uri-list in win32 */
    return;

    var uri1 = Ti.Filesystem.getApplicationDirectory()
      .toURL();
    var uri2 = Ti.Filesystem.getResourcesDirectory()
      .toURL();
    var uri3 = Ti.Filesystem.getDesktopDirectory()
      .toURL();
    var uristring = uri1 + "\n" + uri2 + "\n" + uri3;
    Ti.UI.Clipboard.setData("text/uri-list", uristring);
    var data = Ti.UI.Clipboard.getData("text/uri-list");
    value_of(data)
      .should_be_array();
    value_of(data.length)
      .should_be(3);
    value_of(data[0].indexOf(uri1))
      .should_be(0); // A trailing slash may have been added
    value_of(data[1].indexOf(uri2))
      .should_be(0); // A trailing slash may have been added
    value_of(data[2].indexOf(uri3))
      .should_be(0); // A trailing slash may have been added

    Ti.UI.Clipboard.setData("text/uri-list", null);
    value_of(Ti.UI.Clipboard.hasData("text/uri-list"))
      .should_be_false();
    var data = Ti.UI.Clipboard.getData("text/uri-list");
    value_of(data)
      .should_be_array();
    value_of(data.length)
      .should_be(0);

    Ti.UI.Clipboard.setData("text/uri-list", [uri1, uri2, uri3]);
    var data = Ti.UI.Clipboard.getData("text/uri-list");
    value_of(data)
      .should_be_array();
    value_of(data.length)
      .should_be(3);
    value_of(data[0].indexOf(uri1))
      .should_be(0); // A trailing slash may have been added
    value_of(data[1].indexOf(uri2))
      .should_be(0); // A trailing slash may have been added
    value_of(data[2].indexOf(uri3))
      .should_be(0); // A trailing slash may have been added

    Ti.UI.Clipboard.setData("text/uri-list", null);
    value_of(Ti.UI.Clipboard.hasData("text/uri-list"))
      .should_be_false();
    var data = Ti.UI.Clipboard.getData("text/uri-list");
    value_of(data)
      .should_be_array();
    value_of(data.length)
      .should_be(0);
  },
  test_clipboard_clear_uri_list: function () {
    if (Ti.platform == "win32") /* TODO: implement uri-list in win32 */
    return;

    var uri1 = Ti.Filesystem.getApplicationDirectory()
      .toURL();
    var uri2 = Ti.Filesystem.getResourcesDirectory()
      .toURL();
    var uri3 = Ti.Filesystem.getDesktopDirectory()
      .toURL();
    var uristring = uri1 + "\n" + uri2 + "\n" + uri3;
    Ti.UI.Clipboard.setData("text/uri-list", uristring);
    var data = Ti.UI.Clipboard.getData("text/uri-list");
    value_of(data)
      .should_be_array();
    value_of(data.length)
      .should_be(3);
    value_of(data[0].indexOf(uri1))
      .should_be(0); // A trailing slash may have been added
    value_of(data[1].indexOf(uri2))
      .should_be(0); // A trailing slash may have been added
    value_of(data[2].indexOf(uri3))
      .should_be(0); // A trailing slash may have been added

    Ti.UI.Clipboard.clearData("text/uri-list");
    value_of(Ti.UI.Clipboard.hasData("text/uri-list"))
      .should_be(false);
  },
  test_clipboard_url_data: function () {
    if (Ti.platform == "win32") /* TODO: implement uri-list in win32 */
    return;

    Ti.UI.Clipboard.setData("url", "http://www.google.com");
    var data = Ti.UI.Clipboard.getData("url");
    value_of(data)
      .should_be("http://www.google.com");
    value_of(Ti.UI.Clipboard.hasData("url"))
      .should_be(true);

    Ti.UI.Clipboard.setData("url", "http://www.yahoo.com");
    data = Ti.UI.Clipboard.getData("url");
    value_of(data)
      .should_be("http://www.yahoo.com");
    value_of(Ti.UI.Clipboard.hasData("url"))
      .should_be(true);

    Ti.UI.Clipboard.setData("url", null);
    value_of(Ti.UI.Clipboard.hasData("url"))
      .should_be_false();
    data = Ti.UI.Clipboard.getData("url");
    value_of(data)
      .should_be("");

    Ti.UI.Clipboard.setData("url", ["http://www.google.com", "http://www.yahoo.com"]);
    data = Ti.UI.Clipboard.getData("url");
    value_of(data)
      .should_be("http://www.google.com");
    value_of(Ti.UI.Clipboard.hasData("url"))
      .should_be_true();

    Ti.UI.Clipboard.setData("url", "");
    value_of(Ti.UI.Clipboard.hasData("url"))
      .should_be_false();
    data = Ti.UI.Clipboard.getData("url");
    value_of(data)
      .should_be("");
  },
  test_clipboard_clear_url_list: function () {
    if (Ti.platform == "win32") /* TODO: implement uri-list in win32 */
    return;

    Ti.UI.Clipboard.setData("url", "http://www.yahoo.com");
    var data = Ti.UI.Clipboard.getData("url");
    value_of(data)
      .should_be("http://www.yahoo.com");

    Ti.UI.Clipboard.clearData("url");
    value_of(Ti.UI.Clipboard.hasData("url"))
      .should_be(false);
  }
});