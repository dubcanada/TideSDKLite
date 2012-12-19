/**
* No description provided.
* @class Ti.Network.Interface
* @member Ti.Network
*/
Ti.Network.Interface = {
/**
* Return the display name of this interface.
* @return {String}
* @member Ti.Network.Interface
*/
getDisplayName: function(){},

/**
* Return the IP addresso of this interface.
* @return {Ti.Network.IPAddress}
* @member Ti.Network.Interface
*/
getIPAddress: function(){},

/**
* Get the name of this interface.
* @return {String}
* @member Ti.Network.Interface
*/
getName: function(){},

/**
* Return the subnet mask of this interface as a Network.IPAddress object.
* @return {Ti.Network.IPAddress}
* @member Ti.Network.Interface
*/
getSubnetMask: function(){},

/**
* Return true if this interface supports IPv4 and false otherwise.
* @return {Boolean}
* @member Ti.Network.Interface
*/
supportsIPv4: function(){},

/**
* Return true if this interface supports IPv6 and false otherwise.
* @return {Boolean}
* @member Ti.Network.Interface
*/
supportsIPv6: function(){}}

