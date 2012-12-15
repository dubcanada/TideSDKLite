/**
* An object representing a Desktop notification.
* @class Ti.Notification.Notification
* @member Ti.Notification
*/
Ti.Notification.Notification = {
/**
* Hide this Notification.
* @return {Boolean}
* @member Ti.Notification.Notification
*/
hide: function(){},

/**
* Set a callback function fired when notification is clicked.
* @param {Function} callback function to execute when notification is clicked
* @return {String}
* @member Ti.Notification.Notification
*/
setCallback: function(callback){},

/**
* Set the notification icon image.
* @param {String} icon path to the icon image
* @return {String}
* @member Ti.Notification.Notification
*/
setIcon: function(icon){},

/**
* Set the notification message
* @param {String} message notification message text
* @return {String}
* @member Ti.Notification.Notification
*/
setMessage: function(message){},

/**
* Set the timeout before the notification expires.
* @param {Integer} timeout Timeout in seconds. (-1 = use system default, 0 = never expire)
* @return {String}
* @member Ti.Notification.Notification
*/
setTimeout: function(timeout){},

/**
* Set the notification title
* @param {String} title notification title text
* @return {String}
* @member Ti.Notification.Notification
*/
setTitle: function(title){},

/**
* Display the notification
* @return {Boolean}
* @member Ti.Notification.Notification
*/
show: function(){}}

