#include "Skills.h"
#include "Player.h"
#include "PrayerBook.h"
#include "Magic.h"

#include <iostream>
#include <fstream>
#include <sstream>


const int EXP_FOR_LEVEL[] = { 0, 83, 174, 276, 388, 512, 650, 801, 969, 1154, 1358,
1584, 1833, 2107, 2411, 2746, 3115, 3523, 3973, 4470, 5018, 5624, 6291, 7028, 7842,
8740, 9730, 10824, 12031, 13363, 14833, 16456, 18247, 20224, 22406, 24815, 27473, 30408,
33648, 37224, 41171, 45529, 50339, 55649, 61512, 67983, 75127, 83014, 91721, 101333,
111945, 123660, 136594, 150872, 166636, 184040, 203254, 224466, 247886, 273742, 302288,
333804, 368599, 407015, 449428, 496254, 547953, 605032, 668051, 737627, 814445, 899257,
992895, 1096278, 1210421, 1336443, 1475581, 1629200, 1798808, 1986068, 2192818, 2421087,
2673114, 2951373, 3258594, 3597792, 3972294, 4385776, 4842295, 5346332, 5902831,
6517253, 7195629, 7944614, 8771558, 9684577, 10692629, 11805606, 13034431, 14391160 };

Skills::Skills()
{
}

Skills::Skills(Player *p)
{
	player = p;
	skills[hitpoints].experience = 1154;
	skills[hitpoints].effectiveLevel = 10;
	skills[hitpoints].level = 10;
	for (int i = 1; i < 17; i++)
	{
		skills[i].experience = 0;
		skills[i].level = 1;
		skills[i].effectiveLevel = 1;
	}
}

Skills::~Skills()
{
	player = nullptr;
	delete player;
}

int Skills::getExpForLevel(int skill)
{
	if (getLevel(skill) == 99)
		return getExperience(skill);

	return EXP_FOR_LEVEL[getLevel(skill)] - getExperience(skill);
}

void Skills::heal(int amount)
{
	if (skills[hitpoints].effectiveLevel > skills[hitpoints].level)
		return;
	else skills[hitpoints].effectiveLevel += amount;

	if (skills[hitpoints].effectiveLevel > skills[hitpoints].level)
		skills[hitpoints].effectiveLevel = skills[hitpoints].level;
}

void Skills::subHitpoints(int amount)
{
	skills[hitpoints].effectiveLevel -= amount;
	if (skills[hitpoints].effectiveLevel < 1)
		skills[hitpoints].effectiveLevel = 0;
}

void Skills::drainSkill(int amount, int skill)
{
	skills[skill].effectiveLevel -= amount;

	if (skills[skill].effectiveLevel < 1 && skill == prayer)
	{
		skills[skill].effectiveLevel = 0;
		player->prayerBook->toggleAll();
	}
	else if (skills[skill].effectiveLevel < 1)
		skills[skill].effectiveLevel = 1;
}

void Skills::boostSkill(int add, double modifier, int skill, int type)
{
	if (type && skills[skill].effectiveLevel >= skills[skill].level)
		return;
	else if (type && skills[skill].effectiveLevel < skills[skill].level)
	{
		skills[skill].effectiveLevel += skills[skill].level * modifier + add;

		if (skills[skill].effectiveLevel >= skills[skill].level)
			skills[skill].effectiveLevel = skills[skill].level;
		return;
	}
	else
		skills[skill].effectiveLevel += skills[skill].level * modifier + add;

	if (skills[skill].effectiveLevel > (skills[skill].level + skills[skill].level * modifier + add) && (modifier || add))
		skills[skill].effectiveLevel = (skills[skill].level + skills[skill].level * modifier + add);
	
	if (skills[skill].effectiveLevel < 0)
		skills[skill].effectiveLevel = 0;
}

void Skills::update()
{
	static double prayerDrain = 0;
	static int interval = 0;
	interval++;

	prayerDrain += player->prayerBook->getPrayerDrain();

	if (prayerDrain > 1.0)
	{
		drainSkill((int)prayerDrain, prayer);
		prayerDrain -= (int)prayerDrain;
	}

	if (interval == 100)
	{
		for (int i = 0; i < 7; i++)
		{
			if (i != prayer)
			{
				if (skills[i].effectiveLevel < skills[i].level)
					skills[i].effectiveLevel++;
				else if (skills[i].effectiveLevel > skills[i].level)
					skills[i].effectiveLevel--;
			}
		}
		interval = 0;
	}
}

void Skills::restore(int skill)
{
	skills[skill].effectiveLevel = skills[skill].level;
}

void Skills::addExperience(int exp, int skill)
{
	double ratio = (double)skills[skill].effectiveLevel / skills[skill].level;
	int oLevel = skills[skill].level;

	//BONUS EXPERIENCE
	exp *= 3;

	skills[skill].experience += exp;

	for (int i = 0; i < 100; i++)
	{
		if (skills[skill].experience < EXP_FOR_LEVEL[i])
		{
			skills[skill].level = i;

			if (skills[skill].effectiveLevel < skills[skill].level)
				skills[skill].effectiveLevel = (skills[skill].level * ratio);

			break;
		}
	}

	if (skills[skill].level > 99) skills[skill].level = 99;

	if (skills[skill].effectiveLevel < skills[skill].level)
		skills[skill].effectiveLevel = (skills[skill].level * ratio);

	if (skills[skill].level > oLevel)
	{
		std::string name[] = { "Hitpoints", "Attack", "Strength", "Defense", "Ranged", "Prayer", "Magic", "Woodcutting",
			"Fletching", "Fishing", "Cooking", "Mining", "Smithing", "Herblore", "Crafting", "Runecrafting", "Slayer" };

		system("CLS");
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl << std::endl;
		std::cout << "           Congratulations, you just advanced a " << name[skill] << " level." << std::endl;
		std::cout << "           Your " << name[skill] << " level is now " << skills[skill].level << "." << std::endl << std::endl;
		std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
		
		system("PAUSE>nul");
		system("CLS");
	}
}

void Skills::addCombatExperience(int dmg)
{
	switch (player->getCombatStance())
	{
	case 1:
		addExperience(dmg, hitpoints);
		addExperience(dmg * 4, attack);
		break;
	case 2:
		addExperience(dmg, hitpoints);
		addExperience(dmg * 4, strength);
		break;
	case 3:
		addExperience(dmg, hitpoints);
		addExperience(dmg * 4, defense);
		break;
	case 4:
		addExperience(dmg, hitpoints);
		addExperience(dmg, attack);
		addExperience(dmg, strength);
		addExperience(dmg, defense);
		break;
	case 5:
		addExperience(dmg, hitpoints);
		addExperience(dmg * 4, ranged);
		break;
	case 6:
		addExperience(dmg, hitpoints);
		addExperience(dmg * 2, ranged);
		addExperience(dmg * 2, defense);
		break;
	case 7:
		addExperience(dmg, hitpoints);
		addExperience((dmg * 2) + player->magic->getCurrentSpell()->getBaseExp(), magic);
		break;
	}
}

void Skills::displayStat(int skill)
{
	std::string name[] = { "Hitpoints", "Attack", "Strength", "Defense", "Ranged", "Prayer", "Magic", "Woodcut",
		"Fletching", "Fishing", "Cooking", "Mining", "Smithing", "Herblore", "Crafting", "Runecraft", "Slayer" };

	std::cout << name[skill] << ":\t" << skills[skill].effectiveLevel << "/" << skills[skill].level;
}

void Skills::displayStats()
{
	int totalLevel = 0, totalExperience = 0;

	std::cout << "   ---Skills---" << std::endl;

	std::string name[] = { "Hitpoints", "Attack", "Strength", "Defense", "Ranged", "Prayer", "Magic", "Woodcut", 
		"Fletching", "Fishing", "Cooking", "Mining", "Smithing", "Herblore", "Crafting", "Runecraft", "Slayer" };

	for (int i = 0; i < 17; i++)
	{
		totalLevel += skills[i].level;
		totalExperience += skills[i].experience;
		std::cout << " [" << i + 1 << "] " << name[i] << ":     \t" << skills[i].effectiveLevel << "/" << skills[i].level;
		std::cout << "\t (" << skills[i].experience  << " / " << EXP_FOR_LEVEL[skills[i].level] << ")" << std::endl;
	}

	std::cout << std::endl << " Total Level: " << totalLevel << std::endl;
	std::cout << " Total Exp: " << totalExperience << std::endl;

	std::cout << std::endl << std::endl << std::endl << ">";
}

void Skills::reset()
{
	for (int i = 0; i < 17; i++)
		skills[i].effectiveLevel = skills[i].level;
}

void Skills::save()
{
	std::ofstream outFile("save.txt", std::ios::app);

	outFile << "Skills" << std::endl;

	for (int i = 0; i < 17; i++)
		outFile << skills[i].effectiveLevel << " " << skills[i].level << " " << skills[i].experience << " " << std::endl;

	outFile << std::endl;

	outFile.close();
}

void Skills::load()
{
	std::ifstream infile("save.txt");
	int cur, max, exp,
		i = 0;

	std::string line;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		if (line == "Skills")
		{
			while (infile >> cur >> max >> exp)
			{
				skills[i].effectiveLevel = cur;
				skills[i].level = max;
				skills[i].experience = exp;
				i++;
			}
		}

	}

	infile.close();
}