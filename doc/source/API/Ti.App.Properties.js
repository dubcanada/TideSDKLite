/**
* An object holding a group of properties.
* Application properties provide an alternative to storing information in
* HTML5 Databases or through the TideSDK Database module. They can be categorized
* into System Properties and User Properties. 
*
* System Properties
* -----------------
* System properties are generally defined in your app's tiapp.xml. There are always
* read-only.
* For instance, you can save the properties below in tiapp.xml under the <ti:app> node.
* 		
*		<property name="customText" type="string">This is a string</property> 	
*		<property name="customDouble" type="double">2.45</property>
*		<property name="customBool" type="boolean">true</property>
*		<property name="customInt" type="int">9</property>
*		<property name="customList" type="list">9,8,7</property>
*
* You can now access the above properties as shown below:
*
*		var appProperties = Ti.App.getSystemProperties();
*		alert(appProperties.getString('customString'));
*		alert(appProperties.getInt('customInt'));
*		
* Please note that System properties are read-only. It is so because an application
* might not have write access to its installation directory. This is where tiapp.xml resides.
* Therefore to store properties, its recommended that you use User properties. 
*
* User Properties
* ---------------
* User properties are obtained using the same interface as System properties. 
* Its recommended that you store these in the application data directory.   
* On Windows, this is __%appdata%/TideSDK/appdata.__
* On Linux, this is __~/.tidesdk/appdata/.__
* On OSX, this is __~/Library/Application Support/TideSDK/appdata.__
*
* Let's take a look at the example below:
* 
*		var file = Ti.Filesystem.getFile(Ti.API.application.dataPath, "user.properties");
*		var userProperties;

*		//if file exists, then load properties.
*		if(file.exists()) {
*			userProperties = Ti.App.loadProperties(file);
*		} else {
*		//create new set of properties if file doesn't exist
*			userProperties = Ti.App.createProperties({
*			  	customText : "This is a string",
*			  	customDouble : 2.45,
*			  	customBool : true,
*			  	customInt	: 1,
*			  	customList : [9,8,7]	
*			});
*		}
*		
*		//retrieve a string value
*		alert(userProperties.getString('customText'));
*		//set an integer value in properties
*		userProperties.setInt('customInt',9);
*		//making sure that the property values are saved to the file object
*		userProperties.saveTo(file);
*		//null out file object as pointer not used anymore
*		file = null;
*
*
* @class Ti.App.Properties
* @member Ti.App
*/
Ti.App.Properties = {
/**
* Returns a property value as an integer.
* Throws an exception if this value can not be found and no default is
* provided or the value stored in the properties file could not be
* converted to the appropriate type.
* @param {String} name The name of the property to return.
* @param {Number} defaults The value to return if this property is not set.
* @return {Number}
* @member Ti.App.Properties
*/
getInt: function(name, defaults){},

/**
* Returns a property value as an Array.
* Throws an exception if this value can not be found and no default is
* provided or the value stored in the properties file could not be
* converted to the appropriate type.
* @param {list} name The name of the property to return.
* @param {list} defaults The value to return if this property is not set.
* @return {list}
* @member Ti.App.Properties
*/
getList: function(name, defaults){},

/**
* Returns a property value as a String.
* Throws an exception if this value can not be found and no default is
* provided or the value stored in the properties file could not be
* converted to the appropriate type.
* @param {String} name The name of the property to return.
* @param {String} defaults The value to return if this property is not set.
* @return {String}
* @member Ti.App.Properties
*/
getString: function(name, defaults){},

/**
* Returns a property value as double.
* Throws an exception if this value can not be found and no default is
* provided or the value stored in the properties file could not be
* converted to the appropriate type.
* @param {String} name The name of the property to return.
* @param {Number} defaults The value to return if this property is not set.
* @return {Number}
* @member Ti.App.Properties
*/
getDouble: function(name, defaults){},

/**
* Query whether or not a given property exists in this Property object.
* @param {String} name The name of the property to query.
* @return {Boolean}
* @member Ti.App.Properties
*/
hasProperty: function(name){},

/**
* Returns an Array of all property names in this App.Properties object.
* @return {Array<String>}
* @member Ti.App.Properties
*/
listProperties: function(){},

/**
* Save this App.Properties object to file at the given path.
* @param {String} path The path to the file to save this App.Properties object to.
* @return {void}
* @member Ti.App.Properties
*/
saveTo: function(path){},

/**
* Set a double property value given the name and value.
* @param {String} name The name of the property to set.
* @param {Number} value The value to set the given property to.
* @return {void}
* @member Ti.App.Properties
*/
setDouble: function(name, value){},

/**
* Set an integer property value given the name and value.
* @param {String} name The name of the property to set.
* @param {Number} value The value to set the given property to.
* @return {void}
* @member Ti.App.Properties
*/
setInt: function(name, value){},

/**
* Set a list property value given the name and array of Strings.
* @param {String} name The name of the property to set.
* @param {Array<String>} value The value to set the given property to.
* @return {void}
* @member Ti.App.Properties
*/
setList: function(name, value){},

/**
* Set a String property value given the name and value.
* @param {String} name The name of the property to set.
* @param {String} value The value to set the given property to.
* @return {void}
* @member Ti.App.Properties
*/
setString: function(name, value){}}

