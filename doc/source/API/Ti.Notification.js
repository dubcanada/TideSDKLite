/**
* A module for displaying desktop notifications.
* TideSDK allows you to display notifications from your desktop apps using Growl on OS X, 
* Snarl on Windows and libnotify on Linux. In the event of a notification provider being absent, 
* notifications are shown using HTML/CSS.
*
* Please refer to the code example below
*
*		//Create a callback function for the notification
*		var doSomething = function() {
*			//Do something!
*		}
*		
*		//Creating a notification and displaying it.
*		var notification = Ti.Notification.createNotification({
*			'title' : 'Notification from App',
*			'message' : 'Click here for updates!',
*			'timeout' : 10,
*			'callback' : doSomething,
*			'icon' : 'app://images/notificationIcon.png'		
*		});
*
*		notification.show();
*
*Not all platforms support a callback function or specifying a custom timeout.    
*The notification icon should be always be referenced by an absolute app://, ti:// or file:// URL.
*
*
* @class Ti.Notification
* @singleton
* @member Ti
*/
Ti.Notification = {
/**
* Create a new Notification object.
* @return {Ti.UI.Notification}
* @member Ti.Notification
*/
createNotification: function(){}}

