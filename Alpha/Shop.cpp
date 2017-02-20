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

bool Shop::canAdd(Item _item)
{
	if (stock.size() < 15)
		return true;
	else
	{
		for (int i = 0; i < stock.size(); i++)
		{
			if (stock[i].getId() == _item.getId())
					return true;
		}
		return false;
	}
}

void Shop::add(Item *_item, int amount)
{
	if (canAdd(*_item))
	{
		for (int i = 0; i < stock.size(); i++)
		{
				if (stock[i].getId() == _item->getId())
				{
						stock[i].add(amount);
						return;
				}
			}
		}
	stock.push_back(Item(_item->getId(), amount));
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

		if (stock[i].getItemDefinition()->getGeneralPrice())
			std::cout << "\t" << stock[i].getItemDefinition()->getGeneralPrice() << std::endl;
		else
			std::cout << "\t" << stock[i].getItemDefinition()->getAlchemyPrice() << std::endl;
	}

	if (!stock.size())
		std::cout << " Shop is out of stock." << std::endl;

	std::cout << std::endl << "You have " << player.inventory->hasAmount(516) << " coins." << std::endl;
	std::cout << ">";
}

void Shop::sell(Player *player)
{
	int input, amount, price;

	do
	{
		system("CLS");
		player->inventory->displayInv();

		while (!(std::cin >> input))
		{
			system("CLS");
			player->inventory->displayInv();

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		if (player->inventory->getSlot(input - 1) != nullptr)
		{
			if (player->inventory->getSlot(input - 1)->getItemDefinition()->getId() != 516)
			{
				if ((player->inventory->getSlot(input - 1)->getItemDefinition()->isStackable() && player->inventory->getSlot(input - 1)->getAmount() > 1) || (player->inventory->hasAmount(player->inventory->getSlot(input - 1)->getId()) > 1))
				{
					system("CLS");
					player->inventory->displayInv();
					std::cout << input << "   >";

					while (!(std::cin >> amount))
					{
						system("CLS");
						player->inventory->displayInv();
						std::cout << input << "   >";

						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
					}

					if (amount > player->inventory->hasAmount(player->inventory->getSlot(input - 1)->getItemDefinition()->getId()))
						amount = player->inventory->hasAmount(player->inventory->getSlot(input - 1)->getItemDefinition()->getId());
				}
				else
					amount = 1;

				if (amount > 0)
				{
					price = player->inventory->getSlot(input - 1)->getItemDefinition()->getAlchemyPrice() * 0.66;

					if (player->inventory->canAdd(Item(516, price * amount)))
					{
						add(player->inventory->getSlot(input - 1), amount);
						if (price)
							player->inventory->add(new Item(516, price * amount));
						player->inventory->removeItem(player->inventory->getSlot(input - 1)->getItemDefinition()->getId(), amount);
					}
				}
			}
		}
	} while (input);
}

void Shop::buy(Player* player)
{
	int input, amount;

	do
	{
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

		if (input <= stock.size() && input > 0)
		{
			if (player->inventory->canAdd(stock[input - 1]))
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
				else
					amount = 1;

				if (amount > 0)
				{
					if (amount > stock[input - 1].getAmount())
						amount = stock[input - 1].getAmount();

					if (stock[input - 1].getItemDefinition()->getGeneralPrice())
						if (amount > player->inventory->hasAmount(516) / (stock[input - 1].getItemDefinition()->getGeneralPrice()))
							amount = player->inventory->hasAmount(516) / (stock[input - 1].getItemDefinition()->getGeneralPrice());

					if (amount)
					{
						if (player->inventory->hasItem(516, (stock[input - 1].getItemDefinition()->getGeneralPrice()) * amount))
						{
							int price = stock[input - 1].getItemDefinition()->getGeneralPrice() * amount;
							if (!price) price = stock[input - 1].getItemDefinition()->getAlchemyPrice() * amount;

							player->inventory->removeItem(516, price);
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
			}
			else
			{
				std::cout << "You do not have any space in your inventory." << std::endl;
				system("PAUSE");
				return;
			}
		}
	} while (input);
}

void Shop::enter(Player *player)
{
	int input;

	system("CLS");
	std::cout << "+--------------------+" << std::endl;
	std::cout << "|     ---Shop---     | " << std::endl;
	std::cout << "+--------------------+" << std::endl;
	std::cout << "|     [1] Buy        |" << std::endl;
	std::cout << "|     [2] Sell       |" << std::endl;
	std::cout << "+--------------------+" << std::endl;
	std::cout << ">";

	while (!(std::cin >> input))
	{
		system("CLS");
		std::cout << "+--------------------+" << std::endl;
		std::cout << "|     ---Shop---     | " << std::endl;
		std::cout << "+--------------------+" << std::endl;
		std::cout << "|     [1] Buy        |" << std::endl;
		std::cout << "|     [2] Sell       |" << std::endl;
		std::cout << "+--------------------+" << std::endl;
		std::cout << ">";

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	switch (input)
	{
	case 0:
		return;
		break;
	case 1:
		buy(player);
		break;
	case 2:
		sell(player);
		break;
	}
	enter(player);
}