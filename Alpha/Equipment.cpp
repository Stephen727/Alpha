#include "Equipment.h"
#include "Player.h"
#include "Inventory.h"

#include <sstream>
#include <time.h>


Equipment::Equipment()
{
}


Equipment::Equipment(Player *p)
{
	player = p;
	for (int i = 0; i < 11; i++)
		item[i] = NULL;
	for (int i = 0; i < 8; i++)
		bonus[i] = 0;
}


Equipment::~Equipment()
{
}


void Equipment::calculateBonus()
{
	for (int i = 0; i < 8; i++)
		bonus[i] = 0;

	for (int i = 0; i < 10; i++)
	{
		if (item[i] != NULL)
		{
			bonus[0] += item[i]->getItemBonusDefinition()->getMeleeAtt();
			bonus[1] += item[i]->getItemBonusDefinition()->getRangeAtt();
			bonus[2] += item[i]->getItemBonusDefinition()->getMagicAtt();
			bonus[3] += item[i]->getItemBonusDefinition()->getMeleeDef();
			bonus[4] += item[i]->getItemBonusDefinition()->getRangeDef();
			bonus[5] += item[i]->getItemBonusDefinition()->getMagicDef();
			bonus[6] += item[i]->getItemBonusDefinition()->getStrength();
			bonus[7] += item[i]->getItemBonusDefinition()->getPrayer();
		}
	}
}

void Equipment::unequip(int slot)
{
	if (slot < 0 || slot > 10)
		return;
	else if (item[slot] == NULL)
		return;
	else if (player->inventory->getFreeSlots())
	{
		Item *temp = new Item(item[slot]->getId(), item[slot]->getAmount());
		player->inventory->add(temp);
		delete item[slot];
		item[slot] = NULL;
		calculateBonus();
	}
}

bool Equipment::hasAmmo()
{
	if (item[3] != NULL)
	{
		if (item[3]->getRangedDefinition()->getType())
			return true;
		else if (item[10] != NULL)
		{
			for (int i = 0; item[3]->getRangedDefinition()->getAmmo().size(); i++)
				if (item[10]->getId() == item[3]->getRangedDefinition()->getAmmo()[i])
					return true;
		}
		return false;
	}
	else
		return false;
}

void Equipment::useAmmo()
{
	if (hasAmmo())
	{
		bool keep = (rand() % 5);

		if (item[3]->getRangedDefinition()->getType())
		{
			if (keep) player->inventory->add(new Item(item[3]->getId(), 1));
			item[3]->remove();
		}
		else
		{
			if (keep) player->inventory->add(new Item(item[10]->getId(), 1));
			item[10]->remove();
		}
	}
}

bool Equipment::canEquip(Item *_item)
{
	if (_item != NULL)
		if (_item->getEquipmentDefinition() == NULL)
			return false;
		else if (_item->getEquipmentDefinition()->getSlot() < 0 && _item->getEquipmentDefinition()->getSlot() > 10)
			return false;

	for (int i = 0; i < _item->getEquipmentDefinition()->getReq().size(); i++)
		if (player->skills->getLevel(_item->getEquipmentDefinition()->getReq()[i].skillId) < _item->getEquipmentDefinition()->getReq()[i].skillReq)
			return false;

	if (_item->getEquipmentDefinition()->getSlot() == 3)
		if (_item->getWeaponDefinition()->is2h())
			if (item[5] != NULL && item[3] != NULL)
				if (player->inventory->getFreeSlots() < 1)
					return false;

	return true;
}

void Equipment::equip(int slot)
{
	if (player->inventory->getSlot(slot) == NULL)
		return;

	Item _item = *player->inventory->getSlot(slot);

	if (!canEquip(&_item))
		return;

	player->inventory->remove(slot);
	Item *temp = new Item(_item.getId(), _item.getAmount());

	if (item[_item.getEquipmentDefinition()->getSlot()] != NULL)
	{
		if (_item.getEquipmentDefinition()->getSlot() == 10)
		{
			if (item[10]->getId() == temp->getId())
			{
				item[10]->add(temp->getAmount());
				return;
			}
		}
		player->inventory->add(item[_item.getEquipmentDefinition()->getSlot()]);
	}

	item[_item.getEquipmentDefinition()->getSlot()] = temp;

	if (temp->getEquipmentDefinition()->getSlot() == 3)
	{
		if (temp->getWeaponDefinition()->is2h() && item[5] != NULL)
			unequip(5);
	}
	else if (temp->getEquipmentDefinition()->getSlot() == 5 && item[3] != NULL)
	{
		if (item[3]->getWeaponDefinition()->is2h())
			unequip(3);
	}

	calculateBonus();
}

void Equipment::clear()
{
	for (int i = 0; i < 11; i++)
	{
		delete item[i];
		item[i] = NULL;
	}
	calculateBonus();
}

Item* Equipment::getItem(int slot)
{
	if (item[slot] != NULL)
		return item[slot];
	else
		return NULL;
}

int Equipment::getBonus(int slot)
{
	return bonus[slot];
}

void Equipment::displayBonus()
{
	std::cout << std::endl << "   ---Bonuses---" << std::endl;
	std::cout << "\tAttack   Defense" << std::endl;
	std::cout << "Melee:\t  " << bonus[0] << "\t   " << bonus[3] << std::endl;
	std::cout << "Ranged:\t  " << bonus[1] << "\t   " << bonus[4] << std::endl;
	std::cout << "Magic:\t  " << bonus[2] << "\t   " << bonus[5] << std::endl;
	std::cout << "\tStrength Prayer" << std::endl;
	std::cout << "\t  " << bonus[6] << "\t   " << bonus[7] << std::endl;
}

void Equipment::displayEquip()
{
	std::string slot;

	std::cout << "   ---Equipment---" << std::endl;

	for (int i = 0; i < 11; i++)
	{
		switch (i)
		{
		case 0:
			slot = "Head:  \t";
			break;
		case 1:
			slot = "Cape:  \t";
			break;
		case 2:
			slot = "Neck:  \t";
			break;
		case 3:
			slot = "Weapon:\t";
			break;
		case 4:
			slot = "Chest: \t";
			break;
		case 5:
			slot = "Shield:\t";
			break;
		case 6:
			slot = "Legs:  \t";
			break;
		case 7:
			slot = "Hands: \t";
			break;
		case 8:
			slot = "Feet:  \t";
			break;
		case 9:
			slot = "Ring:  \t";
			break;
		case 10:
			slot = "Ammo:  \t";
			break;
		default:
			slot = "Empty: \t";
			break;
		}

		if (item[i] != NULL)
		{
			std::cout << " [" << i + 1 << "] " << slot << item[i]->getItemDefinition()->getName();
			if (item[i]->getItemDefinition()->isStackable())
				std::cout << " x" << item[i]->getAmount();
			std::cout << std::endl;
		}
		else
			std::cout << " [" << i + 1 << "] " << slot << "Empty" << std::endl;
	}

	std::cout << std::endl << std::endl;
	displayBonus();

	std::cout << std::endl << std::endl << ">";
}

void Equipment::save()
{
	std::ofstream outFile("save.txt", std::ios::app);

	outFile << "Equipment" << std::endl;

	for (int i = 0; i < 11; i++)
	{
		if (item[i] != NULL)
			outFile << *item[i];
	}

	outFile << std::endl;

	outFile.close();
}

void Equipment::load()
{
	std::ifstream infile("save.txt");

	Item temp;
	std::string line;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		if (line == "Equipment")
		{
			while (infile >> temp)
				item[temp.getEquipmentDefinition()->getSlot()] = new Item(temp.getId(), temp.getAmount());
		}
	}

	calculateBonus();

	infile.close();
}