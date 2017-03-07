#include <string>

#include "Item.h"

#ifndef SPELLBOOK_H
#define SPELLBOOK_H

class SpellBook
{
public:
	SpellBook();

	SpellBook(std::string, std::vector<Item>, int, int, int);

	~SpellBook();

private:
	std::string name;
	std::vector<Item> runes;
	int requirement,
		damage,
		baseExp;

public:
	std::string getName() { return name; }
	std::vector<Item> getRunes() { return runes; }
	int getRequirement() { return requirement; }
	int getDamage() { return damage; }
	int getBaseExp() { return baseExp; }
};

extern SpellBook spellBook[20];

#endif