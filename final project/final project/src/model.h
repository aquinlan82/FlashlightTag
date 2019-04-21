#pragma once

#include "map.h"

class Model {
private:
	

	int cursor_x_ = 0;
	int cursor_y_ = 0;
	int cursor_r_ = 0;
	double win_sensitivity_ = 0.5;
	Map map;


public:
	int display_radius_ = 30;
	enum states_ { CALIBRATE, GAME, WIN };
	int game_state_ = CALIBRATE;

	void setCursor(int x, int y, int radius);
	bool checkWin();
	void generateMap();
	vector<int> getCursor();
	std::string getGoalName();
	bool try_open_door(char activation_key);
	std::string getFilename();
};