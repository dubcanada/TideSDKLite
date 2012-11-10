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

describe("JSON tests", {
  test_object: function () {
    value_of(Ti.JSON)
      .should_not_be_null();

    var obj = new Object();
    obj.intProp = 0;
    obj.strProp = "string";
    obj.func = function () {
      Ti.API.info("inside a function");
    };

    value_of(obj)
      .should_be_object();
    value_of(obj.intProp)
      .should_be_number();
    value_of(obj.strProp)
      .should_be_string();
    value_of(obj.func)
      .should_be_function();

    // convert the object to a string.
    var jsonObj = Ti.JSON.stringify(obj);

    value_of(jsonObj)
      .should_be_string();

    Ti.API.debug(jsonObj);
    var theObj = Ti.JSON.parse(jsonObj);

    value_of(theObj)
      .should_be_object();
    value_of(theObj.intProp)
      .should_be_number();
    value_of(theObj.strProp)
      .should_be_string();
    value_of(theObj.func)
      .should_be_undefined();
  }
});