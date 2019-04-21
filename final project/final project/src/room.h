#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "door.h"

class Room {
private: 
	vector<Door> doors_;
	std::string name_;
	std::string img_filename_;

public:
	Room(std::string name, std::string image_name, vector<Door> doors);
	std::string openDoor(char activation_key);
	std::string getName();
	std::string getImageName();
};