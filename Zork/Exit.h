#pragma once
#include "Entity.h"
#include "Room.h"

class Exit :
	public Entity
{
public:
	Exit(const char* name, const char* description, Room* origin, Room* to);
	~Exit();
private:
	Room* from;
	Room* to;
	enum direction {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};
};

