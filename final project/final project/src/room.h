#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "door.h"
#include <vector>
/*
Contains data about each room the user can enter
*/
class Room {
private: 
	vector<Door> doors_;
	std::string name_;
	std::vector<std::string> img_filenames_;

public:
	Room(std::string name, vector<Door> doors);
	std::string openDoor(int side);
	std::string getName();
	std::string getImageName(int side);
};