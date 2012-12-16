/**
 * TideSDK Kitchen Sink
 * ====================
 * The TideSDK Kitchen Sink is a modular application that can easily be extended with new modules.
 * Create a new demo in the `/demos/` folder and make sure to add it to `/demo-index.json`
 */

define(['modules/sidebar-menu', 'text!../demos/index.json'], function (mod_sidebar_menu, demo_index) {
    var sidebar_menu = new mod_sidebar_menu(JSON.parse(demo_index)),
            current_demo = null,
            last_run = true,
            $content = $('#main-content'),
            $section_title = $('#section-title'),
            doc_base = 'http://tidesdk.multipart.net/docs/user-dev/generated/#!/api/';  //Base URL of the TideSDK API docs.

    //Basically, the whole app is controlled with the sidebar module.
    sidebar_menu.on('select', function (id) {

        if (id == 'main') {
            $section_title.text(Ti.App.getVersion());
            $('#meta-area').hide();
        } else {
            $section_title.text(sidebar_menu.get_label(id));
        }

        var demo_id = id.split('.').pop(),
                demo_folder = id.replace(/\./g, '/');

        //Get the demo module.
        require(['../demos/' + demo_folder + '/' + demo_id], function (demo) {

            //If there is currently a loaded demo, unload it.
            if (current_demo !== null) {
                if(last_run) current_demo.cleanup($content);
            }

            //Get the HTML content and the stylesheet, if neccessary.
            var requires = ['text!../demos/' + demo_folder + '/' + demo.content];
            if (typeof demo.stylesheet == 'string') {
                requires.push('css!../demos/' + demo_folder + '/' + demo.stylesheet);
            }

            require(requires, function (content) {
                //Enable googles code prettyprinter!
                content = content.replace(/\<pre\>/g, '<pre class="prettyprint linenums">');

                $content.html(content);

                prettyPrint();

                //Set the meta area.
                if (demo.docs.length) {
                    var html = '';
                    for (var i = 0; i < demo.docs.length; i++) {
                        html += '<li><a target="_blank" href="' + doc_base + demo.docs[i] + '">' + demo.docs[i] + '</a></li>'
                    }
                    $('#doclinks').html(html);
                    $('#doc-btn').show();
                } else {
                    $('#doc-btn').hide();
                }


                $('#os-alert').hide();
                var do_run = true;
                if (demo.platforms.indexOf('win') != -1 || !demo.platforms.length) $('#ico-win').show(); else {
                    $('#ico-win').hide();
                    if (document.body.className.indexOf('win') != -1) {
                        $('#os-alert').show();
                        do_run = false;
                    }
                }
                if (demo.platforms.indexOf('linux') != -1 || !demo.platforms.length) $('#ico-lin').show(); else {
                    $('#ico-lin').hide();
                    if (document.body.className.indexOf('mac') != -1) {
                        $('#os-alert').show();
                        do_run = false;
                    }
                }
                if (demo.platforms.indexOf('mac') != -1 || !demo.platforms.length) $('#ico-mac').show(); else {
                    $('#ico-mac').hide();
                    if (document.body.className.indexOf('linux') != -1) {
                        $('#os-alert').show();
                        do_run = false;
                    }
                }

                //Initialize the demo.
                if (do_run) demo.prepare($content);
                last_run = do_run;

                //Store the demo.
                current_demo = demo;

                if (id != "main") {
                    $('#meta-area').show();
                }
            });
        });

    });

    $('.sidebar').append(sidebar_menu.el);

    sidebar_menu.select('main');
});