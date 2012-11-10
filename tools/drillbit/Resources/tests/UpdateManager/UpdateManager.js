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

describe("Update Manaager Tests", {
  test_object: function () {
    value_of(Ti.UpdateManager)
      .should_not_be_null();
    value_of(Ti.UpdateManager.cancelMonitor)
      .should_be_function();
    value_of(Ti.UpdateManager.installAppUpdate)
      .should_be_function();
    value_of(Ti.UpdateManager.onupdate)
      .should_be_null();
    value_of(Ti.UpdateManager.startMonitor)
      .should_be_function();
  },
  test_version_comparison: function () {
    var compare = Ti.UpdateManager.compareVersions;
    value_of(compare("0.8.0", "0.8.0"))
      .should_be(0);
    value_of(compare("0.8.0", "0.8.1"))
      .should_be_less_than(0);
    value_of(compare("0.8.0", "0.8.0.0"))
      .should_be_less_than(0);
    value_of(compare("0.8.0.0", "0.8.1"))
      .should_be_less_than(0);
    value_of(compare("0.8.0.0", "0"))
      .should_be_greater_than(0);
    value_of(compare("0", "0.8.0.0"))
      .should_be_less_than(0);
    value_of(compare("0.8.a", "0.8.0"))
      .should_be_less_than(0);

    value_of(compare("0", "0"))
      .should_be(0);
    value_of(compare("0", "1"))
      .should_be_less_than(0);
    value_of(compare("1", "0"))
      .should_be_greater_than(0);
    value_of(compare("a", "b"))
      .should_be_less_than(0);
    value_of(compare("c", "a"))
      .should_be_greater_than(0);
    value_of(compare("0.a", "0.b"))
      .should_be_less_than(0);
    value_of(compare("0.c", "0.a"))
      .should_be_greater_than(0);
    value_of(compare("a.a", "a.b"))
      .should_be_less_than(0);
    value_of(compare("0.0.0.0.0", "0.0.0.0.0"))
      .should_be(0);
    value_of(compare("0.0.0.0.0.0", "0.0.0.0.0"))
      .should_be_greater_than(0);

    value_of(compare("0.7.0", "0.8.0"))
      .should_be_less_than(0);
    value_of(compare("0.7.0", "0.8.1"))
      .should_be_less_than(0);
    value_of(compare("0.7.0", "0.8.0.0"))
      .should_be_less_than(0);
    value_of(compare("0.7.0.0", "0.8.1"))
      .should_be_less_than(0);
    value_of(compare("0.7.0.0", "0"))
      .should_be_greater_than(0);
    value_of(compare("0", "0.8.0.0"))
      .should_be_less_than(0);
    value_of(compare("0.7.a", "0.8.0"))
      .should_be_less_than(0);

    value_of(compare("0.8.0", "0.7.0"))
      .should_be_greater_than(0);
    value_of(compare("0.8.0", "0.7.1"))
      .should_be_greater_than(0);
    value_of(compare("0.8.0", "0.7.0.0"))
      .should_be_greater_than(0);
    value_of(compare("0.8.0.0", "0.7.1"))
      .should_be_greater_than(0);
    value_of(compare("0.8.0.0", "0"))
      .should_be_greater_than(0);
    value_of(compare("0", "0.7.0.0"))
      .should_be_less_than(0);
    value_of(compare("0.8.a", "0.7.0"))
      .should_be_greater_than(0);
  }
});
