/**
* An implementation of an HTTPServer.
*
* The HTTPServer module can assist you in creating a HTTP Server.    
* Refer to the code example below:     
*		
*		//Create the HTTPServer object
*		var server = Ti.Network.createHTTPServer();
*
*		//Specify port number and callback function
*		//This example can be tested by pointing your
*		//browser to http://localhost:8082/
*		
*		server.bind(8082,'localhost',function(request,response) {
*			//Data to output
*			var data = '<p>Hello World!</p>';
*			
*			//Setting content type of the response
*			response.setContentType('text/plain');
*			
*			//Setting content length of the response
*			response.setContentLength(data.length);
*			
*			//Setting status and reason
*			response.setStatusAndReason('200','OK');
*			
*			//Finally writing the response back	
*			response.write(data);
*		});     
*                  
*
*
* @class Ti.Network.HTTPServer
* @member Ti.Network
*/
Ti.Network.HTTPServer = {
/**
* bind this server to a port on a specific interface
* @param {Number} port port to bind on
* @param {String} address (optional) address to bind to
* @param {Method} callback callback for server logic (in seperate thread)
* @return {String}
* @member Ti.Network.HTTPServer
*/
bind: function(port, address, callback){},

/**
* close this server
* @return {String}
* @member Ti.Network.HTTPServer
*/
close: function(){},

/**
* check to see if this server socket is closed
* @return {Boolean}
* @member Ti.Network.HTTPServer
*/
isClosed: function(){}}

