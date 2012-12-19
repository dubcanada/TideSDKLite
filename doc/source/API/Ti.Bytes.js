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

