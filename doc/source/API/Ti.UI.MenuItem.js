/**
* An object representing a menu item.
* @class Ti.UI.MenuItem
* @member Ti.UI
*/
Ti.UI.MenuItem = {
/**
* "Add a check item to this menu item's submenu with the given attributes. If this menu item does not have a submenu, it will be created. This method is not available for separator items."
* @param {String} label The label for the new item
* @param {Function} listener (optional) An event listener callback for the item
* @return {Ti.UI.MenuItem}
* @member Ti.UI.MenuItem
*/
addCheckItem: function(label, listener){},

/**
* "Add a separator item to this menu item's submenu. If this menu item does not have a submenu, it will be created. This method is not available for separator items."
* @return {Ti.UI.MenuItem}
* @member Ti.UI.MenuItem
*/
addSeparatorItem: function(){},

/**
* Disable this item i.e. make it non-clickable. This method is not available for separator items.
* @return {String}
* @member Ti.UI.MenuItem
*/
disable: function(){},

/**
* Enable this item i.e. make it clickable. This method is not available for separator items.
* @return {String}
* @member Ti.UI.MenuItem
*/
enable: function(){},

/**
* "Get this item's icon URL This method is not available for separator or check items."
* @return {String|null}
* @member Ti.UI.MenuItem
*/
getIcon: function(){},

/**
* This method is only available for check items.
* @param {Boolean} autocheck Whether or not this item should is an autocheck
* @return {String}
* @member Ti.UI.MenuItem
*/
getAutoCheck: function(autocheck){},

/**
* "Get this item's label. This method is not available for separator items."
* @return {String}
* @member Ti.UI.MenuItem
*/
getLabel: function(){},

/**
* Gets the state of this check item This method is only available for check items.
* @return {Boolean}
* @member Ti.UI.MenuItem
*/
getState: function(){},

/**
* "Get this item's submenu. This method is not available for separator items."
* @return {Ti.UI.Menu|null}
* @member Ti.UI.MenuItem
*/
getSubmenu: function(){},

/**
* Return true if this UI.MenuItem is a check menu item or false otherwise.
* @return {Boolean}
* @member Ti.UI.MenuItem
*/
isCheck: function(){},

/**
* This method is not available for separator items.
* @return {Boolean}
* @member Ti.UI.MenuItem
*/
isEnabled: function(){},

/**
* Return true if this UI.MenuItem is seperator menu item or false otherwise.
* @return {Boolean}
* @member Ti.UI.MenuItem
*/
isSeparator: function(){},

/**
* Set whether or not this check item is an autocheck item. An autocheck item (the default) will automatically flip the state of the check on a a click event. Turning off this behavior makes the check item more useful as a radio button. This method is only available for check items.
* @param {Boolean} autocheck Whether or not this item should be an autocheck
* @return {String}
* @member Ti.UI.MenuItem
*/
setAutoCheck: function(autocheck){},

/**
* Set the icon URL for this item This method is not available for separator or check items.
* @param {String|null} iconURL The new icon URL for this item or null to unset it
* @return {String}
* @member Ti.UI.MenuItem
*/
setIcon: function(iconURL){},

/**
* Set the label for this item. This method is not available for separator items.
* @param {String} label The new label for this item
* @return {String}
* @member Ti.UI.MenuItem
*/
setLabel: function(label){},

/**
* Sets the state of this check item This method is only available for check items.
* @param {Boolean} state A True state is checked, while a False state in unchecked
* @return {String}
* @member Ti.UI.MenuItem
*/
setState: function(state){},

/**
* "Set this item's submenu. This method is not available for separator items."
* @param {UI.Menu|null} menu The submenu to use for this item or null to unset it
* @return {String}
* @member Ti.UI.MenuItem
*/
setSubmenu: function(menu){},

/**
* "Add an item to this menu item's submenu with the given attributes. If this menu item does not have a submenu, it will be created. This method is not available for separator items."
* @param {String} label The label for the new item
* @param {Function} listener (optional) An event listener callback for the item
* @param {String} iconURL "The URL for this item's icon"
* @return {Ti.UI.MenuItem}
* @member Ti.UI.MenuItem
*/
addItem: function(label, listener, iconURL){}}

