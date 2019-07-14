#pragma once
#include "Entity.h"
#include <string>
#include <list>

using namespace std;

class Room : public Entity
{

public:
	Room(string name, string description);
	~Room();

};

