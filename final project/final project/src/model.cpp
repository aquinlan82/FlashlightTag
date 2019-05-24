#include "ofApp.h"
#include "controller.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cv.h>
#include "model.h"

using namespace cv;

/* Initializes class data */
void Model::setup(int width) {
	map_.generateHouse();
	screen_width_ = width;
}

/* Sets location and size of cursor  and rotates if needed*/
void Model::setCursor(int x, int y, int radius) {
	if (x > 0 && y > 0 && radius > 0) {
		cursor_x_ = x;
		cursor_y_ = y;
		cursor_r_ = radius;
	}
	if (x < ROTATE_SIZE && x > 0 && !rotated_) {
		side_--;
		rotated_ = true;
	} 
	if (x > screen_width_ - ROTATE_SIZE && !rotated_) {
		side_++;
		rotated_ = true;
	}
	if (x > ROTATE_SIZE && x < screen_width_ - ROTATE_SIZE) {
		rotated_ = false;
	}
	side_ = mod(side_, 4);
	map_.setSide(side_);
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
bool Model::tryOpenDoor() {
	return map_.tryOpenDoor();
}

/* Returns filename of image for current room*/
std::string Model::getFilename() {
	return map_.getFilename();
}

/* Returns vector of info about winning location*/
std::vector<int> Model::getGoalLocation() {
	return map_.getWinInfo();
}

/* Creates possible goals and sets one to find*/
void Model::setGoal(int seed) {
	map_.generateGoals(seed);
}

/* Modulo */
int Model::mod(int a, int b) { 
	return a >= 0 ? a % b : (b - abs(a%b)) % b; 
}
