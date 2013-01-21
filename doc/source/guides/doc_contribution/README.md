Contributing to the Docs
------------------------
TideSDK is a very huge and sophisticated project. The old Titanium Desktop docs were a bit outdated and were missing a lot of information and examples.

We want to change that with the TideSDK docs: Providing examples whenever its possible and many, many guides (like tutorials) to make it easy for the TideSDK users to create cool desktop applications.


###Preparation
In order to make changes on the TideSDK User docs, you need to have a github account and fork [our documentation project].

After you made your changes, commit them to your fork and send us a pull request.

Its always a good decision to drop by in our IRC channel [#tidesdk @ freenode.net] and talk to us first, if you want to write a new guide or example.


###Working with the API docs
The exposed TideSDK API is documented in a couple of JavaScript skeleton files (only function definitions with empty bodies).    
Those JavaScript files are parsed by JSduck and create the structure of our API documentation.

A doctag to a function should always be structured like this:

	/**
	* The block starts with a description of the functon/method/object you want to document.
	*
	* @class Ti.Module.Name
	* @member Ti.Module
	*/

The @class tag gets the full path to the object you want to document, including the object name itself.
The @member tag gets the full path to the parent object of the object you want to document.

You should read the [JSduck documentation] on github.


###Writing a guide
If you want to provide more advanced information in tutorial form, then the guides section is the right choice for you.    
We aim to create guides in every important section of the TideSDK API to help users with every feature of the SDK.

After you have forked the doc project, have a look into the folder /source/guides/    
Every single guide gets its own, unique folder where the folder name acts like a key for the guide.

Take a look into one or more existing guide folders to learn about how they are structured.    
In a nutshell:

* Everything that belongs to the guide must be stored in the guide folder you created
* The text of the guide is in [markdown format] and has to be stored inside a `README.md` file.
* If you want to use a thumbnail for your guide, place a `icon.png` file with the dimensions 114px x 86px inside your guide folder.

After you have written the guide, you have to add it to the list of existing guides.    
Open the file /source/guides.json and add your created guide to some section where it belongs to.    
If you are not sure, or would need to create a new section, talk to us on IRC, first.


[our documentation project]: https://github.com/TideSDK/TideSDK/tree/master/doc
[#tidesdk @ freenode.net]: irc://chat.freenode.net#tidesdk
[JSduck documentation]: https://github.com/senchalabs/jsduck/wiki
