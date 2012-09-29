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

// ==UserScript==
// @name	Titanium App Tester
// @author	Appcelerator
// @description	Titanium Tests
// @include	app://com.titaniumapp.unittest/index.html
// @version	0.1
// ==/UserScript==

<%
  var Ti = Titanium;

	function add_line_numbers(entry, fname) {
	  var f = entry.test[fname];
	  var code = String(f);
	  var lines = code.split("\n");
	  var ready = false;
	  var new_code = "";
	  for (var linenum = 0; linenum < lines.length; linenum++) {
	    var line = lines[linenum];
	    var idx = line.indexOf('should_');
	    if (idx != -1) {
	      var endIdx = line.lastIndexOf(')');
	      var absoluteLine = linenum + entry.line_offsets[fname] + 1;
	      if (line.charAt(endIdx - 1) == '(') {
	        line = line.substring(0, endIdx) + 'null,' + absoluteLine + ');';
	      } else {
	        line = line.substring(0, endIdx) + ',' + absoluteLine + ');';
	      }

	    }
	    new_code += line + "\n";
	  }

	  return new_code;
	}

	function make_function(entry, fname, scope) {
	  var f = entry.test[fname];
	  if (typeof (f) == 'function') {
	    if (typeof (scope) == 'undefined') {
	      return '(' + add_line_numbers(entry, fname) + ')();\n';
	    } else {
	      var expr = '(function(){var _scope = ' + scope + ';\n';
	      expr += '(' + add_line_numbers(entry, fname) + ').call(_scope,_scope);\n';
	      expr += '})();\n';
	      return expr;
	    }
	  }
	  return '';
	};%>

<%= Ti.Filesystem.getFile(Ti.App.appURLToPath('app://drillbit_func.js')).read() %>

Test.NAME = "<%= entry.name %>";
Test.SOURCE = "<%= entry.source_file.nativePath().replace(/\\/g, "\\\\") %>";
try {
	<%= make_function(entry, 'before_all', 'Test.gscope') %>
}
catch (e) {
	Ti.API.error('before_all caught error:'+e+' at line: '+e.line);
}

<% for (var f in entry.test) {
	var i = excludes.indexOf(f);
	var run = (entry.tests_to_run == "all" || entry.tests_to_run.indexOf(f) != -1);
	if (i == -1 && run) { %>

		Test.tests.push(function() {
			// <%= f %>
			var xscope = new Test.Scope('<%= f %>');
			<%= make_function(entry, 'before', 'xscope') %>;

			try {
				Test.currentTest = '<%= f %>';
				Test.runningTest('<%= entry.name %>', '<%= f %>');
				<%= make_function(entry, f, 'xscope') %>;
				<%
				i = f.indexOf('_as_async');
				if (i==-1)
				{ %>
					Test.testPassed('<%= f %>',Test.currentSubject.lineNumber);
				<% } %>
			}
			catch (___e) {
				// wrap the exception message so we can report the failed test's line number
				var ___err = {
					message: ___e.message || "Non-assertion exception: " + String(___e),
					line: ___e.constructor == Test.Error ? ___e.line : <%= entry.line_offsets[f] %>,
					toString: function() { return this.message; }
				};
				Test.testFailed('<%= f %>', ___err);
			}
			<%= make_function(entry, 'after', 'xscope') %>
			// --- <%= f %> ---
		});
<%	}
} %>

Test.on_complete = function() {
	try {
		<%= make_function(entry, 'after_all','Test.gscope') %>;
	}
	catch (e) {
		Ti.API.error('after_all caught error:'+e+' at line: '+e.line);
	}
	Test.complete();
};

Test.run_next_test();
