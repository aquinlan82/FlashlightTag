#include "map.h"

//house setup hardcoded
void Map::generateHouse()
{
	//entry
	rooms_.push_back(Room("entry", "entry1.jpg", vector<Door> { Door("living room", OF_KEY_UP), Door("kitchen", OF_KEY_LEFT)}));
	//kitchen
	rooms_.push_back(Room("kitchen", "kitchen1.jpg", vector<Door> { Door("entry", OF_KEY_DOWN), Door("bedroom", OF_KEY_RIGHT)}));
	//living room
	rooms_.push_back(Room("living room", "livingroom1.jpg", vector<Door> { Door("entry", OF_KEY_DOWN), Door("bedroom", OF_KEY_LEFT)}));
	//bedroom
	rooms_.push_back(Room("bedroom", "bed1.jpg", vector<Door> { Door("kitchen", OF_KEY_DOWN), Door("living room", OF_KEY_LEFT), Door("office", OF_KEY_RIGHT)}));
	//office
	rooms_.push_back(Room("office", "office1.jpg", vector<Door> { Door("bedroom", OF_KEY_DOWN)}));

	win_info_.push_back(1);
	win_info_.push_back(400);
	win_info_.push_back(400);

	goal_name_ = "doggo";
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
	cout << "Checking " << rooms_[current_index_].getName() << endl;
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

std::string Map::getGoalName() {
	return goal_name_;
}

std::string Map::getFilename() {
	return rooms_[current_index_].getImageName();
}