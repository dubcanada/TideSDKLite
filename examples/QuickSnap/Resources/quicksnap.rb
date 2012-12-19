require 'fileutils'
#require 'RMagick'
#include Magick

SNAPSHOTS_DIR = Titanium.App.appURLToPath("app://snapshots")
FileUtils.mkdir_p(SNAPSHOTS_DIR)

$zoom_step_w = 75
$zoom_step_h = 75
$snapshot_filename = nil
def take_snapshot
  $snapshot_filename = File.join(SNAPSHOTS_DIR, "snapshot_"+rand(10000).to_s+".png")
  Titanium.Desktop.takeScreenshot($snapshot_filename)
  
  document.getElementById('editarea-content').innerHTML = <<IMG
  <img id="snapshot" src="file:///#{$snapshot_filename}"/>
IMG
  snapshot = document.getElementById('snapshot')
  snapshot.onmousewheel = method(:zoom_image)
  #snapshot.onmousedown = method(:start_dragging)
  #snapshot.onmousemove = method(:drag)  
end

def zoom_image(event)
  snapshot = document.getElementById('snapshot')
  zoom_factor = 1
  if event.wheelDelta < 0
    zoom_factor = -1
  end
  
  if snapshot != nil
    snapshot.width -= ($zoom_step_w*zoom_factor)
    snapshot.height -= ($zoom_step_h*zoom_factor)
  end
end

$top = 0
$left = 0
$width = 0
$height = 0
$dragging = false
def start_dragging(event)
  if $dragging
    stop_dragging(event)
  end
  
  $dragging = true
  $drag_area = document.createElement('div')
  $drag_area.setAttribute('id', 'dragarea')
  document.body.appendChild($drag_area)
  
  $top = event.y
  $left = event.x
  $drag_area.style.top = "#{event.y}px"
  $drag_area.style.left = "#{event.x}px"
  $drag_area.style.width = "5px"
  $drag_area.style.height = "5px"
  $drag_area.onmouseup = method(:stop_dragging)
  $drag_area.onmousedown = method(:stop_dragging)
end

def stop_dragging(event=nil)
  if $dragging
    $dragging = false
    #crop_area()
    document.body.removeChild($drag_area)
    $drag_area = nil
  end
end

def drag(event)
  if !$dragging or document.getElementById('dragarea') == nil
    return
  end
  
  $width = event.x - $left
  $height = event.y - $top
  document.getElementById('dragarea').style.width = "#{$width}px"
  document.getElementById('dragarea').style.height = "#{$height}px"
end

def crop_area
	# TODO: finish cropping code
  #snapshot = Magick::ImageList.new($snapshot_filename)
  #cropped = snapshot.crop($top, $left, $width, $height)
  #cropped_filename = File.join(SNAPSHOTS_DIR, "snapshot_"+rand(10000).to_s+"_cropped.png")

  #cropped.write(cropped_filename)
  #window.alert("file://#{cropped_filename}")
  #document.getElementById('snapshot').src = "file://#{cropped_filename}"
end
