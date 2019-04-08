#include "ofApp.h"
#include "controller.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cv.h>

using namespace cv;

void Model::setCursor(int x, int y, int radius) {
	cursor_x = x;
	cursor_y = y;
	cursor_r = radius;
}