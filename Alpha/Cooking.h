#include "Inventory.h"
#include "Skills.h"

class Player;

#ifndef COOKING_H
#define COOKING_H

class Cooking
{
public:
	Cooking();

	Cooking(Player*);

	~Cooking();

private:
	Player *player;

public:
	void cook(int);
};

#endif