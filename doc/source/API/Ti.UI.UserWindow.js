/**
* An object representing a top-level TideSDK window.
* All windows in TideSDK are Ti.UI.UserWindow objects.      
* The current window can be accessed and modified as shown below:      
*
*		var window = Ti.UI.currentWindow;
*		window.setTitle('New Title'); // Will set window title to New Title
*
* Once you open a window, you can close it at anytime. This will ensure that all
* resources attached to that window are freed up. However, this also means that
* the window cannot be opened again. 
* If you need to hide a window , the following code can be used :
*
*		Ti.UI.currentWindow.hide(); //window hidden
*		setTimeout(function() {
*			Ti.UI.currentWindow.show(); //window shown
*		}, 3000);
*		
* 
* @class Ti.UI.UserWindow
* @member Ti.UI
*/
Ti.UI.UserWindow = {

/**
* The ALL event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
ALL: "all",
/**
* @event all Fired on any event
*/

/**
* The APP_EXIT event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
APP_EXIT: "app.exit",
/**
* @event "app.exit" Fired on application exit
*/

/**
* The CLOSE event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
CLOSE: "close",
/**
* @event close Fired before window close
*/

/**
* The CLOSED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
CLOSED: "closed",
/**
* @event closed Fired after window close
*/

/**
* The CREATED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
CREATED: "create",
/**
* @event create Fired on window creation
*/

/**
* The EXIT event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
EXIT: "exit",
/**
* @event exit Fired on application exit
*/

/**
* The FOCUSED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
FOCUSED: "focused",
/**
* @event focused Fired when window gains focus
*/

/**
* The FULLSCREENED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
FULLSCREENED: "fullscreened",
/**
* @event fullscreened Fired when window switches into fullscreen mode
*/

/**
* The HIDDEN event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
HIDDEN: "hidden",
/**
* @event hidden Fired when window has been hidden
*/

/**
* The HTTP_ABORT event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
HTTP_ABORT: "http.abort",
/**
* @event "http.abort"
*/

/**
* The CLOSED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
HTTP_DATA_RECEIVED: "http.datareceived",
/**
* @event "http.datarecived"
*/

/**
* The HTTP_DATA_SENT event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
HTTP_DATA_SENT: "http.datasent",
/**
* @event "http.datasent"
*/

/**
* The HTTP_DONE event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
HTTP_DONE: "http.done",
/**
* @event "http.done"
*/

/**
* The HTTP_REDIRECT event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
HTTP_REDIRECT: "http.redirect",
/**
* @event http.redirect
*/

/**
* The HTTP_STATE_CHANGED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
HTTP_STATE_CHANGED: "http.statechanged",
/**
* @event http.statechanged
*/

/**
* The HTTP_TIMEOUT event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
HTTP_TIMEOUT: "http.timeout",
/**
* @event http.timeout
*/

/**
* The MAXIMIZED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
MAXIMIZED: "maximized",
/**
* @event maximized Fired when the window got maximized
*/

/**
* The MINIMIZED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
MINIMIZED: "minimized",
/**
* @event minimized Fired when the window got minimized
*/

/**
* The MOVED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
MOVED: "moved",
/**
* @event moved Fired when the window has been moved
*/

/**
* The OPEN event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
OPEN: "open",
/**
* @event open Fired before the window is opened
*/

/**
* The OPENED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
OPENED: "opened",
/**
* @event opened Fired after the window has been opened.
*/

/**
* The OPEN_REQUEST event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
OPEN_REQUEST: "open.request",
/**
* @event open.request
*/

/**
* The PAGE_INITIALIZED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
PAGE_INITIALIZED: "page.init",
/**
* @event page.init
*/

/**
* The PAGE_LOADED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
PAGE_LOADED: "page.load",
/**
* @event page.load
*/

/**
* The READ event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
READ: "read",
/**
* @event read
*/

/**
* The RESIZED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
RESIZED: "resized",
/**
* @event resized Fired when the window has been resized
*/

/**
* The SHOWN event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
SHOWN: "shown",
/**
* @event shown Fired when the window has been shown
*/

/**
* The UNFOCUSED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
UNFOCUSED: "unfocused",
/**
* @event unfocused Fired when the window loses focus
*/

/**
* The UNFULLSCREENED event constant
* @property {String}
* @member Ti.UI.UserWindow
*/
UNFULLSCREENED: "unfullscreened",
/**
* @event unfullscreened Fired when the window leaves fullscreen mode
*/

/**
* Registers a single event listener on the window.
* To register more than one event listener for the window, call `addEventListener()` multiple times but with different event types.
* @param {String} type A string representing the event type to listen for.
* @param {EventListener|Function} listener The object that receives a notification when an event of the specified type occurs. This must be an object implementing the [EventListener interface](http://www.w3.org/TR/DOM-Level-2-Events/events.html#Events-EventListener), or simply a JavaScript function.
*/
addEventListener: function(type, listener){},

/**
* Closes a window
* @return {String}
* @member Ti.UI.UserWindow
*/
close: function(){},

/**
* Creates a new window as a child of the current window
* @param {String|Object} options (optional) A string containing a url of the new window or an object containing properties for the new window
* @return {Ti.UI.UserWindow}
* @member Ti.UI.UserWindow
*/
createWindow: function(options){},

/**
* Focuses a window
* @return {String}
* @member Ti.UI.UserWindow
*/
focus: function(){},

/**
* Return this window's bounds object. A bounds object is a simple JavaScript object
* containing four properties <tt>x</tt>, <tt>y</tt>, <tt>width<tt>, and <tt>height</tt>
* which correspond to the window geometry on the screen in pixels.
* @return {object}
* @member Ti.UI.UserWindow
*/
getBounds: function(){},

/**
* Get all children of this UI.UserWindow. All windows open
* from the context of this window are considered children.
* When a window is closed all of its children will also
* be closed automatically.
* @return {Ti.Array<UI.UserWindow>}
* @member Ti.UI.UserWindow
*/
getChildren: function(){},

/**
* Return the context menu set on this UI.Userwindow or null if none is set.
* @return {Ti.UI.Menu|null}
* @member Ti.UI.UserWindow
*/
getContextMenu: function(){},

/**
* Return the current window. This function does not exist outside of the context
* of a window.
* @return {Ti.UI.UserWindow}
* @member Ti.UI.UserWindow
*/
getCurrentWindow: function(){},

/**
* Return the WebKit DOMWindow of the page loaded in this window if
* one exists, otherwise return null. A DOMWindow object will not
* be available until a UI.UserWindow's PAGE_INITIALIZED event has
* fired.
* @return {DOMWindow|null}
* @member Ti.UI.UserWindow
*/
getDOMWindow: function(){},

/**
* "Return this window's height in pixels."
* @return {Number}
* @member Ti.UI.UserWindow
*/
getHeight: function(){},

/**
* "Return this window's icon, if one is set or null"
* @return {String|Null}
* @member Ti.UI.UserWindow
*/
getIcon: function(){},

/**
* Return this window's configuration id.
* @return {String}
* @member Ti.UI.UserWindow
*/
getID: function(){},

/**
* "Return this window's maximum height."
* @return {Number}
* @member Ti.UI.UserWindow
*/
getMaxHeight: function(){},

/**
* "Return this window's maximum height in pixels."
* @return {Number}
* @member Ti.UI.UserWindow
*/
getMaxWidth: function(){},

/**
* Return the window menu set on this UI.UserWindow if one is set, otherwise return null.
* @return {Ti.UI.Menu|null}
* @member Ti.UI.UserWindow
*/
getMenu: function(){},

/**
* "Return this window's minimum height."
* @return {Number}
* @member Ti.UI.UserWindow
*/
getMinHeight: function(){},

/**
* "Return this window's minimum width."
* @return {Number}
* @member Ti.UI.UserWindow
*/
getMinWidth: function(){},

/**
* Return this window's parent window or null if it is a top-level window.
* @return {Ti.UI.UserWindow|null}
* @member Ti.UI.UserWindow
*/
getParent: function(){},

/**
* Return the title of this window.
* @return {String}
* @member Ti.UI.UserWindow
*/
getTitle: function(){},

/**
* "Return this window's opacity."
* @return {Number}
* @member Ti.UI.UserWindow
*/
getTransparency: function(){},

/**
* Return this window's current URL."
* @return {String}
* @member Ti.UI.UserWindow
*/
getURL: function(){},

/**
* "Return this window's width in pixels."
* @return {Number}
* @member Ti.UI.UserWindow
*/
getWidth: function(){},

/**
* Return this windows DOMWindow object.
* @return {DOMWindow} the DOMWindow object of this window.
* @member Ti.UI.UserWindow
*/
getWindow: function(){},

/**
* Return a UI.UserWindow's horizontal (X-axis) position on the screen. The
* origin of the screen is considered to be the top-left on all platforms.
* @return {Number}
* @member Ti.UI.UserWindow
*/
getX: function(){},

/**
* Return a UI.UserWindow's vertical (Y-axis) position on the screen. The
* origin of the screen is considered to be the top-left on all platforms.
* @return {Number}
* @member Ti.UI.UserWindow
*/
getY: function(){},

/**
* Checks whether a window has a transparent background or not. If a window has a transparent background, transparent colors on the page will show through to windows underneath.
* @return {bool}
* @member Ti.UI.UserWindow
*/
hasTransparentBackground: function(){},

/**
* Return true if this window is active. An active window is one
* that has finished opening, but has not yet been closed.
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isActive: function(){},

/**
* Hides a window
* @return {String}
* @member Ti.UI.UserWindow
*/
hide: function(){},

/**
* Checks whether a window could be closed or not
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isCloseable: function(){},

/**
* Returns true if this window is a UI Dialog
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isDialog: function(){},

/**
* Checks whether a window is in an edited state
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isDocumentEdited: function(){},

/**
* Checks whether a window is in fullscreen
* @param {Boolean} chrome true if the window is in fullscreen, false if otherwise
* @return {String}
* @member Ti.UI.UserWindow
*/
isFullscreen: function(chrome){},

/**
* Checks whether a window could be maximized or not
* @return {String}
* @member Ti.UI.UserWindow
*/
isMaximizable: function(){},

/**
* Checks whether a window is maximized
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isMaximized: function(){},

/**
* Checks whether a window could be minimized or not
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isMinimizable: function(){},

/**
* Checks whether a window is minimized
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isMinimized: function(){},

/**
* Checks whether a window is resizable
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isResizable: function(){},

/**
* Checks whether a window is a toolwindow
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isToolWindow: function(){},

/**
* Checks whether a window is top most
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isTopMost: function(){},

/**
* Checks whether a window uses system chrome
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isUsingChrome: function(){},

/**
* Checks whether a window is visible
* @return {Boolean}
* @member Ti.UI.UserWindow
*/
isVisible: function(){},

/**
* Minimizes a window
* @return {String}
* @member Ti.UI.UserWindow
*/
minimize: function(){},

/**
* Maximizes a window
* @return {String}
* @member Ti.UI.UserWindow
*/
maximize: function(){},

/**
* Moves the window to the specified position.
* @param {Integer} x
* @param {Integer} y
* @return {Void}
*/
moveTo: function(x, y){},

/**
* Opens a window
* @return {String}
* @member Ti.UI.UserWindow
*/
open: function(){},

/**
* <p>
* Displays a file chooser dialog. This is suitable for use cases where you
* need the user to select what file(s) to open or be saved.
* </p>
* <p>
* Available Options:
* <ul>
* <li>multiple: true/false - allow user to select multple files [default: true]</li>
* <li>title: string used as the title of the dialog box</li>
* <li>path: location where browsing of files should begin when dialog opens</li>
* <li>types: list of allowable file types that user can pick (ex: js, html, txt)</li>
* </ul>
* </p>
* @param {method} callback a callback function to fire after the user closes the dialog
* @param {object} options (optional) additional options for the dialog
* @return {String}
* @member Ti.UI.UserWindow
*/
openFileChooserDialog: function(callback, options){},

/**
* Displays the folder chooser dialog
* @param {method} callback a callback function to fire after the user closes the dialog
* @param {object} options (optional) additional options for the dialog
* @return {String}
* @member Ti.UI.UserWindow
*/
openFolderChooserDialog: function(callback, options){},

/**
* Displays the save as file dialog.
* Available options:

* * title: string to use for dialog title
* * path: path to where the dialog should be opened at
* * types: array of file extensions that are allowed to be selected
* * multiple: if true, allow user to select more than one file [default: true]
* * defaultName: default name to be used for saving

* @param {method} callback a callback function to fire after the user closes the dialog
* @param {object} options (optional) additional options for the dialog
* @return {null}
* @member Ti.UI.UserWindow
*/
openSaveAsDialog: function(callback, options){},

/**
* Allows the removal of eventlisteners from the window.
* @param {String} type A string representing the event type being removed.
* @param {EventListener|Function} listener The listener object to be removed.
* @member Ti.UI.UserWindow
*/
removeEventListener: function(type, listener){},

/**
* Set this window's bounds object. A bounds object is a simple JavaScript object
* containing four properties <tt>x</tt>, <tt>y</tt>, <tt>width<tt>, and <tt>height</tt>
* which correspond to the window geometry on the screen in pixels.
* @param {object} bounds an object containing the value for the window bounds
* @return {String}
* @member Ti.UI.UserWindow
*/
setBounds: function(bounds){},

/**
* Sets whether a window could be closed or not
* @param {Boolean} closeable true if the window could be closed, false if otherwise
* @return {String}
* @member Ti.UI.UserWindow
*/
setCloseable: function(closeable){},

/**
* Set the contents of the UserWindow, given an HTML string
* and a base URL. Relative links in the HTML will be resolved
* relatively to the base URL.
* @param {String} contents The HTML string to inject into the UserWindow.
* @param {String} baseURL (optional) The base URL of the URL string. If omitted URLs will be resolved relative to the root of the app resources directory.
* @return {String}
* @member Ti.UI.UserWindow
*/
setContents: function(contents, baseURL){},

/**
* "Set this window's context menu"
* @param {Ti.UI.Menu|null} menu The Menu object to use as the context menu or null to unset the menu.
* @return {String}
* @member Ti.UI.UserWindow
*/
setContextMenu: function(menu){},

/**
* Set a window to the edited (a dot in the close button) or unedited state. OS X only.
* @param {Boolean} edited true if the window is edited, false if not
* @return {null}
* @member Ti.UI.UserWindow
*/
setDocumentEdited: function(edited){},

/**
* Makes a window fullscreen
* @param {Boolean} fullscreen set to true for fullscreen, false if otherwise
* @return {String}
* @member Ti.UI.UserWindow
*/
setFullscreen: function(fullscreen){},

/**
* "Sets a window's icon"
* @param {String} icon path to the icon file
* @return {String}
* @member Ti.UI.UserWindow
*/
setIcon: function(icon){},

/**
* "Sets a window's height"
* @param {Number} height the height value of the window
* @return {String}
* @member Ti.UI.UserWindow
*/
setHeight: function(height){},

/**
* "Sets a window's max-height"
* @param {Number} height the max-height value of the window
* @return {String}
* @member Ti.UI.UserWindow
*/
setMaxHeight: function(height){},

/**
* Sets whether a window could be maximized or not
* @param {Boolean} maximizable true if the window could be maximized, false if otherwise
* @return {String}
* @member Ti.UI.UserWindow
*/
setMaximizable: function(maximizable){},

/**
* "Sets a window's max-width"
* @param {Number} width the max-width value of the window
* @return {String}
* @member Ti.UI.UserWindow
*/
setMaxWidth: function(width){},

/**
* "Set this window's menu"
* @param {Ti.UI.Menu|null} menu The Menu object to use as the menu or null to unset the menu.
* @return {String}
* @member Ti.UI.UserWindow
*/
setMenu: function(menu){},

/**
* "Sets a window's min height"
* @param {Number} height the min-height value of the window
* @return {String}
* @member Ti.UI.UserWindow
*/
setMinHeight: function(height){},

/**
* Sets whether a window could be maximized or not
* @param {Boolean} minimizable true if the window could be minimized, false if otherwise
* @return {String}
* @member Ti.UI.UserWindow
*/
setMinimizable: function(minimizable){},

/**
* "Sets a window's min-width"
* @param {Number} width the min-width value of the window
* @return {String}
* @member Ti.UI.UserWindow
*/
setMinWidth: function(width){},

/**
* Set if plugins are enabled
* @param {bool} enabled true if plugins should be enabled
* @return {undefined}
* @member Ti.UI.UserWindow
*/
setPluginsEnabled: function(enabled){},

/**
* Sets whether a window could be resized or not
* @param {Boolean} resizable true if the window could be resized, false if otherwise
* @return {String}
* @member Ti.UI.UserWindow
*/
setResizable: function(resizable){},

/**
* "Sets a window's width and height."
* @param {Number} width the width of the window
* @param {Number} height the height of the window
* @return {undefined}
* @member Ti.UI.UserWindow
*/
setSize: function(width, height){},

/**
* Sets the title of a window
* @param {object} title the title of the window
* @return {String}
* @member Ti.UI.UserWindow
*/
setTitle: function(title){},



/**
* Sets whether a window is top most (above other windows)
* @param {Boolean} topmost true if top most, false if otherwise
* @return {String}
* @member Ti.UI.UserWindow
*/
setTopMost: function(topmost){},

/**
* Sets a window's transparency value
* Note: this will make the window and ALL of its contents transparent.
* @param {Number} A value between 0 and 1 where 0 is fully transparent.
* @return {Void}
* @member Ti.UI.UserWindow
*/
setTransparency: function(alpha){},

/**
* Sets the url for a window
* @param {String} url the url for the window
* @return {String}
* @member Ti.UI.UserWindow
*/
setURL: function(url){},

/**
* Sets whether a window should use system chrome
* @param {Boolean} chrome set to true to use system chrome, false if otherwise
* @return {String}
* @member Ti.UI.UserWindow
*/
setUsingChrome: function(chrome){},

/**
* "Sets a window's width"
* @param {Number} width the width of the window
* @return {String}
* @member Ti.UI.UserWindow
*/
setWidth: function(width){},

/**
* Sets the visibility of the window
* @param {Boolean} visible true if the window should be visible, false if otherwise
* @return {String}
* @member Ti.UI.UserWindow
*/
setVisible: function(visible){},

/**
* Set a UI.UserWindow's horizontal (X-axis) position on the screen. The
* origin of the screen is considered to be the top-left on all platforms.
* @param {Number} x the horizontal position
* @return {String}
* @member Ti.UI.UserWindow
*/
setX: function(x){},

/**
* Set a UI.UserWindow's vertical (Y-axis) position on the screen. The
* origin of the screen is considered to be the top-left on all platforms.
* @param {Number} y the vertical position
* @return {String}
* @member Ti.UI.UserWindow
*/
setY: function(y){},

/**
* Unfocuses a window
* @return {String}
* @member Ti.UI.UserWindow
*/
unfocus: function(){},

/**
* Unmaximizes a window
* @return {String}
* @member Ti.UI.UserWindow
*/
unmaximize: function(){},

/**
* Unminimizes a window
* @return {String}
* @member Ti.UI.UserWindow
*/
unminimize: function(){},

/**
* Show a UI.UserWindow's web inspector.
* @param {Boolean} console (optional) Open the console along with the inspector (defaults to false).
* @return {String}
* @member Ti.UI.UserWindow
*/
showInspector: function(console){},

/**
* Shows a window
* @return {String}
* @member Ti.UI.UserWindow
*/
show: function(){}}

