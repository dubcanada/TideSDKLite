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

(function () {
  var print = Ti.API.print;
  var println = Ti.App.stdout;
  var errPrint = Ti.App.stderr;

  // Javascript with ANSI color, this might be a first.
  var ansi = (Ti.platform != "win32" || 'MANPATH' in Ti.API.getEnvironment());
  var show_log = false;

  var frontend = {
    passed: 0,
    failed: 0,
    ansi: ansi,
    error: function (msg) {
      errPrint(msg);
    },
    suite_started: function (suite) {
      println("Testing suite '" + suite + "'...");
    },
    show_current_test: function (suite, test) {
      print("  Running '" + test + "'...");
    },
    test_passed: function (suite, test) {
      if (!this.ansi) println(" passed");
      else println(" [32m[1mpassed[0m");
      this.passed++;
    },
    test_failed: function (suite, test, line_number, error) {
      if (!this.ansi) println(" failed");
      else println(" [31m[1mfailed[0m");
      println("   => " + test + "() line " + line_number);
      println("   => " + error);
      this.failed++;
    },
    suite_finished: function (suite) {
      println("Finished '" + suite + "'");
    },
    all_finished: function () {
      println("Total: " + this.passed + " passed, " + this.failed + " failed, " + Ti.Drillbit.total_assertions + " assertions");

      if (test_files.length == 1 && show_log) {
        var editor = null;
        if (Ti.platform == "win32") editor = "C:\\Windows\\system32\\notepad.exe";
        else if (Ti.platform == "osx") editor = "/usr/bin/open";
        else editor = "/usr/bin/gedit";

        if ('EDITOR' in Ti.API.getEnvironment()) {
          editor = Ti.API.getEnvironment()['EDITOR'];
        }

        var app = Ti.API.getApplication();
        var path = Ti.App.appURLToPath('app://test_results/' + tests[0].suite + '.log');
        println("opening log: " + path);

        Ti.Process.createProcess([editor, path])();

      }
    }
  };

  var tests = [];
  var test_files = [];
  var load_all = false;
  for (var c = 0; c < Ti.App.arguments.length; c++) {
    var arg = Ti.App.arguments[c];

    if (arg == '--debug-tests') {
      Ti.Drillbit.debug_tests = true;
    } else if (arg == '--show-log') {
      show_log = true;
    } else if (arg == '--all') {
      load_all = true;
    } else {
      var tokens = arg.split(':');
      var fname = tokens[0];
      var testname = tokens[1] || null;
      var file = Ti.Filesystem.getFile(fname);

      if (!file.exists()) {
        var src_file = null;
        if (Ti.platform == "osx") {
          src_file = Ti.Filesystem.getFile(Ti.API.getApplication()
            .getPath(), '..', '..', "..", "..", 'apps', 'drillbit', 'Resources', 'tests', fname, fname + '.js');
        } else {
          src_file = Ti.Filesystem.getFile(Ti.API.getApplication()
            .getPath(), '..', "..", "..", 'apps', 'drillbit', 'Resources', 'tests', fname, fname + '.js');
        }
        if (src_file.exists()) {
          var t = 'all'
          if (testname != null) t = testname.split(',');

          test_files.push(src_file);
          tests.push({
            'suite': fname,
            tests: t
          });
        } else errPrint("Warning: " + arg + " doesn't exist, skipping.");
      } else {
        var suite = file.name()
          .substring(0, file.name()
          .length - 3);
        println("Loading suite: " + suite + ", file: " + file.nativePath());
        test_files.push(file);
        tests.push({
          'suite': suite,
          tests: 'all'
        });
      }
    }
  }

  if (tests.length == 0 && !load_all) {
    errPrint("Usage:\n\t drillbit_cmd.py [--all] [--debug-tests] suite[:test_name] [suite2..suiteN]");
    Ti.App.exit();
  } else {
    Ti.Drillbit.frontend = frontend;
    Ti.Drillbit.auto_close = true;
    if (load_all) {
      var test_dir = Ti.Filesystem.getFile(Ti.App.appURLToPath('app://tests'));
      var dir_list = test_dir.getDirectoryListing();
      Ti.Drillbit.loadTests(dir_list);
      for (var c = 0; c < Ti.Drillbit.test_names.length; c++) {
        var suite = Ti.Drillbit.test_names[c];
        tests.push({
          suite: suite,
          tests: 'all'
        });
      }
    } else {
      Ti.Drillbit.loadTests(test_files);
    }

    Ti.Drillbit.setupTestHarness(Ti.Filesystem.getFile(Ti.Filesystem.getApplicationDirectory(), 'manifest_harness'));
    Ti.Drillbit.runTests(tests);
  }
})();