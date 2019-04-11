#pragma once

class Model {
public:
	int cursor_x = 0;
	int cursor_y = 0;
	int cursor_r = 0;
	int win_x = 120;
	int win_y = 40;
	double win_sensitivity = 0.5;

	void setCursor(int x, int y, int radius);
	bool hasWon();

};
