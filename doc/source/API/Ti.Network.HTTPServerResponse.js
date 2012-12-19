/**
* An object representing a single HTTP server response.
* @class Ti.Network.HTTPServerResponse
* @member Ti.Network
*/
Ti.Network.HTTPServerResponse = {
/**
* add a cookie to this response
* @param {String} name the cookie name
* @param {String} value the cookie value
* @param {Number} maxAge "(optional) the cookie's maximum age"
* @param {String} domain "(optional) the cookie's domain"
* @param {String} path "(optional) the cookie's path"
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
addCookie: function(name, value, maxAge, domain, path){},

/**
* set the content length of this response
* @param {Number} length the content length, i.e 100
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setContentLength: function(length){},

/**
* set the content type of this response
* @param {String} type "the content type, i.e \"text/plain\""
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setContentType: function(type){},

/**
* set an HTTP header of this response
* @param {String} name the header name
* @param {String} value the header value
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setHeader: function(name, value){},

/**
* set the reason of this response
* @param {String} reason "the reason, i.e \"OK\""
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setReason: function(reason){},

/**
* set the status of this response
* @param {String} status "the status, i.e \"200\""
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setStatus: function(status){},

/**
* set the status and reason of this response
* @param {String} status "the status, i.e \"200\""
* @param {String} reason "the reason, i.e \"OK\""
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setStatusAndReason: function(status, reason){},

/**
* write content into this response
* @param {String} data content to write (can be string or bytes content)
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
write: function(data){}}

