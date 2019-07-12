#pragma once
#include "Creature.h"
class Npc :
	public Creature
{
public:
	Npc(const char* name, const char* description, Room* room);
	~Npc();
};

