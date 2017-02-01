#include "Player.h"
#include "Npc.h"

#ifndef COMBAT_H
#define COMBAT_H

class Combat
{
public:
	Combat();

	~Combat();

private:
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

	int getPlayerDamage(Player*, Npc*);
	int getNpcDamage(Npc*, Player*);

	void fight(Player*, Npc*);

public:
	void battle(Player*, int);
};

#endif