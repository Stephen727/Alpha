#include "Player.h"
#include "Npc.h"

#ifndef BARROWS_H
#define BARROWS_H

class Barrows
{
public:
	Barrows();

	~Barrows();

private:
	Npc* brothers[6];
	std::vector<DropDefinition*> loot;

	std::vector<Item*> getLoot();
public:
	void play(Player*);
};

#endif