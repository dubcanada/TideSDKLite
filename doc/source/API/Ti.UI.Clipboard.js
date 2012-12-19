/**
* A module used for accessing clipboard data.    
* Please refer to the code examples below:    
* 	//Code below stores text into the clipboard.    
* 	Ti.UI.Clipboard.setData('text/plain', 'This is my custom text');       
*
*		//Retrieving the stored data.
*	  	Ti.UI.Clipboard.getData('text/plain'); //should return 'This is my custom text'
* 
* Working with text only
* ----------------------
* For setting text/plain data, rather than using the above methods, you may
* use the setText/getText methods.
*
*		Ti.UI.Clipboard.setText('This is my custom text');
*		Ti.UI.Clipboard.getText(); //should return 'This is my custom text'
*
* @class Ti.UI.Clipboard
* @member Ti.UI
*/
Ti.UI.Clipboard = {
/**
* Clear data of the given mime-type from the clipboard. If no mime-type is given, clear all data from the clipboard.
* @param {String} type (optional) The mime-type of the data to clear.
* @return {String}
* @member Ti.UI.Clipboard
*/
clearData: function(type){},

/**
* Clear the text portion of the clipboard.
* @return {String}
* @member Ti.UI.Clipboard
*/
clearText: function(){},

/**
* Get the data on the clipboard from the portion which contains data of the given mime-type.
* @param {String} type The mime-type of the data to get.
* @return {String}
* @member Ti.UI.Clipboard
*/
getData: function(type){},

/**
* Get the current text on the clipboard.
* @return {String}
* @member Ti.UI.Clipboard
*/
getText: function(){},

/**
* Return true if there is any content of the given mime-type on the clipboard.
* @param {String} type (optional) The mime-type of the data to check.
* @return {Boolean}
* @member Ti.UI.Clipboard
*/
hasData: function(type){},

/**
* Return true if there is any content in the text portion of the clipboard.
* @return {Boolean}
* @member Ti.UI.Clipboard
*/
hasText: function(){},

/**
* Set the data on the clipboard given a mime-type and the new data. This method will set data on the appropriate portion of the clipboard for the given mime-type.
* @param {String} type The mime-type of the data to set.
* @param {String} data The new clipboard text.
* @return {String}
* @member Ti.UI.Clipboard
*/
setData: function(type, data){},

/**
* Set the text on the clipboard. This will overwrite the current contents of the clipboard.
* @param {String} newText The new clipboard text. If the text is an empty string, the text portion of the clipboard will be cleared.
* @return {String}
* @member Ti.UI.Clipboard
*/
setText: function(newText){}}

