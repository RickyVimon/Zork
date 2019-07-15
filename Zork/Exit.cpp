#include "pch.h"
#include "Exit.h"
#include "Room.h"


Exit::Exit(string direction_origin, string direction_destination, string name, string description, Room* origin, Room* destination_room) :
	Entity(name, description, (Entity*)origin)
{
	room_destination = destination_room;
	room_origin = origin;
	this->direction_origin = direction_origin;
	this->direction_destination = direction_destination;
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

bool Exit::IsLocked() {
	return locked;
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
