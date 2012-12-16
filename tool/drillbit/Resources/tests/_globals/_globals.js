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

describe("Globals Tests", {
  test_platform: function () {
    // function to testout the global properties in Ti.
    value_of(Ti.platform)
      .should_be_string();
    // get the platform and version.
    value_of(Ti.platform)
      .should_be_one_of(['win32', 'osx', 'linux']);
    Ti.API.info("Ti.platform = " + Ti.platform);
  },

  test_version: function () {
    value_of(Ti.version)
      .should_be_string();
    var arr = Ti.version.split('.');
    value_of(arr.length)
      .should_be(3);
    value_of(Number(arr[0]))
      .should_be_number();
    value_of(Number(arr[1]))
      .should_be_number();
    value_of(Number(arr[2]))
      .should_be_number();

    Ti.API.info("Ti.version = " + Ti.version);
  }
});
