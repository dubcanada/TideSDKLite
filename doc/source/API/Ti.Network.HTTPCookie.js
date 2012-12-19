/**
* An object representing an HTTP cookie.
* @class Ti.Network.HTTPCookie
* @member Ti.Network
*/
Ti.Network.HTTPCookie = {
/**
* Get the cookie comment text
* @return {String}
* @member Ti.Network.HTTPCookie
*/
getComment: function(){},

/**
* Get the domain for which the cookie is valid
* @return {String}
* @member Ti.Network.HTTPCookie
*/
getDomain: function(){},

/**
* Get the lifetime of the cookie, in seconds.
* @return {Integer}
* @member Ti.Network.HTTPCookie
*/
getMaxAge: function(){},

/**
* Get the cookie name
* @return {String}
* @member Ti.Network.HTTPCookie
*/
getName: function(){},

/**
* Get the subset of URLs to which this cookie applies
* @return {String}
* @member Ti.Network.HTTPCookie
*/
getPath: function(){},

/**
* Get the cookie value
* @return {String}
* @member Ti.Network.HTTPCookie
*/
getValue: function(){},

/**
* Identifies to which version of the state management specification the cookie conforms. 0 = netscape 1 = RFC2109
* @return {Integer}
* @member Ti.Network.HTTPCookie
*/
getVersion: function(){},

/**
* Check if the http only flag is set on the cookie
* @return {Boolean}
* @member Ti.Network.HTTPCookie
*/
isHTTPOnly: function(){},

/**
* Check if the secure flag is set on the cookie
* @return {Boolean}
* @member Ti.Network.HTTPCookie
*/
isSecure: function(){},

/**
* Set the cookie comment text
* @param {String} comment text to set as comment
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setComment: function(comment){},

/**
* Set the domain for which the cookie is valid
* @param {String} domain the domain to set
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setDomain: function(domain){},

/**
* Set the http only flag on the cookie
* @param {Boolean} enableHTTPOnly if True sets the http only flag
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setHTTPOnly: function(enableHTTPOnly){},

/**
* Set the lifetime of the cookie, in seconds.
* @param {Integer} lifetime the lifetime in seconds. 0 = discard, -1 = never expire
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setMaxAge: function(lifetime){},

/**
* Set the cookie name
* @param {String} name name of the cookie
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setName: function(name){},

/**
* Set the subset of URLs to which this cookie applies
* @param {String} path the path to set
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setPath: function(path){},

/**
* Set the secure flag on the cookie
* @param {Boolean} enableSecure if True makes the cookie secure
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setSecure: function(enableSecure){},

/**
* "Set the state management specifiction version the cookie conforms. (Default: 0)"
* @param {Integer} version cookie version (0 or 1)
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setVersion: function(version){},

/**
* Set the cookie value
* @param {String} value value to set cookie
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setValue: function(value){}}

