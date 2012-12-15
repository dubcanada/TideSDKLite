/**
* An object representing a menu.
*
* A Menu object can be added to the current window of a TideSDK application. Menu objects can 
* be made up of a number of MenuItems(see Ti.UI.MenuItem). These menu items can be added to the 
* menu object at anytime and TideSDK will ensure that all menu instances update immediately.     
* 
* Please take a look at the code example below:     
* 
*			//Create the menu object
* 			var menu = Ti.UI.createMenu();
*			
*			//Create menu items
*			var subMenu1 = menu.addItem('Menu1');
*			var subMenu2 = menu.addItem('Menu2');
*			var subMenu3 = menu.addItem('Menu3');
*
*			//Add menu to the current window
*			Ti.UI.getCurrentWindow().setMenu(menu);
*
*			//Or alternatively you can use the snippet below
*			//to add the menu to the current window
*			//Ti.UI.currentWindow.menu = menu; 
*
* @class Ti.UI.Menu
* @member Ti.UI
*/
Ti.UI.Menu = {
/**
* Add a check item to this menu with the given attributes.
* @param {String} label The label for the new item
* @param {Function} listener (optional) An event listener callback for the item
* @return {Ti.UI.MenuItem}
* @member Ti.UI.Menu
*/
addCheckItem: function(label, listener){},

/**
* Add an item to this menu with the given attributes.
* @param {String} label The label for the new item
* @param {Function} listener (optional) An event listener callback for the item
* @param {String} iconURL "The URL for this item's icon"
* @return {Ti.UI.MenuItem}
* @member Ti.UI.Menu
*/
addItem: function(label, listener, iconURL){},

/**
* Append a MenuItem object to a menu.
* @param {UI.MenuItem} item Append an item to this menu
* @return {String}
* @member Ti.UI.Menu
*/
appendItem: function(item){},

/**
* Add a separator item to this menu.
* @return {Ti.UI.MenuItem}
* @member Ti.UI.Menu
*/
addSeparatorItem: function(){},

/**
* Remove all items from this menu.
* @return {String}
* @member Ti.UI.Menu
*/
clear: function(){},

/**
* Get the length of this menu.
* @return {Number}
* @member Ti.UI.Menu
*/
getLength: function(){},

/**
* Insert a menu item before the given index. This method will throw an exception if the index of out of range.
* @param {UI.MenuItem} item The menu item to insert
* @param {Number} index The index for this menu item
* @return {String}
* @member Ti.UI.Menu
*/
insertItemAt: function(item, index){},

/**
* Get an item from this menu at the given index. This method will throw an exception if the index is out of range.
* @param {Number} index The index of the item to get
* @return {Ti.UI.MenuItem}
* @member Ti.UI.Menu
*/
getItemAt: function(index){},

/**
* Remove the item in this menu at the given index. This method will throw an exception if the index is out of range.
* @param {Number} index The index of the item to remove
* @return {String}
* @member Ti.UI.Menu
*/
removeItemAt: function(index){}}

