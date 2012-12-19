/**
* A module for exposing platform-specific functionality.
* @class Ti.Platform
* @singleton
* @member Ti
*/
Ti.Platform = {
/**
* Get the per-user machine identifier of this session.
* @return {String}
* @member Ti.Platform
*/
getMachineId: function(){},

/**
* Return the operating system architecture type of this system. This
* value will be either '32bit' or '64bit.'
* @return {String}
* @member Ti.Platform
*/
getOSType: function(){},

/**
* Create a universally unique identifier.
* @return {String}
* @member Ti.Platform
*/
createUUID: function(){},

/**
* Get a String representation of the current system's architecture.
* @return {String}
* @member Ti.Platform
*/
getArchitecture: function(){},

/**
* Return the number of processors on this system.
* @return {Number}
* @member Ti.Platform
*/
getProcessorCount: function(){},

/**
* Get the name of this platform.
* @return {String}
* @member Ti.Platform
*/
getName: function(){},

/**
* Return the version of this system's operating system.
* @return {String}
* @member Ti.Platform
*/
getVersion: function(){},

/**
* Return the username of the current user.
* @return {String}
* @member Ti.Platform
*/
getUsername: function(){},

/**
* Open the given application or file in the system's default program.
* @param {String} name The name or path to the application or file to open.
* @return {String}
* @member Ti.Platform
*/
openApplication: function(name){},

/**
* Take a PNG screenshot of the root window and save it to the given filename.
* @param {String} filename The filename to write the image to.
* @return {String}
* @member Ti.Platform
*/
takeScreenshot: function(filename){},

/**
* Open the given URL in the system's default browser.
* @param {String} url the URL to open.
* @return {String}
* @member Ti.Platform
*/
openURL: function(url){}}

