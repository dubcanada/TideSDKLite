Setting up code completion
==========================

This article covers the usage of code-completion in different IDEs. If your IDE is missing and you know how to add
TideSDK API code completion to it, please talk to us and share your information, or [fork the article on GitHub].

[fork the article on GitHub]: https://github.com/TideSDK/TideSDK-User-Docs/tree/develop/source/guides/ide_autocompletion


The Basics
----------
At first, download our [concatenated API skeleton] in JavaScript format and save it on your harddrive.

[concatenated API skeleton]: http://tidesdk.multipart.net/docs/user-dev/generated/resources/Ti.js


Adding the code-completion to your IDE
--------------------------------------
Pick your IDE from the list below and follow the steps to add code-completion.

###{@img icon-webstorm-phpstorm.png JetBrains WebStorm and PHPStorm} JetBrains WebStorm / PHPStorm

__Adding the TideSDK code-completion__    

1. Click on `File` > `Settings` to open your project Settings.
2. Expand the Option `JavaScript` and select `Libraries`, or search for *Libraries* in the search-box.
3. Click the `Add` button on the left, give the Library a fitting name and select Framework Type `<Custom>`
4. Now add the Ti.js file, by clicking the `Attach...` button in the "Files" area.
5. (optional) If you want to, you can specify the URL to this docs, too.

__Enabling TideSDK code-completion in a project__    

1. Click on `File` > `Settings` to open your project Settings.
2. Expand the Option `JavaScript` and select `Libraries`, or search for *Libraries* in the search-box.
3. Click on the `Manage Scopes...` button on the left.
4. Navigate to the Project folder you want to apply the code-completion on. Code-completion will be available in all sub-dirs, too.
5. Click on the "Library" column right to the folder name and select the name of the TideSDK API library you created before.
6. If it asks you if it should override library settings for child directories, click `Override`.
7. Close all Settings windows with a click on `OK`.