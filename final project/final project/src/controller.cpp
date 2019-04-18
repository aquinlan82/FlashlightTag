#include "ofApp.h"
#include "controller.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cv.h>

using namespace cv;

void Controller::setup(int width, int height, bool useCamera) {
	cam_width_ = width;
	cam_height_ = height;
	thresh_ = 250;
	color_img_.allocate(cam_width_, cam_height_);

	if (useCamera) {
		vid_grabber_.setDeviceID(0);
		vid_grabber_.setVerbose(true);
		vid_grabber_.setDesiredFrameRate(60);
		vid_grabber_.initGrabber(cam_width_, cam_height_);
	}
}

/* Update colored image from camera*/
void Controller::updateColorImg()
{
	vid_grabber_.update();
	color_img_.setFromPixels(vid_grabber_.getPixels());
	color_img_.mirror(false, true);
}

/* Use threshold to mask only bright spots*/
void Controller::updateMaskImg()
{
	int NUM_BLOBS = 25;
	int MAX_AREA = 10000;
	int MIN_AREA = 2000;
	mask_.clear();
	mask_ = color_img_;
	mask_.threshold(thresh_);
	contour_finder_.findContours(mask_, MIN_AREA, MAX_AREA, NUM_BLOBS, false, true);
}

/* Use picture mask instead of camera*/
void Controller::updateMaskImg(string filename)
{
	color_img_.allocate(1390, 675);
	ofImage temp(filename);
	color_img_.setFromPixels(temp.getPixels());
	updateMaskImg();
}

/* Set bright_spots using openCV*/
void Controller::findCircles()
{
	bright_spots_.clear();
	if (contour_finder_.blobs.size() > 0) {
		for (int i = 0; i < contour_finder_.nBlobs; i++) {
			vector<glm::vec3> points = contour_finder_.blobs.at(i).pts;
			vector<Point> allPixels;

			for (int j = 0; j < points.size(); j++) {
				Point temp(points[j].x, points[j].y);
				allPixels.push_back(temp);
			}

			Point2f center;
			float radius;
			minEnclosingCircle(allPixels, center, radius);

			bright_spots_.push_back({(int)center.x, (int)center.y, (int)radius, (int)contour_finder_.blobs.at(i).area});
		}

	}
}

/* Find location and size of cursor*/
vector<int> Controller::calculateCursor(vector<int> last_cursor, int display_radius)
{
	vector<int> spot_score;
	int circle_multiplier = 2;
	int radius_mulitplier = 1;
	int location_multiplier = 1;

	//find the most circly
	for (vector<int> spot : bright_spots_) {
		spot_score.push_back(100 * (int)(1 - (spot[AREA] / (PI * (spot[RADIUS] * spot[RADIUS]))) * circle_multiplier));
	}
	
	//find closest to good radius
	for (int i = 0; i < bright_spots_.size(); i++) {
		spot_score[i] += abs(bright_spots_[i][RADIUS] - display_radius) * radius_mulitplier;
	}
	
	//keep track of one paticular blob b/c continuity
	if (last_cursor[RADIUS] > 0) {
		for (int i = 0; i < bright_spots_.size(); i++) {
			spot_score[i] += abs(bright_spots_[i][X] - last_cursor[X]) + abs(bright_spots_[i][Y] - last_cursor[Y]) * location_multiplier;
		}
	}

	//find lowest score (best match)
	double min_score = MAXINT;
	vector<int> best_spot = { 0,0,0,0 };
	for (int i = 0; i < spot_score.size(); i++) {
		if (spot_score[i] < min_score) {
			min_score = spot_score[i];
			best_spot = bright_spots_[i];
		}
	}
	return best_spot;
}

void Controller::printBrightSpots()
{
	for (int spot = 0; spot < bright_spots_.size(); spot++) {
		cout << "X: " << bright_spots_[spot][X] << " Y: " << bright_spots_[spot][Y] << " Area: " << bright_spots_[spot][AREA] << endl;
	}
}

void Controller::setSize(int width, int height)
{
	cam_width_ = width;
	cam_height_ = height;
}

int Controller::getWidth()
{
	return cam_width_;
}

int Controller::getHeight()
{
	return cam_height_;
}

void Controller::addToThresh(int amount)
{
	thresh_ += amount;
}

ofVideoGrabber Controller::getCameraImage()
{
	return vid_grabber_;
}

ofxCvGrayscaleImage Controller::getMask()
{
	return mask_;
}

vector<vector<int>> Controller::getBrightSpots()
{
	return bright_spots_;
}
