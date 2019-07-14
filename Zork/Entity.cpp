#include <iostream>
#include "pch.h"
#include "Entity.h"

Entity::Entity(string name, string description, Entity* parent = NULL) :
	name(name), description(description), parent(parent)
{
	type = ENTITY;

	if (parent != NULL)
		parent->container.push_back(this);
}

Entity::~Entity()
{
}
