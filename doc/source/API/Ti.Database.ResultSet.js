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

