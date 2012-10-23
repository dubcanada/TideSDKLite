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

describe("Network.Host Tests", {
  // test the network object and properties.
  test_network_object: function () {
    value_of(Titanium.Network)
      .should_not_be_null();
    value_of(Titanium.Network.getHostByAddress)
      .should_be_function();
    value_of(Titanium.Network.getHostByName)
      .should_be_function();
  },

  test_network_Host_object: function () {
    var theHost = Titanium.Network.getHostByName("127.0.0.1");

    value_of(theHost.getAddresses)
      .should_be_function();
    value_of(theHost.getAliases)
      .should_be_function();
    value_of(theHost.getName)
      .should_be_function();
    value_of(theHost.isInvalid)
      .should_be_function();
    value_of(theHost.toString)
      .should_be_function();
  },

  test_network_Host_by_address: function () {
    var theHost = Titanium.Network.getHostByAddress("127.0.0.1");
    value_of(theHost)
      .should_be_object();
    value_of(theHost.isInvalid())
      .should_be_false();

    value_of(theHost.getName())
      .should_be("127.0.0.1");
    Titanium.API.debug(theHost.toString());
  },

  test_network_Host_by_name: function () {
    var theHost = Titanium.Network.getHostByName("localhost");
    value_of(theHost)
      .should_be_object();
    value_of(theHost.isInvalid())
      .should_be_false();

    // this should be the machine name.
    var alias = theHost.getAliases();
    var hostname = theHost.getName();
    var bfound = false;
    value_of(alias)
      .should_be_array();

    // on windows this can be zero length, don't fail.
    if (alias.length > 0) {
      for (i = 0; i < alias.length; i++) {
        value_of(alias[i])
          .should_be_string();
        Titanium.API.debug(alias[i]);
        if (alias[i].indexOf(hostname) != -1) {
          bfound = true;
          break;
        }
      }

      value_of(bfound)
        .should_be_true();
    }
    Titanium.API.debug(theHost.toString());
  },

  test_network_Host_addresses: function () {
    var theHost = Titanium.Network.getHostByName("127.0.0.1");
    value_of(theHost)
      .should_be_object();
    value_of(theHost.isInvalid())
      .should_be_false();

    value_of(theHost.getAddresses)
      .should_be_function();

    var alist = theHost.getAddresses();
    value_of(alist)
      .should_be_array();

    for (i = 0; i < alist.length; i++) {
      value_of(alist[i])
        .should_be_object();
    }
  },

  test_network_Host_aliases: function () {
    var theHost = Titanium.Network.getHostByName("127.0.0.1");
    value_of(theHost)
      .should_be_object();
    value_of(theHost.isInvalid())
      .should_be_false();

    value_of(theHost.getAliases)
      .should_be_function();

    var alist = theHost.getAliases();
    value_of(alist)
      .should_be_array();

    for (i = 0; i < alist.length; i++) {
      value_of(alist[i])
        .should_be_string();
    }
  }
});