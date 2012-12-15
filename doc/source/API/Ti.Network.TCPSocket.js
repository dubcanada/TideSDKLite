/**
* An object representing a TCP client socket connection.
* A simple implementation of connecting to a host has been shown below. 
*		//Create the connection.
*		var socket = Ti.Network.createTCPSocket("127.0.0.1", 8080);
*		socket.connect();
*
*		//The onReadComplete function below ensures that the
*		//read operation is completed and all bytes have been received.
*
*		socket.onReadComplete(function(data) {
*            alert(data);
*        });    
*
* @class Ti.Network.TCPSocket
* @member Ti.Network
*/
Ti.Network.TCPSocket = {
/**
* Close this Network.TCPSocket connection. If there is no open
* connection then do nothing. Return true if the connection was
* closed and false otherwise.
* @return {Boolean}
* @member Ti.Network.TCPSocket
*/
close: function(){},

/**
* Connect the Socket object to the host specified during creation. The connection will be made asynchronously. Use onError to detect failures.
* @return {String}
* @member Ti.Network.TCPSocket
*/
connect: function(){},

/**
* Check whether the Socket is closed.
* @return {Boolean}
* @member Ti.Network.TCPSocket
*/
isClosed: function(){},

/**
* Set the callback that will be fired when the Socket encounters an error.
* @param {Function} onError Function to be called when an error happens.
* @return {String}
* @member Ti.Network.TCPSocket
*/
onError: function(onError){},

/**
* Set a callback that will be fired when data is received on the Socket.
* @param {Function} onRead Function to be called when data is received.
* @return {String}
* @member Ti.Network.TCPSocket
*/
onRead: function(onRead){},

/**
* Set the callback function that will be fired when a read finishes. A read is considered finished if some bytes have been read and a subsequent call to read returns zero bytes.
* @param {Function} onReadComplete Function be called when a read completes.
* @return {String}
* @member Ti.Network.TCPSocket
*/
onReadComplete: function(onReadComplete){},

/**
* Set the callback that will be fired when an operation times out on the Socket.
* @param {Function} onTimeout Function to be called when an operation times out.
* @return {String}
* @member Ti.Network.TCPSocket
*/
onTimeout: function(onTimeout){},

/**
* Set a callback that will be fired when data is written on the Socket.
* @param {Function} onWrite Function to be called when data is written.
* @return {String}
* @member Ti.Network.TCPSocket
*/
onWrite: function(onWrite){},

/**
* "Write data to the Socket's connection, if open."
* @param {String} data The data to write to the connection.
* @return {Boolean}
* @member Ti.Network.TCPSocket
*/
write: function(data){}}

