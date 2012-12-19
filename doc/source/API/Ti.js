/**
* This is the top-level TideSDK module, containing all TideSDK APIs.
* TideSDK API objects generally follow the setProperty()/getProperty()
* pattern, but you may also use accessors for most operations For example:
* 
* 	var window = Ti.UI.currentWindow;
* 	window.setHeight(300); // Set the window height to 300 pixels.
* 	window.height = 300; // The same.
* 
* @class Ti
* @singleton
*/
Ti = {
/**
* The ALL event constant. This can be used for listening for all events.
* @property {String}
* @member Ti
*/
ALL: null,

/**
* The APP_EXIT event constant, fired during host application exit.
* @property {String}
* @member Ti
*/
APP_EXIT: null,

/**
* The CLOSE event constant
* @property {String}
* @member Ti
*/
CLOSE: null,

/**
* The CLOSED event constant
* @property {String}
* @member Ti
*/
CLOSED: null,

/**
* The CREATE event constant
* @property {String}
* @member Ti
*/
CREATE: null,

/**
* The EXIT event constant
* @property {String}
* @member Ti
*/
EXIT: null,

/**
* The FOCUSED event constant
* @property {String}
* @member Ti
*/
FOCUSED: null,

/**
* The FULLSCREENED event constant
* @property {String}
* @member Ti
*/
FULLSCREENED: null,

/**
* The HIDDEN event constant
* @property {String}
* @member Ti
*/
HIDDEN: null,

/**
* "Return the current platform, usually one of 'osx', 'win32', or 'linux'."
* @return {String}
* @member Ti
*/
getPlatform: function(){},

/**
* Return the Ti runtime version.
* @return {String}
* @member Ti
*/
getVersion: function(){},

/**
* The HTTP request aborted event constant.
* @property {String}
* @member Ti
*/
HTTP_ABORT: null,

/**
* The HTTP data sent event constant.
* @property {String}
* @member Ti
*/
HTTP_DATA_SENT: null,

/**
* The HTTP data received event constant.
* @property {String}
* @member Ti
*/
HTTP_DATA_RECEIVED: null,

/**
* The HTTP request complete event constant.
* @property {String}
* @member Ti
*/
HTTP_DONE: null,

/**
* The HTTP redirect event constant.
* @property {String}
* @member Ti
*/
HTTP_REDIRECT: null,

/**
* The HTTP state changed event constant.
* @property {String}
* @member Ti
*/
HTTP_STATE_CHANGED: null,

/**
* The HTTP request timeout event constant.
* @property {String}
* @member Ti
*/
HTTP_TIMEOUT: null,

/**
* The MAXIMIZED event constant
* @property {String}
* @member Ti
*/
MAXIMIZED: null,

/**
* The MINIMIZED event constant
* @property {String}
* @member Ti
*/
MINIMIZED: null,

/**
* The MOVED event constant
* @property {String}
* @member Ti
*/
MOVED: null,

/**
* The OPENED event constant
* @property {String}
* @member Ti
*/
OPENED: null,

/**
* The OPEN request event constant.
* @property {String}
* @member Ti
*/
OPEN_REQUEST: null,

/**
* The PAGE_INITIALIZED event constant
* @property {String}
* @member Ti
*/
PAGE_INITIALIZED: null,

/**
* The PAGE_LOADED event constant
* @property {String}
* @member Ti
*/
PAGE_LOADED: null,

/**
* The READ event constant
* @property {String}
* @member Ti
*/
READ: null,

/**
* The RESIZED event constant
* @property {String}
* @member Ti
*/
RESIZED: null,

/**
* The SHOWN event constant
* @property {String}
* @member Ti
*/
SHOWN: null,

/**
* The UNFOCUSED event constant
* @property {String}
* @member Ti
*/
UNFOCUSED: null,

/**
* The UNFULLSCREENED event constant
* @property {String}
* @member Ti
*/
UNFULLSCREENED: null,

/**
* The OPEN event constant
* @property {String}
* @member Ti
*/
OPEN: null}

