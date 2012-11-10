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

describe("Network.TCPSocket Tests", {
  // ti.network.HTTP objects are covered in the http_server unit test.
  before_all: function () {
    // Launch testing server on port 8080
    this.testServer = Ti.Process.createProcess({
      args: [
        'python', Ti.API.application.resourcesPath + "/testserver.py"
      ],
    });
    this.testServer.launch();
    //@hack WTF is this about? 
    //Well, till python spins up the server, there's a delay. So, we end up with failing tests. 
    //This forces before_all to wait X milliseconds, which gives testserver a chance
    //to spin up and respond.
    var sleep = function(millis) {
        var date = new Date();
        var curDate = null;
        do { curDate = new Date(); }
        while(curDate-date < millis);
    };
    sleep(5000);
  },
  
  after_all: function () {
    //this.testServer.kill();
  },

  before: function () {
    // Create a test socket client
    this.socket = Ti.Network.createTCPSocket("127.0.0.1", 8080);
  },

  // test the network object and properties.
  test_TCPSocket_object: function () {
    value_of(this.socket)
      .should_be_object();
    value_of(this.socket.close)
      .should_be_function();
    value_of(this.socket.connect)
      .should_be_function();
    value_of(this.socket.isClosed)
      .should_be_function();
    value_of(this.socket.write)
      .should_be_function();
  },

  test_connect_as_async: function (test) {
    var timer;
    var socket = this.socket;

    socket.on("connect", function () {
      clearTimeout(timer);
      socket.close();
      test.passed();
    });

    socket.on("error", function (err) {
      clearTimeout(timer);
      test.failed(err);
    });

    socket.connect();
    timer = setTimeout(function () {
      test.failed("Test timed out");
    }, 2000);
  },

  test_timeout_as_async: function (test) {
    var timer;
    var socket = this.socket;

    socket.setTimeout(1000);
    socket.on("timeout", function () {
      clearTimeout(timer);
      socket.close();
      test.passed();
    });

    socket.connect();
    timer = setTimeout(function () {
      test.failed("Test timed out");
    }, 2000);
  },

  test_read_write_as_async: function (test) {
    var timer;
    var message = "hello, can anyone hear me?";
    var socket = this.socket;

    socket.on("connect", function () {
      // Send test server a message.
      socket.write(message);
    });

    socket.on("data", function (data) {
      clearTimeout(timer);

      try {
        // Test server should echo the message back.
        value_of(data)
          .should_be(message);
        socket.close();
        test.passed();
      } catch (e) {
        test.failed(e);
      }
    });

    socket.on("error", function (err) {
      clearTimeout(timer);
      test.failed(err);
    });

    socket.connect();
    timer = setTimeout(function () {
      test.failed("Test timed out");
    }, 2000);
  }
});