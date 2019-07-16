#include "pch.h"
#include "Exit.h"
#include "Room.h"


Exit::Exit(string direction_origin, string direction_destination, string name, string description, Room* origin, Room* destination, bool bidirectional) :
	Entity(name, description, (Entity*)origin),
	closed(false), locked(false), key(NULL), bidirectional(bidirectional), direction_origin(direction_origin) ,direction_destination(direction_destination), room_destination(destination), room_origin(origin)
{
	type = EXIT;
	if (bidirectional == false)
		destination->container.push_back(this);
}

Exit::~Exit()
{
}

Room* Exit::GetOrigin() {
	return room_origin;
}

string Exit::GetDirectionOrigin() {
	return direction_origin;
}

Room* Exit::GetDestination() {
	return room_destination;
}

Room* Exit::NextRoom(Room* leavingRoom) {
	if (GetOrigin() == leavingRoom)
		return GetDestination();
	else if (GetDestination() == leavingRoom)
		return GetOrigin();
	else
		return NULL;
}

string Exit::CheckRoom(string room) {
	if (GetOrigin()->name == room) {
		return direction_origin;
	}
	else if (GetDestination()->name == room){

		return direction_destination;
	}
	else
		return "";
}


