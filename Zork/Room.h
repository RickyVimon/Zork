#pragma once
#include <iostream>
#include "Entity.h"
#include <string>
#include <list>


class Room : public Entity
{

public:
	Room(string name, string description);
	~Room();
	void Look();
	string GetName();

private:
	string room_name;
};

