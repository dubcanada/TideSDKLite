/**
* A module for dealing with media.
* @class Ti.Media
* @singleton
* @member Ti
*/
Ti.Media = {
/**
* Factory method for Sound objects, created given a path or a URL to a sound file.
* The types of sound files that can be played depend on the codecs installed on the
* user's system.
* @param {String} path The path or url to the sound file to play.
* @return {Ti.Media.Sound}
* @member Ti.Media
*/
createSound: function(path){},

/**
* Activate the system bell. Some systems may have disabled the system bell.
* @return {String}
* @member Ti.Media
*/
beep: function(){}}

