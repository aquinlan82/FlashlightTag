#include "map.h"

/* Creates the rooms in the house */
void Map::generateHouse() {
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
	{0,60,463},
	{0,481,514},
	{0,1186,108},
	{0,672,110},
	{1,422,134},
	{1,1160,596},
	{1,913,365},
	{1,227,278},
	{2,873,375},
	{2,737,633},
	{2,233,101},
	{2,548,247},
	{3,136,250},
	{3,1005,395},
	{3,462,422},
	{3,1254,381},
	{4,461,437},
	{4,54,366},
	{4,876,281},
	{4,495,533} };

	if (seed < 0 || seed >= names.size()) {
		seed = rand() % (names.size());
	}

	goal_name_ = names[seed];
	win_info_.clear();
	win_info_.push_back(coords[seed][WIN_INDEX]);
	win_info_.push_back(coords[seed][WIN_X]);
	win_info_.push_back(coords[seed][WIN_Y]);
}

/* Return name of current room */
std::string Map::getCurrentName() {
	return rooms_[current_index_].getName();
}

/* Checks that cursor is in location of goal and correct room */
bool Map::checkWin(int win_radius, int cursor_x, int cursor_y) {
	if (win_info_[WIN_INDEX] == current_index_ && 
		(win_info_[WIN_X] < cursor_x + win_radius && win_info_[WIN_X] > cursor_x - win_radius &&
		win_info_[WIN_Y] < cursor_y + win_radius && win_info_[WIN_Y] > cursor_y - win_radius)) {
		return true;
	}
	return false;
}

/* Changes current room to room opened by key. Returns true if successful false otherwise */
bool Map::tryOpenDoor(char activation_key) {
	std::string new_current_name = rooms_[current_index_].openDoor(activation_key);
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
	return rooms_[current_index_].getImageName();
}

/* Return win_info */
std::vector<int> Map::getWinInfo() {
	return win_info_;
}