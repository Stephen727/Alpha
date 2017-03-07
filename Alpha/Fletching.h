#include "Inventory.h"
#include "Skills.h"

class Player;

#ifndef FLETCHING_H
#define FLETCHING_H

class Fletching
{
public:
	Fletching();

	Fletching(Player*);

	~Fletching();

private:
	Player *player;

	void knifeOnLog(int, int);
	void stringShortbow(int, int);
	void stringCrossbow(int, int, int);
	void fletchArrow(int, int);
	void fletchBolt(int, int, int);
	void makeCrossbow(int, int);
public:
	void fletch(int, int);
};

#endif