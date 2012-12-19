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

describe("Network.IPAddress Tests", {
  // ti.network.HTTP objects are covered in the http_server unit test.

  before: function () {
    value_of(Ti.Network)
      .should_not_be_null();
    value_of(Ti.Network.createIPAddress)
      .should_be_function();
    value_of(Ti.Network.IPAddress)
      .should_not_be_null();

    this.ipAddr = Ti.Network.createIPAddress("127.0.0.1");

    value_of(this.ipAddr)
      .should_not_be_null();
  },

  after: function () {
    this.ipAddr = null;
  },
  // test the network object and properties.
  test_network_IPAddress_object: function () {
    value_of(this.ipAddr)
      .should_be_object();
    value_of(this.ipAddr)
      .should_be_object();

    value_of(this.ipAddr.isBroadcast)
      .should_be_function();
    value_of(this.ipAddr.isGlobalMC)
      .should_be_function();
    value_of(this.ipAddr.isIPV4)
      .should_be_function();
    value_of(this.ipAddr.isIPV6)
      .should_be_function();
    value_of(this.ipAddr.isInvalid)
      .should_be_function();
    value_of(this.ipAddr.isLinkLocal)
      .should_be_function();
    value_of(this.ipAddr.isLinkLocalMC)
      .should_be_function();
    value_of(this.ipAddr.isLoopback)
      .should_be_function();
    value_of(this.ipAddr.isMulticast)
      .should_be_function();
    value_of(this.ipAddr.isNodeLocalMC)
      .should_be_function();
    value_of(this.ipAddr.isOrgLocalMC)
      .should_be_function();
    value_of(this.ipAddr.isSiteLocal)
      .should_be_function();
    value_of(this.ipAddr.isSiteLocalMC)
      .should_be_function();
    value_of(this.ipAddr.isUnicast)
      .should_be_function();
    value_of(this.ipAddr.isWellKnownMC)
      .should_be_function();
    value_of(this.ipAddr.isWildcard)
      .should_be_function();
    value_of(this.ipAddr.toString)
      .should_be_function();

    Ti.API.debug("ipAddr.isBroadcast = " + this.ipAddr.isBroadcast()
      .toString());
    Ti.API.debug("ipAddr.isGlobalMC = " + this.ipAddr.isGlobalMC()
      .toString());
    Ti.API.debug("ipAddr.isIPV4 = " + this.ipAddr.isIPV4()
      .toString());
    Ti.API.debug("ipAddr.isIPV6 = " + this.ipAddr.isIPV6()
      .toString());
    Ti.API.debug("ipAddr.isInvalid = " + this.ipAddr.isInvalid()
      .toString());
    Ti.API.debug("ipAddr.isLinkLocal = " + this.ipAddr.isLinkLocal()
      .toString());
    Ti.API.debug("ipAddr.isLinkLocalMC = " + this.ipAddr.isLinkLocalMC()
      .toString());
    Ti.API.debug("ipAddr.isLoopback = " + this.ipAddr.isLoopback()
      .toString());
    Ti.API.debug("ipAddr.isMulticast = " + this.ipAddr.isMulticast()
      .toString());
    Ti.API.debug("ipAddr.isNodeLocalMC = " + this.ipAddr.isNodeLocalMC()
      .toString());
    Ti.API.debug("ipAddr.isOrgLocalMC = " + this.ipAddr.isOrgLocalMC()
      .toString());
    Ti.API.debug("ipAddr.isSiteLocal = " + this.ipAddr.isSiteLocal()
      .toString());
    Ti.API.debug("ipAddr.isSiteLocalMC = " + this.ipAddr.isSiteLocalMC()
      .toString());
    Ti.API.debug("ipAddr.isUnicast = " + this.ipAddr.isUnicast()
      .toString());
    Ti.API.debug("ipAddr.isWellKnownMC = " + this.ipAddr.isWellKnownMC()
      .toString());
    Ti.API.debug("ipAddr.isWildcard = " + this.ipAddr.isWildcard()
      .toString());
    Ti.API.debug("ipAddr.toString = " + this.ipAddr.toString()
      .toString());

  },

  test_IPAddress_isBroadcast: function () {
    var res = this.ipAddr.isBroadcast();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isGlobalMC: function () {
    var res = this.ipAddr.isGlobalMC();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isIPV4: function () {
    var res = this.ipAddr.isIPV4();
    value_of(res)
      .should_be_true();
  },
  test_IPAddress_isIPV6: function () {
    var res = this.ipAddr.isIPV6();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isInvalid: function () {
    var res = this.ipAddr.isInvalid();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isLinkLocal: function () {
    var res = this.ipAddr.isLinkLocal();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isLinkLocalMC: function () {
    var res = this.ipAddr.isLinkLocalMC();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isLoopback: function () {
    var res = this.ipAddr.isLoopback();
    value_of(res)
      .should_be_true();
  },

  test_IPAddress_isMulticast: function () {
    var res = this.ipAddr.isMulticast();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isNodeLocalMC: function () {
    var res = this.ipAddr.isNodeLocalMC();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isOrgLocalMC: function () {
    var res = this.ipAddr.isOrgLocalMC();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isSiteLocal: function () {
    var res = this.ipAddr.isSiteLocal();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isSiteLocalMC: function () {
    var res = this.ipAddr.isSiteLocalMC();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isUnicast: function () {
    var res = this.ipAddr.isUnicast();
    value_of(res)
      .should_be_true();
  },

  test_IPAddress_isWellKnownMC: function () {
    var res = this.ipAddr.isWellKnownMC();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_isWildcard: function () {
    var res = this.ipAddr.isWildcard();
    value_of(res)
      .should_be_false();
  },

  test_IPAddress_toString: function () {
    var res = this.ipAddr.toString();
    value_of(res)
      .should_be("127.0.0.1");
  }
});