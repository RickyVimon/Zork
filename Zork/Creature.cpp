#include "pch.h"
#include "Creature.h"

Creature::Creature(const char* name, const char* description, Room* room) :
	Entity(name, description, (Entity*)room)
{

}


Creature::~Creature()
{
}
