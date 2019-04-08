#include "ofApp.h"
#include <cv.h>
#include <highgui.h>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

//?
using namespace cv;

void ofApp::setup() {
	control.setupCamera();
	view.setupScreens(control.cam_width, control.cam_height);
}

void ofApp::update() {
	ofBackground(100, 100, 100);
	control.updateColorImg();
	if (control.vid_grabber.isFrameNew()) {
		control.updateMaskImg();
		control.findCircles();
		vector<int> cursor = control.calculateCursor(model.cursor_x, model.cursor_y, model.cursor_r);
		model.setCursor(cursor[0], cursor[1], cursor[2]);
	}
}

void ofApp::draw() {
	
	ofSetHexColor(0xffffff);

	ofTexture video_texture;
	video_texture.loadData(control.mask.getPixels());
	video_texture.draw(20 + 320, 20, 320, 240);
	
	control.vid_grabber.draw(20, 20);

	ofSetColor(255, 0, 0);
	ofDrawCircle(model.cursor_x + 20, model.cursor_y + 20, 20);

}

//--------------------------------------------------------------//
void ofApp::keyPressed(int key) {
	std::cout << "thresh: " << control.thresh << std::endl;
	
	if (key == 's' || key == 'S') {
		control.vid_grabber.videoSettings();
	}
	if (key == 'r') {
		control.thresh += 10;
	}
	if (key == 'f' ) {
		control.thresh -= 10;
	}
	if (key == 't') {
		control.thresh ++;
	}
	if (key == 'g') {
		control.thresh --;
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
