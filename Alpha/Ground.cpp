#include "Ground.h"
#include "Inventory.h"


Ground::Ground()
{
}


Ground::Ground(Player* _player)
{
	player = _player;
}


Ground::~Ground()
{
}


void Ground::drop(Item* drop)
{
	for (int i = 0; i < item.size(); i++)
	{
		if (item[i]->getId() == drop->getId())
		{
			item[i]->add(drop->getAmount());
			return;
		}
	}

	if (item.size() > 19)
		delete item[0];

	item.push_back(new Item(drop->getId(), drop->getAmount()));
}

void Ground::display()
{
	system("CLS");
	std::cout << " ---Loot---" << std::endl;

	std::string str;

	for (int i = 0; i < item.size(); i++)
	{
		str = " [" + std::to_string(i + 1) + "] " + item[i]->getItemDefinition()->getName();
		str.resize(25);

		std::cout << str << "x" << item[i]->getAmount() << std::endl;
	}

	if (!item.size())
		std::cout << " Empty." << std::endl;

	std::cout << std::endl << ">";
}

void Ground::pickup(int slot)
{
	int amount;

	if (slot < 0 || slot > item.size())
		return;
	else if (!item.size())
		return;

	if (item[slot]->getItemDefinition()->isStackable() || item[slot]->getAmount() == 1)
	{
		if (player->inventory->canAdd(*item[slot]))
		{
			player->inventory->add(item[slot]);
			item.erase(item.begin() + slot);
			return;
		}
		else
			return;
	}
	else
	{
		if (item[slot]->getAmount() > 1)
		{
			display();
			std::cout << slot + 1 << "   >";

			while (!(std::cin >> amount) || amount < 0)
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			if (amount > item[slot]->getAmount())
				amount = item[slot]->getAmount();

			while (player->inventory->canAdd(*item[slot]) && amount)
			{
				if (item[slot]->getAmount())
				{
					player->inventory->add(new Item(item[slot]->getId(), 1));
					amount--;
					item[slot]->remove();
				}
				else
					break;
			}
		}
	}

	if (item[slot]->getAmount() < 1)
		item.erase(item.begin() + slot);
}