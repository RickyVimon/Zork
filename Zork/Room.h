#pragma once
#include <iostream>
#include "Entity.h"
#include <string>
#include <list>
#include "Item.h"

using namespace std;

class Room : public Entity
{

public:
	Room(string name, string description);
	~Room();
	void Look();
	string GetName();
	vector<Item*> GetItems(vector<Entity*> ent);

private:
	string room_name;
};

