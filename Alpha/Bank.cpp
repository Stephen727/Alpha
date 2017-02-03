#include "Bank.h"

#include "Player.h"
#include "Inventory.h"

#include <sstream>

Bank::Bank()
{
}


Bank::Bank(Player* p)
{
	player = p;
}


Bank::~Bank()
{
}


void Bank::deposit(Item* _item)
{
	_item->note();

	for (int i = 0; i < item.size(); i++)
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
	item.push_back(_item);
}

void Bank::deposit(int slot)
{
	if (player->inventory->getSlot(slot) != nullptr)
	{
		Item _item = *player->inventory->getSlot(slot);
		_item.note();

		deposit(new Item(_item.getId(), 1));
		player->inventory->remove(slot, 1);
	}
}

void Bank::deposit(int slot, int amount)
{
	if (player->inventory->getSlot(slot) != nullptr)
	{
		Item _item = *player->inventory->getSlot(slot);
		_item.note();

		if (amount > player->inventory->getSlot(slot)->getAmount())
		{
			deposit(new Item(_item.getId(), player->inventory->getSlot(slot)->getAmount()));
			player->inventory->remove(slot, player->inventory->getSlot(slot)->getAmount());
		}
		else if (amount > 0)
		{
			deposit(new Item(_item.getId(), amount));
			player->inventory->remove(slot, amount);
		}
	}
}

void Bank::withdraw(int slot)
{
	if (item.size())
	{
		if (slot >= 0 && slot < item.size())
		{
			if (player->inventory->canAdd(*item[slot]))
			{
				Item *temp = new Item(item[slot]->getId(), 1);
				temp->unNote();
				player->inventory->add(temp);

				item[slot]->remove();
				if (item[slot]->getAmount() < 1)
					item.erase(item.begin() + slot);
			}
		}
	}
}

void Bank::withdraw(int slot, int amount)
{
	if (amount < 1)
		return;

	if (item.size())
	{
		if (slot >= 0 && slot < item.size())
		{
			Item temp = Item(item[slot]->getId(), 1);
			temp.unNote();

			if (!temp.getItemDefinition()->isStackable())
			{
				while (player->inventory->canAdd(temp) && amount)
				{
					if (item[slot]->getAmount())
					{
						player->inventory->add(new Item(temp.getId(), 1));
						amount--;
						item[slot]->remove();
					}
					else
						break;
				}
			}
			else
			{
				if (player->inventory->canAdd(temp))
				{
					if (item[slot]->getAmount() > amount)
					{
						player->inventory->add(new Item(temp.getId(), amount));
						item[slot]->remove(amount);
					}
					else
					{
						player->inventory->add(new Item(temp.getId(), item[slot]->getAmount()));
						item[slot]->remove(item[slot]->getAmount());
					}
				}
			}

			if (item[slot]->getAmount() < 1)
				item.erase(item.begin() + slot);
		}
	}
}

void Bank::displayBank()
{
	std::cout << " ---Bank---" << std::endl;

	std::string str;

	for (int i = 0; i < item.size(); i++)
	{
		str = " [" + std::to_string(i + 1) + "] " + item[i]->getItemDefinition()->getName();
		str.resize(25);

		std::cout << str << "x" << item[i]->getAmount() << std::endl;
	}

	if (!item.size())
		std::cout << " Empty." << std::endl;
}

void Bank::save()
{
	std::ofstream outFile("save.txt", std::ios::app);

	outFile << "Bank" << std::endl;

	for (int i = 0; i < item.size(); i++)
	{
		outFile << *item[i];
	}

	outFile << std::endl;

	outFile.close();
}

void Bank::load()
{
	std::ifstream infile("save.txt");

	int i;
	Item temp;
	std::string line;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		if (line == "Bank")
		{
			while (infile >> temp)
				item.push_back(new Item(temp.getId(), temp.getAmount()));
		}

	}

	infile.close();
}