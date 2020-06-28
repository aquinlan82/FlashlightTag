#include "ofMain.h"
#include "ofApp.h"

/***
Flashlight Tag
Created by Allison Quinlan for CS 126
May 2019
***/

int main() {
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	int horizontal = desktop.right;
	int vertical = desktop.bottom;

	ofSetupOpenGL(horizontal, vertical, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
