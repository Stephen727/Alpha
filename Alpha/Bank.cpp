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
	for (auto it = item.begin(); it != item.end(); ++it)
		delete *it;
	item.clear();
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

		if (amount > player->inventory->hasAmount(_item.getId()))
		{
			deposit(new Item(_item.getId(), player->inventory->hasAmount(_item.getId())));
			player->inventory->removeItem(_item.getId(), player->inventory->hasAmount(_item.getId()));
		}
		else if (amount > 0)
		{
			deposit(new Item(_item.getId(), amount));
			player->inventory->removeItem(_item.getId(), amount);
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
		str.resize(30);

		std::cout << str << "x" << item[i]->getAmount() << std::endl;
	}

	if (!item.size())
		std::cout << " Empty." << std::endl;
}

void Bank::makeDeposit()
{
	int input;

	do
	{
		system("CLS");
		player->inventory->displayInv();
		std::cout << "Which item would you like to deposit? ";

		while (!(std::cin >> input))
		{
			system("CLS");
			player->inventory->displayInv();
			std::cout << "Which item would you like to deposit? ";

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		int amount = 1;

		if (input && player->inventory->getSlot(input - 1) != nullptr)
		{
			if ((player->inventory->getSlot(input - 1)->getItemDefinition()->isStackable() && player->inventory->getSlot(input - 1)->getAmount() > 1) || (player->inventory->hasAmount(player->inventory->getSlot(input - 1)->getId()) > 1))
			{
				system("CLS");
				player->inventory->displayInv();
				std::cout << "Which item would you like to deposit? " << input << std::endl;
				std::cout << "How many do you have to deposit? ";

				while (!(std::cin >> amount))
				{
					system("CLS");
					player->inventory->displayInv();
					std::cout << "Which item would you like to deposit? " << amount << std::endl;
					std::cout << "How many do you have to deposit? ";

					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
				}
			}
		}
		deposit(input - 1, amount);
	} while (input);
}

void Bank::makeWithdraw()
{
	int input;

	do
	{
		system("CLS");
		displayBank();
		std::cout << std::endl << "Which bank slot would you like to access? ";

		while (!(std::cin >> input) || input > item.size())
		{
			system("CLS");
			displayBank();
			std::cout << std::endl << "Which bank slot would you like to access? ";

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		int amount = 1;

		if (input && item[input - 1]->getAmount() > 1)
		{
			system("CLS");
			displayBank();
			std::cout << std::endl << "Which bank slot would you like to access? " << input << std::endl;
			std::cout << "How many would you like to withdraw? ";

			while (!(std::cin >> amount))
			{
				system("CLS");
				displayBank();
				std::cout  << "Which bank slot would you like to access? " << input << std::endl;
				std::cout << "How many would you like to withdraw? ";

				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
		}
		withdraw(input - 1, amount);
	} while (input);
}

void Bank::swap(int first_slot, int second_slot)
{
	if (first_slot < 0 || first_slot > (item.size() - 1))
		return;
	else if (second_slot < 0 || second_slot > (item.size() - 1))
		return;

	Item *temp = item[first_slot];
	item[first_slot] = item[second_slot];
	item[second_slot] = temp;
}

void Bank::access()
{
	int input;

	do
	{
		system("CLS");
		std::cout << "+--------------------+" << std::endl;
		std::cout << "|     ---Bank---     | " << std::endl;
		std::cout << "+--------------------+" << std::endl;
		std::cout << "|   [1] Deposit      |" << std::endl;
		std::cout << "|   [2] Withdraw     |" << std::endl;
		std::cout << "|   [3] Organize     |" << std::endl;
		std::cout << "+--------------------+" << std::endl;
		std::cout << ">";

		while (!(std::cin >> input))
		{
			system("CLS");
			std::cout << "+--------------------+" << std::endl;
			std::cout << "|     ---Bank---     | " << std::endl;
			std::cout << "+--------------------+" << std::endl;
			std::cout << "|   [1] Deposit      |" << std::endl;
			std::cout << "|   [2] Withdraw     |" << std::endl;
			std::cout << "|   [3] Organize     |" << std::endl;
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
		case 1:
			makeDeposit();
			break;
		case 2:
			makeWithdraw();
			break;
		case 3:
			int slotOne, slotTwo;
			do
			{
				system("CLS");
				displayBank();
				while (!(std::cin >> slotOne))
				{
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
					}
				}
				if (slotOne)
				{
					char c;
					std::cout << ">";
					std::cin >> c;

					if (c == 's')
					{
						std::cout << ">";
						std::cin >> slotTwo;
						swap(slotOne - 1, slotTwo - 1);
					}	
				}
			} while (slotOne);
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (input);
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