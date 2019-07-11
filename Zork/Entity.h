#pragma once
#include <vector>
#include <string>
#include <list>

using namespace std;

enum EntityType {
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER
};

class Entity
{
public:
	Entity();
	~Entity();

	EntityType type;
	string name;
	string description;

	Entity* parent;
	list<Entity*> container;
};

