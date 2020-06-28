#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

/*
Connection point between rooms
*/

class Door {
private:
	std::string next_room_name_;
	int side_;

public:
	Door(std::string name, int side);
	std::string getNextName();
	int getSide();

};