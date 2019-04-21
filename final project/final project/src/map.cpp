#include "map.h"

void Map::generateHouse()
{

}

std::string Map::getCurrentName()
{
	return rooms_[current_index_].getName();
}

bool Map::checkWin(int win_radius, int cursor_x, int cursor_y)
{
	if ((win_info_[WIN_X] < cursor_x + win_radius && win_info_[WIN_X] > cursor_x - win_radius &&
		win_info_[WIN_Y] < cursor_y + win_radius && win_info_[WIN_Y] > cursor_y - win_radius)) {
		return true;
	}
	return false;
}

bool Map::try_open_door(char activation_key)
{
	std::string current_name = rooms_[current_index_].openDoor(activation_key);
	if (current_name == rooms_[current_index_].getName()) {
		return false;
	}
	for (int i = 0; i < rooms_.size(); i++) {
		if (rooms_[i].getName() == current_name) {
			current_index_ = i;
			break;
		}
	}
	return true;
}

bool Map::getGoalName() {
	return goal_name_;
}