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

describe("Network Tests", {
  // ti.network.HTTP objects are covered in the http_server unit test.

  // test the network object and properties.
  test_network_object: function () {
    value_of(Titanium.Network)
      .should_not_be_null();
    value_of(Titanium.Network.getProxy)
      .should_be_function();
    value_of(Titanium.Network.setProxy)
      .should_be_function();
    value_of(Titanium.Network.createHTTPClient)
      .should_be_function();
    value_of(Titanium.Network.createHTTPServer)
      .should_be_function();
    value_of(Titanium.Network.createIPAddress)
      .should_be_function();
    value_of(Titanium.Network.createIRCClient)
      .should_be_function();
    value_of(Titanium.Network.createTCPSocket)
      .should_be_function();
    value_of(Titanium.Network.decodeURIComponent)
      .should_be_function();
    value_of(Titanium.Network.encodeURIComponent)
      .should_be_function();
    value_of(Titanium.Network.getHostByAddress)
      .should_be_function();
    value_of(Titanium.Network.getHostByName)
      .should_be_function();
  },

  test_network_URIComponents: function () {
    var str = "the test string";

    var encoded = Titanium.Network.encodeURIComponent(str);

    // is the string encoded?
    value_of(str == encoded)
      .should_be_false();
    value_of(encoded.indexOf("%20"))
      .should_not_be(-1);

    var decoded = Titanium.Network.decodeURIComponent(encoded);

    // is the string decoded?
    value_of(str == decoded)
      .should_be_true();
    value_of(decoded.indexOf("%20"))
      .should_be(-1);
  },
  test_network_proxy_functions: function () {
    value_of(Titanium.Network)
      .should_not_be_null();
    value_of(Titanium.Network.getProxy)
      .should_be_function();
    value_of(Titanium.Network.setProxy)
      .should_be_function();
    value_of(Titanium.Network.getHTTPProxy)
      .should_be_function();
    value_of(Titanium.Network.setHTTPProxy)
      .should_be_function();
    value_of(Titanium.Network.getHTTPSProxy)
      .should_be_function();
    value_of(Titanium.Network.setHTTPSProxy)
      .should_be_function();
  },
  test_proxy: function () {
    var proxy = Titanium.Network.getProxy();
    value_of(proxy)
      .should_be(null);

    Titanium.Network.setProxy("http://www.google.com:81");
    proxy = Titanium.Network.getProxy();
    value_of(proxy)
      .should_be("http://www.google.com:81");

    Titanium.Network.setProxy(null);
    proxy = Titanium.Network.getProxy();
    value_of(proxy)
      .should_be(null);

    Titanium.Network.setProxy("http://www.google.com:81");
    proxy = Titanium.Network.getProxy();
    value_of(proxy)
      .should_be("http://www.google.com:81");

    Titanium.Network.setProxy("www.yahoo.com:81");
    proxy = Titanium.Network.getProxy();
    value_of(proxy)
      .should_be("http://www.yahoo.com:81");

    Titanium.Network.setProxy("");
    proxy = Titanium.Network.getProxy();
    value_of(proxy)
      .should_be(null);
  },
  test_http_proxy: function () {
    var proxy = Titanium.Network.getHTTPProxy();
    value_of(proxy)
      .should_be(null);

    Titanium.Network.setHTTPProxy("http://www.google.com:81");
    proxy = Titanium.Network.getHTTPProxy();
    value_of(proxy)
      .should_be("http://www.google.com:81");

    Titanium.Network.setHTTPProxy(null);
    proxy = Titanium.Network.getHTTPProxy();
    value_of(proxy)
      .should_be(null);

    Titanium.Network.setHTTPProxy("http://www.google.com:81");
    proxy = Titanium.Network.getHTTPProxy();
    value_of(proxy)
      .should_be("http://www.google.com:81");

    Titanium.Network.setHTTPProxy("www.yahoo.com:81");
    proxy = Titanium.Network.getHTTPProxy();
    value_of(proxy)
      .should_be("http://www.yahoo.com:81");

    Titanium.Network.setHTTPProxy("direct://");
    proxy = Titanium.Network.getHTTPProxy();
    value_of(proxy)
      .should_be_null();

    Titanium.Network.setHTTPProxy("http://joe:blow@foo.com:80");
    vproxy = Titanium.Network.getHTTPProxy();
    value_of(vproxy)
      .should_be("http://joe:blow@foo.com:80");

    Titanium.Network.setHTTPProxy("");
    proxy = Titanium.Network.getHTTPProxy();
    value_of(proxy)
      .should_be(null);
  },
  test_https_proxy: function () {
    var proxy = Titanium.Network.getHTTPSProxy();
    value_of(proxy)
      .should_be(null);

    Titanium.Network.setHTTPSProxy("https://www.google.com:81");
    proxy = Titanium.Network.getHTTPSProxy();
    value_of(proxy)
      .should_be("https://www.google.com:81");

    Titanium.Network.setHTTPSProxy(null);
    proxy = Titanium.Network.getHTTPSProxy();
    value_of(proxy)
      .should_be(null);

    Titanium.Network.setHTTPSProxy("https://www.google.com:81");
    proxy = Titanium.Network.getHTTPSProxy();
    value_of(proxy)
      .should_be("https://www.google.com:81");

    Titanium.Network.setHTTPSProxy("www.yahoo.com:81");
    proxy = Titanium.Network.getHTTPSProxy();
    value_of(proxy)
      .should_be("https://www.yahoo.com:81");

    Titanium.Network.setHTTPSProxy("direct://");
    proxy = Titanium.Network.getHTTPSProxy();
    value_of(proxy)
      .should_be_null();

    Titanium.Network.setHTTPSProxy("http://joe:blow@foo.com:80");
    proxy = Titanium.Network.getHTTPSProxy();
    value_of(proxy)
      .should_be("http://joe:blow@foo.com:80");

    Titanium.Network.setHTTPSProxy("");
    proxy = Titanium.Network.getHTTPSProxy();
    value_of(proxy)
      .should_be(null);
  }
});
