CodeEditor = {};
CodeEditor.buttonBar = new TiUI.BlackButtonBar();


//
// Setup main view
//
CodeEditor.setupView = function()
{
	// set default UI state
	TiUI.setBackgroundColor('#06284D');
	TiDev.contentLeft.show();
	TiDev.contentLeftHideButton.show();
	TiDev.contentLeftShowButton.hide();
	
	
	
	CodeEditor.buttonBar.configure({id:'tiui_content_submenu',tabs:[],active:0});
	
	//CodeEditor.buttonBar.configure({id:'tiui_content_submenu',tabs:['<u>S</u>ave',' <img src="ceditor/images/add_folder.png">  Add new Folder ',' <img src="ceditor/images/add_code.png">  Add new File '],active:0});
	//CodeEditor.buttonBar.appendContent('<img style="position:absolute;left:15px;top:6px;cursor:pointer" title="refresh" id="feeds_refresh" src="modules/feeds/images/refresh.png"/>');
	
	CodeEditor.buttonBar.addListener(function(idx)
	{
		alert(idx);
		

	});
	
	
	
	
	CodeEditor.loadProjectFiles();
	
};

CodeEditor.loadProjectFiles = function()
{
	CodeEditor.currentProject = Projects.getProject();
	var resources = Ti.Filesystem.getFile(CodeEditor.currentProject.dir,"Resources");
	sysSep = Ti.Filesystem.getSeparator();


	function getRecursiveDirectoryListing(file){
		if (file.isDirectory()){
			var set = [];
			var children = file.getDirectoryListing();
			children.sort();
			for(var i=0;i<children.length;i++){
				var childSet = getRecursiveDirectoryListing(children[i]);
				for (var j=0;j<childSet.length;j++)
				{
					set.push(childSet[j]);
				}
			}
			sfile=file.nativePath().split(sysSep);
			sfile=sfile[sfile.length-1];
			return [[sfile,['javascript:_foo()',null,'folder'],set]];
		}else{
			sfile=file.nativePath().split(sysSep);
			sfile=sfile[sfile.length-1];
			if(sfile!='.DS_Store' && sfile!='.gitignore'){
				return [[sfile,['javascript:CodeEditor.edit("'+file.nativePath()+'")',null,CodeEditor.ext(sfile)]]];
			}else{
				return '';
			}
		}
	}


	jst_arrNodes = [];
	jst_arrNodes = getRecursiveDirectoryListing(resources);

	renderTree('tiui_content_left_body');
};


CodeEditor.ext = function(t)
{
	r = 'file';
	e = t.toLowerCase().split('.').pop();
	if(e=='png' || e=='jpg' || e=='gif'){
		r = 'picture';
	}
	if(e=='mp3' || e=='aac' || e=='m4a' || e=='ogg' || e=='webm'){
		r = 'music';
	}
	if(e=='mov' || e=='mp4' || e=='m4v'){
		r = 'movie';
	}
	if(e=='js' || e=='jss'){
		r = 'code';
	}
	if(e=='html' || e=='htm'){
		r = 'html';
	}
	if(e=='css'){
		r = 'css';
	}
	if(e=='pdf'){
		r = 'pdf';
	}
	if(e=='xml'){
		r = 'xml';
	}
	if(e=='txt'){
		r = 'txt';
	}
	if(e=='json'){
		r = 'json';
	}
	if(e=='py'){
		r = 'python';
	}
	if(e=='rb'){
		r = 'ruby';
	}
	if(e=='php'){
		r = 'php';
	}
	return r;
}

function aceChangeTheme(th){
	aceThemeSelected = 'ace/theme/'+th;
	//aceeditor.setTheme(aceThemeSelected);
}
function aceChangeFontSize(sz){
	aceFontSize = sz;
}

var aceeditor; // = ace.edit("codeeditor");
var aceFontSize = 12;
var aceThemeSelected = 'ace/theme/twilight';

var ddbrow;
try
{
	ddbrow = TiDev.db.execute('SELECT * from ACE');
	if(ddbrow.isValidRow()){
		aceThemeSelected = "ace/theme/"+ddbrow.fieldByName('theme');
		aceFontSize = ddbrow.fieldByName('font_size');
	}
}
catch(e){}

CodeEditor.edit = function(file)
{
	document.getElementById('codeeditor').innerHTML='';
	if(CodeEditor.ext(file)=='css' || CodeEditor.ext(file)=='html' || CodeEditor.ext(file)=='code' || CodeEditor.ext(file)=='json' || CodeEditor.ext(file)=='php' || CodeEditor.ext(file)=='python' || CodeEditor.ext(file)=='ruby' || CodeEditor.ext(file)=='xml'){
	
		
		$('#codeeditor').css({background:'#fff'});
		$('#tiui_content_body').css({background:'url(../../images/texturegrey.png)'});
		
		aceeditor = ace.edit("codeeditor");
		aceeditor.renderer.setShowPrintMargin(false);
		aceeditor.renderer.setShowGutter(true);
	    aceeditor.setTheme(aceThemeSelected);
		document.getElementById('codeeditor').style.fontSize=aceFontSize+'px';

	
		selectedFilePath = file;
		var ofile = Ti.Filesystem.getFile(file);
		str = ofile.read();
		str = str.toString();
		aceeditor.getSession().setValue(str);




	    var cssMode = require("ace/mode/css").Mode;
		var htmlMode = require("ace/mode/html").Mode;
		var javascriptMode = require("ace/mode/javascript").Mode;
		var jsonMode = require("ace/mode/json").Mode;
		var phpMode = require("ace/mode/php").Mode;
		var pythonMode = require("ace/mode/python").Mode;
		var rubyMode = require("ace/mode/ruby").Mode;
		var xmlMode = require("ace/mode/xml").Mode;

		if(CodeEditor.ext(file)=='css'){
			aceeditor.getSession().setMode(new cssMode());
		}
		if(CodeEditor.ext(file)=='html'){
			aceeditor.getSession().setMode(new htmlMode());
		}
		if(CodeEditor.ext(file)=='code'){
			aceeditor.getSession().setMode(new javascriptMode());
		}
		if(CodeEditor.ext(file)=='json'){
			aceeditor.getSession().setMode(new jsonMode());
		}
		if(CodeEditor.ext(file)=='php'){
			aceeditor.getSession().setMode(new phpMode());
		}
		if(CodeEditor.ext(file)=='python'){
			aceeditor.getSession().setMode(new pythonMode());
		}
		if(CodeEditor.ext(file)=='ruby'){
			aceeditor.getSession().setMode(new rubyMode());
		}
		if(CodeEditor.ext(file)=='xml'){
			aceeditor.getSession().setMode(new xmlMode());
		}	


	}else{
		$('#codeeditor').css({background:'transparent'});
		$('#tiui_content_body').css({background:'url(../../images/bgtransp.gif)'});
		if(CodeEditor.ext(file)=='music'){
			document.getElementById('codeeditor').innerHTML='<audio style="width:100%;" src="file://'+file+'" controls="controls"></audio>';
		}
		if(CodeEditor.ext(file)=='movie'){
			document.getElementById('codeeditor').innerHTML='<video src="file://'+file+'" controls="controls"></video>';
		}
		if(CodeEditor.ext(file)=='picture'){
			document.getElementById('codeeditor').innerHTML='<img src="file://'+file+'" />';
		}
		
	}
	if(document.getElementById('codeeditor').innerHTML==''){
		alert('This file type cannot be edited');
	}

}

var selectedFilePath = '';
function saveSelectedFile(){
	str = aceeditor.getSession().getValue();
	var ofile = Ti.Filesystem.getFile(selectedFilePath);
	ofile.write(str);
}



// setup event handler
CodeEditor.eventHandler = function(event)
{
	if (event == 'focus')
	{
		$('#tiui_content_body').css({background:'url(../../images/bgtransp.gif)'});
		CodeEditor.setupView();
	}
	else if (event == 'load')
	{
		$('#tiui_content_body').css({background:'url(../../images/bgtransp.gif)'});
		CodeEditor.setupView();
	}
	else if (event == 'blur')
	{
		$('#tiui_content_body').css({background:'url(../../images/texturegrey.png)'});
		CodeEditor.buttonBar.hide();
	}
};



// register module
TiDev.registerModule({
	name:'code_editor',
	displayName: 'Code <u>E</u>ditor',
	perspectives:['projects'],
	html:'code_editor.html',
	idx:3,
	callback:CodeEditor.eventHandler
});
