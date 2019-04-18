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

	if ((current_goal_.getX() < cursor_x_ + win_radius && current_goal_.getX() > cursor_x_ - win_radius &&
		current_goal_.getY() < cursor_y_ + win_radius && current_goal_.getY() > cursor_y_ - win_radius) && game_state_ == GAME) {
		game_state_ = WIN;
		return true;
	}

	if (game_state_ == WIN) {
		game_state_ = WIN;
		return true;
	}
	return false;
}

void Model::generateGoals() {
	Goal temp;
	goals_.push_back(temp.set("an Orange Button", 790, 180));
	goals_.push_back(temp.set("Mickey Mouse", 213, 488));
	goals_.push_back(temp.set("the Letter R", 294, 110));
}

void Model::setGoal() {
	generateGoals();
	int index = rand() % (goals_.size());
	current_goal_ = goals_[index];
}

vector<int> Model::getCursor()
{
	vector<int> cursor;
	cursor.push_back(cursor_x_);
	cursor.push_back(cursor_y_);
	cursor.push_back(cursor_r_);
	return cursor;
}

string Model::getGoalName()
{
	return current_goal_.getName();
}

vector<int> Model::getGoalLocation() {
	vector<int> location = { current_goal_.getX(), current_goal_.getY() };
	return location;
}
