#include "ofApp.h"
#include <cv.h>
#include <highgui.h>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;

//--------------------------------------------------------------
void ofApp::setup() {
	cam_width = 320;  // try to grab at this size.
	cam_height = 240;
	thresh = 250;

	//get back a list of devices.
	vector<ofVideoDevice> devices = vid_grabber.listDevices();

	for (size_t i = 0; i < devices.size(); i++) {
		if (devices[i].bAvailable) {
			//log the device
			ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
		}
		else {
			//log the device and note it as unavailable
			ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
		}
	}

	vid_grabber.setDeviceID(0);
	vid_grabber.setVerbose(true);
	vid_grabber.setDesiredFrameRate(60);
	vid_grabber.initGrabber(cam_width, cam_height);

	combined_video.allocate(cam_width, cam_height, OF_PIXELS_RGB);
	hidden_screen.allocate(cam_width, cam_height, OF_PIXELS_RGB);
	ofSetVerticalSync(true);

	grayDiff.allocate(320, 240);
}


//--------------------------------------------------------------
void ofApp::update() {
	ofxCvColorImage color_temp;
	color_temp.allocate(320, 240);

	ofBackground(100, 100, 100);
	vid_grabber.update();

	ofLoadImage(hidden_screen, "test.jpg");

	if (vid_grabber.isFrameNew()) {
		color_temp.setFromPixels(vid_grabber.getPixels());
		ofPixels & pixels = vid_grabber.getPixels();
		for (int x = 0; x < cam_width; x++) {
			for (int y = 0; y < cam_height; y++) {
				if (pixels.getColor(x, y).getBrightness() > 250) {
					combined_video.setColor(x, y, hidden_screen.getColor(x, y));
				}
				else {
					combined_video.setColor(x, y, ofColor::black);
				}
			}
		}	
		color_temp.setFromPixels(vid_grabber.getPixels());
		grayDiff = color_temp;
		grayDiff.threshold(thresh);
		contourFinder.findContours(grayDiff, 5, 10000 / 4, 5, false, true);
		
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetHexColor(0xffffff);
	vid_grabber.draw(20, 20);
	video_texture.draw(20 + cam_width, 20, cam_width, cam_height);
	grayDiff.draw(20, 20 + cam_height, cam_width, cam_height);
	
	for (int i = 0; i < contourFinder.nBlobs; i++) {
		ofRectangle r = contourFinder.blobs.at(i).boundingRect;
		r.x += 320; r.y += 240;
		ofColor c(255, 255, 255);
		ofSetColor(c);
		ofDrawRectangle(r);
	}
	temp();
}

void ofApp::temp() {
	if (contourFinder.blobs.size() > 0) {
		for (int i = 0; i < contourFinder.nBlobs; i++) {
			vector<glm::vec3> points = contourFinder.blobs.at(i).pts;
			//find min enclosed ellipse
			//calculate percent filled
			//use highest percent as cursor
		}
	
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	// in fullscreen mode, on a pc at least, the 
	// first time video settings the come up
	// they come up *under* the fullscreen window
	// use alt-tab to navigate to the settings
	// window. we are working on a fix for this...

	// Video settings no longer works in 10.7
	// You'll need to compile with the 10.6 SDK for this
	// For Xcode 4.4 and greater, see this forum post on instructions on installing the SDK
	// http://forum.openframeworks.cc/index.php?topic=10343
	std::cout << "thresh: " << thresh << std::endl;
	
	if (key == 's' || key == 'S') {
		vid_grabber.videoSettings();
	}
	if (key == 'r') {
		thresh += 10;
	}
	if (key == 'f' ) {
		thresh -= 10;
	}
	if (key == 't') {
		thresh ++;
	}
	if (key == 'g') {
		thresh --;
	}
}





//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}
