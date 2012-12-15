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

