#include "room.h"


Room::Room(std::string name, std::string image_name, vector<Door> doors)
{
	name_ = name;
	img_filename_ = image_name;

	for (Door door : doors) {
		doors_.push_back(door);
	}
}

/* Returns name of new room if able to open door, or current room if impossible */
std::string Room::openDoor(char activation_key)
{

	for (Door door : doors_) {
		if (door.getActivationKey() == activation_key) {
			return door.getNextName();
		}
	}
	return name_;
}

std::string Room::getName()
{
	return name_;
}

std::string Room::getImageName()
{
	return img_filename_;
}
