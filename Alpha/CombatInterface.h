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
	void npcDisplay(const Npc&);
	void playerDisplay(const Player&);
	void attackDisplay(const Player&);
	
public:
	void displayMenu(const Player&, const Npc&);
	void displayScreen(const Player&, const Npc&);
};

#endif