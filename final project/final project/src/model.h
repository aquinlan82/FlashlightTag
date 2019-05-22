#pragma once

#include "map.h"

class Model {
private:
	int cursor_x_ = 0;
	int cursor_y_ = 0;
	int cursor_r_ = 0;
	double win_sensitivity_ = 0.5;
	Map map_;


public:
	int display_radius_ = 50;
	enum states_ { CALIBRATE, GAME, WIN, START };
	int game_state_ = START;

	void setCursor(int x, int y, int radius);
	bool checkWin();
	void generateMap();
	vector<int> getCursor();
	std::string getGoalName();
	bool tryOpenDoor(char activation_key);
	std::string getFilename();
	vector<int> getGoalLocation();
	void setGoal(int seed);
};