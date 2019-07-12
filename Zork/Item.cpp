#include "pch.h"
#include "Item.h"
#include "Room.h"


Item::Item(const char* name, const char* description, Entity* parent):
	Entity(name, description, parent)
{
}


Item::~Item()
{
}
