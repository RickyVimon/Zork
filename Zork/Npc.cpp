#include "pch.h"
#include "Npc.h"


Npc::Npc(string name, string description, Room* room):
	Creature(name, description, room)
{
}


Npc::~Npc()
{
}
