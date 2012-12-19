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

describe("HTML5 Database Tests", {

  before: function () {
    this.db = openDatabase('unittest', '1.0', "Unit test database", 1024 * 1024 * 5);

    // test the return object to make sure we got the correct object.
    value_of(this.db)
      .should_be_object();

    // add methods to verify that we got the proper object.
  },

  after: function () {
    this.db.transaction(function (tx) {
      tx.executeSql('DROP TABLE TEST');
    });
    this.db = null;
  },

  validate_version: function () {
    value_of(this.db.version)
      .should_not_be_undefined();
    value_of(this.db.version)
      .should_be('1.0');
  },

  test_data_as_async: function (scope) {
    function run_test(tx) {
      // see if project table exists
      tx.executeSql("CREATE TABLE TEST (name TEXT)", [], function (tx, result) {
        tx.executeSql('INSERT INTO TEST (name) VALUES (?)', ['foo'], function (tx, result) {
          tx.executeSql('SELECT * FROM TEST', [], function (tx, result) {
            scope.passed();
          },

          function (tx, error) {
            scope.failed('select failed:' + error.message);
          });
        },

        function (tx, error) {
          scope.failed('insert failed:' + error.message);
        });
      },

      function (tx, error) {
        scope.failed('create table failed:' + error.message);
      });
    }
    this.db.transaction(function (tx) {
      tx.executeSql('DROP TABLE TEST', null, function (tx, result) {
        run_test(tx);
      },

      function (tx, error) {
        // this is OK, just means we didn't have the table
        run_test(tx);
      });
    });
  }
});