#pragma once
#include "Entity.h"
#include "Room.h"

using namespace std;

class Exit :
	public Entity
{
public:
	Exit(string direction_origin, string direction_destination, string name, string description, Room* origin, Room* destination);
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

