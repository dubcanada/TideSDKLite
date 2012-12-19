/**
* A module for dealing with Database storage.
* There are two ways to use databases in TideSDK - HTML5 Databases and the TideSDK Database API. Both API's make 
* use of SQLite backends. 
* 
* Opening a Database
* ------------------
* You can open databases in TideSDK using the Ti.Database.open and Ti.Database.openFile methods.
* Using Ti.Database.open will create a database which is WebKit compatible in the same directory.
* (Only if the database file doesn't exist.)
* 	
* 		//Create a database which is WebKit compatible.
* 		var db = Ti.Database.open('customdatabase');
* 
* Alternatively, you can create a database and open it using the Ti.Database.openFile method. This method
* accepts a file path or a Ti.Filesystem.File object.
* 
* 		//Create a database
* 		var db = Ti.Database.openFile(Ti.Filesystem.getFile(
* 									  Ti.Filesystem.getApplicationDataDirectory(), 'customdatabase.db'));	
* 
* Querying Databases
* ------------------
* Please refer to the Ti.Database.DB documentation.
* 
* Note - It is recommended that you store all data in the application data directory and not the application resources
* or contents directory as those may not be writeable.
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

