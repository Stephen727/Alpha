#include "Player.h"
#include "Npc.h"

#ifndef COMBATINTERFACE_H
#define COMBATINTERFACE_H

class CombatInterface
{
public:
	CombatInterface();

	~CombatInterface();

private:
	void barDisplay(int, int);
	void npcDisplay(Npc*);
	void playerDisplay(Player*);
	void attackDisplay(Player*);
	
public:
	void displayMenu(Player*, Npc*);
	void displayScreen(Player*, Npc*);
};

#endif