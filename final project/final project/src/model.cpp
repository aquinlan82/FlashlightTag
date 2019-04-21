#include "ofApp.h"
#include "controller.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cv.h>
#include "model.h"

using namespace cv;

void Model::setCursor(int x, int y, int radius) {
	cursor_x_ = x;
	cursor_y_ = y;
	cursor_r_ = radius;
}

bool Model::checkWin()
{
	int win_radius = cursor_r_ * win_sensitivity_;

	if (game_state_ == GAME && map.checkWin(win_radius, cursor_x_, cursor_y_)) {
		game_state_ = WIN;
		return true;
	}

	if (game_state_ == WIN) {
		game_state_ = WIN;
		return true;
	}
	return false;
}

vector<int> Model::getCursor()
{
	vector<int> cursor;
	cursor.push_back(cursor_x_);
	cursor.push_back(cursor_y_);
	cursor.push_back(cursor_r_);
	return cursor;
}

void Model::generateMap() {
	map.generateHouse();
}

std::string Model::getGoalName() {
	return map.getGoalName();
}

bool Model::try_open_door(char activation_key)
{
	return map.try_open_door(activation_key);
}

std::string Model::getFilename() {
	return map.getFilename();
}
