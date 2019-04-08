#include "ofApp.h"
#include "controller.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cv.h>

using namespace cv;

void Controller::setupCamera() {
	cam_width = 320;  
	cam_height = 240;
	thresh = 250;

	vid_grabber.setDeviceID(0);
	vid_grabber.setVerbose(true);
	vid_grabber.setDesiredFrameRate(60);
	vid_grabber.initGrabber(cam_width, cam_height);

	color_img.allocate(cam_width, cam_height);
	mask.allocate(cam_width, cam_height);
}

void Controller::updateColorImg()
{
	vid_grabber.update();
	color_img.setFromPixels(vid_grabber.getPixels());
	ofPixels& pixels = vid_grabber.getPixels();
}

void Controller::updateMaskImg()
{
	mask = color_img;
	mask.threshold(thresh);
	//magic
	contour_finder.findContours(mask, 500, 2500, 25, false, true);
}

void Controller::findCircles()
{
	bright_spots.clear();
	if (contour_finder.blobs.size() > 0) {
		for (int i = 0; i < contour_finder.nBlobs; i++) {
			vector<glm::vec3> points = contour_finder.blobs.at(i).pts;
			vector<Point> allPixels;

			for (int j = 0; j < points.size(); j++) {
				Point temp(points[j].x, points[j].y);
				allPixels.push_back(temp);
			}

			Point2f center;
			float radius;
			minEnclosingCircle(allPixels, center, radius);

			bright_spots.push_back({(int)center.x, (int)center.y, (int)radius, (int)contour_finder.blobs.at(i).area});
		}

	}
}

vector<int> Controller::calculateCursor(int last_x, int last_y, int last_r)
{
	vector<int> spot_score;
	int circle_multiplier = 1;
	int radius_mulitplier = 1;
	int location_multiplier = 1;
	std::cout << "==================================" << std::endl;
	//find the most circly
	for (vector<int> spot : bright_spots) {
		spot_score.push_back((int)(100 - 100 * (spot[3] / (PI * (spot[RADIUS] * spot[RADIUS]))) * circle_multiplier));
		std::cout << ((int)(100 - 100 * (spot[3] / (PI * (spot[RADIUS] * spot[RADIUS]))) * circle_multiplier)) << " ";
	}
	std::cout << std::endl;
	
	//find closest to good radius
	int good_radius = 20;
	for (int i = 0; i < bright_spots.size(); i++) {
		spot_score[i] += abs(bright_spots[i][RADIUS] - good_radius) * radius_mulitplier;
		std::cout << abs(bright_spots[i][RADIUS] - good_radius) * radius_mulitplier << " ";
	}
	std::cout << std::endl;
	
	//keep track of one paticular blob b/c continuity
	if (last_r > 0) {
		for (int i = 0; i < bright_spots.size(); i++) {
			spot_score[i] += abs(bright_spots[i][X] - last_x) + abs(bright_spots[i][Y] - last_y) * location_multiplier;
			std::cout << abs(bright_spots[i][X] - last_x) + abs(bright_spots[i][Y] - last_y) * location_multiplier << " ";
		}
	}
	std::cout << std::endl;

	//find lowest score (best match)
	double min_score = 30000;
	vector<int> best_spot = { 0,0,0,0 };
	for (int i = 0; i < spot_score.size(); i++) {
		std::cout << spot_score[i] << " ";
		if (spot_score[i] < min_score) {
			min_score = spot_score[i];
			best_spot = bright_spots[i];
		}
	}
	std::cout << std::endl;
	return best_spot;
}
