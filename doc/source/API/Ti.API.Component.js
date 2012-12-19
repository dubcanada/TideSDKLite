/**
* An object representing a TideSDK component, which may be either a module,
* runtime, SDK, Mobile SDK or application update.
* @class Ti.API.Component
* @member Ti.API
*/
Ti.API.Component = {
/**
* Get the name of this component.
* @return {String}
* @member Ti.API.Component
*/
getName: function(){},

/**
* Get the path to this component.
* @return {String}
* @member Ti.API.Component
*/
getPath: function(){},

/**
* Get the type of this component. Component types are defined as constants on the API module.
* @return {Number}
* @member Ti.API.Component
*/
getType: function(){},

/**
* Get the version of this component. Note that bundled components do not currently have a version.
* @return {String}
* @member Ti.API.Component
*/
getVersion: function(){},

/**
* Whether or not this component is currently loaded.
* @return {Boolean}
* @member Ti.API.Component
*/
isLoaded: function(){},

/**
* Whether or not this component is bundled with an application.
* @return {Boolean}
* @member Ti.API.Component
*/
isBundled: function(){}}

