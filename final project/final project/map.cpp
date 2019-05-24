#include "map.h"

/* Creates the rooms in the house */
void Map::generateHouse() {
	//entry
	rooms_.push_back(Room("entry", vector<Door> { Door("livingroom", 2), Door("kitchen", 1)}));
	//kitchen
	rooms_.push_back(Room("kitchen", vector<Door> { Door("entry", 3), Door("bedroom", 2)}));
	//living room
	rooms_.push_back(Room("livingroom", vector<Door> { Door("entry", 0), Door("bedroom", 1)}));
	//bedroom
	rooms_.push_back(Room("bedroom", vector<Door> { Door("kitchen", 0), Door("livingroom", 3), Door("office", 2)}));
	//office
	rooms_.push_back(Room("office", vector<Door> { Door("bedroom", 0)}));

	generateGoals(-1);
}

/* Randomly selects a goal object and sets win_info */
void Map::generateGoals(int seed) {
	vector<std::string> names = { "a broom", "a red chair", "an old phone", "a painting of a man wearing green",
	"an oven mitt", "a corn magnet", "a chicken", "many spoons",
	"the Count from Seasame Street", "a pair of glasses sitting on a laptop", "a glass chandelier", "a green lamp",
	"a blue milk crate", "2 desk lamps", "the words 'Handle with Care'", "a sign that says 'dangerous'",
	"a white keyboard", "a computer tower", "a printer", "a black desk chair"};
	vector<vector<int>> coords = {
	{0,60,463,1},
	{0,481,514,1},
	{0,1186,108,1},
	{0,672,110,1},
	{1,422,134,1},
	{1,1160,596,1},
	{1,913,365,1},
	{1,227,278,1},
	{2,873,375,1},
	{2,737,633,1},
	{2,233,101,1},
	{2,548,247,1},
	{3,136,250,1},
	{3,1005,395,1},
	{3,462,422,1},
	{3,1254,381,1},
	{4,461,437,1},
	{4,54,366,1},
	{4,876,281,1},
	{4,495,533,1} };

	if (seed < 0 || seed >= names.size()) {
		seed = rand() % (names.size());
	}

	goal_name_ = names[seed];
	win_info_.clear();
	win_info_.push_back(coords[seed][WIN_INDEX]);
	win_info_.push_back(coords[seed][WIN_X]);
	win_info_.push_back(coords[seed][WIN_Y]);
	win_info_.push_back(coords[seed][WIN_SIDE]);
}

/* Return name of current room */
std::string Map::getCurrentName() {
	return rooms_[current_index_].getName();
}

/* Checks that cursor is in location of goal and correct room */
bool Map::checkWin(int win_radius, int cursor_x, int cursor_y) {
	if (win_info_[WIN_INDEX] == current_index_ && 
		win_info_[WIN_SIDE] == current_side_ &&
		(win_info_[WIN_X] < cursor_x + win_radius && win_info_[WIN_X] > cursor_x - win_radius &&
		win_info_[WIN_Y] < cursor_y + win_radius && win_info_[WIN_Y] > cursor_y - win_radius)) {
		return true;
	}
	return false;
}

/* Changes current room to room opened by key. Returns true if successful false otherwise */
bool Map::tryOpenDoor() {
	std::string new_current_name = rooms_[current_index_].openDoor(current_side_);
	if (new_current_name == rooms_[current_index_].getName()) {
		return false;
	}
	for (int i = 0; i < rooms_.size(); i++) {
		if (rooms_[i].getName() == new_current_name) {
			current_index_ = i;
			return true;
		}
	}
	return false;
}

/* Return name of goal item*/
std::string Map::getGoalName() {
	return goal_name_;
}

/* Return filename for image of the current room */
std::string Map::getFilename() {
	return rooms_[current_index_].getImageName(current_side_);
}

/* Return win_info */
std::vector<int> Map::getWinInfo() {
	return win_info_;
}

/* Sets side currently faced*/
void Map::setSide(int side) {
	current_side_ = side;
}