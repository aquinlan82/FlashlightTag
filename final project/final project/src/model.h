#pragma once

class Model {
private:
	class Goal {
		std::string name;
		int win_x_;
		int win_y_;
	public:
		Goal Goal::set(std::string name_in, int x_in, int y_in) {
			name = name_in;
			win_x_ = x_in;
			win_y_ = y_in;
			return *this;
		}

		std::string Goal::getName() {
			return name;
		}

		int Goal::getX() { return win_x_; }
		int Goal::getY() { return win_y_; }
	};

	int cursor_x_ = 0;
	int cursor_y_ = 0;
	int cursor_r_ = 0;
	double win_sensitivity_ = 0.5;
	std::vector<Goal> goals_;
	Goal current_goal_;


public:
	int display_radius_ = 30;
	enum states_ { CALIBRATE, GAME, WIN };
	int game_state_ = CALIBRATE;

	void setCursor(int x, int y, int radius);
	bool checkWin();
	void generateGoals();
	void setGoal();
	vector<int> getCursor();
	string getGoalName();
	vector<int> getGoalLocation();

};