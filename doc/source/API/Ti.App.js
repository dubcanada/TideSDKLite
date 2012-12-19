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

