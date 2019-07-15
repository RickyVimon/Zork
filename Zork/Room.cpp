#include "pch.h"
#include "Room.h"
#include "Entity.h"
#include "Exit.h"
#include <string>
#include "Item.h"



Room::Room(string name, string description) :
	Entity(name, description, NULL)
{
	room_name = name;
	type = ROOM;
}


Room::~Room()
{
}

void Room::Look() {
	std::cout << "\n-----------------------\n";
	std::cout << name;
	std::cout << "\n-----------------------\n";
	std::cout << description << "\n";
}

string Room::GetName() {
	return room_name;
}

vector<Item*> Room::GetItems(vector<Entity*> ent) {
	vector<Entity*> items;
	vector<Item*> out;
	for (int i = 0; ent.size() < 0;i++) {
		if (ent[i]->type = ITEM) {
			items.push_back(ent[i]);
		}
	}
	for (int j = 0; j < items.size(); j++) {
		if (items[j]->parent->name == room_name) {
			out.push_back((Item*)items[j]);
		}
	}
	return out;
}
