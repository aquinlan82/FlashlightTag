#include "ofApp.h"
#include "controller.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cv.h>

using namespace cv;

/* Find location and size of cursor*/
vector<int> MouseController::calculateCursor(vector<int> last_cursor, int display_radius) {
	vector<int> cursor = { ofGetMouseX(), ofGetMouseY(), display_radius, 0 };
	return cursor;
}

void MouseController::updateInput() {

}