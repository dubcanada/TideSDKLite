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

