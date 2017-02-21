#include "Inventory.h"
#include "Skills.h"

class Player;

#ifndef CRAFTING_H
#define CRAFTING_H

class Crafting
{
public:
	Crafting();

	Crafting(Player*);

	~Crafting();

private:
	Player *player;

public:
	void pickFlax();
	void spinFlax();

	void tan();
	void craft(int, int);
};

#endif