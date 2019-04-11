#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class View {
public:
	int cam_width;
	int cam_height;
	ofPixels combined_video;
	ofImage hidden_screen;
	ofPixels mask;
	ofTexture video_texture;

	void setupScreens(int width, int height);
	void drawScreen(int cursor_x, int cursor_y);
	void createMask(int cursor_x, int cursor_y);
	void combineMaskAndRoom(int cursor_x, int cursor_y);
	void loadRoom();
};