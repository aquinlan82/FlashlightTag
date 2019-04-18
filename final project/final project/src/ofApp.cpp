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
	control.setup(ofGetWidth(), ofGetHeight(), true);
	view.setupScreens(ofGetWidth(), ofGetHeight());
}

void ofApp::update() {
	control.updateColorImg();
	//if (control.getCameraImage().isFrameNew()) {
		control.updateMaskImg();
		control.findCircles();
		vector<int> cursor = control.calculateCursor(model.getCursor(), model.display_radius_);
		model.setCursor(cursor[control.X], cursor[control.Y], model.display_radius_);
		control.printBrightSpots();
	//}
	model.checkWin();
}

void ofApp::draw() {
	if (model.game_state_ == model.WIN) {
		view.drawWinScreen();
	}
	if (model.game_state_ == model.CALIBRATE) {
		view.drawThreshold(model.getCursor(), control.getMask());
	}
	if (model.game_state_ == model.GAME) {
		view.drawGameScreen(model.getCursor(), model.getGoalName());
	}
}

//--------------------------------------------------------------//
void ofApp::keyPressed(int key) {
	if (key == 's' || key == 'S') {
		control.getCameraImage().videoSettings();
	}
	if (key == 'r' || key == 'R') {
		control.addToThresh(10);
	}
	if (key == 'f' || key == 'F') {
		control.addToThresh(-10);
	}
	if (key == 't' || key == 'T') {
		control.addToThresh(1);
	}
	if (key == 'g' || key == 'G') {
		control.addToThresh(-1);
	}
	if (key == 'n' && model.game_state_ != model.GAME) {
		model.setGoal();
		model.game_state_ = model.GAME;
	}
	if (key == 'c' || key == 'C') {
		model.game_state_ = model.CALIBRATE;
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

