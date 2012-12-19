/**
* An object representing a TideSDK application dependency.
* @class Ti.API.Dependency
* @member Ti.API
*/
Ti.API.Dependency = {
/**
* Get the name of this dependency.
* @return {String}
* @member Ti.API.Dependency
*/
getName: function(){},

/**
* Get the requirement for this dependency. Dependency requirement types are defined as constants on the API module. Currently the installer only support API.EQ dependency types.
* @return {String}
* @member Ti.API.Dependency
*/
getRequirement: function(){},

/**
* Get the type of this dependency. Dependency types are defined as constants on the API module (e.g. API.SDK).
* @return {Number}
* @member Ti.API.Dependency
*/
getType: function(){},

/**
* Get the version part of this dependency.
* @return {String}
* @member Ti.API.Dependency
*/
getVersion: function(){}}

