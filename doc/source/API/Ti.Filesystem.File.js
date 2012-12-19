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

