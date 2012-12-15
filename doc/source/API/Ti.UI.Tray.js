/**
* An object representing a TrayItem in TideSDK.
* @class Ti.UI.Tray
* @member Ti.UI
*/
Ti.UI.Tray = {
/**
* Get the hint for this TrayItem
* @return {String}
* @member Ti.UI.Tray
*/
getHint: function(){},

/**
* Get the icon URL for this TrayItem
* @return {String}
* @member Ti.UI.Tray
*/
getIcon: function(){},

/**
* Get the menu for this TrayItem
* @return {Ti.UI.Menu|null}
* @member Ti.UI.Tray
*/
getMenu: function(){},

/**
* Removes a TrayItem
* @return {String}
* @member Ti.UI.Tray
*/
remove: function(){},

/**
* "Sets a TrayItem's icon"
* @param {String} icon (optional) path to the icon or null to unset
* @return {String}
* @member Ti.UI.Tray
*/
setIcon: function(icon){},

/**
* "Sets a TrayItem's tooltip"
* @param {String} hint (optional) tooltip value or null to unset
* @return {String}
* @member Ti.UI.Tray
*/
setHint: function(hint){},

/**
* Set the menu for this TrayItem
* @param {UI.Menu|null} menu The Menu to use for this TrayItem or null to unset
* @return {String}
* @member Ti.UI.Tray
*/
setMenu: function(menu){}}

