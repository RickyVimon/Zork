#include "pch.h"
#include "Item.h"
#include "Room.h"


Item::Item(string name, string description, Entity* parent):
	Entity(name, description, parent)
{
	type = ITEM;
}


Item::~Item()
{
}
