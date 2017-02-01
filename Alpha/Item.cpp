#include "Item.h"


Item::Item()
{
}


Item::Item(int _id, int _amount)
{
	id = _id;
	amount = _amount;
}


Item::~Item()
{
}

std::istream& operator >> (std::istream& in, Item& obj)
{
	in >> obj.id;
	in >> obj.amount;
	return in;
}

std::ostream& operator << (std::ostream& out, const Item& obj)
{
	out << obj.id << ' ';
	out << obj.amount << std::endl;
	return out;
}

void Item::note()
{
	for (int i = 0; i < definitionLoader.itemDefinition.size(); i++)
	{
		if (definitionLoader.itemDefinition[i]->getId() == id)
		{
			if (definitionLoader.itemDefinition[i]->getNoteId() != -1)
			{
				if (definitionLoader.itemDefinition[i]->isNote())
					return;
				id = definitionLoader.itemDefinition[i]->getNoteId();
				return;
			}
			else
				return;
		}
	}
}

void Item::unNote()
{
	for (int i = 0; i < definitionLoader.itemDefinition.size(); i++)
	{
		if (definitionLoader.itemDefinition[i]->getId() == id)
		{
			if (definitionLoader.itemDefinition[i]->getNoteId() != -1)
			{
				if (definitionLoader.itemDefinition[i]->isNote())
				{
					id = definitionLoader.itemDefinition[i]->getNoteId();
					return;
				}
			}
			else
				return;
		}
	}
}

ItemDefinition* Item::getItemDefinition()
{
	for (int i = 0; i < definitionLoader.itemDefinition.size(); i++)
	{
		if (definitionLoader.itemDefinition[i]->getId() == id)
		{
			return definitionLoader.itemDefinition[i];
		}
	}
	return nullptr;
}

EquipmentDefinition* Item::getEquipmentDefinition()
{
	for (int i = 0; i < definitionLoader.equipmentDefinition.size(); i++)
	{
		if (definitionLoader.equipmentDefinition[i]->getId() == id)
		{
			return definitionLoader.equipmentDefinition[i];
		}
	}
	return nullptr;
}

ItemBonusDefinition* Item::getItemBonusDefinition()
{

	for (int i = 0; i < definitionLoader.itemBonusDefinition.size(); i++)
	{
		if (definitionLoader.itemBonusDefinition[i]->getId() == id)
		{
			return definitionLoader.itemBonusDefinition[i];
		}
	}
	return nullptr;
}

FoodDefinition* Item::getFoodDefinition()
{
	for (int i = 0; i < definitionLoader.foodDefinition.size(); i++)
	{
		if (definitionLoader.foodDefinition[i]->getId() == id)
		{
			return definitionLoader.foodDefinition[i];
		}
	}
	return nullptr;
}

PotionDefinition* Item::getPotionDefinition()
{
	for (int i = 0; i < definitionLoader.potionDefinition.size(); i++)
	{
		if (definitionLoader.potionDefinition[i]->getId() == id)
		{
			return definitionLoader.potionDefinition[i];
		}
	}
	return nullptr;
}

RangedDefinition* Item::getRangedDefinition()
{
	for (int i = 0; i < definitionLoader.rangedDefinition.size(); i++)
	{
		if (definitionLoader.rangedDefinition[i]->getId() == id)
		{
			return definitionLoader.rangedDefinition[i];
		}
	}
	return nullptr;
}

WeaponDefinition* Item::getWeaponDefinition()
{
	for (int i = 0; i < definitionLoader.weaponDefinition.size(); i++)
	{
		if (definitionLoader.weaponDefinition[i]->getId() == id)
		{
			return definitionLoader.weaponDefinition[i];
		}
	}
	return nullptr;
}