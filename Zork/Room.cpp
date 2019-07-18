#include "pch.h"
#include "Room.h"
#include "Entity.h"
#include "Exit.h"
#include <string>
#include "Item.h"
#include "Universal.h"



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
			default:
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
		Entity* ent = (Entity*)*it;
		if (ent->type == EXIT) {
			out.push_back((Exit*)ent);
		}
	}
	return out;
}

vector<Item*> Room::GetItems() {
	vector<Item*> out;
	for (std::list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		Entity* ent = *it;
		if (ent->type == ITEM) {
			out.push_back((Item*)ent);
		}
	}
	return out;
}

vector<Enemy*> Room::GetEnemies() {
	vector<Enemy*> out;
	for (std::list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		Entity* ent = *it;
		if (ent->type == ENEMY) {
			out.push_back((Enemy*)ent);
		}
	}
	return out;
}

void Room::RemoveEnemy(string enemyname) {
	vector<Enemy*> enemies = GetEnemies();
	for (rsize_t i = 0; i< enemies.size(); i++){
		if(Universal::ToLowerString(enemies[0]->name) == Universal::ToLowerString(enemyname))
			container.erase(std::remove(container.begin(), container.end(), (Entity*)enemies[i]), container.end());
	}
}

vector<string> Room::GetEnemiesNames() {
	vector<string> out;
	vector<Enemy*> enemies = GetEnemies();
	for (size_t i = 0; i < enemies.size(); i++) {
		out.push_back(enemies[i]->name);
	}
	return out;
}

vector<string> Room::GetItemsNames() {
	vector<string> out;
	vector<Item*> items = GetItems();
	for (size_t i = 0; i < items.size(); i++) {
		out.push_back(items[i]->name);
	}
	return out;
}

Item* Room::GetItems(string name) {
	Item* out = NULL;
	for (std::list<Entity*>::iterator it = container.begin(); it != container.end(); ++it)
	{
		Item* ent = (Item*)*it;
		if (ent->type == ITEM && Universal::ToLowerString(ent->name) == name) {
			out = ent;
			return out;
		}
	}
	return out;
}

