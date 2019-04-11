#include "ofApp.h"
#include "controller.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cv.h>
#include "model.h"

using namespace cv;

void Model::setCursor(int x, int y, int radius) {
	cursor_x = x;
	cursor_y = y;
	cursor_r = radius;
}

bool Model::hasWon()
{
	int win_radius = cursor_r * win_sensitivity;
	if (win_x < cursor_x + win_radius && win_x > cursor_x - win_radius &&
		win_y < cursor_y + win_radius && win_y > cursor_y - win_radius) {
		return true;
	}
	return false;
}
