#ifndef __Enemy__
#define __Enemy__

#include "Creature.h"
#include "Room.h"
#include <nlohmann/json.hpp>

using namespace std;

class Enemy : public Creature
{
public:
	Enemy(string name, string description, Room* room);
	~Enemy();

	void SetStats(string name);

};
#endif
