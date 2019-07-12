#include <iostream>
#include "pch.h"
#include "Entity.h"

Entity::Entity(const char* name, const char* description, Entity* parent = NULL) :
	name(name), description(description), parent(parent)
{
	type = ENTITY;

	if (parent != NULL)
		parent->container.push_back(this);
}

Entity::~Entity()
{
}
