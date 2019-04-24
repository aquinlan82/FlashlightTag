#include "door.h"

/* Creates a door that leads to a room called 'name' when 'key' is pressed */
Door::Door(string name, char key) {
	next_room_name_ = name;
	activation_key_ = key;
}

/* Returns name of room this door leads to */
string Door::getNextName() {
	return next_room_name_;
}

/* Returns key needed to open door */
char Door::getActivationKey() {
	return activation_key_;
}


