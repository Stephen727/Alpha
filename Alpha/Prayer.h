#include "Item.h"

#ifndef PRAYER_H
#define PRAYER_H

class Player;

class Prayer
{
public:
	Prayer();

	Prayer(Player*);

	~Prayer();

private:
	Player* player;

	int getExp(int);
public:
	bool isBone(int);
	void buryBone(int);
	void offerBones();

	bool boneCrusher(Item*);
};

#endif