#include "UseItem.h"
#include "Player.h"
#include "Equipment.h"
#include "Prayer.h"
#include "Fletching.h"
#include "Crafting.h"
#include "Food.h"
#include "Potion.h"


UseItem::UseItem()
{
}


UseItem::UseItem(Player *p)
{
	player = p;
}


UseItem::~UseItem()
{
	player = nullptr;
	delete player;
}


bool UseItem::isPotion(Item* item)
{
	if (item->getPotionDefinition() != nullptr)
		return true;
	else
		return false;
}


bool UseItem::isFood(Item* item)
{
	if (item->getFoodDefinition() != nullptr)
		return true;
	else
		return false;
}

bool UseItem::isEquipment(Item* item)
{
	if (item->getEquipmentDefinition() != nullptr)
		return true;
	else
		return false;
}

void UseItem::use(int slot)
{
	if (slot < 0 || slot > 19)
		return;
	else if (player->inventory->getSlot(slot) == nullptr)
		return;
	else if (player->prayer->isBone(slot))
		player->prayer->buryBone(slot);
	else if (isFood(player->inventory->getSlot(slot)))
	{
		if (!player->hasEatDelay())
		{
			player->food->eat(slot);
			player->eatDelay();
		}
	}
	else if (isPotion(player->inventory->getSlot(slot)))
	{
		if (!player->hasDrinkDelay())
		{
			player->potion->drink(slot);
			player->drinkDelay();
		}
	}
	else if (isEquipment(player->inventory->getSlot(slot)))
		player->equipment->equip(slot);
	else
		return;
}

void UseItem::select(int slot)
{
	char input;
	std::cout << ">";
	std::cin >> input;

	switch (input)
	{
	case 'd':
	case 'D':
		player->inventory->remove(slot);
		break;
	case 'u':
	case 'U':
		use(slot);
		break;
	case 's':
	case 'S':
	case 'f':
	case 'F':
	case 'c':
	case 'C':
		int newSlot;
		std::cout << ">";
		std::cin >> newSlot;
		newSlot--;

		if (newSlot < 0 || newSlot > 19)
			return;

		if (input == 's' || input == 'S')
			player->inventory->swap(slot, newSlot);
		else if (input == 'f' || input == 'F')
			player->fletching->fletch(slot, newSlot);
		else if (input == 'c' || input == 'C')
			player->crafting->craft(slot, newSlot);
		break;
	default:
		return;
	}
}