#pragma once
#include "Entity.h"
#include "Room.h"

using namespace std;

class Exit :
	public Entity
{
public:
	Exit(const char* direction_origin, const char* direction_destination, const char* name, const char* description, Room* origin, Room* destination);
	~Exit();
private:
	Room* origin;
	Room* destination;
	enum direction {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};
};

