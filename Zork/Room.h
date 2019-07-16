#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Entity.h"

class Item;
class Exit;

using namespace std;

class Room : public Entity
{

public:
	Room(string name, string description);
	~Room();
	void Look();
	string GetName();
	vector<Item*> GetItems();
	vector<Exit*> GetExits();

private:
	string room_name;
};

