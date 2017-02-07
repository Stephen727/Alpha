#include "Shop.h"


Shop::Shop()
{
}


Shop::Shop(int id)
{
	name = definitionLoader.shopDefinition[id]->getName();
	stock = definitionLoader.shopDefinition[id]->getStock();
}


Shop::~Shop()
{
}

void Shop::display(const Player& player)
{
	system("CLS");
	std::cout << "\t---" << name << "---" << std::endl;

	std::string str;

	for (int i = 0; i < stock.size(); i++)
	{
		str = std::to_string(i + 1) + ". " + stock[i].getItemDefinition()->getName();
		str.resize(25);

		std::cout << str;
		std::cout << "x" << stock[i].getAmount();
		std::cout << "\t" << stock[i].getItemDefinition()->getGeneralPrice() << std::endl;
	}

	if (!stock.size())
		std::cout << " Shop is out of stock." << std::endl;

	std::cout << std::endl << "You have " << player.inventory->hasAmount(33) << " coins." << std::endl;
	std::cout << ">";
}

void Shop::enter(Player *player)
{
	int input, amount;
	display(*player);

	while (!(std::cin >> input))
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		display(*player);
	}

	if (input)
	{
		if (input <= stock.size() && input > 0)
		{
			if (player->inventory->getFreeSlots() > 0)
			{
				if (stock[input - 1].getItemDefinition()->isStackable())
				{
					std::cout << ">";

					while (!(std::cin >> amount) && amount <= stock[input - 1].getAmount())
					{
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}

						display(*player);
						std::cout << ">";
					}
				}

				if (amount < 1)
					enter(player);

				if (amount > stock[input - 1].getAmount())
						amount = stock[input - 1].getAmount();

				if (amount > player->inventory->hasAmount(33) / (stock[input - 1].getItemDefinition()->getGeneralPrice()))
						amount = player->inventory->hasAmount(33) / (stock[input - 1].getItemDefinition()->getGeneralPrice());

				if (amount)
				{
					if (player->inventory->hasItem(33, (stock[input - 1].getItemDefinition()->getGeneralPrice()) * amount))
					{
						player->inventory->removeItem(33, (stock[input - 1].getItemDefinition()->getGeneralPrice()) * amount);
						player->inventory->add(new Item(stock[input - 1].getId(), amount));

						std::cout << "You purchased " << amount << ": " << stock[input - 1].getItemDefinition()->getName() << "." << std::endl;

						stock[input - 1].remove(amount);
						if (stock[input - 1].getAmount() < 1)
							stock.erase(stock.begin() + input - 1);

						system("PAUSE");
					}
				}
				else
				{
					std::cout << "You cannot afford this." << std::endl;
					system("PAUSE");
				}
			}
			else
			{
				std::cout << "You do not have any space in your inventory." << std::endl;
				system("PAUSE");
				return;
			}
		}
		enter(player);
	}
	else
		return;
}