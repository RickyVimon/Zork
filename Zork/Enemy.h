#pragma once
#include "Creature.h"
#include "Room.h"
#include "Item.h"

class Enemy :
	public Creature
{
public:
	Enemy(const char* name, const char* description, Room* room);	
	~Enemy();

	void SetStats(const char * name);

};

