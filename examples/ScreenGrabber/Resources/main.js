var desktopPath = Ti.Filesystem.getDesktopDirectory();
var format = Ti.platform == "osx" ? "png" : "bmp";
var screenshotFile = Ti.Filesystem.getFile(desktopPath, "screenshot."+format);
var screenshotPath = screenshotFile.nativePath();

function takeScreenshot()
{
	$("#message").html("Saving screenshot...");
	Ti.Desktop.takeScreenshot(screenshotPath);
	$("#message").html("Done!");
	
	$("#image").html("<img src=\"file:///"+screenshotPath+"\" />");
}

