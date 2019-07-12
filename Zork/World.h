#pragma once

#include <list>
#include <vector>
#include "Entity.h"

class World
{
public:
	World();
	~World();
	bool ParseCommand();
	vector<Entity*> entities;

};

