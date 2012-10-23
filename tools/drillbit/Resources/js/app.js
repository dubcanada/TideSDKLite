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

var Ti = Titanium;

Ti.AppCreator = {

  osx: function (assetsDir, destination, name, appid, install) {
    var src = Ti.Filesystem.getFile(destination, name + '.app');
    src.createDirectory(true);
    var contents = Ti.Filesystem.getFile(src, 'Contents');
    contents.createDirectory(true);
    var resources = Ti.Filesystem.getFile(contents, 'Resources');
    resources.createDirectory(true);
    var macos = Ti.Filesystem.getFile(contents, 'MacOS');
    macos.createDirectory(true);
    var lproj = Ti.Filesystem.getFile(resources, 'English.lproj');
    lproj.createDirectory(true);

    var fromMacos = Ti.Filesystem.getFile(assetsDir, 'kboot');
    fromMacos.copy(macos);
    var boot = Ti.Filesystem.getFile(macos, 'kboot');
    boot.rename(name);
    boot.setExecutable(true);

    var mainMenu = Ti.Filesystem.getFile(assetsDir, 'MainMenu.nib');
    mainMenu.copy(lproj);

    var icns = Ti.Filesystem.getFile(assetsDir, 'Titanium.icns');
    icns.copy(lproj);

    var plist = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" +
    "<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n" +
    "<plist version=\"1.0\">\n" +
    "<dict>\n" +
    "	<key>CFBundleDevelopmentRegion</key>\n" +
    "	<string>English</string>\n" +
    "	<key>CFBundleExecutable</key>\n" +
    "	<string>" + name + "</string>\n" +
    "	<key>CFBundleIconFile</key>\n" +
    "	<string>Ti.icns</string>\n" +
    "	<key>CFBundleIdentifier</key>\n" +
    "	<string>" + appid + (install ? '.installer' : '') + "</string>\n" +
    "	<key>CFBundleInfoDictionaryVersion</key>\n" +
    "	<string>6.0</string>\n" +
    "	<key>CFBundleName</key>\n" +
    "	<string>" + name + "</string>\n" +
    "	<key>CFBundlePackageType</key>\n" +
    "	<string>APPL</string>\n" +
    " 	<key>CFBundleSignature</key>\n" +
    "  	<string>WRUN</string>\n" +
    "  	<key>CFBundleVersion</key>\n" +
    "  	<string>0.1</string>\n" +
    "	<key>NSMainNibFile</key>\n" +
    "	<string>MainMenu</string>\n" + 
    "	<key>NSPrincipalClass</key>\n" +
    "	<string>NSApplication</string>\n" +
    "</dict>\n" + "</plist>\n";

    var infoplist = Ti.Filesystem.getFile(contents, 'Info.plist');
    infoplist.write(plist);

    // set our marker file
    var marker = Ti.Filesystem.getFile(contents, '.installed');
    if (!install) {
      marker.write(String(new Date()));
    } else {
      marker.deleteFile();
    }

    return {
      resources: resources,
      base: contents,
      executable: src
    };
  },

  linux: function (assetsDir, destination, name, appid, install) {
    var appDir = Ti.Filesystem.getFile(destination, name);
    appDir.createDirectory(true);
    var resources = Ti.Filesystem.getFile(appDir, 'Resources');
    resources.createDirectory(true);

    var kboot = Ti.Filesystem.getFile(assetsDir, 'kboot');
    var appExecutable = Ti.Filesystem.getFile(appDir, name);
    kboot.copy(appExecutable);

    // set our marker file
    var marker = Ti.Filesystem.getFile(appDir, '.installed');
    if (!install) {
      marker.write(String(new Date()));
    } else {
      marker.deleteFile();
    }

    return {
      resources: resources,
      base: appDir,
      executable: appExecutable
    };
  },

  win32: function (assetsDir, destination, name, appid, install) {
    var appDir = Ti.Filesystem.getFile(destination, name);
    appDir.createDirectory(true);
    var resources = Ti.Filesystem.getFile(appDir, 'Resources');
    resources.createDirectory(true);

    var kboot = Ti.Filesystem.getFile(assetsDir, 'kboot.exe');
    var appExecutable = Ti.Filesystem.getFile(appDir, name + '.exe');
    kboot.copy(appExecutable);

    // set our marker file
    var marker = Ti.Filesystem.getFile(appDir, '.installed');
    if (!install) {
      marker.write(String(new Date()));
    } else {
      marker.deleteFile();
    }

    return {
      resources: resources,
      base: appDir,
      executable: appExecutable
    };
  }
};


Ti.createApp = function (destination, name, appid, install) {

  // DRILLBIT ONLY: We just grab the bundled SDK here, since we know
  // that's where the assets are.
  var components = Ti.API.getApplication()
    .getComponents();
  var assetsDir = null;
  for (var i = 0; i < components.length; i++) {
    var c = components[i];
    if (c.getType() == Ti.API.SDK) {
      assetsDir = Ti.Filesystem.getFile(components[i].getPath());
      break;
    }
  }

  if (!assetsDir.exists()) {
    Ti.API.error("Could not find assets directory at: " + assetsDir);
  }
  install = (typeof (install) == 'undefined') ? true : install;

  var platform = Ti.platform;
  var fn = Ti.AppCreator[platform];
  return fn(assetsDir, destination, name, appid, install);
};

Ti.linkLibraries = function (runtimeDir) {
  if (Ti.platform == 'osx') {
    var fw = ['WebKit', 'WebCore', 'JavaScriptCore'];
    for (var c = 0; c < fw.length; c++) {
      var fwn = fw[c];
      var fwd = Ti.Filesystem.getFile(runtimeDir, fwn + '.framework');
      var fwd_name = fwd.name();
      var versions = Ti.Filesystem.getFile(fwd, 'Versions');
      var ver = Ti.Filesystem.getFile(versions, 'A');
      if (ver.exists()) continue; // skip if already linked
      var current = Ti.Filesystem.getFile(fwd, 'Versions', 'Current');
      ver.createShortcut('Current', versions);
      var hf = Ti.Filesystem.getFile(fwd, 'Headers');
      hf.createShortcut('Versions/Current/Headers', fwd);
      var ph = Ti.Filesystem.getFile(fwd, 'PrivateHeaders');
      ph.createShortcut('Versions/Current/PrivateHeaders', fwd);
      var rf = Ti.Filesystem.getFile(fwd, 'Resources');
      rf.createShortcut('Versions/Current/Resources', fwd);
    }
  }
};