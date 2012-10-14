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

describe("WebKit AJAX Tests", {
  twitter_as_async: function (callback) {
    var timer = 0;

    $.ajax({
      type: 'GET',
      dataType: 'json',
      url: 'http://maps.googleapis.com/maps/api/geocode/json',

      success: function (data) {
        clearTimeout(timer);
        if (typeof (data) !== 'object') {
          callback.failed("HTTP request did not return object");
        } else {
          callback.passed();
        }
      },
      error: function (xhr, status, error) {
        var err = "HTTP request failed:";
        err += (status | error | "Unknown");
        callback.failed(err);
      }
    });

    // fail test after 30s
    timer = setTimeout(function () {
      callback.failed('ajax request timed out after 30s');
    }, 30000);
  },
  twitter_https_as_async: function (callback) {
    var timer = 0;
    $.ajax({
      type: 'GET',
      dataType: 'json',
      url: 'https://maps.googleapis.com/maps/api/geocode/json',

      success: function (data) {
        clearTimeout(timer);
        if (typeof (data) !== 'object') {
          callback.failed("HTTPS request did not return object");
        } else {
          callback.passed();
        }
      },
      error: function (xhr, status, error) {
        var err = "HTTPS request failed:";
        err += (status | error | "Unknown");
        callback.failed(err);
      }
    });

    // fail test after 30s
    timer = setTimeout(function () {
      callback.failed('ajax request timed out after 30s');
    }, 30000);
  },
  local_file_fail_using_app_as_async: function (callback) {
    // fail test after 2s
    var timer = setTimeout(

    function () {
      callback.failed('ajax request timed out after 30s');
    }, 2000);

    $.ajax({
      url: 'app://testasdfasdfasdf.js',
      success: function (data) {
        clearTimeout(timer);
        callback.failed("Request succeeded, but should have failed");
      },
      error: function () {
        clearTimeout(timer);
        callback.passed();
      }
    });
  }
  /* XXX Temporarily disable - Local files always return a status code of 0
  local_file_using_app_as_async: function (callback) {
    // fail test after 2s
    var timer = setTimeout(function () {
      callback.failed('ajax request timed out after 30s');
    }, 2000);

    $.ajax({
      url: 'app://test.js',
      success: function (data) {
        clearTimeout(timer);
        callback.passed();
      },
      error: function (xhr, textStatus) {
        clearTimeout(timer);
        callback.failed("Request failed" + textStatus);
      }
    });
  },
  test_query_string_as_async: function (callback) {
    var timer = setTimeout(function () {
      callback.failed('ajax request timed out after 30s');
    }, 2000);
    $.getJSON('app://test.js?q=1', function (data) {
      clearTimeout(timer);
      try {
        value_of(data)
          .should_be_object();
        value_of(data.success)
          .should_be_true();
        value_of(data.abc)
          .should_be(123);
        callback.passed();
      } catch (e) {
        callback.failed(e);
      }
    });
  }
  */
});