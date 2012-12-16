TideSDK-KitchenSink
===================

TideSDK Application illustrating example use of TideSDK's API's

How to create a demo
--------------------
Demos are stored under `Resources/demos/`
Each demo needs a unique key by which it can be identified. Keys only have to be unique for the demo group.

If you place a demo folder directly under `demos/`, then its not assigned to any group. If you want to create a group,
create a folder in `demos` and place your demo folder in there. I.e. `demos/ui/window_menu/` to place the demo with the key
`window_menu` inside the `ui` group.

Inside your demo folder, you need to create a .js file with the same filename as the demo key. So for our window menu example,
the file needs to be: `demos/ui/window_menu/window_menu.js`.

Here are the contents of that file:

```javascript
/**
 * Demo Name
 * =========
 * Give a short description of the demo and what it does.
 */
define({
    /**
     * The HTML-Chunk to be loaded for this demo.
     */
    content:'content.html',
    /**
     * A optional stylesheet file to be loaded for the demo.
     */
    stylesheet:'assets/style.css',
    /**
     * Define one or more API nodes here to display a button which opens the users browser and point to the API docs.
     * Example: ['Ti.UI.Menu', 'Ti.UI.MenuItem']
     */
    docs: [],
    /**
     * Specify on which platforms the following demo is tryable. Leave the array empty to enable all platforms.
     * Pass strings to specify the platform(s):
     * ['win', 'linux', 'mac']
     */
    platforms: [],
    /**
     * The Code to be executed after the HTML chunk has been placed in the content container.
     * @param {DOMObject} Content Container node.
     */
    prepare:function (container) {},
    /**
     * The code to be executed when the demo is unloaded and replaced by another demo.
     * Use this to detach any event-listeners and quit intervals and whatever.
     * @param {DOMObject} Content Container node.
     */
    cleanup:function (container) {}
});
```

The whole KitchenSink application is built on the AMD principle using require.js, so your demos are in fact AMD-Modules, hence the "define" encapsulation.
Here are some more information about the single object properties and methods:
 
###content
The content property defines a html file relative to the demo js file which should be loaded and displayed on the right area of the application.
Place descriptions and code examples in `<pre>` here. Code examples will be prettified automatically.
 
###stylesheet
If your html content needs some special styling, save your styles inside a css file relative to the demo js file and tell KitchenSink to load it alongside the html source.    
__Heads up!__ Please prefix all css-classes with your demo key to prevent interferences with the UI or other demos, since once loaded CSS files won't be unloaded again.

###docs
Define one or more API nodes which are used inside your demos here. This will render a dropdown menu above your demo, enabling the user to quickly lookup the matching API docs to get further information.

###platforms
If a demo is platform specific, define here which platforms are capable of running the demo.
When a user tries to launch a demo which is not capable to run on his system, the `prepare()` and `cleanup()` functions won't be executed for this demo and the user gets a notice that he cannot launch the demo on his system.
__Tip:__ Your content container will get the css-class "no-run" applied, which you can use to hide certain elements like a button which launches the demo.

###prepare(container)
This function is executed by KitchenSink when a user selects your demo in the sidebar menu. Its executed AFTER the HTML code has been placed in the content container.
The function gets passed the jQuery enabled DOM element of the content container as first parameter.

###cleanup(container)
This function is executed by KitchenSink when your demo is currently on screen and the user selects another demo from the sidebar menu.
Its considered to remove any event listeners or hide and destroy demo elements you created, to get back to a clean state.
The function gets passed the jQuery enabled DOM element of the content container as first parameter.

-----------------------

###Adding your demo to the sidebar menu
Finally, after you have created your demo files, you have to add it to `Resources/demos/index.json`.
Here is an example how the file is structured:

```json
{
        "main": "Main",
        "ui": {
            "label": "User Interface",
            "children": {
                "window_menu": "Window Menu",
                "tray_icon": "Tray Icon"
            }
        }
}
```

Its pretty straightforward: you list your demo by adding a key/value pair where the demo key (foldername) becomes the object key
and your demo title becomes the value.

If you want to create a new group, just add another JSON object there and use the group folder name as key. For a group, you have to
define the "label" and "children" properties, which are self-explaining.

-----------------------

If you are unsure about something, just take a look at existing demos in the `Resources/demos/` folder.