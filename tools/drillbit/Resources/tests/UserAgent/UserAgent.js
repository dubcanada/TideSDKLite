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

describe("Contents of user agent", {
  validate_name_and_version: function () {
    value_of(Ti.userAgent)
      .should_contain('Titanium/');
    value_of(Ti.userAgent)
      .should_contain('Titanium/' + Ti.version);
    // for now, we're going to simulate Safari -- this addresses TI-303
    value_of(Ti.userAgent)
      .should_contain('Safari');
  }
});
