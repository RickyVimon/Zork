#include "pch.h"
#include "Npc.h"


Npc::Npc(const char* name, const char* description, Room* room):
	Creature(name, description, room)
{
}


Npc::~Npc()
{
}
