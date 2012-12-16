/**
 * Main Page
 * =========
 * The main page is used as the default "demo".
 * Its not really a demo, but a welcome page.
 *
 * You can copy this folder to use it as a base for a new demo.
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