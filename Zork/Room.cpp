#include "pch.h"
#include "Room.h"
#include "Entity.h"
#include "Exit.h"


Room::Room(string name, string description) :
	Entity(name, description, NULL)
{
	room_name = name;
	type = ROOM;
}


Room::~Room()
{
}

void Room::Look() {
	std::cout << "\n-----------------------\n";
	std::cout << name;
	std::cout << "\n-----------------------\n";
	std::cout << description << "\n";
}

string Room::GetName() {
	return room_name;
}

