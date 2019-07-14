#include <iostream>
#include "pch.h"
#include "Room.h"
#include "Entity.h"
#include "Exit.h"


Room::Room(string name, string description) :
	Entity(name, description, NULL)
{
	type = ROOM;
}


Room::~Room()
{
}
