/**
* An object representing a host on the network.
* 
* The following code shows some uses of the Ti.Network.Host object.    
*
*		var localhost = Ti.Network.getHostByAddress('127.0.0.1');
*		
*		localhost.isInvalid(); //returns true if the host is valid and on the network. 
*		localhost.getAliases(); //returns an array of all aliases for the host defined by the address above. 
*		
*
* @class Ti.Network.Host
* @member Ti.Network
*/
Ti.Network.Host = {
/**
* Returns the list of address for a Host object
* @return {Ti.Array<Network.IPAddress>}
* @member Ti.Network.Host
*/
getAddresses: function(){},

/**
* Returns the list of aliases for a Host object
* @return {Array<String>}
* @member Ti.Network.Host
*/
getAliases: function(){},

/**
* Return the hostname of a Host object
* @return {String}
* @member Ti.Network.Host
*/
getName: function(){},

/**
* Checks whether the Host object is invalid
* @return {Boolean}
* @member Ti.Network.Host
*/
isInvalid: function(){}}

