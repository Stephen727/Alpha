#include "Aura.h"


Aura::Aura(std::string _name, int _level, double _drainRate, AuraType _auraType)
{
	name = _name;
	level = _level;
	drainRate = _drainRate;
	auraType = _auraType;
}


Aura::~Aura()
{
	delete[] aura;
}

Aura *aura[20] = {
	new Aura("Thick Skin", 1, 12.0, DEFENSE),
	new Aura("Burst of Strength", 4, 12.0, STRENGTH),
	new Aura("Clarity of Thought", 7, 12.0, ATTACK),
	new Aura("Sharp Eye", 8, 12.0, MAGE_RANGE),
	new Aura("Mystic Will", 9, 12.0, MAGE_RANGE),
	new Aura("Rock Skin", 10, 8.0, DEFENSE),
	new Aura("Superhuman Strength", 13, 8.0, STRENGTH),
	new Aura("Improved Reflexes", 16, 8.0, ATTACK),
	new Aura("Hawk Eye", 26, 6.0, MAGE_RANGE),
	new Aura("Mystic Lore", 27, 6.0, MAGE_RANGE),
	new Aura("Steel Skin", 28, 6.0, DEFENSE),
	new Aura("Ultimate Strength", 31, 6.0, STRENGTH),
	new Aura("Incredible Reflexes", 34, 6.0, ATTACK),
	new Aura("Protect from Magic", 37, 4.0, OVER_HEAD),
	new Aura("Protect from Range", 40, 4.0, OVER_HEAD),
	new Aura("Protect from Melee", 43, 4.0, OVER_HEAD),
	new Aura("Eagle Eye", 44, 6.0, MAGE_RANGE),
	new Aura("Mystic Might", 45, 6.0, MAGE_RANGE),
	new Aura("Chivalry", 60, 3.0, COMBAT),
	new Aura("Piety", 70, 3.0, COMBAT) };