#include "pch.h"
#include "Exit.h"
#include "Room.h"


Exit::Exit(string direction_origin, string direction_destination, string name, string description, Room* source, Room* origin) :
	Entity(name, description, (Entity*)origin)
{
	
}



Exit::~Exit()
{
}
