var ti = Titanium;
var desktopPath = ti.Filesystem.getDesktopDirectory();
var format = Titanium.platform == "osx" ? "png" : "bmp";
var screenshotFile = ti.Filesystem.getFile(desktopPath, "screenshot."+format);
var screenshotPath = screenshotFile.nativePath();

function takeScreenshot()
{
	$("#message").html("Saving screenshot...");
	Titanium.Desktop.takeScreenshot(screenshotPath);
	$("#message").html("Done!");
	
	$("#image").html("<img src=\"file:///"+screenshotPath+"\" />");
}

