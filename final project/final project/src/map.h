#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "room.h"

class Map {
private:
	vector<Room> rooms_;
	int current_index_;
	int current_side_;
	vector<int> win_info_;
	std::string goal_name_;

public:
	const int WIN_INDEX = 0;
	const int WIN_X = 1;
	const int WIN_Y = 2;
	const int WIN_SIDE = 3;

	void generateHouse();
	void generateGoals(int seed);
	std::string getCurrentName();
	bool checkWin(int win_radius, int cursor_x, int cursor_y);
	bool tryOpenDoor();
	std::string getGoalName();
	std::string getFilename();
	std::vector<int> getWinInfo();
	void setSide(int side);
};