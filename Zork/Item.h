#pragma once
#include "Entity.h"
class Item :
	public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent);
	~Item();
};

