#include "door.h"

Door::Door(string name, char key)
{
	next_room_name = name;
	activation_key = key;
}

string Door::getNextName()
{
	return next_room_name;
}

char Door::getActivationKey()
{
	return activation_key;
}


