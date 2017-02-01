#include <string>

#ifndef NPCDEFINITION_H
#define NPCDEFINITION_H

class NpcDefinition
{
public:
	NpcDefinition() {};

	NpcDefinition(int _id, std::string _name, int _level, int _hitpoints, int _maxHit, int _weakness, int _attackStyle, int _attackSpeed, int _attackStat, int _defenseStat)
	{
		id = _id;
		name = _name;
		level = _level;
		hitpoints = _hitpoints;
		maxHit = _maxHit;
		weakness = _weakness;
		attackStyle = _attackStyle;
		attackSpeed = _attackSpeed;
		attackStat = _attackStat;
		defenseStat = _defenseStat;
	};

	~NpcDefinition() {};

private:
	int id;
	std::string name;
	int level,
		hitpoints,
		maxHit,
		weakness, //0 = none, 1 = melee, 2 = ranged, 3 = mage
		attackStyle, // 0 = melee, 1 = ranged, 2 = magic
		attackSpeed,
		attackStat,
		defenseStat;

public:
	int getId() { return id; }
	std::string getName() { return name; }
	int getLevel() { return level; }
	int getHitpoints() { return hitpoints; }
	int getMaxHit() { return maxHit; }
	int getWeakness() { return weakness; }
	int getAttackStyle() { return attackStyle; }
	int getAttackSpeed() { return attackSpeed; }
	int getAttackStat() { return attackStat; }
	int getDefenseStat() { return defenseStat; }
};

#endif