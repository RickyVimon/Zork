#pragma once
#include "Entity.h"
#include "Room.h"

class Creature : 
	public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	~Creature();
};

