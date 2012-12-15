/**
* An object representing a TideSDK Worker.
* @class Ti.Worker.Worker
* @member Ti.Worker
*/
Ti.Worker.Worker = {
/**
* "Post a message (async) into the worker thread's queue to be handled by onmessage"
* @param {any} data Any JSON serializable type to pass to the child.
* @return {String}
* @member Ti.Worker.Worker
*/
postMessage: function(data){},

/**
* Start the worker thread
* @return {String}
* @member Ti.Worker.Worker
*/
start: function(){},

/**
* Terminate the worker thread. The thread can be restarted with Worker.start()
* @return {String}
* @member Ti.Worker.Worker
*/
terminate: function(){}}

