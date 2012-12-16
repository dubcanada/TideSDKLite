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

Ti.Project = {
  requiredModulesList: ['api', 'tiapp', 'tifilesystem', 'tiplatform', 'tiui', 'javascript'],
  requiredModules: [],
  optionalModules: [],
  runtimeDir: null,
  runtimeVersion: null,
  getModuleVersion: function (versions) {
    var latestVer = 0
    for (var i = 0; i < versions.length; i++) {
      var ver = parseFloat(versions[i]);
      if (ver > latestVer) {
        latestVer = ver;
      }
    }
    return ver;
  },
  setModules: function (dir, runtime) {
    var result = this.getModulesAndRuntime(dir, runtime);

    // set runtime DIR and VERSION
    this.runtimeDir = result['runtime_basedir'];
    this.runtimeVersion = runtime;

    this.requiredModules = [];
    this.optionalModules = [];

    // set optional and required modules
    for (var c = 0; c < result.modules.length; c++) {
      var name = result.modules[c].name;
      if (this.requiredModulesList.indexOf(name) == -1) {
        this.optionalModules.push({
          name: name,
          version: result.modules[c].version,
          dir: result.modules[c].dir
        });
      }
    }

    // write out required modules in order
    for (var i = 0; i < this.requiredModulesList.length; i++) {
      for (var c = 0; c < result.modules.length; c++) {
        if (result.modules[c].name == this.requiredModulesList[i]) {
          this.requiredModules.push({
            name: result.modules[c].name,
            version: result.modules[c].version,
            dir: result.modules[c].dir
          });
        }
      }
    }
  },
  writeManifest: function (project) {
    this.setModules(project.dir, project.runtime);

    var resources = Ti.Filesystem.getFile(project.dir, 'Resources');

    // build the manifest
    var manifest = '#appname:' + project.name + '\n';
    manifest += '#appid:' + project.appid + '\n';
    manifest += '#publisher:' + project.publisher + '\n';

    if (project.image) {
      // look for image in two places - either full path or in resources dir
      var image = Ti.Filesystem.getFile(project.image);
      if (!image.exists()) {
        image = Ti.Filesystem.getFile(resources, project.image);
      }
      // use default if not exists
      if (!image.exists()) {
        var path = Ti.App.appURLToPath('app://images');
        image = Ti.Filesystem.getFile(path, 'default_app_logo.png')
      }

      var image_dest = Ti.Filesystem.getFile(resources, image.name());
      if (image.toString() != image_dest.toString()) {
        image.copy(image_dest);
      }
      imageName = image.name();
      manifest += '#image:' + image.name() + '\n';
    }

    manifest += '#url:' + project.url + '\n';
    manifest += '#guid:' + project.guid + '\n';
    manifest += '#desc:' + project.description + '\n';
    manifest += '#type:desktop\n';
    manifest += 'runtime:0.4.0\n';

    // write out required modules
    for (var i = 0; i < this.requiredModules.length; i++) {
      manifest += this.requiredModules[i].name + ':' + this.requiredModules[i].version + '\n';
    }
    // write out optional modules
    for (var c = 0; c < this.optionalModules.length; c++) {
      // check for optional ruby language module
      if (this.optionalModules[c].name == 'ruby') {
        if (project['languageModules']) {
          if (project['languageModules'].ruby == 'on') {
            manifest += this.optionalModules[c].name + ':' + this.optionalModules[c].version + '\n';
          }
          continue;
        }
      }

      // check for optional python language module
      if (this.optionalModules[c].name == 'python') {
        if (project['languageModules']) {

          if (project['languageModules'].python == 'on') {
            manifest += this.optionalModules[c].name + ':' + this.optionalModules[c].version + '\n';
          }
          continue;
        }
      }

      manifest += this.optionalModules[c].name + ':' + this.optionalModules[c].version + '\n';
    }

    var mf = Ti.Filesystem.getFile(project.dir, 'manifest');
    mf.write(manifest);
    return manifest;

  },
  launch: function (project, install, callback, args) {
    try {
      // write out new manifest based on current modules
      var manifest = this.writeManifest(project);

      // create dist dir
      var dist = Ti.Filesystem.getFile(project.dir, 'dist', Ti.platform);
      dist.createDirectory(true);

      var app = Ti.createApp(dist, project.name, project.appid, install);

      // write out new manifest
      var app_manifest = Ti.Filesystem.getFile(app.base, 'manifest');
      app_manifest.write(manifest);

      // write out tiapp.xml
      var resources = Ti.Filesystem.getFile(project.dir, 'Resources');
      var tiapp = Ti.Filesystem.getFile(project.dir, 'tiapp.xml');
      tiapp.copy(app.base);

      Ti.Filesystem.asyncCopy(resources, app.resources, function () {
        // no modules to bundle, install the net installer
        var net_installer_src = Ti.Filesystem.getFile(runtime, 'installer');
        var net_installer_dest = Ti.Filesystem.getFile(app.base, 'installer');
        Ti.Filesystem.asyncCopy(net_installer_src, net_installer_dest, function (filename, c, total) {
          var appModules = Ti.Filesystem.getFile(project.dir, "modules");
          if (appModules.exists()) {
            var moduleDest = Ti.Filesystem.getFile(app.base, "modules");
            Ti.Filesystem.asyncCopy(appModules, moduleDest, function () {
              Ti.Process.setEnv('KR_DEBUG', 'true');
              var x = Ti.Process.launch(app.executable.nativePath(), args);
              if (x && callback) {
                callback(x);
              }
            });
          } else {
            Ti.Process.setEnv('KR_DEBUG', 'true');
            var x = Ti.Process.launch(app.executable.nativePath(), args);
            if (x && callback) {
              callback(x);
            }
          }
        });
      });
    } catch (e) {
      alert('Error launching app ' + e);
    }

  },

  getRuntimes: function (appDir) {
    var app = Ti.API.readApplicationManifest(appDir + Ti.Filesystem.getSeparator() + 'manifest');
    var modules = app.getAvailableComponents();
    var versions = [];
    var tracker = {};
    if (modules) {
      for (var i = 0; i < modules.length; i++) {
        if (modules[i].getName() == 'runtime') {
          if (!tracker[modules[i].getVersion()]) {
            versions.push(modules[i].getVersion());
            tracker[modules[i].getVersion()] = true;
          }
        }
      }
    }
    return versions;
  },
  getModulesAndRuntime: function (appDir, runtime) {
    var os = Ti.platform;
    var results = [];
    var runtimeDir = null;

    // get core runtime modules
    var app = Ti.API.readApplicationManifest(appDir + Ti.Filesystem.getSeparator() + 'manifest');
    var modules = app.getAvailableComponents();
    var tracker = {};
    if (modules) {
      for (var i = 0; i < modules.length; i++) {
        var mod = modules[i];
        if (mod.getVersion() == "0.4.0") {
          if (mod.getName() == 'runtime') {
            runtimeDir = mod.getPath();
          } else {
            if (!tracker[mod.getName()]) {
              results.push({
                name: mod.getName(),
                version: String(mod.getVersion()),
                dir: mod.getPath()
              });
              tracker[mod.getName()] = true;
            }

          }
        }
      }
    }

    return {
      modules: results,
      'runtime_basedir': runtimeDir
    };

  },
  parseEntry: function (entry) {
    if (entry[0] == ' ' || entry.length == 0) return null;
    var i = entry.indexOf(':');
    if (i < 0) return null;
    var key = jQuery.trim(entry.substring(0, i));
    var value = jQuery.trim(entry.substring(i + 1));
    var token = false;
    if (key.charAt(0) == '#') {
      token = true;
      key = key.substring(1);
    }
    return {
      key: key,
      value: value,
      token: token
    };
  },
  addEntry: function (line, result) {
    if (line) {
      var entry = Ti.Project.parseEntry(line);
      if (!entry) return;
      if (entry.token) result.properties[entry.key] = entry.value;
      else result.map[entry.key] = entry.value;
    }
  },
  getManifest: function (mf) {
    var manifest = Ti.Filesystem.getFile(mf);
    if (!manifest.isFile()) {
      return {
        success: false,
        message: "Couldn't find manifest!"
      };
    }
    var result = {
      success: true,
      file: manifest,
      map: {},
      properties: {}
    };
    var line = manifest.readLine(true);
    Ti.Project.addEntry(line, result);
    while (true) {
      line = manifest.readLine();
      if (!line) break;
      Ti.Project.addEntry(line, result);
    }
    return result;
  },
  writeTiXML: function (id, name, publisher, url, outdir) {
    var tiappxml = this.XML_PROLOG;
    var year = new Date()
      .getFullYear();
    tiappxml += this.makeEntry('id', id);
    tiappxml += this.makeEntry('name', name);
    tiappxml += this.makeEntry('version', '1.0');
    tiappxml += this.makeEntry('publisher', publisher);
    tiappxml += this.makeEntry('url', url);
    tiappxml += this.makeEntry('copyright', year + ' by ' + publisher);
    tiappxml += "<window>\n";
    tiappxml += this.makeEntry('id', 'initial');
    tiappxml += this.makeEntry('title', name);
    tiappxml += this.makeEntry('url', 'app://index.html');
    tiappxml += this.makeEntry('width', '700');
    tiappxml += this.makeEntry('max-width', '3000');
    tiappxml += this.makeEntry('min-width', '0');
    tiappxml += this.makeEntry('height', '800');
    tiappxml += this.makeEntry('max-height', '3000');
    tiappxml += this.makeEntry('min-height', '0');
    tiappxml += this.makeEntry('fullscreen', 'false');
    tiappxml += this.makeEntry('resizable', 'true');
    tiappxml += this.makeEntry('chrome', 'true', {
      'scrollbars': 'true'
    });
    tiappxml += this.makeEntry('maximizable', 'true');
    tiappxml += this.makeEntry('minimizable', 'true');
    tiappxml += this.makeEntry('closeable', 'true');
    tiappxml += "</window>\n";
    tiappxml += this.XML_EPILOG;
    var ti = Ti.Filesystem.getFile(outdir, 'tiapp.xml');
    ti.write(tiappxml);
    return ti;
  },
  create: function (options) {
    var name = options.name;
    var guid = options.guid;
    var desc = options.desc;
    var dir = options.dir;
    var publisher = options.publisher;
    var url = options.url;
    var image = options.image;
    var jsLibs = options.jsLibs;
    var html = options.html;
    var type = options.type;
    var id = options.id;

    var outdir = Ti.Filesystem.getFile(dir, name);
    if (outdir.isDirectory()) {
      return {
        success: false,
        message: "Directory already exists: " + outdir
      }
    }
    outdir.createDirectory(true);

    // write out the TIAPP.xml
    var tiappxml = this.XML_PROLOG;
    var year = new Date()
      .getFullYear();
    tiappxml += this.makeEntry('id', id);
    tiappxml += this.makeEntry('name', name);
    tiappxml += this.makeEntry('version', '1.0');
    tiappxml += this.makeEntry('publisher', publisher);
    tiappxml += this.makeEntry('url', url);
    tiappxml += this.makeEntry('copyright', year + ' by ' + publisher);
    tiappxml += "<window>\n";
    tiappxml += this.makeEntry('id', 'initial');
    tiappxml += this.makeEntry('title', name);
    tiappxml += this.makeEntry('url', 'app://index.html');
    tiappxml += this.makeEntry('width', '700');
    tiappxml += this.makeEntry('max-width', '3000');
    tiappxml += this.makeEntry('min-width', '0');
    tiappxml += this.makeEntry('height', '800');
    tiappxml += this.makeEntry('max-height', '3000');
    tiappxml += this.makeEntry('min-height', '0');
    tiappxml += this.makeEntry('fullscreen', 'false');
    tiappxml += this.makeEntry('resizable', 'true');
    tiappxml += this.makeEntry('chrome', 'true', {
      'scrollbars': 'true'
    });
    tiappxml += this.makeEntry('maximizable', 'true');
    tiappxml += this.makeEntry('minimizable', 'true');
    tiappxml += this.makeEntry('closeable', 'true');
    tiappxml += "</window>\n";
    tiappxml += this.XML_EPILOG;
    var ti = Ti.Filesystem.getFile(outdir, 'tiapp.xml');
    ti.write(tiappxml);
    var resources = Ti.Filesystem.getFile(outdir, 'Resources');
    resources.createDirectory();
    var index = Ti.Filesystem.getFile(resources, 'index.html');

    var jquery = '<script type="text/javascript" src="jquery-1.3.2.js"></script>\n';
    var entourage = '<script type="text/javascript" src="entourage-jquery-3.0.js"></script>\n';
    var prototype_js = '<script type="text/javascript" src="prototype-1.6.0.js"></script>\n';
    var scriptaculous = '<script type="text/javascript" src="scriptaculous-1.8.2.js"></script>\n';
    var mootools = '<script type="text/javascript" src="mootools-1.2.1.js"></script>\n';
    var yahoo = '<script type="text/javascript" src="yui-2.6.0.js"></script>\n';
    var swfobject = '<script type="text/javascript" src="swfobject-1.5.js"></script>\n';
    var dojo = '<script type="text/javascript" src="dojo-1.2.3.js"></script>\n';

    var head = '';

    if (html) {
      head += '<head>\n';
    } else {
      head += '<head><style>body{background-color:#292929;color:white}</style>\n';
    }

    var path = Ti.App.appURLToPath('app://thirdparty_js');
    if (jsLibs) {
      for (var i = 0; i < jsLibs.length; i++) {
        switch (jsLibs[i]) {
        case 'jquery':
          {
            head += jquery
            var f = Ti.Filesystem.getFile(path, 'jquery-1.3.2.js');
            f.copy(resources);
            continue;
          }
        case 'entourage':
          {
            head += entourage;
            var f = Ti.Filesystem.getFile(path, 'entourage', 'entourage-jquery-3.0.js');
            f.copy(resources);
            var f2 = Ti.Filesystem.getFile(path, 'entourage', 'entourage-ui');
            f2.copy(resources);
            continue;
          }
        case 'mootools':
          {
            head += mootools;
            var f = Ti.Filesystem.getFile(path, 'mootools-1.2.1.js');
            f.copy(resources);
            continue;
          }
        case 'prototype':
          {
            head += prototype_js;
            var f = Ti.Filesystem.getFile(path, 'prototype-1.6.0.js');
            f.copy(resources);
            continue;
          }
        case 'scriptaculous':
          {
            head += scriptaculous;
            var f = Ti.Filesystem.getFile(path, 'scriptaculous-1.8.2.js');
            f.copy(resources);
            continue;
          }
        case 'dojo':
          {
            head += dojo;
            var f = Ti.Filesystem.getFile(path, 'dojo-1.2.3.js');
            f.copy(resources);
            continue;
          }
        case 'yui':
          {
            head += yahoo;
            var f = Ti.Filesystem.getFile(path, 'yui-2.6.0.js');
            f.copy(resources);
            continue;
          }
        case 'swf':
          {
            head += swfobject;
            var f = Ti.Filesystem.getFile(path, 'swfobject-1.5.js');
            f.copy(resources);
            continue;
          }
        }

      }
    }
    head += '</head>';

    if (html) {
      index.write('<html>\n' + head + '\n<body>\n' + html + '\n</body>\n</html>')
    } else {
      index.write('<html>\n' + head + '\n<body>\nWelcome to Ti\n</body>\n</html>');
    }

    var manifest = "#appname: " + name + "\n" + "#publisher: " + publisher + "\n" + "#url: " + url + "\n" + "#image: " + image + "\n" + "#appid: " + id + "\n" + "#desc: " + desc + "\n" + "#type: " + type + "\n" + "#guid: " + guid + "\n";

    var mf = Ti.Filesystem.getFile(outdir, 'manifest');
    mf.write(manifest);

    var gi = Ti.Filesystem.getFile(outdir, '.gitignore');
    gi.write('dist\ntmp\n');

    var dist = Ti.Filesystem.getFile(outdir, 'dist');
    dist.createDirectory();

    return {
      basedir: outdir,
      resources: resources,
      id: id,
      name: name,
      success: true
    };
  },
  makeEntry: function (key, value, attrs) {
    var str = '<' + key;
    if (attrs) {
      str += ' ';
      var values = [];
      for (name in attrs) {
        var v = attrs[name];
        if (v) {
          values.push(name + '=' + '"' + v + '"');
        }
      }
      str += values.join(' ');
    }
    str += '>' + value + '</' + key + '>\n';
    return str;
  },

  updateManifest: function (values, addGuid) {
    var manifest = Ti.Filesystem.getFile(values.dir, "manifest");
    var normalized_name = name.replace(/[^a-zA-Z0-9]/g, '_')
      .toLowerCase();
    normalized_name = normalized_name.replace(/ /g, '_')
      .toLowerCase();
    var normalized_publisher = publisher.replace(/[^a-zA-Z0-9]/g, '_')
      .toLowerCase();
    normalized_publisher = normalized_publisher.replace(/ /g, '_')
      .toLowerCase();
    var id = 'com.' + normalized_publisher + '.' + normalized_name;
    var newManifest = ''

    // add guid if not exists
    if (addGuid == true) {
      newManifest = '#guid:' + values.guid + "\n";
    }

    var line = manifest.readLine(true);
    var entry = Ti.Project.parseEntry(line);
    for (var i = 0; i < 1000; i++) {
      if (entry == null) {
        line = manifest.readLine();
        if (!line || line == null) break;
        entry = Ti.Project.parseEntry(line);
      }
      if (entry.key.indexOf('appname') != -1) {
        newManifest += '#appname:' + values.name + "\n";
      } else if (entry.key.indexOf('publisher') != -1) {
        newManifest += '#publisher:' + values.publisher + "\n";
      } else if (entry.key.indexOf('url') != -1) {
        newManifest += '#url:' + values.url + "\n";
      } else if (entry.key.indexOf('image') != -1) {
        newManifest += '#image:' + values.image + "\n";
      } else if (entry.key.indexOf('appid') != -1) {
        newManifest += '#appid:' + id + "\n";
      } else if (entry.key.indexOf('guid') != -1) {
        newManifest += '#guid:' + values.guid + "\n";
      } else if (entry.key.indexOf('description') != -1) {
        newManifest += '#desc:' + values.description + "\n";
      } else {
        newManifest += entry.key + ":" + entry.value + "\n";
      }
      entry = null;
    }
    manifest.write(newManifest);
  }
};

// // by default, add our current modules
// (function()
// {
// 	var tok = Ti.platform=='win32' ? ';' : ':';
// 	var modules = Ti.Process.getEnv('KR_MODULES').split(tok);
// 	for (var c=0;c<modules.length;c++)
// 	{
// 		var m = modules[c];
// 		if (m)
// 		{
// 			var f = Ti.Filesystem.getFile(m);
// 			alert("name="+m+",f="+f);
// 			var name = f.getName();
// 			Ti.Project.optionalModules.push(name);
// 		}
// 	}
// })();

Ti.Project.XML_PROLOG = "<?xml version='1.0' encoding='UTF-8'?>\n" + "<ti:app xmlns:ti='http://ti.appcelerator.org'>\n";

Ti.Project.XML_EPILOG = "</ti:app>";