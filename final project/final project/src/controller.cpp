#include "ofApp.h"
#include "controller.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cv.h>

using namespace cv;

/* Initializes variables and camera if needed */
void Controller::setup(int width, int height, bool useCamera) {
	cam_width_ = width;
	cam_height_ = height;
	thresh_ = DEFAULT_THRESH;
	color_img_.allocate(cam_width_, cam_height_);

	if (useCamera) {
		vid_grabber_.setDeviceID(0);
		vid_grabber_.setVerbose(true);
		vid_grabber_.setDesiredFrameRate(60);
		vid_grabber_.initGrabber(cam_width_, cam_height_);
	}
}

/* Prints all found blobs. Used in debugging */
void Controller::printBrightSpots() {
	for (int spot = 0; spot < bright_spots_.size(); spot++) {
		cout << "X: " << bright_spots_[spot][X] << " Y: " << bright_spots_[spot][Y] << " Area: " << bright_spots_[spot][AREA] << endl;
	}
}

/* Set width and height of screen*/
void Controller::setSize(int width, int height) {
	if (width > 0 && height > 0) {
		cam_width_ = width;
		cam_height_ = height;
	}
}

int Controller::getWidth() {
	return cam_width_;
}

int Controller::getHeight() {
	return cam_height_;
}

void Controller::addToThresh(int amount) {
	thresh_ += amount;
}

ofVideoGrabber Controller::getCameraImage() {
	return vid_grabber_;
}

ofxCvGrayscaleImage Controller::getMask() {
	return mask_;
}

vector<vector<int>> Controller::getBrightSpots() {
	return bright_spots_;
}

/* Not strictly needed for mouse but used for inheritance reasons */
void Controller::updateInput() {
	
}

