#include "Player.h"
#include "Npc.h"
#include "CombatInterface.h"
#include "Ground.h"

#ifndef COMBAT_H
#define COMBAT_H

class Combat
{
public:
	Combat();

	~Combat();

private:
	int playerInput,
		playerHit,
		npcHit;
	CombatInterface *combatInterface;

	int meleeAttack(Player*, Npc*);
	int rangedAttack(Player*, Npc*);
	int magicAttack(Player*, Npc*);

	int meleeAttack(Npc*, Player*);
	int rangedAttack(Npc*, Player*);
	int magicAttack(Npc*, Player*);

	int getMaxInput(Player*);
	bool cantAttack(Player*, int);

	int getPlayerInput(Player*);
	bool checkPlayerInput(Player*);
	void resetPlayerInput() { playerInput = -1; }

	int getPlayerDamage(Player*, Npc*);
	int getNpcDamage(Npc*, Player*);

	void fight(Player*, Npc*);
	void getLoot(Player*, int, Ground*);

public:
	void battle(Player*, int);
	void battle(Player*, Npc*);
};

#endif