#include "Inventory.h"
#include "Skills.h"

class Player;

#ifndef HERBLORE_H
#define HERBLORE_H

class Herblore
{
public:
	Herblore();

	Herblore(Player*);

	~Herblore();

private:
	Player *player;

public:
	void brew(int);
	void display();
	bool decant(int, int);
};

#endif