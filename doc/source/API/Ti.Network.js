/**
* A module for network functionality.
* @class Ti.Network
* @singleton
* @member Ti
*/
Ti.Network = {
/**
* Adds a connectivity change listener that fires when the system connects or disconnects from the internet
* @return {Number}
* @member Ti.Network
*/
addConnectivityListener: function(){},

/**
* Creates an HTTPClient object
* @return {Ti.Network.HTTPClient}
* @member Ti.Network
*/
createHTTPClient: function(){},

/**
* Creates a new HTTPCookie object
* @return {Ti.Network.HTTPCookie}
* @member Ti.Network
*/
createHTTPCookie: function(){},

/**
* Creates an HTTPServer object
* @return {Ti.Network.HTTPServer}
* @member Ti.Network
*/
createHTTPServer: function(){},

/**
* Creates an IPAddress object
* @param {String} address the IP address
* @return {Ti.Network.IPAddress}
* @member Ti.Network
*/
createIPAddress: function(address){},

/**
* Creates an IRCClient object [DEPRECATED]
* @return {Ti.Network.IRCClient}
* @member Ti.Network
*/
createIRCClient: function(){},

/**
* Creates a TCPSocket object
* @param {String} host the hostname to connect to
* @param {Number} port the port to use
* @return {Ti.Network.TCPSocket}
* @member Ti.Network
*/
createTCPSocket: function(host, port){},

/**
* Encodes a URI Component
* @param {String} value value to encode
* @return {String}
* @member Ti.Network
*/
encodeURIComponent: function(value){},

/**
* Decodes a URI component
* @param {String} value value to decode
* @return {String}
* @member Ti.Network
*/
decodeURIComponent: function(value){},

/**
* Return the first IPv4 address in this system's list of interfaces.
* @return {String}
* @member Ti.Network
*/
getFirstIPAddress: function(){},

/**
* Return the first MAC address in this system's list of interfaces.
* @return {String
paramters: }
* @member Ti.Network
*/
getFirstMACAddress: function(){},

/**
* Returns a Host object using an address
* @param {String} address the address
* @return {Ti.Network.Host}
* @member Ti.Network
*/
getHostByAddress: function(address){},

/**
* Returns a Host object using a hostname
* @param {String} name the hostname
* @return {Ti.Network.Host}
* @member Ti.Network
*/
getHostByName: function(name){},

/**
* Return the proxy override, if one is set.
* @return {String|null}
* @member Ti.Network
*/
getHTTPSProxy: function(){},

/**
* Return a list of network interfaces on this system.
* @return {Ti.Array<Network.Interface>}
* @member Ti.Network
*/
getInterfaces: function(){},

/**
* Return the proxy override, if one is set.
* @return {String|null}
* @member Ti.Network
*/
getHTTPProxy: function(){},

/**
* Note: this is deprecated and only returns true starting in 1.2.
* @property {Boolean}
* @member Ti.Network
*/
online: null,

/**
* Removes a connectivity change listener
* @param {Number} id the callback id of the method
* @return {String}
* @member Ti.Network
*/
removeConnectivityListener: function(id){},

/**
* Override application proxy autodetection with a proxy URL.
* @param {String} hostname The full proxy hostname.
* @return {String}
* @member Ti.Network
*/
setHTTPProxy: function(hostname){},

/**
* Override application proxy autodetection with a proxy URL.
* @param {String} hostname The full proxy hostname.
* @return {String}
* @member Ti.Network
*/
setHTTPSProxy: function(hostname){}}

