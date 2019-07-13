#include "Entity.h"
#include "Room.h"
#include "Item.h"
#include <string>


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
	int lvl;
	int exp;
};

