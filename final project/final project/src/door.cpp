#include "door.h"

/* Creates a door that leads to a room called 'name' when 'key' is pressed */
Door::Door(string name, int side) {
	next_room_name_ = name;
	side_ = side;
}

/* Returns name of room this door leads to */
string Door::getNextName() {
	return next_room_name_;
}

/* Returns key needed to open door */
int Door::getSide() {
	return side_;
}


