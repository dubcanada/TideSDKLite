/**
* An object representing an IO pipe.
* An IO Pipe helps in reading data from an input stream, processing
* this data and then writing this to an output stream.  
*      
* This can be demonstrated with the example below.     
*		
* 		var echoCmd = Ti.platform === "win32" ? ["C:\\Windows\\System32\\cmd.exe", "/C", "echo"] : ["/bin/echo"];
*	
* 		echoCmd.push("Data.from.echo!");
*
* 		var moreCmd = Ti.platform === "win32" ? ["C:\\Windows\\System32\\more.com"] : ["cat"];
*
* 		// Create the processes.
* 		var echo = Ti.Process.createProcess(echoCmd);
* 		var more = Ti.Process.createProcess(moreCmd);
*		
*			//Code for displaying the data received by the 'more' process.
* 		more.setOnReadLine(function(data) {
* 		 	alert(data.toString());
* 		});
*
* 		//Attaching the processes through IO pipes below.
* 		echo.stdout.attach(more.stdin);
*			//Launching Processes.
* 		echo.launch();
* 		more.launch();     
*
*
* @class Ti.Process.Pipe
* @member Ti.Process
*/
Ti.Process.Pipe = {
/**
* "Attach an IO object to this pipe. An IO object is an object that implements a public \"write(Bytes)\". In Ti, this include FileStreams, and Pipes. You may also use your own custom IO implementation here."
* @return {String}
* @member Ti.Process.Pipe
*/
attach: function(){},

/**
* Close this pipe to further reading/writing.
* @return {String}
* @member Ti.Process.Pipe
*/
close: function(){},

/**
* Detach an IO object from this pipe. see Process.Pipe.attach.
* @return {String}
* @member Ti.Process.Pipe
*/
detach: function(){},

/**
* 
* @return {bool}
* @member Ti.Process.Pipe
*/
isAttached: function(){},

/**
* Write data to this pipe
* @param {Bytes|String} data a Bytes object or String to write to this pipe
* @return {Number}
* @member Ti.Process.Pipe
*/
write: function(data){}}

