TideSDK API Docs
-----------------
The TideSDK API Docs are built, using JSduck from sencha.    
If you want to make your own build of the docs, you have to install the JSduck gem on your machine.

###Building the docs locally

To build the docs with JSduck, call the following commands:
First, build the welcome.html file as documentation index.


    cd /helpers/welcome
    node welcome.build.js

This will create `source/welcome.html` which you need to compile the docs with the following command:

    cd /source
    jsduck --config doc_build.json

To compile the documentation into the generated/ folder.

After you compiled the docs, or if you just want to create the latest Ti.js for autocompletion in your IDE, call:

    cd /helpers/source_contatenator
    node source-concatenator.js

This will create the file `generated/resources/Ti.js`, which only exists if you built the docs beforehand.


###The API
The exposed API is documented in the folder source/API/.    
The old YML docs have been converted into Javascript skeletons with doctags.

Every module and object of tide is exposed in its own JS file.



###The guides
User guides are stored in the folder source/guides/

To create a new guide, create a new sub-folder there with a unique name.    
Into that folder goes every asset file the guide will use (i.e. images), including the guide itself in markdown format, stored as "README.md".

You can make use of the images inside your guides, by using the @img tag in markdown:

	{@img some-image.png Alt text}


After you have written a new guide, update the file source/guides.json to have the new guide displayed in the docs.

The guides.json file is divided into sections. Each section has a title, and items.    
Find a fitting section for your new guide, or create a new one. Then insert your guide, by inserting its unique name, the title and a short description:

	{
      "name": "getting_started",
      "title": "Getting Started with TideSDK",
      "description": "This introduction to TideSDK explains how you can get started."
  	}

Remember: the unique name must refer to the guide folder, you created before.

If you want to have a unique thumbnail displayed for your guide in the guides overview, place a "icon.png" file with the dimensions 114x86px inside your guide folder.
