/**
* Script object.
* @class Ti.API.Script
* @member Ti.API
*/
Ti.API.Script = {
/**
* <p>
* Adds a script evalutor Script evaluators are responsible for matching and evaluating
* custom <script> types, and preprocessing URLs.
* </p>
* <p>
* When a <tt>&lt;script type="text/language"&gt;</tt> tag is seen, the first
* evaluator that returns true to <tt>canEvaluate("text/language")</tt> will
* evaluate that script.
* </p>
* When a URLRequest is received, the first evaluator that returns true to
* <tt>canPreprocess(URL)</tt> will preprocess that URL. Evaluators should
* follow this API:
* <ol><li>
* <tt>canEvaluate(String mimeType)</tt> returns true or false.
* </li> <li>
* <tt>canPreprocess(String mimeType)</tt> returns true or false.
* </li><li>
* <tt>evaluate(String mimeType, String name, String sourceCode, Object scope)</tt> returns result of evaluation
* </li><li>
* <tt>preprocess(String url, Object scope)</tt> returns preprocessed content.
* </li></ol>
* @param {Object} evaluator The evaluator to add.
* @return {String}
* @member Ti.API.Script
*/
addScriptEvaluator: function(evaluator){},

/**
* 
* @param {Object} evaluator The mimeType to check
* @return {bool}
* @member Ti.API.Script
*/
canEvaluate: function(evaluator){},

/**
* 
* @param {String} url The URL to check
* @return {bool}
* @member Ti.API.Script
*/
canPreprocess: function(url){},

/**
* Evaluates a string of code
* @param {String} mimeType "The code's mime type (i.e. \"text/ruby\", \"text/php\")"
* @param {String} name "The name of the code's origin (usually a filename, or URL)"
* @param {String} code The actual code
* @param {Object} scope "global variable scope (i.e. \"window\")"
* @return {Any}
* @member Ti.API.Script
*/
evaluate: function(mimeType, name, code, scope){},

/**
* Runs an app URL through preprocessing, returning the result as a string
* @param {String} URL the URL for this resource (app, ti, and file URLs are accepted)
* @param {Object} scope global variable scope to expose into the preprocessed file
* @return {String}
* @member Ti.API.Script
*/
preprocess: function(URL, scope){},

/**
* Removes a script evalutor
* @param {Object} evaluator The evaluator to remove
* @return {String}
* @member Ti.API.Script
*/
removeScriptEvaluator: function(evaluator){}}

