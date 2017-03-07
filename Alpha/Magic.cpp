#include "Magic.h"
#include "Player.h"
#include "Skills.h"
#include "Inventory.h"
#include "Equipment.h"


Magic::Magic()
{
}


Magic::Magic(Player* _player)
{
	player = _player;
}


Magic::~Magic()
{
	player = nullptr;
	delete player;
}


bool Magic::hasRunes()
{
	if (spellBook[currentSpell].getName() == "Smite")
		if (player->equipment->getItem(3) == nullptr)
			return false;
		else if (player->equipment->getItem(3)->getId() != 569) //God Staff
			return false;
	else if (spellBook[currentSpell].getName() == "Magic Dart")
		if (player->equipment->getItem(3) == nullptr)
			return false;
		else if (player->equipment->getItem(3)->getId() != 571) //Slayer's Staff
			return false;

	std::vector<Item> runes = spellBook[currentSpell].getRunes();

	if (player->equipment->getItem(3) != nullptr)
	{
		switch (player->equipment->getItem(3)->getId())
		{
		case 561: //Air staff
			for (int i = 0; i < runes.size(); i++) if (runes[i].getId() == 539) runes.erase(runes.begin() + i);
			break;
		case 563: //Water staff
			for (int i = 0; i < runes.size(); i++) if (runes[i].getId() == 541) runes.erase(runes.begin() + i);
			break;
		case 565: //Earth staff
			for (int i = 0; i < runes.size(); i++) if (runes[i].getId() == 542) runes.erase(runes.begin() + i);
			break;
		case 567: //Fire staff
			for (int i = 0; i < runes.size(); i++) if (runes[i].getId() == 543) runes.erase(runes.begin() + i);
			break;
		default:
			break;
		}
	}

	return player->inventory->hasItems(runes);
}

void Magic::useRunes()
{
	std::vector<Item> runes = spellBook[currentSpell].getRunes();

	if (player->equipment->getItem(3) != nullptr)
	{
		switch (player->equipment->getItem(3)->getId())
		{
		case 561: //Air staff
			for (int i = 0; i < runes.size(); i++) if (runes[i].getId() == 539) runes.erase(runes.begin() + i);
			break;
		case 563: //Water staff
			for (int i = 0; i < runes.size(); i++) if (runes[i].getId() == 541) runes.erase(runes.begin() + i);
			break;
		case 565: //Earth staff
			for (int i = 0; i < runes.size(); i++) if (runes[i].getId() == 542) runes.erase(runes.begin() + i);
			break;
		case 567: //Fire staff
			for (int i = 0; i < runes.size(); i++) if (runes[i].getId() == 543) runes.erase(runes.begin() + i);
			break;
		default:
			break;
		}
	}

	return player->inventory->remove(runes);
}

void Magic::setCurrentSpell(int spell)
{
	if (spell < 0 || spell > 20)
		return;
	else if (player->skills->getLevel(magic) < spellBook[spell].getRequirement())
		return;
	else if (spell == 12) //Alchemy
	{
		currentSpell = spell;
		player->setAutoCast(false);
		if (hasRunes())
		{
			player->inventory->displayInv();
			int input;
			while (!(std::cin >> input) || (input < 0 || input > 20))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			if (!input) return;
			else if (player->inventory->getSlot(input - 1) != nullptr)
			{
				if (player->inventory->getSlot(input - 1)->getId() == 6)
					if (player->inventory->getSlot(input - 1)->getAmount() < 2)
						return;
				else if (player->inventory->getSlot(input - 1)->getId() == 4)
					if (player->inventory->getSlot(input - 1)->getAmount() < 6)
						return;
				
				if (player->inventory->canAdd(Item(516, player->inventory->getSlot(input - 1)->getItemDefinition()->getAlchemyPrice())))
				{
					player->inventory->add(new Item(516, player->inventory->getSlot(input - 1)->getItemDefinition()->getAlchemyPrice()));
					player->inventory->remove(input - 1, 1);
					player->skills->addExperience(spellBook[spell].getBaseExp(), magic);
					useRunes();
				}
			}
		}
	}
	else if (spell == 14) //Conversion
	{
		currentSpell = spell;
		player->setAutoCast(false);
		if (hasRunes())
		{
			for (int i = 0; i < 20; i++)
			{
				if (player->inventory->getSlot(i) != nullptr)
				{
					if (player->inventory->getSlot(i)->getId() == 549) //Bones
						player->inventory->replace(new Item(517, 1), i);
					else if (player->inventory->getSlot(i)->getId() == 551) //Big Bones
						player->inventory->replace(new Item(517, 1), i);
					else if (player->inventory->getSlot(i)->getId() == 553) //Dragon Bones
						player->inventory->replace(new Item(517, 1), i);
					else if (player->inventory->getSlot(i)->getId() == 555) //Lava Dragon Bones
						player->inventory->replace(new Item(517, 1), i);
				}
			}
			player->skills->addExperience(spellBook[spell].getBaseExp(), magic);
			useRunes();
		}
	}
	else if (currentSpell == spell)
	{
		if (player->getAutoCast())
			player->toggleAutoCast();
		else if (hasRunes())
			player->toggleAutoCast();
	}
	else
	{
		currentSpell = spell;
		if (hasRunes())
			player->setAutoCast(true);
		else
			player->setAutoCast(false);
	}
}

void Magic::castSpell()
{
	useRunes();
	//if (!hasRunes())
		//player->setAutoCast(false);
}

void Magic::displaySpellBook()
{
	std::cout << "   ---Spell Book---" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		std::cout << " [" << i + 1 << "] ";
		if (player->getAutoCast() && currentSpell == i) std::cout << "<";
		std::cout << spellBook[i].getName();
		if (player->getAutoCast() && currentSpell == i) std::cout << ">";
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl << ">";
}