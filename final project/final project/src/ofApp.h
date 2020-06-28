#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "controller.h"
#include "view.h"
#include "model.h"

/*
Upper level control of the program
*/
class ofApp : public ofBaseApp {
private:
	Controller* control_;
	FlashController flash_;
	MouseController mouse_;
	Model model_;
	View view_;

public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};


