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

describe("UI.Menu Active Tests", {
  test_basic_menu_append_and_getitemat_as_async: function (cb) {
    var w1 = Ti.UI.getCurrentWindow();
    var w2 = Ti.UI.createWindow({
      url: 'blah.html'
    });
    w2.open();

    var tui = Ti.UI;
    var menu = tui.createMenu();
    w1.setMenu(menu);
    w2.setMenu(menu);

    setTimeout(function () {
      var item1 = tui.createMenuItem('blah1');
      var item2 = tui.createMenuItem('blah2');
      var item3 = tui.createMenuItem('blah3');
      menu.appendItem(item1);
      menu.appendItem(item2);
      menu.appendItem(item3);

      if (menu.getLength() != 3 || !menu.getItemAt(0)
        .equals(item1) || !menu.getItemAt(1)
        .equals(item2) || !menu.getItemAt(2)
        .equals(item3)) cb.failed("Length incorrect");

      var exc = true;
      try {
        var a = menu.getItemAt(-1);
        exc = false;
      } catch (e) {}
      try {
        var a = menu.getItemAt(3);
        exc = false;
      } catch (e) {}
      try {
        var a = menu.getItemAt(30);
        exc = false;
      } catch (e) {}
      try {
        var a = menu.getItemAt(-30);
        exc = false;
      } catch (e) {}
      if (!exc) cb.failed("no exception");

      cb.passed();
    }, 200);
  },
  test_active_removeitem_at_as_async: function (cb) {
    var w1 = Ti.UI.getCurrentWindow();
    var w2 = Ti.UI.createWindow({
      url: 'blah.html'
    });
    w2.open();

    var tui = Ti.UI;
    var menu = tui.createMenu();
    w1.setMenu(menu);
    w2.setMenu(menu);

    var item1 = tui.createMenuItem('blah1');
    var item2 = tui.createMenuItem('blah2');
    var item3 = tui.createMenuItem('blah3');
    var item4 = tui.createMenuItem('blah4');
    var item5 = tui.createMenuItem('blah5');
    menu.appendItem(item1);
    menu.appendItem(item2);
    menu.appendItem(item3);
    menu.appendItem(item4);
    menu.appendItem(item5);

    setTimeout(function () {
      menu.removeItemAt(0);
      if (menu.getLength() != 4 || !menu.getItemAt(0)
        .equals(item2) || !menu.getItemAt(1)
        .equals(item3) || !menu.getItemAt(2)
        .equals(item4) || !menu.getItemAt(3)
        .equals(item5)) cb.failed("Part 1 Failed");

      menu.removeItemAt(1);
      if (menu.getLength() != 3 || !menu.getItemAt(0)
        .equals(item2) || !menu.getItemAt(1)
        .equals(item4) || !menu.getItemAt(2)
        .equals(item5)) cb.failed("Part 2 failed");

      menu.appendItem(item1);
      menu.removeItemAt(3);
      if (menu.getLength() != 3 || !menu.getItemAt(0)
        .equals(item2) || !menu.getItemAt(1)
        .equals(item4) || !menu.getItemAt(2)
        .equals(item5)) cb.failed("Part 3 failed");
      cb.passed();
    }, 200);
  }
});