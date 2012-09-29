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

describe("Platform Tests", {
  test_interfaces: function () {
    var interfaces = Titanium.Platform.interfaces;
    value_of(Titanium.Platform.interfaces)
      .should_be_array();
    value_of(Titanium.Platform.interfaces.length > 0)
      .should_be_true();

    for (var i = 0; i < Titanium.Platform.interfaces.length; i++) {
      var iface = Titanium.Platform.interfaces[i];
      value_of(iface.name)
        .should_be_string();
      value_of(iface.address)
        .should_be_string();
      value_of(iface.displayName)
        .should_be_string();

      Titanium.API.debug("interface " + iface.name + ", " + iface.address + ", " + iface.displayName);
    }
  },

  test_platform_properties: function () {
    value_of(Titanium.Platform.name)
      .should_be_string();
    value_of(Titanium.Platform.ostype)
      .should_be_string();
    value_of(Titanium.Platform.version)
      .should_be_string();
    value_of(Titanium.Platform.architecture)
      .should_be_string();
    value_of(Titanium.Platform.address)
      .should_be_string();
    value_of(Titanium.Platform.id)
      .should_be_string();
    value_of(Titanium.Platform.macaddress)
      .should_be_string();
    value_of(Titanium.Platform.processorCount)
      .should_be_number();
    value_of(Titanium.Platform.username)
      .should_be_string();
    value_of(Titanium.Platform.createUUID)
      .should_be_function();

    Titanium.API.debug("Titanium.Platform.name " + Titanium.Platform.name);
    Titanium.API.debug("Titanium.Platform.ostype " + Titanium.Platform.ostype);
    Titanium.API.debug("Titanium.Platform.version " + Titanium.Platform.version);
    Titanium.API.debug("Titanium.Platform.architecture " + Titanium.Platform.architecture);
    Titanium.API.debug("Titanium.Platform.address " + Titanium.Platform.address);
    Titanium.API.debug("Titanium.Platform.id " + Titanium.Platform.id);
    Titanium.API.debug("Titanium.Platform.macaddress " + Titanium.Platform.macaddress);
    Titanium.API.debug("Titanium.Platform.processorCount " + Titanium.Platform.processorCount);
    Titanium.API.debug("Titanium.Platform.username " + Titanium.Platform.username);

    // TODO add more specific tests to insure we report the correct platform.
    if (Titanium.platform == "osx") {
      value_of(Titanium.Platform.name)
        .should_not_be("Windows NT");
    } else if (Titanium.platform == "linux") {
      value_of(Titanium.Platform.name)
        .should_not_be("Windows NT");
    } else if (Titanium.platform == "win32") {
      value_of(Titanium.Platform.name)
        .should_be("Windows NT");
    } else {
      // this is a delibrate error.  we should never get here.
      // but just in case we do, log it.
      value_of(Titanium.Platform.name)
        .should_not_be("unknown");
    }
  },

  test_unique_uuid: function () {
    var uuids = [];
    for (var i = 0; i < 100; i++) {
      var uuid = Titanium.Platform.createUUID();
      value_of(uuid in uuids)
        .should_be_false();
      uuids.push(uuid);
    }
  }
});