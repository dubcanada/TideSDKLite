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
* @return {void}
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
* Create a Kroll Bytes object given a String. A Bytes object is a generic
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
* Create a Kroll list given an optional JavaScript array. This method is mainly used for testing.
* @param {Array} toWrap (optional) An Array to wrap in a new KList.
* @return {Array}
* @member Ti.API
*/
createKList: function(toWrap){},

/**
* Create a Kroll method given an existing JavaScript Funtion. This method is mainly used for testing.
* @param {Function} toWrap (optional) A Function to wrap in a new KMethod.
* @return {Function}
* @member Ti.API
*/
createKMethod: function(toWrap){},

/**
* Create a Kroll object given an existing JavaScript Object. This method is mainly used for testing.
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
* @param {String} eventName The event name to remove.
* @param {Function} callback The callback to invoke when upon removing the listener.
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

