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
	SpellBook("Wind Bolt", { Item(539, 1), Item(540, 1) }, 1, 2),
	SpellBook("Frost Bolt", { Item(539, 1), Item(541, 1), Item(540, 1) }, 5, 4),
	SpellBook("Earth Bolt", { Item(539, 1), Item(542, 2), Item(540, 1) }, 9, 6),
	SpellBook("Fire Bolt", { Item(539, 1), Item(543, 3), Item(540, 1) }, 13, 8),
	SpellBook("Air Strike", { Item(539, 2), Item(545, 1) }, 17, 9),
	SpellBook("Water Strike", { Item(539, 2), Item(541, 2), Item(545, 1) }, 21, 10),
	SpellBook("Terra Strike", { Item(539, 2), Item(542, 3), Item(545, 1) }, 29, 12),
	SpellBook("Flame Strike", { Item(539, 3), Item(543, 4), Item(545, 1) }, 35, 14),
	SpellBook("Howling Blast", { Item(539, 3), Item(547, 1) }, 41, 16),
	SpellBook("Ice Blast", { Item(539, 3), Item(541, 3), Item(547, 1) }, 47, 18),
	SpellBook("Magic Dart", { Item(540, 4), Item(547, 1) }, 50, 15),
	SpellBook("Rock Blast", { Item(539, 3), Item(542, 4), Item(547, 1) }, 53, 20),
	SpellBook("Alchemy", { Item(546, 1), Item(543, 5) }, 55, 0),
	SpellBook("Pyro Blast", { Item(539, 4), Item(543, 6), Item(547, 1) }, 59, 22),
	SpellBook("Conversion", { Item(546, 2), Item(541, 2), Item(542, 4) }, 60, 0),
	SpellBook("Smite", { Item(548, 2), Item(544, 4) }, 61, 30),
	SpellBook("Cloud Burst", { Item(548, 1), Item(539, 5) }, 62, 24),
	SpellBook("Storm Burst", { Item(548, 1), Item(541, 7), Item(539, 5) }, 65, 26),
	SpellBook("Seismic Burst", { Item(548, 1), Item(542, 7), Item(539, 5) }, 70, 28),
	SpellBook("Lava Burst", { Item(548, 1), Item(543, 7), Item(539, 5) }, 75, 30)
};