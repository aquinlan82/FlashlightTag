#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

/*
Class that controls what the user sees
*/

class View {
public:
	int const RADIUS = 2;
	int const X = 0;
	int const Y = 1;

	int const BAR_HEIGHT = 20;
	int const INSTR_X = 50;
	int const INSTR_Y = 20;
	int const INSTR_SIZE = 14;

	void setupScreens(int width, int height);
	void drawGameScreen(std::vector<int> cursor, std::string goal, std::string filename);
	void drawWinScreen();
	void createMask(int cursor_x, int cursor_y, int cursor_r);
	void combineMaskAndRoom(int cursor_x, int cursor_y, int cursor_r);
	void loadRoom(std::string filename);
	void drawThreshold(std::vector<int> cursor, ofxCvGrayscaleImage mask);
	void drawStartScreen();

private:
	int cam_width_;
	int cam_height_;
	ofPixels combined_video_;
	ofImage hidden_screen_;
	ofPixels mask_;
	ofImage win_screen_;
	ofTexture video_texture_;
	ofTrueTypeFont	text;
};