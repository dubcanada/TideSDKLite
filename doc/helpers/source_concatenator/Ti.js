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


/**
* An object representing a TideSDK application, either the currently running
* application or one on disk. 
*
* Example
* ------------
* You can retrieve information about the currently running TideSDK application
* using the Ti.API.getApplication module.
*
*		var app = Ti.API.application;
*		alert(app.getPID()); //Alert the process identifier for this application.
*		alert(app.getDataPath()); //Alert the path to the application's user data directory.
*
*
* @class Ti.API.Application
* @member Ti.API
*/
Ti.API.Application = {
/**
* Find the value for a given argument. You may either pass
* 'param' or '--param' and this method will find the command-line
* value for '--param=<value>'.
* @param {String} argument The name of the argument to find the value for.
* @return {String}
* @member Ti.API.Application
*/
getArgumentValue: function(argument){},

/**
* Return a list of all available (installed and bundled) components
* for this application. This is simply the list returned by
* API.getInstalledComponents() plus any components bundled with the
* application. Note that bundled components do not have a version
* currently.
* @return {Ti.Array<API.Component>}
* @member Ti.API.Application
*/
getAvailableComponents: function(){},

/**
* Return a list of all available (installed and bundled) runtimes
* for this application. This is simply the list returned by
* API.getInstalledModules() plus any components bundled with the
* application. Note that bundled components do not have a version
* currently.
* @return {Ti.Array<API.Component>}
* @member Ti.API.Application
*/
getAvailableRuntimes: function(){},

/**
* Return a list of all available (installed and bundled) modules
* for this application. This is simply the list returned by
* API.getInstalledModules() plus any components bundled with the
* application. Note that bundled components do not have a version
* currently.
* @return {Ti.Array<API.Component>}
* @member Ti.API.Application
*/
getAvailableModules: function(){},

/**
* Return a list of all bundled components for this for this application.
* Bundled components currently live inside the application contents directory
* in the following directories:
* <ul>
* <li>My App.app/Contents/modules</li>
* <li>My App.app/Contents/runtime</li>
* <li>My App.app/Contents/sdk</li>
* <li>My App.app/Contents/mobilesdk</li>
* </ul>
* @return {Ti.Array<API.Component>}
* @member Ti.API.Application
*/
getBundledComponents: function(){},

/**
* Return a list of all bundled modules for this for this application.
* Bundled modules currently live inside the application contents directory
* in the "My App.app/Contents/modules" directory.
* @return {Ti.Array<API.Component>}
* @member Ti.API.Application
*/
getBundledModules: function(){},

/**
* Return a list of all bundled runtimes for this for this application.
* A bundled runtime currently live inside the application contents directory
* in the "My App.app/Contents/runtime" directory.
* @return {Ti.Array<API.Component>}
* @member Ti.API.Application
*/
getBundledRuntimes: function(){},

/**
* Return a list of all resolved components for this for this application.
* Resolved components may either be installed or bundled components.
* Note that currently bundled components returned in this list do not have
* a version.
* @return {Ti.Array<API.Component>}
* @member Ti.API.Application
*/
getComponents: function(){},

/**
* Retrieve a list of command-line arguments passed to this application. This
* list will include the first argument, which is the path to the executable.
* @return {Array<String>}
* @member Ti.API.Application
*/
getArguments: function(){},

/**
* Get the path to the application's user data directory. This path is
* guaranteed to be writable (as opposed to the application directory
* which should not be written to) and is suitable for storing any
* application files.
* @return {String}
* @member Ti.API.Application
*/
getDataPath: function(){},

/**
* Get a list of this application's dependencies. Dependencies
* are defined in the application manifest file.
* @return {Ti.Array<API.Dependency>}
* @member Ti.API.Application
*/
getDependencies: function(){},

/**
* Get the path to this application's executable.
* @return {String}
* @member Ti.API.Application
*/
getExecutablePath: function(){},

/**
* "Get the path to this application's manifest"
* @return {String}
* @member Ti.API.Application
*/
getManifestPath: function(){},

/**
* Get the contents of this application's manifest as an array
* of string pairs (array of size 2). Each entry in the manifest
* is a simple key-value pair. Comments are ignored.
* @return {Array<Array<String>>}
* @member Ti.API.Application
*/
getManifest: function(){},

/**
* Get this human readable id currently defined in both the
* application manifest and the application's tiapp.xml file.
* @return {String}
* @member Ti.API.Application
*/
getID: function(){},

/**
* Return a list of all resolved modules for this for this application.
* Resolved components may either be installed or bundled components.
* Note that currently bundled components returned in this list do not have
* a version.
* @return {Ti.Array<API.Component>}
* @member Ti.API.Application
*/
getModules: function(){},

/**
* "Get this application's name."
* @return {String}
* @member Ti.API.Application
*/
getName: function(){},

/**
* Get this application globally unique identifier. This is
* currently defined in the application manifest.
* @return {String}
* @member Ti.API.Application
*/
getGUID: function(){},

/**
* Get this application's path. Note that this is the top-level path of
* application, not the path to the application contents directory. On
* OS X currently, the application contents directory is "[app path]/Contents"
* @return {String}
* @member Ti.API.Application
*/
getPath: function(){},

/**
* Retrieve the process identifier of this application. If this application
* is not the currently running application, this method will returned
* <tt>undefined</tt>.
* @return {Number}
* @member Ti.API.Application
*/
getPID: function(){},

/**
* Return the path to this application's resources directory. This directory
* is the 'Resources' subdirectory of the application contents directory.
* @return {String}
* @member Ti.API.Application
*/
getResourcesPath: function(){},

/**
* Return the resolved runtime for this for this application.
* Resolved components may either be installed or bundled components.
* Note that currently bundled components returned from this method
* do not have a version.
* @return {Ti.API.Component}
* @member Ti.API.Application
*/
getRuntime: function(){},

/**
* "Get this application's version."
* @return {String}
* @member Ti.API.Application
*/
getVersion: function(){},

/**
* Determine if the given argument is in the argument list.
* You may either pass 'param' or '--param' and this method will
* find the command-line argument.
* @param {String} argument The name of the argument to search for.
* @return {Boolean}
* @member Ti.API.Application
*/
hasArgument: function(argument){},

/**
* Returns whether or not this is the currently running application.
* @return {Boolean}
* @member Ti.API.Application
*/
isCurrent: function(){},

/**
* Attempt to resolve all the dependencies for this application. Resolved components
* should be accessible through API.Application.getComponents afterward. Note that
* the currently running applicaiton should already have all of its dependencies resolved.
* @return {Ti.Array<API.Dependency>}
* @member Ti.API.Application
*/
resolveDependencies: function(){}}


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


/**
* A module for holding core TideSDK functionality.
* @class Ti.API
* @singleton
* @member Ti
*/
Ti.API = {
/**
* Register a root event listener. Event listeners registered using this
* function will receive <em>all</em> events from Ti.
* @param {String} eventName The event name to listen for.
* @param {Function} callback The callback to invoke when this message occurs.
* @return {Number}
* @member Ti.API
*/
addEventListener: function(eventName, callback){},

/**
* A constant representing an application update component type.
* @property {Number}
* @member Ti.API
*/
APP_UPDATE: null,

/**
* Create a Tide Bytes object given a String. A Bytes object is a generic
* way of holding a String of bytes.
* @return {Bytes}
* @member Ti.API
*/
createBytes: function(){},

/**
* A constructor for API.Dependency objects.
* @param {Number} type The type of this dependency. This is usually one of the component type constants (e.g. API.MODULE).
* @param {String} name The name of this dependency.
* @param {String} version The version requirement for this dependency.
* @return {Ti.API.Dependency}
* @member Ti.API
*/
createDependency: function(type, name, version){},

/**
* Create a Tide list given an optional JavaScript array. This method is mainly used for testing.
* @param {Array} toWrap (optional) An Array to wrap in a new KList.
* @return {Array}
* @member Ti.API
*/
createKList: function(toWrap){},

/**
* Create a Tide method given an existing JavaScript Funtion. This method is mainly used for testing.
* @param {Function} toWrap (optional) A Function to wrap in a new KMethod.
* @return {Function}
* @member Ti.API
*/
createKMethod: function(toWrap){},

/**
* Create a Tide object given an existing JavaScript Object. This method is mainly used for testing.
* @param {Object} toWrap (optional) An Object to wrap in a new KObject.
* @return {Object}
* @member Ti.API
*/
createKObject: function(toWrap){},

/**
* A constant representing CRITICAL logger severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @property {Number}
* @member Ti.API
*/
CRITICAL: null,

/**
* Log a statement with CRITICAL severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @param {String} statement The String to send to the logger.
* @return {void}
* @member Ti.API
*/
critical: function(statement){},

/**
* A constant representing DEBUG logger severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @property {Number}
* @member Ti.API
*/
DEBUG: null,

/**
* Log a statement with DEBUG severity. The severity levels in order from
* least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @param {String} statement The String to send to the logger.
* @return {void}
* @member Ti.API
*/
debug: function(statement){},

/**
* A constant representing an equality dependency.
* This is used to specify resolutions to Ti application dependencies.
* @property {Number}
* @member Ti.API
*/
EQ: null,

/**
* A constant representing ERROR logger severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @property {Number}
* @member Ti.API
*/
ERROR: null,

/**
* Log a statement with ERROR severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @param {String} statement The String to send to the logger.
* @return {void}
* @member Ti.API
*/
error: function(statement){},

/**
* A constant representing FATAL logger severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @property {Number}
* @member Ti.API
*/
FATAL: null,

/**
* Log a statement with FATAL severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @param {String} statement The String to send to the logger.
* @return {void}
* @member Ti.API
*/
fatal: function(statement){},

/**
* Fire an event to the top-level event listener.
* @param {String|Object} event The name of the event to fire or the event object itself
* @return {void}
* @member Ti.API
*/
fireEvent: function(event){},

/**
* Get an attribute in the global object
* @param {String} key Key of the attribute to get
* @return {Any}
* @member Ti.API
*/
get: function(key){},

/**
* Get the currently running application. This application will
* should have all of its dependencies resolved.
* @return {Ti.API.Application}
* @member Ti.API
*/
getApplication: function(){},

/**
* Get the system environment object, which can be queried and updated
* just by accessing or setting its properties.
* @return {Ti.API.Environment}
* @member Ti.API
*/
getEnvironment: function(){},

/**
* Get a list of the currently installed Ti components.
* An installed component is one that has been found on the list of paths
* returned by Ti.API.getComponentSearchPaths. This list does not
* include bundled components.
* @return {Ti.Array<API.Component>}
* @member Ti.API
*/
getInstalledComponents: function(){},

/**
* Get a list of the paths on which Ti searches for installed components. This does not include paths of bundled components.
* @return {Ti.Array<API.Component>}
* @member Ti.API
*/
getComponentSearchPaths: function(){},

/**
* Get a list of the currently installed Ti Mobile SDK components.
* An installed component is one that has been found on the list of paths
* returned by Ti.API.getComponentSearchPaths. This list does not
* include bundled components.
* @return {Ti.Array<API.Component>}
* @member Ti.API
*/
getInstalledMobileSDKs: function(){},

/**
* Get a list of the currently installed Ti module components.
* An installed component is one that has been found on the list of paths
* returned by Ti.API.getComponentSearchPaths. This list does not
* include bundled components.
* @return {Ti.Array<API.Component>}
* @member Ti.API
*/
getInstalledModules: function(){},

/**
* Get a list of the currently installed Ti runtime components.
* An installed component is one that has been found on the list of paths
* returned by Ti.API.getComponentSearchPaths. This list does not
* include bundled components.
* @return {Ti.Array<API.Component>}
* @member Ti.API
*/
getInstalledRuntimes: function(){},

/**
* Get a list of the currently installed Ti SDK components.
* An installed component is one that has been found on the list of paths
* returned by Ti.API.getComponentSearchPaths. This list does not
* include bundled components.
* @return {Ti.Array<API.Component>}
* @member Ti.API
*/
getInstalledSDKs: function(){},

/**
* Get the log level threshold of the Ti logger. The logger
* will log statements with this severity or one that is more severe.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @return {Number}
* @member Ti.API
*/
getLogLevel: function(){},

/**
* A constant representing an greater-than dependency.
* This is used to specify resolutions to Ti application dependencies.
* @property {Number}
* @member Ti.API
*/
GT: null,

/**
* A constant representing an greater-than-or-equal-to dependency.
* This is used to specify resolutions to Ti application dependencies.
* @property {Number}
* @member Ti.API
*/
GTE: null,

/**
* Log a statement with INFO severity. The severity levels in order from
* least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @param {String} statement The String to send to the logger.
* @return {void}
* @member Ti.API
*/
info: function(statement){},

/**
* Log a statement with a given severity level. The severity levels are
* defined as constants on the API module.
* In order from least severe to most severe, they are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @param {Number} type The severity of this log statement.
* @param {String} statement The String to pass to the logger.
* @return {void}
* @member Ti.API
*/
log: function(type, statement){},

/**
* A constant representing an less-than dependency.
* This is used to specify resolutions to Ti application dependencies.
* @property {Number}
* @member Ti.API
*/
LT: null,

/**
* a constant representing a Mobile SDK component type.
* @property {Number}
* @member Ti.API
*/
MOBILESDK: null,

/**
* Print a String to stdout without a trailing newline
* @param {Any} data The data to print. If not a String, it will be converted using the equivalent of <tt>String(data);</tt>
* @return {void}
* @member Ti.API
*/
print: function(data){},

/**
* A constant representing NOTICE logger severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @property {Number}
* @member Ti.API
*/
NOTICE: null,

/**
* Remove a root event listener. If no listener with the given id or
* funtion is registered for this object, the call will do nothing.
* @param {Number|Function} id The id or the Function of the event listener to remove.
* @return {void}
* @member Ti.API
*/
removeEventListener: function(id){},

/**
* Execute the method asynchronously on the main thread. This should be
* used when attempting to run JavaScript methods from non-JavaScript threads.
* This method blocks until the function finishes executing and returns
* the return value of the method passed.
* @param {Function} method The method to execute.
* @param {Any} multiple A variable-length list of arguments to pass to the method.
* @return {Any}
* @member Ti.API
*/
runOnMainThread: function(method, multiple){},

/**
* Execute the method asynchronously on the main thread. This should be
* used when attempting to run JavaScript methods from non-JavaScript threads.
* This method does not wait for the method to complete and returns immediately.
* @param {Function} method The method to execute.
* @param {Any} multiple A variable-length list of arguments to pass to the method.
* @return {void}
* @member Ti.API
*/
runOnMainThreadAsync: function(method, multiple){},

/**
* A constant representing a runtime component type.
* @property {Number}
* @member Ti.API
*/
RUNTIME: null,

/**
* A constant representing a module component type.
* @property {Number}
* @member Ti.API
*/
MODULE: null,

/**
* a constant representing an SDK component type.
* @property {Number}
* @member Ti.API
*/
SDK: null,

/**
* A constant representing INFO logger severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @property {Number}
* @member Ti.API
*/
INFO: null,

/**
* Set an attribute in the global object
* @param {String} key Key of the attribute to set
* @param {String} value New value of the attribute
* @return {void}
* @member Ti.API
*/
set: function(key, value){},

/**
* Set the log level threshold of the Ti logger. The logger
* will log statements with this severity or one that is more severe.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @param {Number} level The threshold of severity to log.
* @return {void}
* @member Ti.API
*/
setLogLevel: function(level){},

/**
* A constant representing TRACE logger severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @property {Number}
* @member Ti.API
*/
TRACE: null,

/**
* Log a statement with TRACE severity. The severity levels in order from
* least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @param {String} statement The String to send to the logger.
* @return {void}
* @member Ti.API
*/
trace: function(statement){},

/**
* Read an application manifest at a given path and return an
* Ti.API.Application object representing the application.
* @param {String} manifestPath The path to the manifest to read.
* @param {String} applicationPath (optional) An optional application path override, which can be used if the manifest and the application are in different paths.
* @return {Ti.API.Application}
* @member Ti.API
*/
readApplicationManifest: function(manifestPath, applicationPath){},

/**
* A constant representing WARN logger severity.
* The severity levels in order from least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @property {Number}
* @member Ti.API
*/
WARN: null,

/**
* Log a statement with NOTICE severity. The severity levels in order from
* least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @param {String} statement the statement to log
* @return {void}
* @member Ti.API
*/
notice: function(statement){},

/**
* a constant representing an UNKNOWN component type.
* @property {Number}
* @member Ti.API
*/
UNKNOWN: null,

/**
* A constant representing an less-than-or-equal-to dependency.
* This is used to specify resolutions to Ti application dependencies.
* @property {Number}
* @member Ti.API
*/
LTE: null,

/**
* Log a statement with WARN severity. The severity levels in order from
* least severe to most severe are:
* <ol>
* <li>TRACE</li>
* <li>DEBUG</li>
* <li>INFO</li>
* <li>NOTICE</li>
* <li>WARN</li>
* <li>ERROR</li>
* <li>CRITICAL</li>
* <li>FATAL</li>
* </ol>
* @param {String} statement The String to send to the logger.
* @return {void}
* @member Ti.API
*/
warn: function(statement){},

/**
* Invoke the installer to find and install a list of dependencies. When
* the installer is finished running, it will call the given callback.
* The only way to determine whether or not the installation was successful
* at this point is to try to resolve the dependencies that were passed
* to the installer. <em>Currently the installer only supports Ti.API.EQ
* dependencies.</em>
* @param {Array<API.Dependency>} dependencies A list of API.Dependency to find and install.
* @param {Function} callback A callback to invoke when the installer is finished.
* @return {void}
* @member Ti.API
*/
installDependencies: function(dependencies, callback){}}


/**
* Script object.
* @class Ti.API.Script
* @member Ti.API
*/
Ti.API.Script = {
/**
* <p>
* Adds a script evalutor Script evaluators are responsible for matching and evaluating
* custom <script> types, and preprocessing URLs.
* </p>
* <p>
* When a <tt>&lt;script type="text/language"&gt;</tt> tag is seen, the first
* evaluator that returns true to <tt>canEvaluate("text/language")</tt> will
* evaluate that script.
* </p>
* When a URLRequest is received, the first evaluator that returns true to
* <tt>canPreprocess(URL)</tt> will preprocess that URL. Evaluators should
* follow this API:
* <ol><li>
* <tt>canEvaluate(String mimeType)</tt> returns true or false.
* </li> <li>
* <tt>canPreprocess(String mimeType)</tt> returns true or false.
* </li><li>
* <tt>evaluate(String mimeType, String name, String sourceCode, Object scope)</tt> returns result of evaluation
* </li><li>
* <tt>preprocess(String url, Object scope)</tt> returns preprocessed content.
* </li></ol>
* @param {Object} evaluator The evaluator to add.
* @return {String}
* @member Ti.API.Script
*/
addScriptEvaluator: function(evaluator){},

/**
* 
* @param {Object} evaluator The mimeType to check
* @return {bool}
* @member Ti.API.Script
*/
canEvaluate: function(evaluator){},

/**
* 
* @param {String} url The URL to check
* @return {bool}
* @member Ti.API.Script
*/
canPreprocess: function(url){},

/**
* Evaluates a string of code
* @param {String} mimeType "The code's mime type (i.e. \"text/ruby\", \"text/php\")"
* @param {String} name "The name of the code's origin (usually a filename, or URL)"
* @param {String} code The actual code
* @param {Object} scope "global variable scope (i.e. \"window\")"
* @return {Any}
* @member Ti.API.Script
*/
evaluate: function(mimeType, name, code, scope){},

/**
* Runs an app URL through preprocessing, returning the result as a string
* @param {String} URL the URL for this resource (app, ti, and file URLs are accepted)
* @param {Object} scope global variable scope to expose into the preprocessed file
* @return {String}
* @member Ti.API.Script
*/
preprocess: function(URL, scope){},

/**
* Removes a script evalutor
* @param {Object} evaluator The evaluator to remove
* @return {String}
* @member Ti.API.Script
*/
removeScriptEvaluator: function(evaluator){}}


/**
* A module for holding currently running application specific functionality.
* @class Ti.App
* @singleton
* @member Ti
*/
Ti.App = {
/**
* Convert the given app URL to a filesystem path. App URLs generally have
* the form 'app://subdir/resource.html' and resolve to a fileystem path
* rooted in the application resources directory.
* @return {String}
* @member Ti.App
*/
appURLToPath: function(){},

/**
* Cause the application to exit after firing the Ti.EXIT
* event. The application isn't gauaranteed to exit when this
* method is called, because an event handler may cancel the
* EXIT event by calling preventDefault or stopPropagation on it.
* @return {void}
* @member Ti.App
*/
exit: function(){},

/**
* Return the application's copyright information, defined in the tiapp.xml file.
* @return {String}
* @member Ti.App
*/
getCopyright: function(){},

/**
* Return the application's description, defined in the tiapp.xml file.
* @return {String}
* @member Ti.App
*/
getDescription: function(){},

/**
* Return the full path to the application home directory. The application
* home or contents directory is the subdirectory within the application which
* contains the application Resources directory and bundled components. On OS X
* this is the directory "My App.app/Contents" and on Windows and Linux it is
* simply the path to the application.
* @return {String}
* @member Ti.App
*/
getHome: function(){},

/**
* Return the full path to the application icon. The application icon path
* is specified in the application manifest and tiapp.xml relative to the
* application Resources directory.
* @return {String}
* @member Ti.App
*/
getIcon: function(){},

/**
* Return the application name.
* @return {String}
* @member Ti.App
*/
getName: function(){},

/**
* Return the application publisher information specifiedi in the tiapp.xml file.
* @return {String}
* @member Ti.App
*/
getPublisher: function(){},

/**
* "Return the stream URL for the application's updates."
* @param {String} multiple Any number of String arguments which will be appended as path components of the stream URL.
* @return {String}
* @member Ti.App
*/
getStreamURL: function(multiple){},

/**
* Get this human readable id defined in both the
* application manifest and the application's tiapp.xml file.
* @return {String}
* @member Ti.App
*/
getID: function(){},

/**
* Return the application's GUID, defined in the application manifest.
* @return {String}
* @member Ti.App
*/
getGUID: function(){},

/**
* Return the command-line arguments passed to this application,
* excluding the first which is the path to the application executable.
* @return {Array<String>}
* @member Ti.App
*/
getArguments: function(){},

/**
* Get the system properties defined in tiapp.xml (see App.Properties).
* @return {Ti.App.Properties}
* @member Ti.App
*/
getSystemProperties: function(){},

/**
* Return the application URL definedin the tiapp.xml file.
* @return {String}
* @member Ti.App
*/
getURL: function(){},

/**
* Create a new App.Properties object.
* @param {Object} properties (optional) Initial properties for the new App.Properties object.
* @return {Ti.App.Properties}
* @member Ti.App
*/
createProperties: function(properties){},

/**
* Return the full path to the application executable.
* @return {String}
* @member Ti.App
*/
getPath: function(){},

/**
* Return the application version defined in the tiapp.xml file.
* @return {String}
* @member Ti.App
*/
getVersion: function(){},

/**
* Loads a properties list from a file path.
* @param {String} path Path to a properties file.
* @return {Ti.Array<App.Properties>}
* @member Ti.App
*/
loadProperties: function(path){},

/**
* Exit the application and restart it.
* @return {String}
* @member Ti.App
*/
restart: function(){},

/**
* Print a raw string to stderr without a trailing newline.
* @param {Any} data The data to print. If not a String, it will be converted using the equivalent of <tt>String(data);</tt>
* @return {String}
* @member Ti.App
*/
stderr: function(data){},

/**
* Reads from stdin
* @param {String} prompt "(optional) Text prompt for input. If not specified, no prompt will appear."
* @param {String} delimiter "(optional) Will continue reading stdin until the delimiter character is reached. If no argument is specified, this method will continue reading until a newline."
* @return {String}
* @member Ti.App
*/
stdin: function(prompt, delimiter){},

/**
* Print a String to stdout including a trailing newline.
* @param {Any} data The data to print. If not a String, it will be converted using the equivalent of <tt>String(data);</tt>
* @return {void}
* @member Ti.App
*/
stdout: function(data){}}


/**
* An object holding a group of properties.
* Application properties provide an alternative to storing information in
* HTML5 Databases or through the TideSDK Database module. They can be categorized
* into System Properties and User Properties. 
*
* System Properties
* -----------------
* System properties are generally defined in your app's tiapp.xml. There are always
* read-only.
* For instance, you can save the properties below in tiapp.xml under the <ti:app> node.
* 		
*		<property name="customText" type="string">This is a string</property> 	
*		<property name="customDouble" type="double">2.45</property>
*		<property name="customBool" type="boolean">true</property>
*		<property name="customInt" type="int">9</property>
*		<property name="customList" type="list">9,8,7</property>
*
* You can now access the above properties as shown below:
*
*		var appProperties = Ti.App.getSystemProperties();
*		alert(appProperties.getString('customString'));
*		alert(appProperties.getInt('customInt'));
*		
* Please note that System properties are read-only. It is so because an application
* might not have write access to its installation directory. This is where tiapp.xml resides.
* Therefore to store properties, its recommended that you use User properties. 
*
* User Properties
* ---------------
* User properties are obtained using the same interface as System properties. 
* Its recommended that you store these in the application data directory.   
* On Windows, this is __%appdata%/TideSDK/appdata.__  
* On Linux, this is __~/.tidesdk/appdata/.__  
* On OSX, this is __~/Library/Application Support/TideSDK/appdata.__  
*
* Let's take a look at the example below:
* 
*		var file = Ti.Filesystem.getFile(Ti.API.application.dataPath, "user.properties");
*		var userProperties;

*		//if file exists, then load properties.
*		if(file.exists()) {
*			userProperties = Ti.App.loadProperties(file);
*		} else {
*		//create new set of properties if file doesn't exist
*			userProperties = Ti.App.createProperties({
*			  	customText : "This is a string",
*			  	customDouble : 2.45,
*			  	customBool : true,
*			  	customInt	: 1,
*			  	customList : [9,8,7]	
*			});
*		}
*		
*		//retrieve a string value
*		alert(userProperties.getString('customText'));
*		//set an integer value in properties
*		userProperties.setInt('customInt',9);
*		//making sure that the property values are saved to the file object
*		userProperties.saveTo(file);
*		//null out file object as pointer not used anymore
*		file = null;
*
*
* @class Ti.App.Properties
* @member Ti.App
*/
Ti.App.Properties = {
/**
* Returns a property value as an integer.
* Throws an exception if this value can not be found and no default is
* provided or the value stored in the properties file could not be
* converted to the appropriate type.
* @param {String} name The name of the property to return.
* @param {Number} defaults The value to return if this property is not set.
* @return {Number}
* @member Ti.App.Properties
*/
getInt: function(name, defaults){},

/**
* Returns a property value as an Array.
* Throws an exception if this value can not be found and no default is
* provided or the value stored in the properties file could not be
* converted to the appropriate type.
* @param {list} name The name of the property to return.
* @param {list} defaults The value to return if this property is not set.
* @return {list}
* @member Ti.App.Properties
*/
getList: function(name, defaults){},

/**
* Returns a property value as a String.
* Throws an exception if this value can not be found and no default is
* provided or the value stored in the properties file could not be
* converted to the appropriate type.
* @param {String} name The name of the property to return.
* @param {String} defaults The value to return if this property is not set.
* @return {String}
* @member Ti.App.Properties
*/
getString: function(name, defaults){},

/**
* Returns a property value as double.
* Throws an exception if this value can not be found and no default is
* provided or the value stored in the properties file could not be
* converted to the appropriate type.
* @param {String} name The name of the property to return.
* @param {Number} defaults The value to return if this property is not set.
* @return {Number}
* @member Ti.App.Properties
*/
getDouble: function(name, defaults){},

/**
* Query whether or not a given property exists in this Property object.
* @param {String} name The name of the property to query.
* @return {Boolean}
* @member Ti.App.Properties
*/
hasProperty: function(name){},

/**
* Returns an Array of all property names in this App.Properties object.
* @return {Array<String>}
* @member Ti.App.Properties
*/
listProperties: function(){},

/**
* Save this App.Properties object to file at the given path.
* @param {String} path The path to the file to save this App.Properties object to.
* @return {void}
* @member Ti.App.Properties
*/
saveTo: function(path){},

/**
* Set a double property value given the name and value.
* @param {String} name The name of the property to set.
* @param {Number} value The value to set the given property to.
* @return {void}
* @member Ti.App.Properties
*/
setDouble: function(name, value){},

/**
* Set an integer property value given the name and value.
* @param {String} name The name of the property to set.
* @param {Number} value The value to set the given property to.
* @return {void}
* @member Ti.App.Properties
*/
setInt: function(name, value){},

/**
* Set a list property value given the name and array of Strings.
* @param {String} name The name of the property to set.
* @param {Array<String>} value The value to set the given property to.
* @return {void}
* @member Ti.App.Properties
*/
setList: function(name, value){},

/**
* Set a String property value given the name and value.
* @param {String} name The name of the property to set.
* @param {String} value The value to set the given property to.
* @return {void}
* @member Ti.App.Properties
*/
setString: function(name, value){}}


/**
* An object for holding arrays of bytes.
* @class Ti.Bytes
* @member Ti
*/
Ti.Bytes = {
/**
* Return the character code (or byte value) at the given index in a Bytes.
* @param {Number} index The index to look for a character code at.
* @return {Number}
* @member Ti.Bytes
*/
byteAt: function(index){},

/**
* Return a character representing a byte at the given index in a Bytes.
* @param {Number} index The index to look for a character at.
* @return {String}
* @member Ti.Bytes
*/
charAt: function(index){},

/**
* Concatenate multiple Bytes and Strings into one Bytes.
* @param {Byte|String} multiple A variable-length list of Bytes or Strings to concatenate to this Bytes object.
* @return {Bytes}
* @member Ti.Bytes
*/
concat: function(multiple){},

/**
* Return the index of a String within this Bytes. The String will first
* be converted to UTF-8 before this method searches the Bytes object.
* @param {String} needle The String to search for.
* @return {Number}
* @member Ti.Bytes
*/
indexOf: function(needle){},

/**
* Return the last index of a String within this Bytes. The String will first
* be converted to UTF-8 before this method searches the Bytes object.
* @param {String} needle The String to search for
* @return {Number}
* @member Ti.Bytes
*/
lastIndexOf: function(needle){},

/**
* Split a bytes as if it were a String given a delimiter. The Bytes object is
* expected to contain a UTF-8 encoded String. That means that the first NUL
* character in the string will be the end of the string.
* @param {String} delimiter The index to look for a character at
* @param {Number} limit (optional) The maximum number of matches to return
* @return {Array<String>}
* @member Ti.Bytes
*/
split: function(delimiter, limit){},

/**
* Return a substring of a Bytes given a start index and a length. This
* assumes that Bytes contains a UTF-8 string. This means that the first
* NUL character in the Bytes object will signify the end of the string.
* If no length index is given, return all characters from the start index
* to the end of the string.
* @param {Number} startIndex The starting index
* @param {Number} length (optional) The length of the substring
* @return {String}
* @member Ti.Bytes
*/
substr: function(startIndex, length){},

/**
* The number of bytes in this Bytes object.
* @property {String}
* @member Ti.Bytes
*/
length: null,

/**
* Return a substring of a Bytes given a start index and end index. This
* assumes that Bytes contains a UTF-8 string. This means that the first
* NUL character in the Bytes object will signify the end of the string.
* If no end index is given, return all characters from the start index
* to the end of the string. If startIndex &gt; endIndex, the indices are swapped.
* @param {Number} startIndex The starting index
* @param {Number} endIndex (optional) The ending index
* @return {String}
* @member Ti.Bytes
*/
substring: function(startIndex, endIndex){},

/**
* Convert characters in the Bytes to lower-case as if it it were a String.
* This method assumes that Bytes contains a UTF-8 string. This means that the first
* NUL character in the Bytes object will signify the end of the string.
* @return {String}
* @member Ti.Bytes
*/
toLowerCase: function(){},

/**
* Convert characters in the Bytes to upper-case as if it it were a String.
* This method assumes that Bytes contains a UTF-8 string. This means that the first
* NUL character in the Bytes object will signify the end of the string.
* @return {String}
* @member Ti.Bytes
*/
toUpperCase: function(){}}


/**
* A module for dealing with encoding and decoding.
* @class Ti.Codec
* @singleton
* @member Ti
*/
Ti.Codec = {
/**
* Constant specifying the Adler-32 checksum algorithm.
* @property {Number}
* @member Ti.Codec
*/
ADLER32: null,

/**
* Constant specifying the CRC32 checksum algorithm.
* @property {String}
* @member Ti.Codec
*/
CRC32: null,

/**
* Asynchronously write the contents of a directory to a zip file.
* @param {Filesystem.File|String} root A directory root to write to the zip stream.
* @param {Filesystem.File|String} zipFile The path or File object of the destination zip file.
* @param {Function} onComplete A function callback that receives the zip file when writing is finished
* @return {String}
* @member Ti.Codec
*/
createZip: function(root, zipFile, onComplete){},

/**
* Compute the checksum of the given String with the given checksum algorithm.
* @param {String} data The string to compute the checksum on. The checksum will be computed on the UTF-8 version of this String.
* @param {int} checksumType (optional) The checksum algorithm to use. Either Codec.CRC32 (default) or Codec.ADLER32
* @return {Number}
* @member Ti.Codec
*/
checksum: function(data, checksumType){},

/**
* Encode some data using a digest algorithm to a hex binary String.
* String data will first be converted to UTF-8 data.
* @param {int} hashType The hash type of the digest, which should be one Codec.MD2, Codec.MD4, Codec.MD5, or Codec.SHA1.
* @param {String|Bytes} data The data to encode.
* @return {String}
* @member Ti.Codec
*/
digestToHex: function(hashType, data){},

/**
* Decode a Base64-encoded String.
* @param {String} data String to decode.
* @return {String}
* @member Ti.Codec
*/
decodeBase64: function(data){},

/**
* Digest a String into a hex binary HMAC.
* String data will first be converted to UTF-8 data.
* @param {int} hashType The hash type of the HMAC, which should be one Codec.MD2, Codec.MD4, Codec.MD5, or Codec.SHA1.
* @param {String} data The data to encode.
* @param {String} data The key to us for the HMAC.
* @return {String}
* @member Ti.Codec
*/
digestHMACToHex: function(hashType, data, data){},

/**
* Decode a hex binary-encoded String.
* @param {String} data String to decode.
* @return {String}
* @member Ti.Codec
*/
decodeHexBinary: function(data){},

/**
* Encode some data into Base64.
* String data will first be converted to UTF-8 data.
* @param {String|Bytes} data The data to encode.
* @return {String}
* @member Ti.Codec
*/
encodeBase64: function(data){},

/**
* Encode some data into a hex binary String.
* String data will first be converted to UTF-8 data.
* @param {String|Bytes} data data to encode
* @return {String}
* @member Ti.Codec
*/
encodeHexBinary: function(data){},

/**
* Asynchronously extract the contents of a zip file.
* @param {Filesystem.File|String} zipFile The path or File object of the zip file being extracted.
* @param {Filesystem.File|String} dest A directory into which the files will be extracted.
* @param {Function} onComplete A function callback that receives destination directory when completed.
* @return {String}
* @member Ti.Codec
*/
extractZip: function(zipFile, dest, onComplete){},

/**
* Constant specifying the MD2 hash algorithm.
* @property {String}
* @member Ti.Codec
*/
MD2: null,

/**
* Constant specifying the SHA1 hash algorithm.
* @property {String}
* @member Ti.Codec
*/
SHA1: null,

/**
* Constant specifying the MD4 hash algorithm.
* @property {String}
* @member Ti.Codec
*/
MD4: null,

/**
* Constant specifying the MD5 hash algorithm.
* @property {String}
* @member Ti.Codec
*/
MD5: null}


/**
* An object representing a TideSDK Database.
* After opening a database (Ti.Database), you can use the properties of this object to interact with it.
*
* Querying Databases
* ------------------
* Note - Please make sure that all queries are SQLite compatible. 
* Please refer to the code examples below:
*
*		//Open the database first
*		var db = Ti.Database.openFile(Ti.Filesystem.getFile(
*									  Ti.Filesystem.getApplicationDataDirectory(), 'customdatabase.db'));	
*		
*		//Create a table and insert values into it
*		db.execute("CREATE TABLE IF NOT EXISTS Users(id INTEGER, firstName TEXT)");
*		db.execute("INSERT INTO Users VALUES(1,'Joe Bloggs')");		 
*		
*		//Select from Table
*		var rows = db.execute("SELECT * FROM Users");
*		while (rows.isValidRow()) {
*			//Alert the value of fields id and firstName from the Users database
*			alert('The user id is '+rows.fieldByName('id')+', and user name is '+rows.fieldByName('firstName'));
*			rows.next();	
*		}
*
*		//Release memory once you are done with the resultset and the database
*		rows.close();
*		db.close();	
*		
*
*
* @class Ti.Database.DB
* @member Ti.Database
*/
Ti.Database.DB = {
/**
* Close an open Database.DB. If the database is not open, this method will do nothing.
* @return {void}
* @member Ti.Database.DB
*/
close: function(){},

/**
* Get the full filesystem path to the database. If this database was
* opened via Datbase.openFile this path will be the originally path
* used, otherwise it will be the path to a WebKit database in the
* application data directory.
* @return {String}
* @member Ti.Database.DB
*/
getPath: function(){},

/**
* Executes an SQL query on this Database.DB. Currently all queries must
* be valid SQLite-style SQL.
* @param {String} query The SQL query to execute on this Database.DB.
* @param {Any} multiple (optional) A variable-length argument list of values to use with the given query
* @return {Ti.Database.ResultSet}
* @member Ti.Database.DB
*/
execute: function(query, multiple){},

/**
* The row id of the last insert operation.
* @property {Number}
* @member Ti.Database.DB
*/
lastInsertRowId: null,

/**
* Remove a Database.DB. This method will close the database
* if it is open and remove the file from the filesystem.
* @return {void}
* @member Ti.Database.DB
*/
remove: function(){},

/**
* The number of rows affected by the last execute call.
* @property {Number}
* @member Ti.Database.DB
*/
rowsAffected: null}


/**
* A module for dealing with Database storage.
*There are two ways to use databases in TideSDK - HTML5 Databases and the TideSDK Database API. Both API's make 
*use of SQLite backends. 
*
*Opening a Database
*------------------
*You can open databases in TideSDK using the Ti.Database.open and Ti.Database.openFile methods.
*Using Ti.Database.open will create a database which is WebKit compatible in the same directory.
*(Only if the database file doesn't exist.)
*	
*		//Create a database which is WebKit compatible.
*		var db = Ti.Database.open('customdatabase');
*
*Alternatively, you can create a database and open it using the Ti.Database.openFile method. This method
*accepts a file path or a Ti.Filesystem.File object.
*
*		//Create a database
*		var db = Ti.Database.openFile(Ti.Filesystem.getFile(
*									  Ti.Filesystem.getApplicationDataDirectory(), 'customdatabase.db'));	
*
*Querying Databases
*------------------
*Please refer to the Ti.Database.DB documentation.
*
*Note - It is recommended that you store all data in the application data directory and not the application resources
*or contents directory as those may not be writeable.
*
* @class Ti.Database
* @singleton
* @member Ti
*/
Ti.Database = {
/**
* Open a WebKit HTML5 compatible-database, given the name of the database
* to open. WebKit HTML5 databases are stored per-security origin and are
* not available between security origins. A security origin is composed
* of a URL scheme and hostname pair.
* @param {String} name Name of the database. The call will create the database if it does not exist.
* @return {Ti.Database.DB}
* @member Ti.Database
*/
open: function(name){},

/**
* Open a database, given a path to an sqlite file.
* @param {String} path Path to an SQLite file to store the database in. If the file does not exist, it will be created.
* @return {Ti.Database.DB}
* @member Ti.Database
*/
openFile: function(path){}}


/**
* An object representing a set of result from a Database.DB query.
* @class Ti.Database.ResultSet
* @member Ti.Database
*/
Ti.Database.ResultSet = {
/**
* Releases the memory associated with this Database.ResultSet.
* @return {void}
* @member Ti.Database.ResultSet
*/
close: function(){},

/**
* Return the value of a field in the current row of this Database.ResultSet, given
* its index in the original SQL query.
* @param {Number} fieldIndex The zero-based index of the field to query.
* @return {Boolean|String|Number|Bytes}
* @member Ti.Database.ResultSet
*/
field: function(fieldIndex){},

/**
* Return the value of the specified field in the current row.
* @param {String} name The name of the field to query.
* @return {Boolean|String|Number|Bytes}
* @member Ti.Database.ResultSet
*/
fieldByName: function(name){},

/**
* Return the number of fields in this Database.ResultSet.
* @return {Number}
* @member Ti.Database.ResultSet
*/
fieldCount: function(){},

/**
* Return the name of the specified field in the Database.ResultSet given its index.
* The index of a field is determined by the original SQL query that generated this
* Database.ResultSet.
* @param {Number} fieldIndex The zero-based index of the field to query.
* @return {String}
* @member Ti.Database.ResultSet
*/
fieldName: function(fieldIndex){},

/**
* Check whether the current row of this Datbase.ResultSet is valid. Reasons
* for the current row not being valid include an error in the original SQL
* statement, a query that returned no results or iterating to the end of
* the Database.ResultSet.
* @return {Boolean}
* @member Ti.Database.ResultSet
*/
isValidRow: function(){},

/**
* Move the Database.ResultSet iterator to the next row of this
* result set. When the iterator has gone past the last entry in
* the Database.ResultSet, the <tt>isValidRow</tt> method will return
* false.
* @return {void}
* @member Ti.Database.ResultSet
*/
next: function(){},

/**
* Return the number of rows in this Database.ResultSet.
* @return {Number}
* @member Ti.Database.ResultSet
*/
rowCount: function(){}}


/**
* A representation of an asynchronous copy operation created via calling Filesystem.asyncCopy.
* @class Ti.Filesystem.AsyncCopy
* @member Ti.Filesystem
*/
Ti.Filesystem.AsyncCopy = {
/**
* True if this asynchronous copy operation is active, false otherwise.
* @property {Boolean}
* @member Ti.Filesystem.AsyncCopy
*/
running: null}


/**
* An object which represents a path to a file or directory. A Filesystem.File is not guaranteed to be a valid path.
* @class Ti.Filesystem.File
* @member Ti.Filesystem
*/
Ti.Filesystem.File = {
/**
* Copies a file to the specified location. If the target is a directory
* the file will be written to that directory. If the target is a file,
* the file will be written to that file.
* @param {String|Filesystem.File} target The target of this move operation.
* @return {void}
* @member Ti.Filesystem.File
*/
copy: function(target){},

/**
* Create a new directory at this File object's path. If the
* directory already exists, this method will do nothing. This
* method will return true if the directory was created or false
* if it was not.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
createDirectory: function(){},

/**
* Return the timestamp for when this file or directory was created.
* The return value of this function will be microseconds since the
* epoch at the time this file was created.
* @return {Number}
* @member Ti.Filesystem.File
*/
createTimestamp: function(){},

/**
* Remove the file or directory specified by this Filesystem.File.
* Return true if removal succeeded and false otherwise.
* @param {Boolean} recursive If this Filesystem.File is a directory, remove it recursively.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
deleteDirectory: function(recursive){},

/**
* Remove the file or directory specified by this Filesystem.File,
* this method never removes directories recursively.
* Return true if removal succeeded and false otherwise.
* @return {String}
* @member Ti.Filesystem.File
*/
deleteFile: function(){},

/**
* Return true if a file or directory exists at the path
* specified by this Filesystem.File.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
exists: function(){},

/**
* Return the extension of this Filesystem.File.
* @return {String}
* @member Ti.Filesystem.File
*/
extension: function(){},

/**
* If this Filesystem.File specifies the path to a directory,
* return an Array of items inside this directory. If this path
* does not exist or is not a directory, return null.
* @return {Ti.Array<Filesystem.File>}
* @member Ti.Filesystem.File
*/
getDirectoryListing: function(){},

/**
* Creates a shortcut to a file or directory at this Filesystem.File's
* path. On Windows this will create a Win32 style shortcut. On Linux
* and OS X this will create a symlink. If the operation is successful
* this method will return true and false otherwise.
* @param {String|Filesystem.File} target The target of this shortcut.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
createShortcut: function(target){},

/**
* Return true if the path specified by this Filesystem.File refers
* to a directory or false otherwise.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
isDirectory: function(){},

/**
* Return true if the directory or file at the path specified by
* this Filesystem.File object has the executable bit set. If the
* file does not exists, this method will return false.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
isExecutable: function(){},

/**
* Return true if the path specified by this Filesystem.File refers
* to a file or false otherwise.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
isFile: function(){},

/**
* Return true if the path specified by this Filesystem.File refers
* to a hidden file. On Windows this means that the file has the hidden
* attribute and on Linux and OS X this means that the basename of
* this path begins with a period.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
isHidden: function(){},

/**
* Return true if the path specified by this Filesystem.File refers
* to a read-only file.
* @return {String}
* @member Ti.Filesystem.File
*/
isReadonly: function(){},

/**
* Return true if the path specified by this Filesystem.File refers
* to a symbolic link.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
isSymbolicLink: function(){},

/**
* Return true if the path specified by this Filesystem.File refers
* to a writable file and false otherwise.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
isWritable: function(){},

/**
* Return the timestamp for when this file or directory was modified.
* The return value of this function will be microseconds since the
* epoch at the last time this file was modified.
* @return {Number}
* @member Ti.Filesystem.File
*/
modificationTimestamp: function(){},

/**
* Moves to the specified location. If the target is a directory
* the file will be written to that directory. If the target is a file,
* the file will be written to that file.
* @param {String|Filesystem.File} target The target of this move operation.
* @return {String}
* @member Ti.Filesystem.File
*/
move: function(target){},

/**
* Return the full path of this File.Filesystem object.
* @return {String}
* @member Ti.Filesystem.File
*/
nativePath: function(){},

/**
* Create and open a Filestream for this File object.
* @param {Boolean} binary (optional) Whether or not to open this stream in binary mode. If not supplied this will be false.
* @param {Boolean} append (optional) Whether or not to open this stream in append mode. If not supplied this will be false.
* @return {Ti.Filesystem.Filestream}
* @member Ti.Filesystem.File
*/
open: function(binary, append){},

/**
* Return the parent directory of this File.Filesystem object.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem.File
*/
parent: function(){},

/**
* Return the entire contents of a file as a Bytes object.
* deprecated:
* reason: The method has been superseded by Filestream.read()
* version: 1.1.0
* @return {Bytes}
* @member Ti.Filesystem.File
*/
read: function(){},

/**
* Return one line from the file specified by this Filesystem.File object.
* This method will return null when it finishes reading the file or if
* it encounters and error. The file object will remain in an open state until
* the entire file has been read via Filestream.File.readLine. It is recommended
* that new applications use Filesystem.Filestream to read files instead, which
* allow for explicit control over the native file handles.
* deprecated:
* reason: The method has been superseded by Filestream.readLine()
* version: 1.1.0
* @return {String}
* @member Ti.Filesystem.File
*/
readLine: function(){},

/**
* Renames a file to the given path.
* @param {String} newPath The new path of the file
* @return {String}
* @member Ti.Filesystem.File
*/
rename: function(newPath){},

/**
* Set the execute bit on the file or directory at the path specified
* by this Filesystem.File object. Return true if the file or directory
* at this path is executable after the operation completes.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
setExecutable: function(){},

/**
* Resolves a given relative path against the path specified by this
* Filesystem.File object. If the given path is absolute, the absolute
* path is returned.
* @param {String} subPath The subPath to resolve against this Filesystem.File object.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem.File
*/
resolve: function(subPath){},

/**
* Remove the wrtiable bit and ensure there is a readable bit on the file
* or directory at the path specified by this Filesystem.File object. Return
* true if the file or directory at this path is read-only after the operation
* completes.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
setReadonly: function(){},

/**
* Return the size of the file in number of bytes.
* @return {Number}
* @member Ti.Filesystem.File
*/
size: function(){},

/**
* Set the write bit on the file or directory at the path specified
* by this Filesystem.File object. Return true if the file or directory
* at this path is writable after the operation completes.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
setWritable: function(){},

/**
* Return the space available on the filesystem containing the
* path specified by this Filesystem.File object in number of
* bytes..
* @return {Number}
* @member Ti.Filesystem.File
*/
spaceAvailable: function(){},

/**
* Creates a new, empty file in an atomic operation.
* Returns true if the file was created or false if it already exists.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
touch: function(){},

/**
* If this file is a zip file, unzip it into the given destination directory.
* Return true if the operation was successful or false otherwise. This operation
* will block the main thread.
* deprecated:
* reason: The method has been superseded by Codec.extractZip()
* version: 1.1.0
* @param {Filesystem.File|String} destination Directory to unzip the file to.
* @return {Boolean}
* @member Ti.Filesystem.File
*/
unzip: function(destination){},

/**
* Write data to the file at the path specified by this Filesystem.File
* object. Returns true if any data was written to the file or false
* otherwise.
* deprecated:
* reason: The method has been superseded by Filestream.write()
* version: 1.1.0
* @param {String|Bytes|Number} data The data to write to this Filesystem.File.
* @return {String}
* @member Ti.Filesystem.File
*/
write: function(data){}}


/**
* A object for reading and writing data to files.
* @class Ti.Filesystem.Filestream
* @member Ti.Filesystem
*/
Ti.Filesystem.Filestream = {
/**
* Return true if this Fileystem.Filestream is open and false otherwise.
* @return {Boolean}
* @member Ti.Filesystem.Filestream
*/
isOpen: function(){},

/**
* Close this Filsystem.Filstream. Return true if the stream closed
* without any problems and false otherwise.
* @return {Boolean}
* @member Ti.Filesystem.Filestream
*/
close: function(){},

/**
* A constant representing append mode for file access.
* @property {Number}
* @member Ti.Filesystem.Filestream
*/
MODE_APPEND: null,

/**
* A constant representing read mode for file access.
* @property {Number}
* @member Ti.Filesystem.Filestream
*/
MODE_READ: null,

/**
* A constant representing write mode for file access.
* @property {String}
* @member Ti.Filesystem.Filestream
*/
MODE_WRITE: null,

/**
* Open this Filesystem.Filestream. Return true if the operation is
* successful or false otherwise.
* @param {Boolean} binary (optional) Whether or not to open this stream in binary mode. If not supplied this will be false.
* @param {Boolean} append (optional) Whether or not to open this stream in append mode. If not supplied this will be false.
* @return {Boolean}
* @member Ti.Filesystem.Filestream
*/
open: function(binary, append){},

/**
* Read data from a Filesystem.Filestream into a Bytes object
* and return it. This method will throw an exception if the
* operation fails.
* @param {Integer} size Number of bytes to read from the file.
* @return {Bytes}
* @member Ti.Filesystem.Filestream
*/
read: function(size){},

/**
* Reads one line from this Filesystem.Filestream. The stream must
* be open before using this method (or an exception will be thrown).
* Each call will return a Bytes object until the end of the stream,
* when null will be returned.
* @return {Bytes|null}
* @member Ti.Filesystem.Filestream
*/
readLine: function(){},

/**
* Return true if this Filesystem.Filestream is ready for IO operations or false otherwise.
* @return {Boolean}
* @member Ti.Filesystem.Filestream
*/
ready: function(){},

/**
* Returns current position in file relative to the beginning
* @return {Integer}
* @member Ti.Filesystem.Filestream
*/
tell: function(){},

/**
* Writes a line to this Filesystem.Filestream. Return true if this
* operation succeeds and false otherwise.
* @param {String|Bytes|Number} data The data to write to this Filesystem.Filestream.
* @return {Boolean}
* @member Ti.Filesystem.Filestream
*/
write: function(data){},

/**
* Set the current read/write position with in the file.
* @param {Integer} offset new position relative to the absolute position specifed by the dir parameter
* @param {Integer} dir specifies an absolute position in the file where offset will be applied
* @return {void}
* @member Ti.Filesystem.Filestream
*/
seek: function(offset, dir){},

/**
* Writes a line to this Filesystem.Filestream. The data will be followed
* by the platform dependent line-ending sequence. Return true if this
* operation succeeds and false otherwise.
* @param {String|Bytes|Number} data The data to write to this Filesystem.Filestream.
* @return {Boolean}
* @member Ti.Filesystem.Filestream
*/
writeLine: function(data){}}


/**
* A module for accessing the Filesystem.
* @class Ti.Filesystem
* @singleton
* @member Ti
*/
Ti.Filesystem = {
/**
* Executes an asynchronous copy operation and returns an AsyncCopy object.
* @param {Array<String|Filesystem.File>|String|Filesystem.File} paths The source paths to include in the copy operation.
* @param {Filesystem.File|String} destination A path or a File object representing the destination directory of the asynchronous copy.
* @return {Ti.Filesystem.AsyncCopy}
* @member Ti.Filesystem
*/
asyncCopy: function(paths, destination){},

/**
* Create an temporary file. This file is guaranteed to be
* writable. If it still exists when the application exits, it
* will be deleted.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
createTempFile: function(){},

/**
* Create a temporary directory. This directory is guaranteed to be
* writable. If it still exists when the application exits, it
* will be deleted.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
createTempDirectory: function(){},

/**
* Return the data directory of the application. The data directory is per-user
* directory for storing application data. It is guaranteed to be writable and
* stable between releases.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
getApplicationDataDirectory: function(){},

/**
* Return the Desktop directory for the current user. OS X and Windows will
* always have a valid Desktop directory. Some Linux systems may not have one,
* in which case the home directory will be returned.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
getDesktopDirectory: function(){},

/**
* Return the documents directory for the current user. OS X and Windows will
* always have a valid Documents directory. Some Linux systems may not have one,
* in which case the home directory will be returned.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
getDocumentsDirectory: function(){},

/**
* Return the directory containing the application. The application directory
* may contain the application contents directory (OS X) or be the application
* contents directory (Windows and Linux). The application directory may not
* be writable and applications should not attempt to write to it.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
getApplicationDirectory: function(){},

/**
* Create a Filesystem.Filestream object given a Filesystem.File or a path.
* Filesystem.Filestream is the preferred way of writing to files.
* @param {Filesystem.File|String} file A file or path used for the construction of this Filesystem.Filestream.
* @return {Ti.Filesystem.Filestream}
* @member Ti.Filesystem
*/
getFileStream: function(file){},

/**
* Return the line ending most commonly used by the current operating system.
* This is useful for writing files with the platform compatibility in mind.
* File.Filestream.writeLine will use this value when completing lines.
* @return {String}
* @member Ti.Filesystem
*/
getLineEnding: function(){},

/**
* Create a Filesystem.File object given a variable-length argument list
* of Filesystem.File or a path strings. The list will be joined together
* to form one long path string.
* @param {Filesystem.File|String} base The base to this file. This may be a file or directory.
* @param {Filesystem.File|String} multiple (optional) A variable length argument list of Files or paths that are joined to the base in an platform-specific way.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
getFile: function(base, multiple){},

/**
* Return the directory commonly used for storing applications on this
* platform. On Linux systems, there can be many places for storing
* executables, so it is not recommended using this value to locate them.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
getProgramsDirectory: function(){},

/**
* Return the path to this application's resources directory. This diretory
* is the 'Resources' subdirectory of the application contents directory.
* The application directory may not be writable and applications should
* not attempt to write to it.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
getResourcesDirectory: function(){},

/**
* Return the system root directories. On Unix systems there is at
* most one root directory '/' while on Windows active drive letters
* are considered system root directories.
* @return {Ti.Array<Filesystem.File>}
* @member Ti.Filesystem
*/
getRootDirectories: function(){},

/**
* Return the directory of the current Ti runtime files.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
getRuntimeHomeDirectory: function(){},

/**
* A constant representing write mode for file access.
* @property {Number}
* @member Ti.Filesystem
*/
MODE_WRITE: null,

/**
* A constant representing read mode for file access.
* @property {Number}
* @member Ti.Filesystem
*/
MODE_READ: null,

/**
* Return the path separator used by the operating system.
* @return {String}
* @member Ti.Filesystem
*/
getSeparator: function(){},

/**
* A constant representing append mode for file access.
* @property {Number}
* @member Ti.Filesystem
*/
MODE_APPEND: null,

/**
* Return the home directory of the current user.
* @return {Ti.Filesystem.File}
* @member Ti.Filesystem
*/
getUserDirectory: function(){}}


/**
* A module for serializing and deserializing JSON.
* @class Ti.JSON
* @singleton
* @member Ti
*/
Ti.JSON = {
/**
* Deserialize a JSON string into a JavaScript value.
* @param {String} jsonString JSON string to deserialize into a JavaScript object.
* @return {any}
* @member Ti.JSON
*/
parse: function(jsonString){},

/**
* Serialize a JavaScript value into a JSON string.
* @param {any} value The JavaScript value to serialize into a JSON string.
* @return {String}
* @member Ti.JSON
*/
stringify: function(value){}}


/**
* A module for dealing with media.
* @class Ti.Media
* @singleton
* @member Ti
*/
Ti.Media = {
/**
* Factory method for Sound objects, created given a path or a URL to a sound file.
* The types of sound files that can be played depend on the codecs installed on the
* user's system.
* @param {String} path The path or url to the sound file to play.
* @return {Ti.Media.Sound}
* @member Ti.Media
*/
createSound: function(path){},

/**
* Activate the system bell. Some systems may have disabled the system bell.
* @return {String}
* @member Ti.Media
*/
beep: function(){}}


/**
* An object allowing for loading simple sounds and simple types of playback.
* @class Ti.Media.Sound
* @member Ti.Media
*/
Ti.Media.Sound = {
/**
* Return the current volume of this Media.Sound object. Volume
* values will be between 0.0 and 1.0.
* @return {Number}
* @member Ti.Media.Sound
*/
getVolume: function(){},

/**
* Return true if this Media.Sound is set to loop and false otherwise.
* @return {Boolean}
* @member Ti.Media.Sound
*/
isLooping: function(){},

/**
* Return true if this Media.Sound is paused and false otherwise.
* @return {Boolean}
* @member Ti.Media.Sound
*/
isPaused: function(){},

/**
* Return true if this Media.Sound is playing and false otherwise.
* @return {Boolean}
* @member Ti.Media.Sound
*/
isPlaying: function(){},

/**
* Pause a currently playing sound.
* @return {void}
* @member Ti.Media.Sound
*/
pause: function(){},

/**
* Set a callback to invoke once this sound is finished playing. If
* the sound is looping, this callback will be invoked after each
* iteration of the loop. Passing null as the argument to this function
* will unset the onComplete callback.
* @param {Function|null} callback The new callback function or null to unset it.
* @return {void}
* @member Ti.Media.Sound
*/
onComplete: function(callback){},

/**
* Play a sound object. If the sound is paused, it will resume from the current location.
* @return {void}
* @member Ti.Media.Sound
*/
play: function(){},

/**
* Reload this sound from the original URL or path.
* @return {void}
* @member Ti.Media.Sound
*/
reload: function(){},

/**
* Set whether or not this sound should loop.
* @param {Boolean} looping True if the sound should loop, false otherwise.
* @return {void}
* @member Ti.Media.Sound
*/
setLooping: function(looping){},

/**
* Set the volume of this sound. Sound volumes should be between
* 0.0 and 1.0. Values outside of this range will be clipped to
* 0.0 or 1.0.
* @param {Number} volume The new volume value of the sound between 0.0 to 1.0
* @return {void}
* @member Ti.Media.Sound
*/
setVolume: function(volume){},

/**
* Stop a currently playing sound.
* @return {void}
* @member Ti.Media.Sound
*/
stop: function(){}}


/**
* An object representing a host on the network.
* 
* The following code shows some uses of the Ti.Network.Host object.    
*
*		var localhost = Ti.Network.getHostByAddress('127.0.0.1');
*		
*		localhost.isInvalid(); //returns true if the host is valid and on the network. 
*		localhost.getAliases(); //returns an array of all aliases for the host defined by the address above. 
*		
*
* @class Ti.Network.Host
* @member Ti.Network
*/
Ti.Network.Host = {
/**
* Returns the list of address for a Host object
* @return {Ti.Array<Network.IPAddress>}
* @member Ti.Network.Host
*/
getAddresses: function(){},

/**
* Returns the list of aliases for a Host object
* @return {Array<String>}
* @member Ti.Network.Host
*/
getAliases: function(){},

/**
* Return the hostname of a Host object
* @return {String}
* @member Ti.Network.Host
*/
getName: function(){},

/**
* Checks whether the Host object is invalid
* @return {Boolean}
* @member Ti.Network.Host
*/
isInvalid: function(){}}


/**
* An HTTPClient which can be used as an alternative to XMLHttpRequest.    
* The HTTPClient module is used for making HTTP requests.    
* A simple 'GET' request has been shown below.    
*		
*		//Request URL
*		var url = 'http://mywebsite.com/api/users/';
*		//Create the HTTP Client
*		var client = Ti.Network.createHTTPClient({
*			onload: function(e) {
*				//request complete do something with data
*				//assuming that we are not working with XML
*				Ti.API.INFO('Response received '+this.responseText);
*			},
*			onerror: function(e) {
*				//error received, do something
*			}
*		});
*
*		//Specify request type and open 
*		client.open('GET',url);
*		//Send request
*		client.send();
*
* @class Ti.Network.HTTPClient
* @member Ti.Network
*/
Ti.Network.HTTPClient = {
/**
* Aborts an in progress connection
* @return {String}
* @member Ti.Network.HTTPClient
*/
abort: function(){},

/**
* Clear any cookies set on the request
* @return {String}
* @member Ti.Network.HTTPClient
*/
clearCookies: function(){},

/**
* Whether an HTTPClient object is connected or not
* @property {String}
* @member Ti.Network.HTTPClient
*/
connected: null,

/**
* Amount of data received from server so far. Updated on HTTP_DATA_RECEIVED event.
* @property {String}
* @member Ti.Network.HTTPClient
*/
dataReceived: null,

/**
* Amount of data sent to server so far. Updated on HTTP_DATA_SENT event.
* @property {String}
* @member Ti.Network.HTTPClient
*/
dataSent: null,

/**
* The DONE readyState property
* @property {String}
* @member Ti.Network.HTTPClient
*/
DONE: null,

/**
* Get a HTTP cookie from the response.
* @param {String} name name of the cookie to get
* @return {Ti.Network.HTTPCookie}
* @member Ti.Network.HTTPClient
*/
getCookie: function(name){},

/**
* "Return the value of a response header, given it's name. If the given name occurs multiple times, this method will only return one occurence."
* @param {String} name The response header name.
* @return {String}
* @member Ti.Network.HTTPClient
*/
getResponseHeader: function(name){},

/**
* Get the maximum number of redirects to follow. The default is -1, which means that there is no maximum limit to the number of redirects to follow.
* @return {Number}
* @member Ti.Network.HTTPClient
*/
getMaxRedirects: function(){},

/**
* Return all response headers as an array of two element arrays.
* @return {Array<Array<String, String>>}
* @member Ti.Network.HTTPClient
*/
getResponseHeaders: function(){},

/**
* Return the current timeout setting of this Network.HTTPClient
* object in milliseconds. Thie value may be -1 to indicate no
* timeout. The default timeout value is five minutes.
* @return {Number}
* @member Ti.Network.HTTPClient
*/
getTimeout: function(){},

/**
* The HEADERS_RECEIVED readyState property
* @property {String}
* @member Ti.Network.HTTPClient
*/
HEADERS_RECEIVED: null,

/**
* The LOADING readyState property
* @property {String}
* @member Ti.Network.HTTPClient
*/
LOADING: null,

/**
* The handler function that will be fired as stream data is received from an HTTP request
* @property {String}
* @member Ti.Network.HTTPClient
*/
ondatastream: null,

/**
* The handler function that will be fired when request is completed
* @property {String}
* @member Ti.Network.HTTPClient
*/
onload: null,

/**
* The handler function that will be fired when the readyState code of an HTTPClient object changes.
* @property {String}
* @member Ti.Network.HTTPClient
*/
onreadystatechange: null,

/**
* The handler function that will be fired as the stream data is sent.
* @property {String}
* @member Ti.Network.HTTPClient
*/
onsendstream: null,

/**
* Opens an HTTP connection
* @param {String} method The HTTP method to use e.g. POST
* @param {String} url The url to connect to
* @param {Boolean} asynchronous "(optional) Whether or not the request should be asynchronous (default: True)"
* @param {String} username (optional) The HTTP username to use
* @param {String} password (optional) The HTTP password to use
* @return {Boolean}
* @member Ti.Network.HTTPClient
*/
open: function(method, url, asynchronous, username, password){},

/**
* The OPENED readyState property
* @property {String}
* @member Ti.Network.HTTPClient
*/
OPENED: null,

/**
* The ready-state status for the connection
* @property {String}
* @member Ti.Network.HTTPClient
*/
readyState: null,

/**
* Sends a request to the server and receive data with the provided handler.
* @param {Object|Function} handler A handler to receive the response data. handler can either be Ti.Filesystem.File or a Function.
* @param {Object|String|null} data (optional) Data to send to the server.
* @return {Boolean}
* @member Ti.Network.HTTPClient
*/
receive: function(handler, data){},

/**
* The response of an HTTP request as a Bytes. Currently this property is only valid after the request has been completed.
* @property {String}
* @member Ti.Network.HTTPClient
*/
responseData: null,

/**
* The response of an HTTP request as text
* @property {String}
* @member Ti.Network.HTTPClient
*/
responseText: null,

/**
* The response of an HTTP request as parsable XML
* @property {String}
* @member Ti.Network.HTTPClient
*/
responseXML: null,

/**
* Sends data through the HTTP connection
* @param {Object|String|null} data (optional) Data to send to the server.
* @return {Boolean}
* @member Ti.Network.HTTPClient
*/
send: function(data){},

/**
* Sends the contents of a file as body content
* @param {Ti.Filesystem.File} file the File object to send
* @return {String}
* @member Ti.Network.HTTPClient
*/
sendFile: function(file){},

/**
* Set the basic authentication credentials
* @param {String} username The username to use or an empty String to use none.
* @param {String} password The password to use or an empty String to use none.
* @return {String}
* @member Ti.Network.HTTPClient
*/
setBasicCredentials: function(username, password){},

/**
* Set a HTTP cookie in the request.
* @param {String} name the cookie name
* @param {String} value the cookie value
* @return {String}
* @member Ti.Network.HTTPClient
*/
setCookie: function(name, value){},

/**
* Set the authentication credentials for the HTTPClient.
* @param {String} username The username to use or an empty String to use none.
* @param {String} password The password to use or an empty String to use none.
* @return {String}
* @member Ti.Network.HTTPClient
*/
setCredentials: function(username, password){},

/**
* Set the maximum number of redirects to follow. The default is -1, which means that there is no maximum limit to the number of redirects to follow.
* @param {Number} amount the number of redirects to follow.
* @return {String}
* @member Ti.Network.HTTPClient
*/
setMaxRedirects: function(amount){},

/**
* Sets a request header for the connection
* @param {String} header request header name
* @param {String} value request header value
* @return {String}
* @member Ti.Network.HTTPClient
*/
setRequestHeader: function(header, value){},

/**
* Set the timeout setting of this Network.HTTPClient.
* Thie value may be -1 to indicate no timeout. The default
* timeout value is five minutes.
* @param {Number} timeout The new timeout value in milliseconds.
* @return {String}
* @member Ti.Network.HTTPClient
*/
setTimeout: function(timeout){},

/**
* The response status code of an HTTP request
* @property {String}
* @member Ti.Network.HTTPClient
*/
status: null,

/**
* The response status text of an HTTP Request
* @property {String}
* @member Ti.Network.HTTPClient
*/
statusText: null,

/**
* True if HTTP request timed out
* @property {String}
* @member Ti.Network.HTTPClient
*/
timedOut: null,

/**
* The UNSENT readyState property.
* @property {String}
* @member Ti.Network.HTTPClient
*/
UNSENT: null,

/**
* The request URL. This value will be updated on redirect events.
* @property {String}
* @member Ti.Network.HTTPClient
*/
url: null,

/**
* "User agent string to use for requests. (Default: Ti.userAgent)"
* @property {String}
* @member Ti.Network.HTTPClient
*/
userAgent: null}


/**
* An object representing an HTTP cookie.
* @class Ti.Network.HTTPCookie
* @member Ti.Network
*/
Ti.Network.HTTPCookie = {
/**
* Get the cookie comment text
* @return {String}
* @member Ti.Network.HTTPCookie
*/
getComment: function(){},

/**
* Get the domain for which the cookie is valid
* @return {String}
* @member Ti.Network.HTTPCookie
*/
getDomain: function(){},

/**
* Get the lifetime of the cookie, in seconds.
* @return {Integer}
* @member Ti.Network.HTTPCookie
*/
getMaxAge: function(){},

/**
* Get the cookie name
* @return {String}
* @member Ti.Network.HTTPCookie
*/
getName: function(){},

/**
* Get the subset of URLs to which this cookie applies
* @return {String}
* @member Ti.Network.HTTPCookie
*/
getPath: function(){},

/**
* Get the cookie value
* @return {String}
* @member Ti.Network.HTTPCookie
*/
getValue: function(){},

/**
* Identifies to which version of the state management specification the cookie conforms. 0 = netscape 1 = RFC2109
* @return {Integer}
* @member Ti.Network.HTTPCookie
*/
getVersion: function(){},

/**
* Check if the http only flag is set on the cookie
* @return {Boolean}
* @member Ti.Network.HTTPCookie
*/
isHTTPOnly: function(){},

/**
* Check if the secure flag is set on the cookie
* @return {Boolean}
* @member Ti.Network.HTTPCookie
*/
isSecure: function(){},

/**
* Set the cookie comment text
* @param {String} comment text to set as comment
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setComment: function(comment){},

/**
* Set the domain for which the cookie is valid
* @param {String} domain the domain to set
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setDomain: function(domain){},

/**
* Set the http only flag on the cookie
* @param {Boolean} enableHTTPOnly if True sets the http only flag
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setHTTPOnly: function(enableHTTPOnly){},

/**
* Set the lifetime of the cookie, in seconds.
* @param {Integer} lifetime the lifetime in seconds. 0 = discard, -1 = never expire
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setMaxAge: function(lifetime){},

/**
* Set the cookie name
* @param {String} name name of the cookie
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setName: function(name){},

/**
* Set the subset of URLs to which this cookie applies
* @param {String} path the path to set
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setPath: function(path){},

/**
* Set the secure flag on the cookie
* @param {Boolean} enableSecure if True makes the cookie secure
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setSecure: function(enableSecure){},

/**
* "Set the state management specifiction version the cookie conforms. (Default: 0)"
* @param {Integer} version cookie version (0 or 1)
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setVersion: function(version){},

/**
* Set the cookie value
* @param {String} value value to set cookie
* @return {String}
* @member Ti.Network.HTTPCookie
*/
setValue: function(value){}}


/**
* An implementation of an HTTPServer.
*
* The HTTPServer module can assist you in creating a HTTP Server.    
* Refer to the code example below:     
*		
*		//Create the HTTPServer object
*		var server = Ti.Network.createHTTPServer();
*
*		//Specify port number and callback function
*		//This example can be tested by pointing your
*		//browser to http://localhost:8082/
*		
*		server.bind(8082,'localhost',function(request,response) {
*			//Data to output
*			var data = '<p>Hello World!</p>';
*			
*			//Setting content type of the response
*			response.setContentType('text/plain');
*			
*			//Setting content length of the response
*			response.setContentLength(data.length);
*			
*			//Setting status and reason
*			response.setStatusAndReason('200','OK');
*			
*			//Finally writing the response back	
*			response.write(data);
*		});     
*                  
*
*
* @class Ti.Network.HTTPServer
* @member Ti.Network
*/
Ti.Network.HTTPServer = {
/**
* bind this server to a port on a specific interface
* @param {Number} port port to bind on
* @param {String} address (optional) address to bind to
* @param {Method} callback callback for server logic (in seperate thread)
* @return {String}
* @member Ti.Network.HTTPServer
*/
bind: function(port, address, callback){},

/**
* close this server
* @return {String}
* @member Ti.Network.HTTPServer
*/
close: function(){},

/**
* check to see if this server socket is closed
* @return {Boolean}
* @member Ti.Network.HTTPServer
*/
isClosed: function(){}}


/**
* An object representing a single HTTP server request.
* @class Ti.Network.HTTPServerRequest
* @member Ti.Network
*/
Ti.Network.HTTPServerRequest = {
/**
* the content length of this request
* @return {Number}
* @member Ti.Network.HTTPServerRequest
*/
getContentLength: function(){},

/**
* get an HTTP header value from this request
* @param {String} header the header of the request
* @param {String} header the header of the request
* @return {String}
* @member Ti.Network.HTTPServerRequest
*/
getHeader: function(header, header){},

/**
* get the content type of this request
* @return {String}
* @member Ti.Network.HTTPServerRequest
*/
getContentType: function(){},

/**
* get the HTTP method of this request
* @return {String}
* @member Ti.Network.HTTPServerRequest
*/
getMethod: function(){},

/**
* get an HTTP header value from this request
* @return {String}
* @member Ti.Network.HTTPServerRequest
*/
getHeaders: function(){},

/**
* get the HTTP version of this request
* @return {String}
* @member Ti.Network.HTTPServerRequest
*/
getVersion: function(){},

/**
* read content from this request
* @param {Number} length (optional) the number of bytes to read (default 8096)
* @return {String}
* @member Ti.Network.HTTPServerRequest
*/
read: function(length){},

/**
* check to see if this request has an HTTP header
* @param {String} header the header of the request to check
* @return {Boolean}
* @member Ti.Network.HTTPServerRequest
*/
hasHeader: function(header){},

/**
* get the URI of this request
* @return {String}
* @member Ti.Network.HTTPServerRequest
*/
getURI: function(){}}


/**
* An object representing a single HTTP server response.
* @class Ti.Network.HTTPServerResponse
* @member Ti.Network
*/
Ti.Network.HTTPServerResponse = {
/**
* add a cookie to this response
* @param {String} name the cookie name
* @param {String} value the cookie value
* @param {Number} maxAge "(optional) the cookie's maximum age"
* @param {String} domain "(optional) the cookie's domain"
* @param {String} path "(optional) the cookie's path"
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
addCookie: function(name, value, maxAge, domain, path){},

/**
* set the content length of this response
* @param {Number} length the content length, i.e 100
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setContentLength: function(length){},

/**
* set the content type of this response
* @param {String} type "the content type, i.e \"text/plain\""
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setContentType: function(type){},

/**
* set an HTTP header of this response
* @param {String} name the header name
* @param {String} value the header value
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setHeader: function(name, value){},

/**
* set the reason of this response
* @param {String} reason "the reason, i.e \"OK\""
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setReason: function(reason){},

/**
* set the status of this response
* @param {String} status "the status, i.e \"200\""
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setStatus: function(status){},

/**
* set the status and reason of this response
* @param {String} status "the status, i.e \"200\""
* @param {String} reason "the reason, i.e \"OK\""
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
setStatusAndReason: function(status, reason){},

/**
* write content into this response
* @param {String} data content to write (can be string or bytes content)
* @return {String}
* @member Ti.Network.HTTPServerResponse
*/
write: function(data){}}


/**
* No description provided.
* @class Ti.Network.Interface
* @member Ti.Network
*/
Ti.Network.Interface = {
/**
* Return the display name of this interface.
* @return {String}
* @member Ti.Network.Interface
*/
getDisplayName: function(){},

/**
* Return the IP addresso of this interface.
* @return {Ti.Network.IPAddress}
* @member Ti.Network.Interface
*/
getIPAddress: function(){},

/**
* Get the name of this interface.
* @return {String}
* @member Ti.Network.Interface
*/
getName: function(){},

/**
* Return the subnet mask of this interface as a Network.IPAddress object.
* @return {Ti.Network.IPAddress}
* @member Ti.Network.Interface
*/
getSubnetMask: function(){},

/**
* Return true if this interface supports IPv4 and false otherwise.
* @return {Boolean}
* @member Ti.Network.Interface
*/
supportsIPv4: function(){},

/**
* Return true if this interface supports IPv6 and false otherwise.
* @return {Boolean}
* @member Ti.Network.Interface
*/
supportsIPv6: function(){}}


/**
* An object representing an IP address.
* @class Ti.Network.IPAddress
* @member Ti.Network
*/
Ti.Network.IPAddress = {
/**
* Check whether an IPAddress object is a broadcast address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isBroadcast: function(){},

/**
* Check whether an IPAddress object is a global multicast address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isGlobalMC: function(){},

/**
* Check whether an IPAddress object is invalid.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isInvalid: function(){},

/**
* Check whether an IPAddress object is an IPv6 address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isIPV6: function(){},

/**
* Check whether an IPAddress object is an IPv4 address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isIPV4: function(){},

/**
* Check whether an IPAddress object is a link-local address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isLinkLocal: function(){},

/**
* Check whether an IPAddress object is a link-local multicast address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isLinkLocalMC: function(){},

/**
* Check whether an IPAddress object is a loopback address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isLoopback: function(){},

/**
* Check whether an IPAddress object is a multicast address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isMulticast: function(){},

/**
* Check whether an IPAddress object is a node-local multicast address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isNodeLocalMC: function(){},

/**
* Check whether an IPAddress object is an organization local multicast address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isOrgLocalMC: function(){},

/**
* Check whether an IPAddrss object is a site-local address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isSiteLocal: function(){},

/**
* Check whether an IPAddress object is a site-local multicast address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isSiteLocalMC: function(){},

/**
* Check whether an IPAddress object is a well-known multicast address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isWellKnownMC: function(){},

/**
* Check whether an IPAddress object is a wildcard address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isWildcard: function(){},

/**
* Check whether an IPAddress object is a unicast address.
* @return {Boolean}
* @member Ti.Network.IPAddress
*/
isUnicast: function(){}}


/**
* An object representing an IRC client connection. [DEPRECATED]
* @class Ti.Network.IRCClient
* @member Ti.Network
*/
Ti.Network.IRCClient = {
/**
* Connects an IRC to the host specified during creation of the IRCClient object
* @param {String} hostname the hostname
* @param {Number} port the port
* @param {String} nick the users nickname
* @param {String} name the users full name
* @param {String} user the users login name
* @param {String} pass the users password
* @param {Function} callback a callback function to recieve IRC events.
* @return {String}
* @member Ti.Network.IRCClient
*/
connect: function(hostname, port, nick, name, user, pass, callback){},

/**
* Disconnects an IRC connection
* @return {String}
* @member Ti.Network.IRCClient
*/
disconnect: function(){},

/**
* Returns the nick name for the connection
* @return {String}
* @member Ti.Network.IRCClient
*/
getNick: function(){},

/**
* Returns a list of users for the channel
* @return {Array<String>}
* @member Ti.Network.IRCClient
*/
getUsers: function(){},

/**
* Checks whether a user has OP status
* @return {Boolean}
* @member Ti.Network.IRCClient
*/
isOp: function(){},

/**
* Checks whether a user has VOICE status
* @return {Boolean}
* @member Ti.Network.IRCClient
*/
isVoice: function(){},

/**
* Joins a channel
* @param {String} channel channel to join to
* @return {String}
* @member Ti.Network.IRCClient
*/
join: function(channel){},

/**
* Sends data to the IRC connection
* @param {String} channel the channel to send the data to
* @param {String} message message to send
* @return {String}
* @member Ti.Network.IRCClient
*/
send: function(channel, message){},

/**
* Sets the nick name for the connection
* @param {String} nick nickname to use
* @return {String}
* @member Ti.Network.IRCClient
*/
setNick: function(nick){},

/**
* The connected property of an IRCClient object
* @property {String}
* @member Ti.Network.IRCClient
*/
connected: null,

/**
* Leaves a channel
* @param {String} channel channel to leave
* @return {String}
* @member Ti.Network.IRCClient
*/
unjoin: function(channel){}}


/**
* A module for network functionality.
* @class Ti.Network
* @singleton
* @member Ti
*/
Ti.Network = {
/**
* Adds a connectivity change listener that fires when the system connects or disconnects from the internet
* @return {Number}
* @member Ti.Network
*/
addConnectivityListener: function(){},

/**
* Creates an HTTPClient object
* @return {Ti.Network.HTTPClient}
* @member Ti.Network
*/
createHTTPClient: function(){},

/**
* Creates a new HTTPCookie object
* @return {Ti.Network.HTTPCookie}
* @member Ti.Network
*/
createHTTPCookie: function(){},

/**
* Creates an HTTPServer object
* @return {Ti.Network.HTTPServer}
* @member Ti.Network
*/
createHTTPServer: function(){},

/**
* Creates an IPAddress object
* @param {String} address the IP address
* @return {Ti.Network.IPAddress}
* @member Ti.Network
*/
createIPAddress: function(address){},

/**
* Creates an IRCClient object [DEPRECATED]
* @return {Ti.Network.IRCClient}
* @member Ti.Network
*/
createIRCClient: function(){},

/**
* Creates a TCPSocket object
* @param {String} host the hostname to connect to
* @param {Number} port the port to use
* @return {Ti.Network.TCPSocket}
* @member Ti.Network
*/
createTCPSocket: function(host, port){},

/**
* Encodes a URI Component
* @param {String} value value to encode
* @return {String}
* @member Ti.Network
*/
encodeURIComponent: function(value){},

/**
* Decodes a URI component
* @param {String} value value to decode
* @return {String}
* @member Ti.Network
*/
decodeURIComponent: function(value){},

/**
* Return the first IPv4 address in this system's list of interfaces.
* @return {String}
* @member Ti.Network
*/
getFirstIPAddress: function(){},

/**
* Return the first MAC address in this system's list of interfaces.
* @return {String
paramters: }
* @member Ti.Network
*/
getFirstMACAddress: function(){},

/**
* Returns a Host object using an address
* @param {String} address the address
* @return {Ti.Network.Host}
* @member Ti.Network
*/
getHostByAddress: function(address){},

/**
* Returns a Host object using a hostname
* @param {String} name the hostname
* @return {Ti.Network.Host}
* @member Ti.Network
*/
getHostByName: function(name){},

/**
* Return the proxy override, if one is set.
* @return {String|null}
* @member Ti.Network
*/
getHTTPSProxy: function(){},

/**
* Return a list of network interfaces on this system.
* @return {Ti.Array<Network.Interface>}
* @member Ti.Network
*/
getInterfaces: function(){},

/**
* Return the proxy override, if one is set.
* @return {String|null}
* @member Ti.Network
*/
getHTTPProxy: function(){},

/**
* Note: this is deprecated and only returns true starting in 1.2.
* @property {Boolean}
* @member Ti.Network
*/
online: null,

/**
* Removes a connectivity change listener
* @param {Number} id the callback id of the method
* @return {String}
* @member Ti.Network
*/
removeConnectivityListener: function(id){},

/**
* Override application proxy autodetection with a proxy URL.
* @param {String} hostname The full proxy hostname.
* @return {String}
* @member Ti.Network
*/
setHTTPProxy: function(hostname){},

/**
* Override application proxy autodetection with a proxy URL.
* @param {String} hostname The full proxy hostname.
* @return {String}
* @member Ti.Network
*/
setHTTPSProxy: function(hostname){}}


/**
* An object representing a TCP client socket connection.
* A simple implementation of connecting to a host has been shown below. 
*		//Create the connection.
*		var socket = Ti.Network.createTCPSocket("127.0.0.1", 8080);
*		socket.connect();
*
*		//The onReadComplete function below ensures that the
*		//read operation is completed and all bytes have been received.
*
*		socket.onReadComplete(function(data) {
*            alert(data);
*        });    
*
* @class Ti.Network.TCPSocket
* @member Ti.Network
*/
Ti.Network.TCPSocket = {
/**
* Close this Network.TCPSocket connection. If there is no open
* connection then do nothing. Return true if the connection was
* closed and false otherwise.
* @return {Boolean}
* @member Ti.Network.TCPSocket
*/
close: function(){},

/**
* Connect the Socket object to the host specified during creation. The connection will be made asynchronously. Use onError to detect failures.
* @return {String}
* @member Ti.Network.TCPSocket
*/
connect: function(){},

/**
* Check whether the Socket is closed.
* @return {Boolean}
* @member Ti.Network.TCPSocket
*/
isClosed: function(){},

/**
* Set the callback that will be fired when the Socket encounters an error.
* @param {Function} onError Function to be called when an error happens.
* @return {String}
* @member Ti.Network.TCPSocket
*/
onError: function(onError){},

/**
* Set a callback that will be fired when data is received on the Socket.
* @param {Function} onRead Function to be called when data is received.
* @return {String}
* @member Ti.Network.TCPSocket
*/
onRead: function(onRead){},

/**
* Set the callback function that will be fired when a read finishes. A read is considered finished if some bytes have been read and a subsequent call to read returns zero bytes.
* @param {Function} onReadComplete Function be called when a read completes.
* @return {String}
* @member Ti.Network.TCPSocket
*/
onReadComplete: function(onReadComplete){},

/**
* Set the callback that will be fired when an operation times out on the Socket.
* @param {Function} onTimeout Function to be called when an operation times out.
* @return {String}
* @member Ti.Network.TCPSocket
*/
onTimeout: function(onTimeout){},

/**
* Set a callback that will be fired when data is written on the Socket.
* @param {Function} onWrite Function to be called when data is written.
* @return {String}
* @member Ti.Network.TCPSocket
*/
onWrite: function(onWrite){},

/**
* "Write data to the Socket's connection, if open."
* @param {String} data The data to write to the connection.
* @return {Boolean}
* @member Ti.Network.TCPSocket
*/
write: function(data){}}


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


/**
* A module for creating processes.
* A simple example for process creation can be seen below:
*
*		//Following code executes a python script located in
*		//the resources folder.
*
*		var myScript = Ti.Process.createProcess({
*                args:['python',Ti.API.application.resourcesPath + "/myScript.py"]
*        });
*		
*		//Launches the process	
*       myScript.launch();
*
* 		
* @class Ti.Process
* @singleton
* @member Ti
*/
Ti.Process = {
/**
* Create a Process object. There are two main ways to use this function:
* <pre><code>
* Ti.Process.createProcess({
* args: ['mycmd', 'arg1', 'arg2'],
* env: {'PATH': '/something'},
* stdin: pipeIn,
* stdout: pipeOut,
* stderr: pipeErr
* });
* </code></pre>
* <pre><code>
* Ti.Process.createProcess(args, environment, stdin, stdout, stderr);
* </code></pre>
* @param {Array|Object} args Either a list of command-line arguments to use for this process invocation (including the executable path) or an object describing all parameters of this Process object (see above).
* @param {Object} envionment (optional) An object representing the environment to pass to this process.
* @param {Process.Pipe} pipeIn (optional) A Process.Pipe object which the new process should use for receiving input.
* @param {Process.Pipe} pipeOut (optional) A Process.Pipe object which the new process should use for sending output.
* @param {Process.Pipe} pipeErr (optional) A Process.Pipe object which the new process should use for sending error output.
* @return {Ti.Process.Process}
* @member Ti.Process
*/
createProcess: function(args, envionment, pipeIn, pipeOut, pipeErr){},

/**
* Create a pipe for attaching to/from any number of processes.
* @return {Ti.Process.Pipe}
* @member Ti.Process
*/
createPipe: function(){},

/**
* This method is deprecated. See Process.Process.createProcess()
* @param {String} command The command to launch
* @param {Array<String>} arguments A list of arguments to the command
* @return {String}
* @member Ti.Process
*/
launch: function(command, arguments){},

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGCHLD: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGEMT: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGFPE: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGHUP: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGILL: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGINFO: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGINT: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGIO: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGKILL: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGPIPE: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGPROF: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGQUIT: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGSEGV: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGSTOP: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGSYS: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGTERM: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGTRAP: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGTSTP: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGTTOU: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGURG: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGUSR1: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGTTIN: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGUSR2: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGVTALRM: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGXCPU: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGXFSZ: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGALRM: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGABRT: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGBUS: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGWINCH: null}


/**
* An object representing an IO pipe.
* An IO Pipe helps in reading data from an input stream, processing
* this data and then writing this to an output stream.  
*      
* This can be demonstrated with the example below.     
*		
* 		var echoCmd = Ti.platform === "win32" ? ["C:\\Windows\\System32\\cmd.exe", "/C", "echo"] : ["/bin/echo"];
*	
* 		echoCmd.push("Data.from.echo!");
*
* 		var moreCmd = Ti.platform === "win32" ? ["C:\\Windows\\System32\\more.com"] : ["cat"];
*
* 		// Create the processes.
* 		var echo = Ti.Process.createProcess(echoCmd);
* 		var more = Ti.Process.createProcess(moreCmd);
*		
*			//Code for displaying the data received by the 'more' process.
* 		more.setOnReadLine(function(data) {
* 		 	alert(data.toString());
* 		});
*
* 		//Attaching the processes through IO pipes below.
* 		echo.stdout.attach(more.stdin);
*			//Launching Processes.
* 		echo.launch();
* 		more.launch();     
*
*
* @class Ti.Process.Pipe
* @member Ti.Process
*/
Ti.Process.Pipe = {
/**
* "Attach an IO object to this pipe. An IO object is an object that implements a public \"write(Bytes)\". In Ti, this include FileStreams, and Pipes. You may also use your own custom IO implementation here."
* @return {String}
* @member Ti.Process.Pipe
*/
attach: function(){},

/**
* Close this pipe to further reading/writing.
* @return {String}
* @member Ti.Process.Pipe
*/
close: function(){},

/**
* Detach an IO object from this pipe. see Process.Pipe.attach.
* @return {String}
* @member Ti.Process.Pipe
*/
detach: function(){},

/**
* 
* @return {bool}
* @member Ti.Process.Pipe
*/
isAttached: function(){},

/**
* Write data to this pipe
* @param {Bytes|String} data a Bytes object or String to write to this pipe
* @return {Number}
* @member Ti.Process.Pipe
*/
write: function(data){}}


/**
* An object representing a process instance.
* @class Ti.Process.Process
* @member Ti.Process
*/
Ti.Process.Process = {
/**
* Return the list of arguments associated with this Process.
* @return {Array<String>}
* @member Ti.Process.Process
*/
getArguments: function(){},

/**
* Return a clone of this process' environment.
* @return {Object, environment}
* @member Ti.Process.Process
*/
cloneEnvironment: function(){},

/**
* Return the environment associated with this process.
* @param {String} key an environment key
* @return {String|Object}
* @member Ti.Process.Process
*/
getEnvironment: function(key){},

/**
* Return the exit code for this process. Before the process exits, this value will be null.
* @return {Number}
* @member Ti.Process.Process
*/
getExitCode: function(){},

/**
* Return the process identifier for this process. Before the process launches, this value will be -1.
* @return {Number}
* @member Ti.Process.Process
*/
getPID: function(){},

/**
* Return the stderr pipe for this process.
* @return {Ti.Process.Pipe}
* @member Ti.Process.Process
*/
getStderr: function(){},

/**
* Return the stdin pipe for this process.
* @return {Ti.Process.Pipe}
* @member Ti.Process.Process
*/
getStdin: function(){},

/**
* Return the stdout pipe for this process.
* @return {Ti.Process.Pipe}
* @member Ti.Process.Process
*/
getStdout: function(){},

/**
* Return true if this process is running and false otherwise.
* @return {Boolean}
* @member Ti.Process.Process
*/
isRunning: function(){},

/**
* Kill this process (SIGINT in Unix, TerminateProcess in Windows)
* @return {String}
* @member Ti.Process.Process
*/
kill: function(){},

/**
* "Launch this process asynchronously (not waiting for it's exit)"
* @return {String}
* @member Ti.Process.Process
*/
launch: function(){},

/**
* "Send a signal (e.g. Process.SIGHUP) to this Process NOTE: this method does nothing in Windows"
* @param {Number|String} signal The name of the signal to send.
* @return {String}
* @member Ti.Process.Process
*/
sendSignal: function(signal){},

/**
* Set an environment variable for this process
* @param {String} key an environment key
* @param {String} value the value
* @return {String}
* @member Ti.Process.Process
*/
setEnvironment: function(key, value){},

/**
* Set an onRead event handler for this process stdout and stderr. This handler will take one argument which is the event for this output. To retrieve event data, simply access <tt>event.data</tt>.
* @param {Function} onRead "a handler that is passed an event, with a \"data\" Bytes full of data read from the pipe"
* @return {String}
* @member Ti.Process.Process
*/
setOnRead: function(onRead){},

/**
* Set an onExit event handler for this process
* @param {Function} onExit a function
* @return {String}
* @member Ti.Process.Process
*/
setOnExit: function(onExit){},

/**
* Set the callback to invoke every time a line of input is received from the process. This callback will take one argument, which will be the line of output.
* @param {Function} fn a callback that is called with every line of output received from this process
* @return {String}
* @member Ti.Process.Process
*/
setOnReadLine: function(fn){},

/**
* Terminate this process (SIGTERM in Unix, TerminateProcess in Windows)
* @return {String}
* @member Ti.Process.Process
*/
terminate: function(){}}


/**
* A module used for accessing clipboard data.    
* Please refer to the code examples below:    
* 	//Code below stores text into the clipboard.    
* 	Ti.UI.Clipboard.setData('text/plain', 'This is my custom text');       
*
*		//Retrieving the stored data.
*	  	Ti.UI.Clipboard.getData('text/plain'); //should return 'This is my custom text'
* 
* Working with text only
* ----------------------
* For setting text/plain data, rather than using the above methods, you may
* use the setText/getText methods.
*
*		Ti.UI.Clipboard.setText('This is my custom text');
*		Ti.UI.Clipboard.getText(); //should return 'This is my custom text'
*
* @class Ti.UI.Clipboard
* @member Ti.UI
*/
Ti.UI.Clipboard = {
/**
* Clear data of the given mime-type from the clipboard. If no mime-type is given, clear all data from the clipboard.
* @param {String} type (optional) The mime-type of the data to clear.
* @return {String}
* @member Ti.UI.Clipboard
*/
clearData: function(type){},

/**
* Clear the text portion of the clipboard.
* @return {String}
* @member Ti.UI.Clipboard
*/
clearText: function(){},

/**
* Get the data on the clipboard from the portion which contains data of the given mime-type.
* @param {String} type The mime-type of the data to get.
* @return {String}
* @member Ti.UI.Clipboard
*/
getData: function(type){},

/**
* Get the current text on the clipboard.
* @return {String}
* @member Ti.UI.Clipboard
*/
getText: function(){},

/**
* Return true if there is any content of the given mime-type on the clipboard.
* @param {String} type (optional) The mime-type of the data to check.
* @return {Boolean}
* @member Ti.UI.Clipboard
*/
hasData: function(type){},

/**
* Return true if there is any content in the text portion of the clipboard.
* @return {Boolean}
* @member Ti.UI.Clipboard
*/
hasText: function(){},

/**
* Set the data on the clipboard given a mime-type and the new data. This method will set data on the appropriate portion of the clipboard for the given mime-type.
* @param {String} type The mime-type of the data to set.
* @param {String} data The new clipboard text.
* @return {String}
* @member Ti.UI.Clipboard
*/
setData: function(type, data){},

/**
* Set the text on the clipboard. This will overwrite the current contents of the clipboard.
* @param {String} newText The new clipboard text. If the text is an empty string, the text portion of the clipboard will be cleared.
* @return {String}
* @member Ti.UI.Clipboard
*/
setText: function(newText){}}


/**
* An object representing a Dialog window.
* @class Ti.UI.Dialog
* @member Ti.UI
*/
Ti.UI.Dialog = {
/**
* Get an incoming UI dialog parameter
* @param {String} name Name of the parameter
* @param {Any} defaultValue Default value of the parameter
* @return {any}
* @member Ti.UI.Dialog
*/
getDialogParameter: function(name, defaultValue){},

/**
* get results from UI dialog
* @return {String}
* @member Ti.UI.Dialog
*/
getDialogResult: function(){}}


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
CENTERED: null,

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


/**
* An object representing a menu.
*
* A Menu object can be added to the current window of a TideSDK application. Menu objects can 
* be made up of a number of MenuItems(see Ti.UI.MenuItem). These menu items can be added to the 
* menu object at anytime and TideSDK will ensure that all menu instances update immediately.     
* 
* Please take a look at the code example below:     
* 
*			//Create the menu object      
* 		var menu = Ti.UI.createMenu;
*			
*			//Create menu items
*			var subMenu1 = Ti.UI.createMenuItem('Menu1');
*			var subMenu2 = Ti.UI.createMenuItem('Menu2');	
*			var subMenu3 = Ti.UI.createMenuItem('Menu3');		
*			
*			//Add the menu items to menu
*			menu.appendItem(subMenu1);
*			menu.appendItem(subMenu2);
*			menu.appendItem(subMenu3);	
*
*			//Add menu to the current window
*			Ti.UI.currentWindow.menu = menu;
*
* @class Ti.UI.Menu
* @member Ti.UI
*/
Ti.UI.Menu = {
/**
* Add a check item to this menu with the given attributes.
* @param {String} label The label for the new item
* @param {Function} listener (optional) An event listener callback for the item
* @return {Ti.UI.MenuItem}
* @member Ti.UI.Menu
*/
addCheckItem: function(label, listener){},

/**
* Add an item to this menu with the given attributes.
* @param {String} label The label for the new item
* @param {Function} listener (optional) An event listener callback for the item
* @param {String} iconURL "The URL for this item's icon"
* @return {Ti.UI.MenuItem}
* @member Ti.UI.Menu
*/
addItem: function(label, listener, iconURL){},

/**
* Append a MenuItem object to a menu.
* @param {UI.MenuItem} item Append an item to this menu
* @return {String}
* @member Ti.UI.Menu
*/
appendItem: function(item){},

/**
* Add a separator item to this menu.
* @return {Ti.UI.MenuItem}
* @member Ti.UI.Menu
*/
addSeparatorItem: function(){},

/**
* Remove all items from this menu.
* @return {String}
* @member Ti.UI.Menu
*/
clear: function(){},

/**
* Get the length of this menu.
* @return {Number}
* @member Ti.UI.Menu
*/
getLength: function(){},

/**
* Insert a menu item before the given index. This method will throw an exception if the index of out of range.
* @param {UI.MenuItem} item The menu item to insert
* @param {Number} index The index for this menu item
* @return {String}
* @member Ti.UI.Menu
*/
insertItemAt: function(item, index){},

/**
* Get an item from this menu at the given index. This method will throw an exception if the index is out of range.
* @param {Number} index The index of the item to get
* @return {Ti.UI.MenuItem}
* @member Ti.UI.Menu
*/
getItemAt: function(index){},

/**
* Remove the item in this menu at the given index. This method will throw an exception if the index is out of range.
* @param {Number} index The index of the item to remove
* @return {String}
* @member Ti.UI.Menu
*/
removeItemAt: function(index){}}


/**
* An object representing a menu item.
* @class Ti.UI.MenuItem
* @member Ti.UI
*/
Ti.UI.MenuItem = {
/**
* "Add a check item to this menu item's submenu with the given attributes. If this menu item does not have a submenu, it will be created. This method is not available for separator items."
* @param {String} label The label for the new item
* @param {Function} listener (optional) An event listener callback for the item
* @return {Ti.UI.MenuItem}
* @member Ti.UI.MenuItem
*/
addCheckItem: function(label, listener){},

/**
* "Add a separator item to this menu item's submenu. If this menu item does not have a submenu, it will be created. This method is not available for separator items."
* @return {Ti.UI.MenuItem}
* @member Ti.UI.MenuItem
*/
addSeparatorItem: function(){},

/**
* Disable this item i.e. make it non-clickable. This method is not available for separator items.
* @return {String}
* @member Ti.UI.MenuItem
*/
disable: function(){},

/**
* Enable this item i.e. make it clickable. This method is not available for separator items.
* @return {String}
* @member Ti.UI.MenuItem
*/
enable: function(){},

/**
* "Get this item's icon URL This method is not available for separator or check items."
* @return {String|null}
* @member Ti.UI.MenuItem
*/
getIcon: function(){},

/**
* This method is only available for check items.
* @param {Boolean} autocheck Whether or not this item should is an autocheck
* @return {String}
* @member Ti.UI.MenuItem
*/
getAutoCheck: function(autocheck){},

/**
* "Get this item's label. This method is not available for separator items."
* @return {String}
* @member Ti.UI.MenuItem
*/
getLabel: function(){},

/**
* Gets the state of this check item This method is only available for check items.
* @return {Boolean}
* @member Ti.UI.MenuItem
*/
getState: function(){},

/**
* "Get this item's submenu. This method is not available for separator items."
* @return {Ti.UI.Menu|null}
* @member Ti.UI.MenuItem
*/
getSubmenu: function(){},

/**
* Return true if this UI.MenuItem is a check menu item or false otherwise.
* @return {Boolean}
* @member Ti.UI.MenuItem
*/
isCheck: function(){},

/**
* This method is not available for separator items.
* @return {Boolean}
* @member Ti.UI.MenuItem
*/
isEnabled: function(){},

/**
* Return true if this UI.MenuItem is seperator menu item or false otherwise.
* @return {Boolean}
* @member Ti.UI.MenuItem
*/
isSeparator: function(){},

/**
* Set whether or not this check item is an autocheck item. An autocheck item (the default) will automatically flip the state of the check on a a click event. Turning off this behavior makes the check item more useful as a radio button. This method is only available for check items.
* @param {Boolean} autocheck Whether or not this item should be an autocheck
* @return {String}
* @member Ti.UI.MenuItem
*/
setAutoCheck: function(autocheck){},

/**
* Set the icon URL for this item This method is not available for separator or check items.
* @param {String|null} iconURL The new icon URL for this item or null to unset it
* @return {String}
* @member Ti.UI.MenuItem
*/
setIcon: function(iconURL){},

/**
* Set the label for this item. This method is not available for separator items.
* @param {String} label The new label for this item
* @return {String}
* @member Ti.UI.MenuItem
*/
setLabel: function(label){},

/**
* Sets the state of this check item This method is only available for check items.
* @param {Boolean} state A True state is checked, while a False state in unchecked
* @return {String}
* @member Ti.UI.MenuItem
*/
setState: function(state){},

/**
* "Set this item's submenu. This method is not available for separator items."
* @param {UI.Menu|null} menu The submenu to use for this item or null to unset it
* @return {String}
* @member Ti.UI.MenuItem
*/
setSubmenu: function(menu){},

/**
* "Add an item to this menu item's submenu with the given attributes. If this menu item does not have a submenu, it will be created. This method is not available for separator items."
* @param {String} label The label for the new item
* @param {Function} listener (optional) An event listener callback for the item
* @param {String} iconURL "The URL for this item's icon"
* @return {Ti.UI.MenuItem}
* @member Ti.UI.MenuItem
*/
addItem: function(label, listener, iconURL){}}


/**
* An object representing a TrayItem in TideSDK.
* @class Ti.UI.Tray
* @member Ti.UI
*/
Ti.UI.Tray = {
/**
* Get the hint for this TrayItem
* @return {String}
* @member Ti.UI.Tray
*/
getHint: function(){},

/**
* Get the icon URL for this TrayItem
* @return {String}
* @member Ti.UI.Tray
*/
getIcon: function(){},

/**
* Get the menu for this TrayItem
* @return {Ti.UI.Menu|null}
* @member Ti.UI.Tray
*/
getMenu: function(){},

/**
* Removes a TrayItem
* @return {String}
* @member Ti.UI.Tray
*/
remove: function(){},

/**
* "Sets a TrayItem's icon"
* @param {String} icon (optional) path to the icon or null to unset
* @return {String}
* @member Ti.UI.Tray
*/
setIcon: function(icon){},

/**
* "Sets a TrayItem's tooltip"
* @param {String} hint (optional) tooltip value or null to unset
* @return {String}
* @member Ti.UI.Tray
*/
setHint: function(hint){},

/**
* Set the menu for this TrayItem
* @param {UI.Menu|null} menu The Menu to use for this TrayItem or null to unset
* @return {String}
* @member Ti.UI.Tray
*/
setMenu: function(menu){}}


/**
* An object representing a top-level TideSDK window.
* @class Ti.UI.UserWindow
* @member Ti.UI
*/
Ti.UI.UserWindow = {
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
* true if this window is a UI Dialog
* @property {Boolean}
* @member Ti.UI.UserWindow
*/
isDialog: null,

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
* @param {UI.Menu|null} menu The Menu object to use as the context menu or null to unset the menu.
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
* @param {UI.Menu|null} menu The Menu object to use as the menu or null to unset the menu.
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
* "Sets a window's transparency value"
* @param {Number} url the transparency value of the window
* @return {String}
* @member Ti.UI.UserWindow
*/
setTransparency: function(url){},

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


/**
* A module for creating Worker threads in TideSDK.
* @class Ti.Worker
* @singleton
* @member Ti
*/
Ti.Worker = {
/**
* Create a worker thread instance.
* @param {String|Function} source Either a JavaScript function (does not support closures), the URL of a JavaScript file, or a string containing JavaScript source.
* @return {Ti.Worker.Worker}
* @member Ti.Worker
*/
createWorker: function(source){}}


/**
* An object representing a TideSDK Worker.
* @class Ti.Worker.Worker
* @member Ti.Worker
*/
Ti.Worker.Worker = {
/**
* "Post a message (async) into the worker thread's queue to be handled by onmessage"
* @param {any} data Any JSON serializable type to pass to the child.
* @return {String}
* @member Ti.Worker.Worker
*/
postMessage: function(data){},

/**
* Start the worker thread
* @return {String}
* @member Ti.Worker.Worker
*/
start: function(){},

/**
* Terminate the worker thread. The thread can be restarted with Worker.start()
* @return {String}
* @member Ti.Worker.Worker
*/
terminate: function(){}}


