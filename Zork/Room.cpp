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
	if (container.size() > 0) {
		bool firstitem = true;
		bool firstenemy = true;
		//cout << "You can see the following items:\n";
		for (std::list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
		{
			Entity* ent = *it;
			switch (ent->type) {
			case (ITEM):
				if (firstitem) {
					firstitem = false;
					cout << "You can see the following items:\n";
				}
				cout << " - " << ent->name << ".\n";
				break;
			case (ENEMY):
				if (firstenemy) {
					firstenemy = false;
					cout << "CAUTION! There is an enemy ";
				}
				cout << ent->name << ".\n";
				break;
			}
			
		}
	}
}

string Room::GetName() {
	return room_name;
}

vector<Exit*> Room::GetExits() {
	vector<Exit*> out;
	for (std::list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		Exit* ent = (Exit*)*it;
		if (ent->type = EXIT) {
			out.push_back(ent);
		}
	}
	return out;
}

vector<Item*> Room::GetItems() {
	vector<Item*> out;
	for (std::list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		Item* ent = (Item*)*it;
		if (ent->type = ITEM) {
			out.push_back(ent);
		}
	}
	return out;
}
