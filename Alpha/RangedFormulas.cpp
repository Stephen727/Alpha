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
	case 0: //Bronze arrow
		return 7;
		break;
	case 1: //Bronze bolt
	case 2: //Iron arrow
		return 10;
		break;
	case 3: //Steel arrow
		return 16;
		break;
	case 4: //Mithril arrow
		return 22;
		break;
	case 5: //Adamant arrow
		return 31;
		break;
	case 6: //Iron bolt
	case 7: //Rune arrow
		return 49;
		break;
	case 8: //Steel bolt
		return 64;
		break;
	case 9: //Mithril bolt
		return 82;
		break;
	case 10: //Broad bolt
	case 11: //Adamant bolt
		return 100;
		break;
	case 12: //Rune bolt
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

double RangedFormulas::getDefenseRoll(Npc npc)
{
	return npc.getNpcDefinition()->getDefenseStat() * (2.0 + npc.getNpcDefinition()->getDefenseStat() * 0.33);
}

double RangedFormulas::getAttackRoll(const Player &player)
{
	return getEffectiveRange(player) * (2.0 + (double)player.equipment->getBonus(1));
}

double RangedFormulas::getAttackRoll(Npc npc)
{
	return npc.getNpcDefinition()->getAttackStat() * (2.0 + npc.getNpcDefinition()->getAttackStat() * 0.33);
}

double RangedFormulas::calculateBasedamage(const Player &player)
{
	return (13 + getEffectiveRange(player) + (getRangedStrength(player) / 8) + ((getEffectiveRange(player) * getRangedStrength(player)) / 64)) / 10;
}