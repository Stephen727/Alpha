#include "DefinitionLoader.h"

#ifndef NPC_H
#define NPC_H

class Npc
{
public:
	Npc();

	Npc(int);

	~Npc();

private:
	int id,
		hitpoints,
		delay;

public:
	int getId() { return id; }
	int getHitpoints() { return hitpoints; }
	int getDelay() { return delay; }

	NpcDefinition* getNpcDefinition();

	void subHitpoints(int i) { hitpoints -= i; if (hitpoints < 1) hitpoints = 0; }
	void tickDelay() { delay--; if (delay == -1) delay = getNpcDefinition()->getAttackSpeed(); }
};

#endif