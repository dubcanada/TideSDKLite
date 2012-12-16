/**
 * Main Page
 * =========
 * The main page is used as the default "demo".
 * Its not really a demo, but a welcome page.
 *
 * You can copy this folder to use it as a base for a new demo.
 */
define({
    prepare:function (container) {
        //Create the menu object.
        var menu = Ti.UI.createMenu();

        //Add some items
        var item1 = Ti.UI.createMenuItem('Menu1');
        var item2 = Ti.UI.createMenuItem('Menu2');
        var item3 = Ti.UI.createMenuItem('Menu3');

        //Add the items to the menu
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
    platforms: []
});