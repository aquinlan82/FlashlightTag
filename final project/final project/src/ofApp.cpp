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
	view.setupScreens(ofGetWidth(), ofGetHeight(), "entry1.jpg");
	model.generateMap();
}

void ofApp::update() {
	control.updateInput();
	vector<int> cursor = control.calculateCursor(model.getCursor(), model.display_radius_);
	model.setCursor(cursor[control.X], cursor[control.Y], model.display_radius_);
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
		view.drawGameScreen(model.getCursor(), model.getGoalName(), model.getFilename());
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
	if (key == ' ') {
		if (model.game_state_ == model.CALIBRATE) {
			model.game_state_ = model.GAME;
		}
		else if (model.game_state_ == model.GAME) {
			model.game_state_ = model.CALIBRATE;
		}
	}
	if (key == OF_KEY_UP || key == OF_KEY_DOWN || key == OF_KEY_LEFT || key == OF_KEY_RIGHT) {
		if (model.tryOpenDoor(key)) {
			view.loadRoom(model.getFilename());
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

