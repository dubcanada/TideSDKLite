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

describe("Ti.Filesystem tests", {
  before_all: function () {
    // clean up testing folder if needed
    var base = Ti.Filesystem.getFile(Ti.Filesystem.getApplicationDataDirectory(), "unittest_filesystem");
    if (base.exists() && base.isDirectory()) {
      base.deleteDirectory(true);
    } else if (base.exists() && base.isFile()) {
      base.deleteFile();
    }

    base.createDirectory();

    this.base = base;

    this.createDirTree = function (base, name) {
      var dir = Ti.Filesystem.getFile(base, name);
      if (!dir.exists()) {
        dir.createDirectory();
      }

      var file1 = Ti.Filesystem.getFileStream(dir, "file1.txt");
      var file2 = Ti.Filesystem.getFileStream(dir, "file2.txt");
      var subDir1 = Ti.Filesystem.getFile(dir, "subDir1");
      subDir1.createDirectory();
      var file3 = Ti.Filesystem.getFileStream(subDir1, "file3.txt");

      file1.open(Ti.Filesystem.MODE_WRITE);
      file1.write("Text for file1");
      file1.close();

      file2.open(Ti.Filesystem.MODE_WRITE);
      file2.write("Text for file2");
      file2.close();

      file3.open(Ti.Filesystem.MODE_WRITE);
      file3.write("Text for file3");
      file3.close();
    };


  },

  filesystem_basic_static_properties: function () {
    var methods = ['getFile', 'getFileStream', 'getApplicationDataDirectory'];

    for (var c = 0; c < methods.length; c++) {
      var method = methods[c];
      value_of(Ti.Filesystem[method])
        .should_be_function();
    }
  },

  other_props: function () {
    value_of(Ti.Filesystem.getLineEnding)
      .should_be_function();
    value_of(Ti.Filesystem.getSeparator)
      .should_be_function();
    value_of(Ti.Filesystem.MODE_READ)
      .should_not_be_null();
    value_of(Ti.Filesystem.MODE_WRITE)
      .should_not_be_null();
    value_of(Ti.Filesystem.MODE_APPEND)
      .should_not_be_null();

    value_of(Ti.Filesystem.getLineEnding())
      .should_not_be_null();
    value_of(Ti.Filesystem.getSeparator())
      .should_not_be_null();
  },

  get_file: function () {
    var f = Ti.Filesystem.getFile(this.base, "getFileTest.txt");
    value_of(f)
      .should_not_be_null();
    // we only created a path to a file, not a real file.
    value_of(f.exists())
      .should_be_false();
  },

  get_file_stream: function () {
    var fs = Ti.Filesystem.getFileStream(this.base, "getFileStreamTest.txt");
    value_of(fs)
      .should_not_be_null();
  },

  temp_file: function () {
    value_of(Ti.Filesystem.createTempFile)
      .should_be_function();

    var f = Ti.Filesystem.createTempFile();
    value_of(f)
      .should_not_be_null();
    value_of(f.exists())
      .should_be_true();
    value_of(f.isFile())
      .should_be_true();
    value_of(f.isDirectory())
      .should_be_false();
  },

  temp_directory: function () {
    value_of(Ti.Filesystem.createTempDirectory)
      .should_be_function();

    var f = Ti.Filesystem.createTempDirectory();
    value_of(f)
      .should_not_be_null();
    value_of(f.exists())
      .should_be_true();
    value_of(f.isFile())
      .should_be_false();
    value_of(f.isDirectory())
      .should_be_true();
  },

  common_directories: function () {
    value_of(Ti.Filesystem.getProgramsDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getApplicationDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getRuntimeHomeDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getResourcesDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getDesktopDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getDocumentsDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getUserDirectory)
      .should_be_function();

    value_of(Ti.Filesystem.getProgramsDirectory())
      .should_not_be_null();
    value_of(Ti.Filesystem.getApplicationDirectory())
      .should_not_be_null();
    value_of(Ti.Filesystem.getRuntimeHomeDirectory())
      .should_not_be_null();
    value_of(Ti.Filesystem.getResourcesDirectory())
      .should_not_be_null();
    value_of(Ti.Filesystem.getDesktopDirectory())
      .should_not_be_null();
    value_of(Ti.Filesystem.getDocumentsDirectory())
      .should_not_be_null();
    value_of(Ti.Filesystem.getUserDirectory())
      .should_not_be_null();
  },

  test_ProgramsDirectory: function () {
    value_of(Ti.Filesystem.getProgramsDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getProgramsDirectory())
      .should_not_be_null();

    var folder = Ti.Filesystem.getProgramsDirectory();
    value_of(folder)
      .should_not_be_null();
    value_of(folder.exists())
      .should_be_true();
    value_of(folder.isFile())
      .should_be_false();
    value_of(folder.isDirectory())
      .should_be_true();

    Ti.API.debug("Ti.Filesystem.getProgramsDirectory=" + folder.nativePath());

    var progFileFolder = null;

    if (Ti.platform == 'win32') {
      // in windows we have an environment variable we can check
      // for the program files directory.

      progFileFolder = Ti.API.getEnvironment()["PROGRAMFILES"];
      Ti.API.debug("windows env PROGRAMFILES=" + progFileFolder);
    } else if (Ti.platform == 'osx') {
      // on the Mac, this should be hard coded to '/Applications' according to the source code.
      progFileFolder = "/Applications";
    } else if (Ti.platform == 'linux') {
      // currently under linux we are hard coded to this path.  this could change
      progFileFolder = "/usr/local/bin";
    } else {
      failed("unknown platform");
    }
    value_of(progFileFolder.indexOf(folder.nativePath()))
      .should_not_be(-1);
  },

  test_ApplicationDirectory: function () {
    value_of(Ti.Filesystem.getApplicationDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getApplicationDirectory())
      .should_not_be_null();

    var f = Ti.Filesystem.getApplicationDirectory();
    Ti.API.debug("application folder" + f.nativePath());
    value_of(f == Ti.App.home)
      .should_be_true();
  },

  test_RuntimeHomeDirectory: function () {
    value_of(Ti.Filesystem.getRuntimeHomeDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getRuntimeHomeDirectory())
      .should_not_be_null();

    var f = Ti.Filesystem.getRuntimeHomeDirectory();
    Ti.API.debug("runtime home folder" + f.nativePath());

    var componentPaths = Ti.API.getComponentSearchPaths();
    value_of(componentPaths)
      .should_be_array();

    var bfound = false;

    for (i = 0; i < componentPaths.length; i++) {
      if (f == componentPaths[i]) {
        Ti.API.debug("runtime reported path = " + componentPaths[i].toString());
        bfound = true;
        break;
      }
    }
    value_of(bfound)
      .should_be_true();
  },

  test_ResourcesDirectory: function () {
    value_of(Ti.Filesystem.getResourcesDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getResourcesDirectory())
      .should_not_be_null();

    var f = Ti.Filesystem.getResourcesDirectory();
    Ti.API.debug("Resources folder" + f.nativePath());

    value_of(f.nativePath()
      .indexOf(Ti.Filesystem.getApplicationDirectory()))
      .should_not_be(-1);
  },
  test_DesktopDirectory: function () {
    value_of(Ti.Filesystem.getDesktopDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getDesktopDirectory())
      .should_not_be_null();

    var desktop = Ti.Filesystem.getDesktopDirectory();
    value_of(desktop)
      .should_not_be_null();

    var userHome = null;
    // we have an environment variable we can check
    // for the user home directory.  then we can make sure it's a substring
    // of the desktop folder path
    if (Ti.platform == 'win32') {
      userHome = Ti.API.getEnvironment()["USERPROFILE"];
      Ti.API.debug(Ti.platform + " env USERPROFILE=" + userHome);
    } else {
      // on the Mac, this should be hard coded to '~/desktop' according to the source code.
      // on linux, this will be hard coded in a similar fashion
      userHome = Ti.API.getEnvironment()["HOME"];
      Ti.API.debug(Ti.platform + " env HOME=" + userHome);
    }
    var path = desktop.nativePath();
    value_of(path.indexOf(userHome))
      .should_not_be(-1);
  },
  test_DocumentsDirectory: function () {
    value_of(Ti.Filesystem.getDocumentsDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getDocumentsDirectory())
      .should_not_be_null();

    var documents = Ti.Filesystem.getDesktopDirectory();
    value_of(documents)
      .should_not_be_null();

    var userHome = null;
    // we have an environment variable we can check
    // for the user home directory.  then we can make sure it's a substring
    // of the desktop folder path
    if (Ti.platform == 'win32') {
      userHome = Ti.API.getEnvironment()["USERPROFILE"];
      Ti.API.debug(Ti.platform + " env USERPROFILE=" + userHome);
    } else {
      // on the Mac, this should be hard coded to '~/desktop' according to the source code.
      // on linux, this will be hard coded in a similar fashion
      userHome = Ti.API.getEnvironment()["HOME"];
      Ti.API.debug(Ti.platform + " env HOME=" + userHome);
    }
    var path = documents.nativePath();
    value_of(path.indexOf(userHome))
      .should_not_be(-1);
  },
  test_UserDirectory: function () {
    value_of(Ti.Filesystem.getUserDirectory)
      .should_be_function();
    value_of(Ti.Filesystem.getUserDirectory())
      .should_not_be_null();

    var f = Ti.Filesystem.getUserDirectory();
    value_of(f)
      .should_not_be_null();
    Ti.API.debug("user home folder =" + f.nativePath());

    var userHome = null;
    if (Ti.platform == 'win32') {
      // in windows we have an environment variable we can check
      // for the program files directory.
      userHome = Ti.API.getEnvironment()["USERPROFILE"];
      Ti.API.debug(Ti.platform + " environment USERPROFILE=" + userHome);
    } else {
      // on the Mac, this should be hard coded to '~/desktop' according to the source code.
      userHome = Ti.API.getEnvironment()["HOME"];
      Ti.API.debug(Ti.platform + " environment HOME=" + userHome);
    }
    value_of(f.nativePath())
      .should_be(userHome);
  },

  root_directories: function () {
    value_of(Ti.Filesystem.getRootDirectories)
      .should_be_function();

    var rootDirs = Ti.Filesystem.getRootDirectories();
    value_of(rootDirs)
      .should_not_be_null();
    value_of(rootDirs.length > 0)
      .should_be_true();
    var rootDirFirst = rootDirs[0];
    value_of(rootDirFirst)
      .should_be_object();
    try {
      value_of(rootDirFirst.isDirectory())
        .should_be_true();
    } catch (e) {
      // swallow accesss errors here, silly windows
      if (e.toString()
        .indexOf("File access error") == -1) {
        throw e;
      }
    }
  },

  async_copy: function () {
    var fromDir = Ti.Filesystem.getFile(this.base, "ayncCopyFrom");
    var toDir = Ti.Filesystem.getFile(this.base, "asynCopyTo");
    this.createDirTree(this.base, "ayncCopyFrom");
    Ti.Filesystem.asyncCopy(fromDir, toDir, function () {

      value_of(AsyncCopy.running)
        .should_be_true();

      var listings = toDir.getDirectoryListing();
      value_of(listings)
        .should_not_be_null();
      value_of(listings.length == 3)
        .should_be_true();

      var toSubDir1 = Ti.Filesystem.getFile(fromDir, "subDir1");
      value_of(toSubDir1.isDirectory())
        .should_be_true();

      var subDirListings = toSubDir1.getDirectoryListing();
      value_of(subDirListings)
        .should_not_be_null();
      value_of(subDirListings.length == 1)
        .should_be_true();
    });
  },

  test_line_endings: function () {
    value_of(Ti.Filesystem.getLineEnding)
      .should_be_function();
    value_of(Ti.Filesystem.getLineEnding())
      .should_not_be_null();

    if (Ti.platform == 'win32') {
      // this is weird, we need to investigate further.
      value_of(Ti.Filesystem.getLineEnding())
        .should_be("\n");
    } else {
      value_of(Ti.Filesystem.getLineEnding())
        .should_be("\n");
    }
  },

  test_separator: function () {
    value_of(Ti.Filesystem.getSeparator)
      .should_be_function();
    value_of(Ti.Filesystem.getSeparator())
      .should_not_be_null();

    if (Ti.platform == 'win32') {
      value_of(Ti.Filesystem.getSeparator())
        .should_be("\\");
    } else {
      value_of(Ti.Filesystem.getSeparator())
        .should_be("/");
    }
  }
});