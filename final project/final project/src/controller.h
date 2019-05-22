#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class Controller {

public:
	int const AREA = 3;
	int const RADIUS = 2;
	int const X = 0;
	int const Y = 1;
	int const DEFAULT_THRESH = 250;

	void setup(int width, int height, bool useCamera);
	virtual void updateInput() = 0;
	virtual vector<int> calculateCursor(std::vector<int> last_cursor, int disp_radius) = 0;
	void setSize(int width, int height);
	int getWidth();
	int getHeight();
	void addToThresh(int amount);
	ofVideoGrabber getCameraImage();
	ofxCvGrayscaleImage getMask();
	vector<vector<int>> getBrightSpots();
	void printBrightSpots();
	Controller& operator= (const Controller &controller);

protected:
	int cam_width_;
	int cam_height_;
	int thresh_;
	vector<vector<int>> bright_spots_;
	ofVideoGrabber vid_grabber_;
	ofxCvColorImage color_img_;
	ofxCvContourFinder contour_finder_;
	ofxCvGrayscaleImage mask_;
};

class FlashController : public Controller {
public:
	void updateColorImg();
	void updateMaskImg();
	void updateMaskImg(string filename);
	void findCircles();

	virtual void updateInput();
	virtual vector<int> calculateCursor(std::vector<int> last_cursor, int disp_radius);
};


class MouseController : public Controller {
public:
	virtual vector<int> calculateCursor(std::vector<int> last_cursor, int disp_radius);
	virtual void updateInput();
};