/**
* An object representing an IRC client connection. [DEPRECATED]
* @class Ti.Network.IRCClient
* @member Ti.Network
*/
Ti.Network.IRCClient = {
/**
* Connects an IRC to the host specified during creation of the IRCClient object
* @param {String} hostname the hostname
* @param {Number} port the port
* @param {String} nick the users nickname
* @param {String} name the users full name
* @param {String} user the users login name
* @param {String} pass the users password
* @param {Function} callback a callback function to recieve IRC events.
* @return {String}
* @member Ti.Network.IRCClient
*/
connect: function(hostname, port, nick, name, user, pass, callback){},

/**
* Disconnects an IRC connection
* @return {String}
* @member Ti.Network.IRCClient
*/
disconnect: function(){},

/**
* Returns the nick name for the connection
* @return {String}
* @member Ti.Network.IRCClient
*/
getNick: function(){},

/**
* Returns a list of users for the channel
* @return {Array<String>}
* @member Ti.Network.IRCClient
*/
getUsers: function(){},

/**
* Checks whether a user has OP status
* @return {Boolean}
* @member Ti.Network.IRCClient
*/
isOp: function(){},

/**
* Checks whether a user has VOICE status
* @return {Boolean}
* @member Ti.Network.IRCClient
*/
isVoice: function(){},

/**
* Joins a channel
* @param {String} channel channel to join to
* @return {String}
* @member Ti.Network.IRCClient
*/
join: function(channel){},

/**
* Sends data to the IRC connection
* @param {String} channel the channel to send the data to
* @param {String} message message to send
* @return {String}
* @member Ti.Network.IRCClient
*/
send: function(channel, message){},

/**
* Sets the nick name for the connection
* @param {String} nick nickname to use
* @return {String}
* @member Ti.Network.IRCClient
*/
setNick: function(nick){},

/**
* The connected property of an IRCClient object
* @property {String}
* @member Ti.Network.IRCClient
*/
connected: null,

/**
* Leaves a channel
* @param {String} channel channel to leave
* @return {String}
* @member Ti.Network.IRCClient
*/
unjoin: function(channel){}}

