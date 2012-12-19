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

