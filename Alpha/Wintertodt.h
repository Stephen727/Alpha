#include "Player.h"
#include "Npc.h"

#ifndef WINTERTODT
#define WINTERTODT

class Wintertodt
{
public:
	Wintertodt();

	~Wintertodt();

private:
	Npc* npc;

	void fightBruma(Player*);
	void fightWintertodt(Player*);

	void gearDisplay(Player*);
	void bagDisplay(Player*);
	
	bool getInput(Player*);
public:
	void play(Player*);
};

#endif