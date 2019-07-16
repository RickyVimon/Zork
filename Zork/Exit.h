#pragma once
#include "Entity.h"

using namespace std;

class Room;

class Exit :
	public Entity
{
public:
	Exit(string direction_origin, string direction_destination, string name, string description, Room* origin, Room* destination, bool bidirectional = false);
	~Exit();
	Room* GetOrigin();
	Room* GetDestination();
	string GetDirectionOrigin();
	string CheckRoom(string room);
	Room* NextRoom(Room* leavingRoom);
	bool locked;
	bool bidirectional;
	bool closed;

private:
	string direction_destination;
	string direction_origin;
	Entity* key;
	Room* room_origin;
	Room* room_destination;
	enum direction {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};
};

