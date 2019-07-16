#pragma once
#include "Entity.h"
#include <string>

enum ItemType
{
	COMMON,
	WEAPON,
	ARMOR,
	USABLE
};

class Item :
	public Entity
{
public:
	Item(string name, string description, Entity* parent, int value, ItemType item_type = COMMON);
	~Item();
	void ChangeStat(string stat_name, int value);

private:
	vector<Item*> GetItems();
	int damage;
	int armor;
	ItemType item_type;
	string stat_name_mod;
	int value_mod;
};

