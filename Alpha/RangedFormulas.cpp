#include "RangedFormulas.h"
#include "Skills.h"
#include "Equipment.h"
#include "PrayerBook.h"


RangedFormulas::RangedFormulas()
{
}


RangedFormulas::~RangedFormulas()
{
}


double RangedFormulas::getEffectiveDefense(const Player &player)
{
	double effectiveDefense = player.skills->getEffect(defense);

	if (player.getCombatStance() == 6) effectiveDefense += 1;

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

	return effectiveDefense;
}

double RangedFormulas::getEffectiveRange(const Player &player)
{
	double effectiveAttack = player.skills->getEffect(ranged);

	if (player.getCombatStance() == 5) effectiveAttack += 3;
	else if (player.getCombatStance() == 6) effectiveAttack += 1;

	if (player.prayerBook->getActivated(3))
		effectiveAttack *= 1.05;
	else if (player.prayerBook->getActivated(8))
		effectiveAttack *= 1.10;
	else if (player.prayerBook->getActivated(16))
		effectiveAttack *= 1.15;

	return effectiveAttack;
}

double RangedFormulas::getRangedStrength(const Player &player)
{
	if (player.equipment->getItem(10) == nullptr)
		return 0;

	switch (player.equipment->getItem(10)->getId())
	{
	case 52: //Bronze arrow
		return 7;
		break;
	case 59: //Bronze bolt
	case 53: //Iron arrow
		return 10;
		break;
	case 54: //Steel arrow
		return 16;
		break;
	case 55: //Mithril arrow
		return 22;
		break;
	case 58: //Broad arrow
		return 28;
		break;
	case 56: //Adamant arrow
		return 31;
		break;
	case 60: //Iron bolt
	case 57: //Rune arrow
		return 49;
		break;
	case 61: //Steel bolt
		return 64;
		break;
	case 62: //Mithril bolt
		return 82;
		break;
	case 63: //Adamant bolt
	case 65: //Broad bolt
		return 100;
		break;
	case 64: //Rune bolt
		return 115;
		break;
	default:
		return 0;
		break;
	}
}

double RangedFormulas::getDefenseRoll(const Player &player)
{
	return getEffectiveDefense(player) * (2.0 + (double)player.equipment->getBonus(4));
}

double RangedFormulas::getDefenseRoll(const Npc &npc)
{
	return npc.getNpcDefinition().getDefenseStat() * (2.0 + npc.getNpcDefinition().getDefenseStat() * 0.33);
}

double RangedFormulas::getAttackRoll(const Player &player)
{
	return getEffectiveRange(player) * (2.0 + (double)player.equipment->getBonus(1));
}

double RangedFormulas::getAttackRoll(const Npc &npc)
{
	return npc.getNpcDefinition().getAttackStat() * (2.0 + npc.getNpcDefinition().getAttackStat() * 0.33);
}

double RangedFormulas::calculateBasedamage(const Player &player)
{
	return (13 + getEffectiveRange(player) + (getRangedStrength(player) / 8) + ((getEffectiveRange(player) * getRangedStrength(player)) / 64)) / 10;
}