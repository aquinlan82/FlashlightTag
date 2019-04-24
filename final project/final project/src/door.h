#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class Door {
private:
	std::string next_room_name_;
	char activation_key_;

public:
	Door(std::string name, char key);
	std::string getNextName();
	char getActivationKey();

};