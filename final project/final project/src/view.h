#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class View {
public:
	int cam_width;
	int cam_height;
	ofPixels combined_video;
	ofPixels hidden_screen;
	ofTexture video_texture;

	void setupScreens(int width, int height);
	void loadHiddenScreen();
	void combineScreens();
	void drawScreen();
};