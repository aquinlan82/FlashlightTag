#include "ofApp.h"
#include <cv.h>
#include <highgui.h>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;

void ofApp::setup() {
	control.setupCamera(ofGetWidth(), ofGetHeight());
	view.setupScreens(ofGetWidth(), ofGetHeight());
}

void ofApp::update() {
	control.updateColorImg();
	if (control.vid_grabber_.isFrameNew()) {
		control.updateMaskImg();
		control.findCircles();
		vector<int> cursor = control.calculateCursor(model.cursor_x, model.cursor_y, model.cursor_r);
		model.setCursor(cursor[control.X], cursor[control.Y], cursor[control.RADIUS]);
	}
}

void ofApp::draw() {
	view.drawScreen(model.cursor_x, model.cursor_y);
}

//--------------------------------------------------------------//
void ofApp::keyPressed(int key) {
	std::cout << "thresh: " << control.thresh_ << std::endl;
	
	if (key == 's' || key == 'S') {
		control.vid_grabber_.videoSettings();
	}
	if (key == 'r') {
		control.thresh_ += 10;
	}
	if (key == 'f' ) {
		control.thresh_ -= 10;
	}
	if (key == 't') {
		control.thresh_ ++;
	}
	if (key == 'g') {
		control.thresh_ --;
	}
}

void ofApp::keyReleased(int key) {
}

void ofApp::mouseMoved(int x, int y) {
}

void ofApp::mouseDragged(int x, int y, int button) {
}

void ofApp::mousePressed(int x, int y, int button) {
}

void ofApp::mouseReleased(int x, int y, int button) {
}

void ofApp::mouseEntered(int x, int y) {
}

void ofApp::mouseExited(int x, int y) {
}

void ofApp::windowResized(int w, int h) {
}

void ofApp::gotMessage(ofMessage msg) {
}

void ofApp::dragEvent(ofDragInfo dragInfo) {
}



