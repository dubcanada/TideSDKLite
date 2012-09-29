/**
* (c) 2008-2012 Appcelerator Inc.
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

describe("Desktop tests", {
  test_desktop_functions: function () {
    value_of(Titanium.Desktop.openApplication)
      .should_be_function();
    value_of(Titanium.Desktop.openURL)
      .should_be_function();
    value_of(Titanium.Desktop.takeScreenshot)
      .should_be_function();
  },
  test_screenshot: function () {
    // not implemented in linux yet
    if (Titanium.platform == "linux") return;

    var invalid_args = false;
    try {
      Titanium.Desktop.takeScreenshot();
    } catch (E) {
      invalid_args = true;
    }

    value_of(invalid_args)
      .should_be_true();

    var ext = "png";
    if (Titanium.platform == "win32") {
      ext = "bmp";
    }

    var appdir = Titanium.Filesystem.getApplicationDataDirectory();
    var file = Titanium.Filesystem.getFile(appdir, "screenshot." + ext);
    Titanium.Desktop.takeScreenshot(file.nativePath());

    value_of(file.exists())
      .should_be_true();
  }
});