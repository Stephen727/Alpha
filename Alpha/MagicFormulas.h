#include "player.h"
#include "Npc.h"

#ifndef MAGICFORMULAS_H
#define MAGICFORMULAS_H

class MagicFormulas
{
public:
	MagicFormulas();

	~MagicFormulas();

private:
	double getEffectiveDefense(const Player&);
	double getEffectiveMagic(const Player&);

public:
	double getDefenseRoll(const Player&);
	double getDefenseRoll(const Npc&);
	double getAttackRoll(const Player&);
	double getAttackRoll(const Npc&);

	double calculateBasedamage(const Player&);
};

#endif