#include <vector>

#include "Inventory.h"
#include "Skills.h"

class Player;

#ifndef WOODCUTTING_H
#define WOODCUTIING_H

class Woodcutting
{
public:
	Woodcutting();

	Woodcutting(Player*);

	~Woodcutting();

private:
	Player *player;

	void wait(int);
	bool getInput(char*);
public:
	void chop(int);
};

#endif