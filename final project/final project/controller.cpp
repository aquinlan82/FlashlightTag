#include "ofApp.h"
#include "controller.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cv.h>

using namespace cv;

/* Open set camera settings */
void Controller::setupCamera(int width, int height) {
	cam_width_ = width;  
	cam_height_ = height;
	thresh_ = 250;

	vid_grabber_.setDeviceID(0);
	vid_grabber_.setVerbose(true);
	vid_grabber_.setDesiredFrameRate(60);
	vid_grabber_.initGrabber(cam_width_, cam_height_);

	color_img_.allocate(cam_width_, cam_height_);
	mask_.allocate(cam_width_, cam_height_);
}

/* Update colored image from camera*/
void Controller::updateColorImg()
{
	vid_grabber_.update();
	color_img_.setFromPixels(vid_grabber_.getPixels());
	ofPixels& pixels = vid_grabber_.getPixels();
}

/* Use threshold to mask only bright spots*/
void Controller::updateMaskImg()
{
	mask_ = color_img_;
	mask_.threshold(thresh_);
	//magic numbers
	contour_finder_.findContours(mask_, 2000, 10000, 25, false, true);
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
vector<int> Controller::calculateCursor(int last_x, int last_y, int last_r)
{
	//fix magic numbers
	vector<int> spot_score;
	int circle_multiplier = 2;
	int radius_mulitplier = 1;
	int location_multiplier = 1;
	//find the most circly
	for (vector<int> spot : bright_spots_) {
		spot_score.push_back((int)(100 - 100 * (spot[AREA] / (PI * (spot[RADIUS] * spot[RADIUS]))) * circle_multiplier));
	}
	
	//find closest to good radius
	for (int i = 0; i < bright_spots_.size(); i++) {
		spot_score[i] += abs(bright_spots_[i][RADIUS] - cursor_radius_) * radius_mulitplier;
	}
	
	//keep track of one paticular blob b/c continuity
	if (last_r > 0) {
		for (int i = 0; i < bright_spots_.size(); i++) {
			spot_score[i] += abs(bright_spots_[i][X] - last_x) + abs(bright_spots_[i][Y] - last_y) * location_multiplier;
		}
	}

	//find lowest score (best match)
	double min_score = 30000;
	vector<int> best_spot = { 0,0,0,0 };
	for (int i = 0; i < spot_score.size(); i++) {
		if (spot_score[i] < min_score) {
			min_score = spot_score[i];
			best_spot = bright_spots_[i];
		}
	}
	return best_spot;
}
