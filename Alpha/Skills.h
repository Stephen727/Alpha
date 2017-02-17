#include <iostream>
#include <algorithm>
#include <string>

class Player;

#ifndef SKILLS_H
#define SKILLS_H

enum SKILL { hitpoints, attack, strength, defense, ranged, prayer, magic, woodcutting, fletching, fishing, cooking, mining, smithing, herblore, crafting, runecrafting, slayer };

class Skills
{
public:
	Skills();

	Skills(Player*);

	~Skills();

private:
	struct Skill
	{
		Skill() {};

		Skill(int _exp, int _effLvl, int _lvl)
		{
			experience = _exp;
			effectiveLevel = _effLvl;
			level = _lvl;
		}

		int experience,
			effectiveLevel,
			level;
	};

	Skill *skills = new Skill[17];
	Player *player;

public:
	int getEffect(int i) { return skills[i].effectiveLevel; }
	int getLevel(int i) { return skills[i].level; }
	int getExperience(int i) { return skills[i].experience; }
	int getCombatLevel() { return ((0.25 * (skills[hitpoints].level + skills[defense].level + (skills[prayer].level / 2))) + (0.325 * std::max(skills[ranged].level + skills[magic].level, (skills[attack].level + skills[strength].level)))); }
	int getExpForLevel(int);

	void heal(int);
	void subHitpoints(int);
	void drainSkill(int, int);
	void boostSkill(int, double, int, int);
	void update();
	void restore(int);

	void addExperience(int, int);
	void addCombatExperience(int);

	void displayStat(int);
	void displayStats();

	void reset();
	void save();
	void load();
};

#endif