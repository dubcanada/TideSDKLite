/**
* A module for dealing with application and component updates in TideSDK.
* @class Ti.UpdateManager
* @singleton
* @member Ti
*/
Ti.UpdateManager = {
/**
* Check the update service for a new version
* @param {Number} id The monitor id returned from startMonitor
* @return {String}
* @member Ti.UpdateManager
*/
cancelMonitor: function(id){},

/**
* Set the update handler implementation function that will be invoked when an update is detected
* @property {String}
* @member Ti.UpdateManager
*/
onupdate: null,

/**
* Install an application update received from update monitor. This method will cause the process to first be restarted for the update to begin.
* @param {Object} updateSpec Update spec object received from update service.
* @return {String}
* @member Ti.UpdateManager
*/
installAppUpdate: function(updateSpec){},

/**
* Check the update service for a new version
* @param {String} component Name of the component
* @param {Function} callback Function callback to call when completed
* @param {Number} interval Interval in milliseconds for how often to check for an update
* @return {Number}
* @member Ti.UpdateManager
*/
startMonitor: function(component, callback, interval){}}

