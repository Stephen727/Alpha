#include <vector>

#include "Inventory.h"
#include "Skills.h"

class Player;

#ifndef SMITHING_H
#define SMITHING_H

class Smithing
{
public:
	Smithing();

	Smithing(Player*);

	~Smithing();

private:
	Player *player;

	void smelt(std::vector<Item>, int, int);

public:
	void smelt(int);
	void smith(int, int);
};

#endif