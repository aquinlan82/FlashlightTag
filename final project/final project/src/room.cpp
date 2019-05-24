#include "room.h"

/* Creates a room with a name, image, and doors*/
Room::Room(std::string name, vector<Door> doors) {
	name_ = name;
	for (int i = 0; i < 4; i++) {
		img_filenames_.push_back(name + to_string(i) + ".jpg");
	}

	for (Door door : doors) {
		doors_.push_back(door);
	}
}

/* Returns name of new room if able to open door, or current room if impossible */
std::string Room::openDoor(int side) {
	for (Door door : doors_) {
		if (door.getSide() == side) {
			return door.getNextName();
		}
	}
	return name_;
}

/* Returns name of room */
std::string Room::getName() {
	return name_;
}

/* Returns filename of image for this room*/
std::string Room::getImageName(int side) {
	return img_filenames_[side];
}
