/**
* A module for controlling the user interface.
* @class Ti.UI
* @singleton
* @member Ti
*/
Ti.UI = {
/**
* The CENTERED event constant
* @property {Number}
* @member Ti.UI
*/
CENTERED: -404404404,

/**
* "Empty the tray of all this application's tray items"
* @return {void}
* @member Ti.UI
*/
clearTray: function(){},

/**
* Create a new CheckMenuItem object.
* @param {String} label The label for this menu item
* @param {Function} eventListener (optional) An event listener for this menu item
* @return {Ti.UI.CheckMenuItem}
* @member Ti.UI
*/
createCheckMenuItem: function(label, eventListener){},

/**
* Create and add a tray icon
* @param {String} iconURL Local URL on system which app is running on to the icon location
* @param {Function} eventListener (optional) Event listener to add for this item
* @return {Ti.UI.Tray|null}
* @member Ti.UI
*/
addTray: function(iconURL, eventListener){},

/**
* Create a new menu item.
* @param {String} label The label for this menu item
* @param {Function} eventListener (optional) An event listener for this menu item
* @param {String} iconURL (optional) A URL to an icon to use for this menu item
* @return {Ti.UI.MenuItem}
* @member Ti.UI
*/
createMenuItem: function(label, eventListener, iconURL){},

/**
* Create a new separator menu item.
* @return {Ti.UI.SeparatorMenuItem}
* @member Ti.UI
*/
createSeperatorMenuItem: function(){},

/**
* Create a new menu
* @return {Ti.UI.Menu}
* @member Ti.UI
*/
createMenu: function(){},

/**
* <p>
* Create a new child window of the current window. This means that
* when the originating window is closed, the new window will be closed
* as well. If this function is called outside of the context of a window
* it will create a new top-level window.
* </p>
* <p>
* There are three ways to call this function. You may pass no arguments,
* in which case the new window will have the same configuration as the
* originating window. You may also simply pass a new absolute URL:
* <pre><code>
* Ti.UI.createWindow("app://second_page.html");
* </code></pre>
* If the URL matches the url or url-regex field of a tiapp.xml window
* configuration, then the window will use that configuration. For more
* information see the <a href="http://developer.appcelerator.com/doc/desktop/tiapp.xml">tiapp.xml guide</a>.
* </p>
* <p>
* A window may also be craeated with an options object. Almost every
* field in a tiapp.xml window configuration has a corresponding field
* in the options object. Below is a call which uses every field:
* <pre><code>
* Ti.UI.createWindow({
* id: "propertyWindow",
* url: "app://second_page.html",
* title: "My New Window",
* contents: "<html>foo!</html>"
* baseURL: "app://page_url"
* x: 300,
* y: 400,
* width: 500,
* minWidth: 500,
* maxWidth: 500,
* height: 500,
* minHeight: 500,
* maxHeight: 500,
* maximizable: true,
* minimizable: true,
* closeable: true,
* resizable: true,
* fullscreen: false,
* maximized: false,
* minimized: false,
* usingChrome: true,
* topMost: false,
* visible: true,
* transparentBackground: false,
* transparency: false
* });
* </code></pre>
* For more information on what these properties do, please see the
* <a href="http://developer.appcelerator.com/doc/desktop/tiapp.xml">tiapp.xml guide</a>.
* </p>
* @param {String|Object} options (optional) A string containing a url of the new window or an object containing properties for the new window
* @return {Ti.UI.UserWindow}
* @member Ti.UI
*/
createWindow: function(options){},

/**
* Return this application's context menu or null if none is set.
* @return {Ti.UI.Menu|null}
* @member Ti.UI
*/
getContextMenu: function(){},

/**
* Return the current window. This function does not exist outside of the context
* of a window.
* @return {Ti.UI.UserWindow}
* @member Ti.UI
*/
getCurrentWindow: function(){},

/**
* "Return the user's idle time (for the desktop, not just the application)"
* @return {Number}
* @member Ti.UI
*/
getIdleTime: function(){},

/**
* "Return the application's main window"
* @return {Ti.UI.UserWindow}
* @member Ti.UI
*/
getMainWindow: function(){},

/**
* "Return the application's main MenuItem or null if none is set."
* @return {Ti.UI.Menu|null}
* @member Ti.UI
*/
getMenu: function(){},

/**
* Return a list of currently open windows.
* @return {Ti.Array<UI.UserWindow>}
* @member Ti.UI
*/
getOpenWindows: function(){},

/**
* Return a list of currently open windows.
* @return {Ti.Array<UI.UserWindow>}
* @member Ti.UI
*/
getWindows: function(){},

/**
* "Set the application icon's badge text."
* @param {String} text The new badge text.
* @return {String}
* @member Ti.UI
*/
setBadge: function(text){},

/**
* "Set the application icon's badge image."
* @param {String} imageURL URL to the new badge image.
* @return {String}
* @member Ti.UI
*/
setBadgeImage: function(imageURL){},

/**
* "Set the application's context menu"
* @param {UI.Menu|null} menu a MenuItem object or null to unset the menu.
* @return {String}
* @member Ti.UI
*/
setContextMenu: function(menu){},

/**
* Set the dock icon
* @param {String} icon path to the icon
* @return {String}
* @member Ti.UI
*/
setDockIcon: function(icon){},

/**
* Set the dock menu
* @param {UI.Menu} menu The new menu for the dock or null to unset the menu.
* @return {String}
* @member Ti.UI
*/
setDockMenu: function(menu){},

/**
* "Set the application's icon"
* @param {String} menu path to the icon
* @return {String}
* @member Ti.UI
*/
setIcon: function(menu){},

/**
* Set a menu for the application
* @param {UI.Menu|null} menu A Menu object to use as the menu or null to unset the menu.
* @return {String}
* @member Ti.UI
*/
setMenu: function(menu){},

/**
* create a UI dialog
* @param {Object} params options to pass in to create window
* @return {Ti.UI.Dialog}
* @member Ti.UI
*/
showDialog: function(params){}}

