/**
* A module for creating processes.
* A simple example for process creation can be seen below:
*
*		//Following code executes a python script located in
*		//the resources folder.
*
*		var myScript = Ti.Process.createProcess({
*                args:['python',Ti.API.application.resourcesPath + "/myScript.py"]
*        });
*		
*		//Launches the process	
*       myScript.launch();
*
* 		
* @class Ti.Process
* @singleton
* @member Ti
*/
Ti.Process = {
/**
* Create a Process object. There are two main ways to use this function:
* <pre><code>
* Ti.Process.createProcess({
* args: ['mycmd', 'arg1', 'arg2'],
* env: {'PATH': '/something'},
* stdin: pipeIn,
* stdout: pipeOut,
* stderr: pipeErr
* });
* </code></pre>
* <pre><code>
* Ti.Process.createProcess(args, environment, stdin, stdout, stderr);
* </code></pre>
* @param {Array|Object} args Either a list of command-line arguments to use for this process invocation (including the executable path) or an object describing all parameters of this Process object (see above).
* @param {Object} envionment (optional) An object representing the environment to pass to this process.
* @param {Process.Pipe} pipeIn (optional) A Process.Pipe object which the new process should use for receiving input.
* @param {Process.Pipe} pipeOut (optional) A Process.Pipe object which the new process should use for sending output.
* @param {Process.Pipe} pipeErr (optional) A Process.Pipe object which the new process should use for sending error output.
* @return {Ti.Process.Process}
* @member Ti.Process
*/
createProcess: function(args, envionment, pipeIn, pipeOut, pipeErr){},

/**
* Create a pipe for attaching to/from any number of processes.
* @return {Ti.Process.Pipe}
* @member Ti.Process
*/
createPipe: function(){},

/**
* This method is deprecated. See Process.Process.createProcess()
* @param {String} command The command to launch
* @param {Array<String>} arguments A list of arguments to the command
* @return {String}
* @member Ti.Process
*/
launch: function(command, arguments){},

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGCHLD: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGEMT: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGFPE: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGHUP: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGILL: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGINFO: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGINT: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGIO: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGKILL: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGPIPE: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGPROF: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGQUIT: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGSEGV: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGSTOP: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGSYS: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGTERM: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGTRAP: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGTSTP: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGTTOU: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGURG: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGUSR1: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGTTIN: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGUSR2: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGVTALRM: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGXCPU: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGXFSZ: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGALRM: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGABRT: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGBUS: null,

/**
* 
* @property {String}
* @member Ti.Process
*/
SIGWINCH: null}

