#include <string>

#include "Item.h"

#ifndef SPELLBOOK_H
#define SPELLBOOK_H

class SpellBook
{
public:
	SpellBook();

	SpellBook(std::string, std::vector<Item>, int, int);

	~SpellBook();

private:
	std::string name;
	std::vector<Item> runes;
	int requirement,
		damage;

public:
	std::string getName() { return name; }
	std::vector<Item> getRunes() { return runes; }
	int getRequirement() { return requirement; }
	int getDamage() { return damage; }
};

extern SpellBook spellBook[20];

#endif