#include "SpellBook.h"

#ifndef MAGIC_H
#define MAGIC_H

class Player;

class Magic
{
public:
	Magic();

	Magic(Player*);

	~Magic();

private:
	Player* player;
	int currentSpell;

	bool hasRunes();
	void useRunes();

public:
	void setCurrentSpell(int);
	
	SpellBook* getCurrentSpell() { return &spellBook[currentSpell]; }

	void castSpell();

	void displaySpellBook();
};

#endif