#include "pch.h"
#include "Exit.h"
#include "Room.h"


Exit::Exit(const char* name, const char* description, Room* source, Room* origin) :
	Entity(name, description, (Entity*)origin)
{
	
}


Exit::~Exit()
{
}
