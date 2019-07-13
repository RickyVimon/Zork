#include "Entity.h"
#include "Room.h"
#include "Item.h"

class Creature : 
	public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	~Creature();
	virtual int Attack(Item* weapon, Creature* enemy) = 0;
	virtual void SetStats(const char* name) = 0;
	int Roll(int max_number);

protected:
	int str;
	int str_mod;
	int dex;
	int dex_mod;
	int con;
	int con_mod;
	int max_health;
	int health;
	int ac;
};

