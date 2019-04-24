#include "ofApp.h"
#include "controller.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cv.h>
#include "model.h"

using namespace cv;

/* Sets location and size of cursor */
void Model::setCursor(int x, int y, int radius) {
	if (x > 0 && y > 0 && radius > 0) {
		cursor_x_ = x;
		cursor_y_ = y;
		cursor_r_ = radius;
	}
}

/* Checks that cursor is in goal location and game state is correct */
bool Model::checkWin() {
	int win_radius = cursor_r_ * win_sensitivity_;

	if (game_state_ == GAME && map_.checkWin(win_radius, cursor_x_, cursor_y_)) {
		game_state_ = WIN;
		return true;
	}

	if (game_state_ == WIN) {
		game_state_ = WIN;
		return true;
	}

	return false;
}

/* Returns cursor as a vector: {x, y, radius} */
vector<int> Model::getCursor() {
	vector<int> cursor;
	cursor.push_back(cursor_x_);
	cursor.push_back(cursor_y_);
	cursor.push_back(cursor_r_);
	return cursor;
}

/* Creates rooms */
void Model::generateMap() {
	map_.generateHouse();
}

/* Returns name of goal object */
std::string Model::getGoalName() {
	return map_.getGoalName();
}

/* Returns true if room changed, false otherwise */
bool Model::tryOpenDoor(char activation_key) {
	return map_.tryOpenDoor(activation_key);
}

/* Returns filename of image for current room*/
std::string Model::getFilename() {
	return map_.getFilename();
}

std::vector<int> Model::getGoalLocation() {
	return map_.getWinInfo();
}

void Model::setGoal(int seed) {
	map_.generateGoals(seed);
}
