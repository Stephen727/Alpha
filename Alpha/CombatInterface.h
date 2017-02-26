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
	std::string npcOutput,
		playerOutput;
	bool firstCall;

	void barDisplay(int, int);
	void npcDisplay(const Npc&);
	void playerDisplay(const Player&);
	void attackDisplay(const Player&);
	void textDisplay(const Player&, const Npc&, int, int);

public:
	void displayMenu(const Player&, const Npc&, int, int);
	void displayScreen(const Player&, const Npc&, int, int);
};

#endif