#include "Inventory.h"
#include "Player.h"


#include <sstream>


Inventory::Inventory()
{
}


Inventory::Inventory(Player *p)
{
	player = p;
	for (int i = 0; i < 20; i++)
		item[i] = NULL;
}


Inventory::~Inventory()
{
}


bool Inventory::canAdd(Item _item)
{
	for (int i = 0; i < 20; i++)
	{
		if (item[i] == NULL)
		{
			return true;
		}
		else
		{
			if (item[i]->getId() == _item.getId())
			{
				if (item[i]->getItemDefinition()->isStackable())
				{
					return true;
				}
			}
		}
	}
	return false;
}

void Inventory::add(Item *_item)
{
	if (canAdd(*_item))
	{
		for (int i = 0; i < 20; i++)
		{
			if (item[i] != NULL)
			{
				if (item[i]->getId() == _item->getId())
				{
					if (item[i]->getItemDefinition()->isStackable())
					{
						item[i]->add(_item->getAmount());
						return;
					}
				}
			}
		}
		for (int i = 0; i < 20; i++)
		{
			if (item[i] == NULL)
			{
				item[i] = _item;
				return;
			}
		}
	}
}

void Inventory::remove(int slot)
{
	if (item[slot] != NULL)
	{
		delete item[slot];
		item[slot] = NULL;
	}
}

void Inventory::remove(int slot, int amount)
{
	item[slot]->remove(amount);

	if (item[slot]->getAmount() < 1)
	{
		delete item[slot];
		item[slot] = NULL;
	}
}

void Inventory::remove(std::vector<Item> items)
{
	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (item[j] != NULL)
			{
				if (item[j]->getId() == items[i].getId())
				{
					remove(j, items[i].getAmount());
				}
			}
		}
	}
}

void Inventory::replace(Item *_item, int slot)
{
	remove(slot);
	item[slot] = _item;
}

void Inventory::clear()
{
	for (int i = 0; i < 20; i++)
	{
		if (item[i] != NULL)
		{
			delete item[i];
			item[i] = NULL;
		}
	}
}

Item* Inventory::getSlot(int slot)
{
	if (slot >= 0 && slot < 20)
		if (item[slot] != NULL)
			return item[slot];

	return NULL;
}

int Inventory::getFreeSlots()
{
	int total = 0;
	for (int i = 0; i < 20; i++)
	{
		if (item[i] == NULL)
			total++;
	}
	return total;
}

bool Inventory::hasItem(int id)
{
	for (int i = 0; i < 20; i++)
	{
		if (item[i] != NULL)
		{
			if (item[i]->getId() == id)
				return true;
		}
	}
	return false;
}

bool Inventory::hasItem(int id, int amount)
{
	int total = 0;

	for (int i = 0; i < 20; i++)
	{
		if (item[i] != NULL)
		{
			if (item[i]->getId() == id)
				total += item[i]->getAmount();
		}
	}

	return total >= amount;
}

bool Inventory::hasItems(std::vector<Item> items)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (!(hasItem(items[i].getId(), items[i].getAmount())))
			return false;
	}
	return true;
}

int Inventory::hasAmount(int id)
{
	int total = 0;

	for (int i = 0; i < 20; i++)
	{
		if (item[i] != NULL)
		{
			if (item[i]->getId() == id)
				total += item[i]->getAmount();
		}
	}

	return total;
}

void Inventory::removeItem(int id)
{
	for (int i = 0; i < 20; i++)
	{
		if (item[i] != NULL)
		{
			if (item[i]->getId() == id)
			{
				remove(i);
				return;
			}
		}
	}
}

void Inventory::removeItem(int id, int amount)
{
	int i = 0;

	do
	{
		if (i > 20)
			return;

		if (item[i] != NULL)
		{
			if (item[i]->getId() == id)
			{
				if (item[i]->getAmount() >= amount)
				{
					remove(i, amount);
					amount = 0;
				}
				else
				{
					amount -= item[i]->getAmount();
					remove(i);
				}
			}
		}
		i++;
	} while (amount > 0);
}

void Inventory::swap(int first_slot, int second_slot)
{
	if (item[first_slot] == NULL)
		return;
	else if (item[second_slot] != NULL)
	{
		Item *temp = item[first_slot];
		item[first_slot] = item[second_slot];
		item[second_slot] = temp;
	}
	else
	{
		item[second_slot] = item[first_slot];
		item[first_slot] = NULL;
	}
}

bool hasRunes()
{
	return false;
}

void useRunes()
{

}

void Inventory::displayInv()
{
	std::cout << " ---Inventory---" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		if (item[i] != NULL)
		{
			std::cout << " [" << i + 1 << "]\t" << item[i]->getItemDefinition()->getName();

			if (item[i]->getItemDefinition()->isStackable())
				std::cout << " x" << item[i]->getAmount() << std::endl;
			else
				std::cout << std::endl;
		}
		else
			std::cout << " [" << i + 1 << "]\tEmpty" << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl << ">";
}

void Inventory::save()
{
	std::ofstream outFile("save.txt", std::ios::app);

	outFile << "Inventory" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		if (item[i] != NULL)
			outFile << i << " " << *item[i];
	}

	outFile << std::endl;

	outFile.close();
}

void Inventory::load()
{
	std::ifstream infile("save.txt");

	int i;
	Item temp;
	std::string line;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		if (line == "Inventory")
		{
			while (infile >> i >> temp)
				item[i] = new Item(temp.getId(), temp.getAmount());
		}

	}

	infile.close();
}