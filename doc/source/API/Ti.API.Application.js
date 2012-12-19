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

