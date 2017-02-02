#include "Player.h"
#include "Npc.h"

#ifndef MELEEFORMULAS_H
#define MELEEFORMULAS_H

class MeleeFormulas
{
public:
	MeleeFormulas();

	~MeleeFormulas();

private:
	double getEffectiveDefense(const Player&);
	double getEffectiveAttack(const Player&);
	double getEffectiveStrength(const Player&);

public:
	double getDefenseRoll(const Player&);
	double getDefenseRoll(const Npc&);
	double getAttackRoll(const Player&);
	double getAttackRoll(const Npc&);

	double calculateBasedamage(const Player&);
};

#endif