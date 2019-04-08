#include "ofApp.h"
#include "controller.h"
#include <cv.h>

void Controller::setupCamera() {
	cam_width = 320;  
	cam_height = 240;
	thresh = 250;

	vid_grabber.setDeviceID(0);
	vid_grabber.setVerbose(true);
	vid_grabber.setDesiredFrameRate(60);
	vid_grabber.initGrabber(cam_width, cam_height);
}
