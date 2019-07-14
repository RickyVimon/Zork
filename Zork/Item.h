#pragma once
#include "Entity.h"
class Item :
	public Entity
{
public:
	Item(string name, string description, Entity* parent);
	~Item();
};

