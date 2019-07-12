#include <iostream>
#include "pch.h"
#include "Room.h"
#include "Entity.h"
#include "Exit.h"


Room::Room(const char* name, const char* description) :
	Entity(name, description, NULL)
{
	type = ROOM;
}


Room::~Room()
{
}
