#pragma once
#include "Entity.h"
#include "Room.h"

using namespace std;

class Exit :
	public Entity
{
public:
	Exit(string direction_origin, string direction_destination, string name, string description, Room* origin_room, Room* destination_room);
	~Exit();
	Room* GetOrigin();
	Room* GetDestination();
	string GetDirectionOrigin();
	bool IsLocked();
	string CheckRoom(string room);
	Room* NextRoom(Room* leavingRoom);

private:
	bool locked;
	string direction_destination;
	string direction_origin;
	Room* room_origin;
	Room* room_destination;
	enum direction {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};
};

