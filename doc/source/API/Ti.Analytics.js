/**
* The TideSDK Analytics module used for recording analytics events.
* @class Ti.Analytics
* @singleton
* @member Ti
*/
Ti.Analytics = {
/**
* Send an analytics event associated with application feature functionality.
* @param {String} name Feature name.
* @param {Object} data Extra event data to pass along. This will be converted to JSON.
* @return {void}
* @member Ti.Analytics
*/
featureEvent: function(name, data){},

/**
* Send an analytics event associated with application navigation.
* @param {String} from "Navigation starting point, the context we're leaving."
* @param {String} to "Navigation ending point, the context to which we're going."
* @param {String} name Event name.
* @param {Object} data Extra event data to pass along. This will be converted to JSON.
* @return {void}
* @member Ti.Analytics
*/
navEvent: function(from, to, name, data){},

/**
* Send an analytics event tracking the duration of an application action
* @param {String} event Event name
* @param {Date} start Event start time (optional if duration is specified).
* @param {Date} stop Event stop time (optional if duration is specified).
* @param {Number} duration Duration in seconds (optional if both start and stop are specified)
* @param {Object} data Extra event data to pass along. This will be converted to JSON.
* @return {String}
* @member Ti.Analytics
*/
timedEvent: function(event, start, stop, duration, data){},

/**
* Send an analytics event associated with application settings or configuration
* @param {String} name Setting name.
* @param {Object} data Extra event data to pass along. This will be converted to JSON.
* @return {String}
* @member Ti.Analytics
*/
settingsEvent: function(name, data){},

/**
* Send an analytics event not covered by the other interfaces.
* @param {String} name Event name.
* @param {Object} data Extra event data to pass along. This will be converted to JSON.
* @return {String}
* @member Ti.Analytics
*/
userEvent: function(name, data){}}

