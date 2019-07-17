#ifndef __Creature__
#define __Creature__

#include "Entity.h"
#include "Room.h"
#include "Item.h"
#include <string>
#include <iostream>
#include <map>
#include <list>


using namespace std;


class Creature :
	public Entity
{
public:
	Creature(string name, string description, Room* room);
	~Creature();
	virtual int Attack(Item* weapon, Creature* enemy);
	virtual void SetStats(string name);
	int Roll(int max_number);
	void SetMods();
	void AutoEquip(Item* item);
	void Drop(Item* item);
	void Take(Item* item);
	void Equip(string itemname);
	void Unequip(Item* item);
	void UpdateArmor(int value);
	vector<Item*> GetItems();
	Item * GetItems(string name);
	vector<string> GetItemsNames();
	bool IsEquipped(string itemname);

protected:
	Room* actualroom;
	//list<Item*> equiped;
	map<string, int> stats;
	list<Item*> equiped;
	int str;
	int str_mod;
	int dex;
	int dex_mod;
	int con;
	int con_mod;
	int max_health;
	int health;
	int ac;
	int lvl;
	int exp;
};

#endif //__Creature__


