#include <vector>

#include "Inventory.h"
#include "Skills.h"

class Player;

#ifndef MINING_H
#define MINING_H

class Mining
{
public:
	Mining();

	Mining(Player*);

	~Mining();

private:
	Player *player;

	void wait(int);
	bool getInput(char*);
public:
	void mine(int);
};

#endif