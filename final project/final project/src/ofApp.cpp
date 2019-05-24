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
	control_ = &flash_;
	(*control_).setup(ofGetWidth(), ofGetHeight(), true);
	view_.setupScreens(ofGetWidth(), ofGetHeight());
	model_.setup(ofGetWidth());
}

void ofApp::update() {
	(*control_).updateInput();
	vector<int> cursor = (*control_).calculateCursor(model_.getCursor(), model_.display_radius_);
	model_.setCursor(cursor[(*control_).X], cursor[(*control_).Y], model_.display_radius_);
	model_.checkWin();
}

void ofApp::draw() {
	if (model_.game_state_ == model_.START) {
		view_.drawStartScreen();
	}
	if (model_.game_state_ == model_.WIN) {
		view_.drawWinScreen();
	}
	if (model_.game_state_ == model_.CALIBRATE) {
		view_.drawThreshold(model_.getCursor(), (*control_).getMask());
	}
	if (model_.game_state_ == model_.GAME) {
		view_.drawGameScreen(model_.getCursor(), model_.getGoalName(), model_.getFilename());
	}
}

//--------------------------------------------------------------//
void ofApp::keyPressed(int key) {
	if (key == 's' || key == 'S') {
		(*control_).getCameraImage().videoSettings();
	}
	if (key == 'r' || key == 'R') {
		(*control_).addToThresh(10);
	}
	if (key == 'f' || key == 'F') {
		(*control_).addToThresh(-10);
	}
	if (key == 't' || key == 'T') {
		(*control_).addToThresh(1);
	}
	if (key == 'g' || key == 'G') {
		(*control_).addToThresh(-1);
	}
	if (key == ' ') {
		if (model_.game_state_ == model_.CALIBRATE) {
			model_.game_state_ = model_.GAME;
		} else if (model_.game_state_ == model_.GAME) {
			model_.game_state_ = model_.CALIBRATE;
		} else if (model_.game_state_ == model_.START) {
			model_.game_state_ = model_.CALIBRATE;
		} else if (model_.game_state_ == model_.WIN) {
			model_.generateMap();
			model_.game_state_ = model_.GAME;
		}
	}
	if (key == OF_KEY_UP) {
		if (model_.tryOpenDoor()) {
			view_.loadRoom(model_.getFilename());
		}
	}
	if (key == 'm' || key == 'M') {
		if (control_ == &mouse_) {
			control_ = &flash_;
		} else {
			control_ = &mouse_;
		}
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

