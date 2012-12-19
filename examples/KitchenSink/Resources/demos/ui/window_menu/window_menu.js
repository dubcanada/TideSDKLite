/**
 * Window Menu
 * =========
 * This demo shows how to set up and remove a window specific menu.
 */
define({
    prepare:function (container) {
        //Create the menu object.
        var menu = Ti.UI.createMenu();

        //Add a toplevel item
        var item1 = Ti.UI.createMenuItem('Menu1', function () {
            //Adding a event-listener function here.
            alert('You clicked me!');
        });

        //Another toplevel item, but we will add children.
        var item2 = Ti.UI.createMenuItem('Menu2');
        //We want to add some child options
        item2.addItem('Option 1');
        //Add a icon (should be 16x16px) to the item.
        //Note: the URL base is Resources/
        var smiley = item2.addItem('Option 2', null, 'demos/ui/window_menu/assets/emoticon_smile.png');

        //Smiley gets some childs, too!
        smiley.addItem('A childs child');

        item2.addSeparatorItem(); //Draw a line here!
        item2.addItem('Option 3', function () {
            //And another event-listener.
            alert('you chose option 3');
        });

        var item3 = Ti.UI.createMenuItem('Menu3');
        var checker = item3.addCheckItem('I am a checker!', function (e) {
            alert(checker.getState());
        });

        //Add the main items to the menu
        menu.appendItem(item1);
        menu.appendItem(item2);
        menu.appendItem(item3);

        //Attach the menu to the current window.
        Ti.UI.getCurrentWindow().setMenu(menu);
    },
    cleanup:function (container) {
        var win = Ti.UI.getCurrentWindow();
        setTimeout(function () {
            win.setMenu(null);

            //Workaround for issue #32 => https://github.com/TideSDK/TideSDK/issues/32
            win.setHeight(win.getHeight() + 1);
            win.setHeight(win.getHeight() - 1);
        }, 1000);
    },
    content:'content.html',
    docs:['Ti.UI.Menu', 'Ti.UI.MenuItem'],
    platforms:[]
});