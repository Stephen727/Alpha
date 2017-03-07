#include "SpellBook.h"


SpellBook::SpellBook()
{
}

SpellBook::SpellBook(std::string _name, std::vector<Item> _runes, int _requirement, int _damage, int _baseExp)
{
	name = _name;
	runes = _runes;
	requirement = _requirement;
	damage = _damage;
	baseExp = _baseExp;
}

SpellBook::~SpellBook()
{
}

SpellBook spellBook[20] =
{
	SpellBook("Wind Bolt", { Item(539, 1), Item(540, 1) }, 1, 2, 6),
	SpellBook("Frost Bolt", { Item(539, 1), Item(541, 1), Item(540, 1) }, 5, 4, 8),
	SpellBook("Earth Bolt", { Item(539, 1), Item(542, 2), Item(540, 1) }, 9, 6, 10),
	SpellBook("Fire Bolt", { Item(539, 1), Item(543, 3), Item(540, 1) }, 13, 8, 12),
	SpellBook("Air Strike", { Item(539, 2), Item(545, 1) }, 17, 9, 14),
	SpellBook("Water Strike", { Item(539, 2), Item(541, 2), Item(545, 1) }, 21, 10, 17),
	SpellBook("Terra Strike", { Item(539, 2), Item(542, 3), Item(545, 1) }, 29, 12, 20),
	SpellBook("Flame Strike", { Item(539, 3), Item(543, 4), Item(545, 1) }, 35, 14, 22),
	SpellBook("Howling Blast", { Item(539, 3), Item(547, 1) }, 41, 16, 26),
	SpellBook("Ice Blast", { Item(539, 3), Item(541, 3), Item(547, 1) }, 47, 18, 28),
	SpellBook("Magic Dart", { Item(540, 4), Item(547, 1) }, 50, 15, 30),
	SpellBook("Rock Blast", { Item(539, 3), Item(542, 4), Item(547, 1) }, 53, 20, 32),
	SpellBook("Alchemy", { Item(546, 1), Item(543, 5) }, 55, 0, 65),
	SpellBook("Pyro Blast", { Item(539, 4), Item(543, 6), Item(547, 1) }, 59, 22, 35),
	SpellBook("Conversion", { Item(546, 2), Item(541, 2), Item(542, 4) }, 60, 0, 36),
	SpellBook("Smite", { Item(548, 2), Item(544, 4) }, 61, 30, 61),
	SpellBook("Cloud Burst", { Item(548, 1), Item(539, 5) }, 62, 24, 36),
	SpellBook("Storm Burst", { Item(548, 1), Item(541, 7), Item(539, 5) }, 65, 26, 38),
	SpellBook("Seismic Burst", { Item(548, 1), Item(542, 7), Item(539, 5) }, 70, 28, 40),
	SpellBook("Lava Burst", { Item(548, 1), Item(543, 7), Item(539, 5) }, 75, 30, 43)
};