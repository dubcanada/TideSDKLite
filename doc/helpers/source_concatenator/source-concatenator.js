/**
* TideSDK API source concatenator
* ===============================
*
* The source concatenator is a node.js app, used to merge all .js files from the /source/API/ folder.
* The concatenated file is stored in this folder as "Ti.js" and can be used for autocompletion in code-editors i.e. JetBrains PHPStorm.
*
* @author: Christian Engel <christian.engel@tidesdk.org>
* @version 1 27 Aug 2012
*/
var fs = require('fs'),
    src = '',
    files = fs.readdirSync('../../source/API/');

//Remove the "Ti.js" from the list, since this is the file we have to start with.
files.splice(files.indexOf('Ti.js'), 1);

var src = fs.readFileSync('../../source/API/Ti.js', 'utf8') + '\n';

for(var i = 0; i < files.length; i++){
    src += fs.readFileSync('../../source/API/' + files[i], 'utf8') + '\n';
}

//Namespace fix has to be removed when the namespace move from Titanium.* to Ti.* is made!
src = src.replace(/Ti\./g, 'Titanium.').replace(/Ti = \{/, 'var Titanium = {');

fs.writeFileSync('../../generated/resources/Ti.js', src, 'utf8');

console.log('done');