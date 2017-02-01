#include "SpellBook.h"


SpellBook::SpellBook()
{
}

SpellBook::SpellBook(std::string _name, std::vector<Item> _runes, int _requirement, int _damage)
{
	name = _name;
	runes = _runes;
	requirement = _requirement;
	damage = _damage;
}

SpellBook::~SpellBook()
{
}

SpellBook spellBook[20] =
{
	SpellBook("Wind Bolt", { Item(0, 1), Item(1, 1) }, 1, 2),
	SpellBook("Frost Bolt", { Item(0, 1), Item(2, 1), Item(1, 1) }, 5, 4),
	SpellBook("Earth Bolt", { Item(0, 1), Item(3, 2), Item(1, 2) }, 9, 6),
	SpellBook("Fire Bolt", { Item(0, 1), Item(4, 3), Item(1, 1) }, 13, 8),
	SpellBook("Air Strike", { Item(0, 2), Item(5, 1) }, 17, 9),
	SpellBook("Water Strike", { Item(0, 2), Item(2, 2), Item(5, 1) }, 21, 10),
	SpellBook("Terra Strike", { Item(0, 2), Item(3, 3), Item(5, 1) }, 29, 12),
	SpellBook("Flame Strike", { Item(0, 3), Item(4, 4), Item(5, 1) }, 35, 14),
	SpellBook("Howling Blast", { Item(0, 3), Item(7, 1) }, 41, 16),
	SpellBook("Ice Blast", { Item(0, 3), Item(2, 3), Item(7, 1) }, 47, 18),
	SpellBook("Magic Dart", { Item(1, 4), Item(7, 1) }, 50, 15),
	SpellBook("Rock Blast", { Item(0, 3), Item(3, 4), Item(7, 1) }, 53, 20),
	SpellBook("Alchemy", { Item(6, 1), Item(4, 5) }, 55, 0),
	SpellBook("Pyro Blast", { Item(0, 4), Item(4, 6), Item(7, 1) }, 59, 22),
	SpellBook("Conversion", { Item(6, 2), Item(3, 2), Item(2, 4) }, 60, 0),
	SpellBook("Smite", { Item(8, 2), Item(4, 4), Item(0, 4) }, 61, 30),
	SpellBook("Cloud Burst", { Item(8, 1), Item(0, 5) }, 62, 24),
	SpellBook("Storm Burst", { Item(8, 1), Item(2, 7), Item(0, 5) }, 65, 26),
	SpellBook("Seismic Burst", { Item(8, 1), Item(3, 7), Item(0, 5) }, 70, 28),
	SpellBook("Lava Burst", { Item(8, 1), Item(4, 7), Item(0, 5) }, 75, 30)
};