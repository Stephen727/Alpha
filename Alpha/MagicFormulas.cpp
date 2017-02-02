#include "MagicFormulas.h"
#include "Skills.h"
#include "Equipment.h"
#include "PrayerBook.h"
#include "Magic.h"


MagicFormulas::MagicFormulas()
{
}


MagicFormulas::~MagicFormulas()
{
}


double MagicFormulas::getEffectiveDefense(const Player &player)
{
	double effectiveDefense = player.skills->getEffect(defense) + 3;

	if (player.prayerBook->getActivated(0))
		effectiveDefense *= 1.05;
	else if (player.prayerBook->getActivated(5))
		effectiveDefense *= 1.10;
	else if (player.prayerBook->getActivated(10))
		effectiveDefense *= 1.15;
	else if (player.prayerBook->getActivated(18))
		effectiveDefense *= 1.20;
	else if (player.prayerBook->getActivated(19))
		effectiveDefense *= 1.25;

	return (effectiveDefense * 0.66) + (getEffectiveMagic(player) * 0.33);
}

double MagicFormulas::getEffectiveMagic(const Player &player)
{
	double effectiveAttack = player.skills->getEffect(magic);

	if (player.prayerBook->getActivated(4))
		effectiveAttack *= 1.05;
	else if (player.prayerBook->getActivated(9))
		effectiveAttack *= 1.10;
	else if (player.prayerBook->getActivated(17))
		effectiveAttack *= 1.15;

	return effectiveAttack;
}

double MagicFormulas::getDefenseRoll(const Player &player)
{
	return getEffectiveDefense(player) * (2.0 + (double)player.equipment->getBonus(5));
}

double MagicFormulas::getDefenseRoll(const Npc &npc)
{
	return npc.getNpcDefinition().getDefenseStat() * (2.0 + npc.getNpcDefinition().getDefenseStat() * 0.33);
}

double MagicFormulas::getAttackRoll(const Player &player)
{
	return getEffectiveMagic(player) * (2.0 + (double)player.equipment->getBonus(2));
}

double MagicFormulas::getAttackRoll(const Npc &npc)
{
	return npc.getNpcDefinition().getAttackStat() * (2.0 + npc.getNpcDefinition().getAttackStat() * 0.33);
}

double MagicFormulas::calculateBasedamage(const Player& player)
{
	if (player.magic->getCurrentSpell()->getName() == "Magic Dart")
		return ((double)player.skills->getLevel(magic) / 5.0) + 10;

	return player.magic->getCurrentSpell()->getDamage();
}