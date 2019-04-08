#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class Controller {
//add _
public:
	int RADIUS = 2;
	int X = 0;
	int Y = 1;


	int cam_width;
	int cam_height;
	int thresh;
	vector<vector<int>> bright_spots;
	ofVideoGrabber vid_grabber;
	ofxCvColorImage color_img;
	ofxCvContourFinder contour_finder;
	ofxCvGrayscaleImage mask;

	void setupCamera();
	void updateColorImg();
	void updateMaskImg();
	void findCircles();
	vector<int> calculateCursor(int last_x, int last_y, int last_r);

};