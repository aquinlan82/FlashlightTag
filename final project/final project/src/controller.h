#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class Controller {
//add _
public:
	int AREA = 3;
	int RADIUS = 2;
	int X = 0;
	int Y = 1;


	int cam_width_;
	int cam_height_;
	int thresh_;
	int cursor_radius_ = 30;
	vector<vector<int>> bright_spots_;
	ofVideoGrabber vid_grabber_;
	ofxCvColorImage color_img_;
	ofxCvContourFinder contour_finder_;
	ofxCvGrayscaleImage mask_;

	void setupCamera(int width, int height);
	void updateColorImg();
	void updateMaskImg();
	void findCircles();
	vector<int> calculateCursor(int last_x, int last_y, int last_r);

};