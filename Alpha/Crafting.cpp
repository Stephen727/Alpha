#include "Crafting.h"
#include "Player.h"

#include <time.h>

Crafting::Crafting()
{
}


Crafting::Crafting(Player* p)
{
	player = p;
}


Crafting::~Crafting()
{
}


void Crafting::pickFlax()
{
	while (player->inventory->getFreeSlots())
	{
		std::cout << "You pick some flax..." << std::endl;
		_sleep(300);
		player->inventory->add(new Item(28, 1));
	}
}

void Crafting::spinFlax()
{
	if (player->skills->getEffect(crafting) >= 10)
	{
		for (int i = 0; i < 20; i++)
		{
			if (player->inventory->getSlot(i) != nullptr)
			{
				if (player->inventory->getSlot(i)->getId() == 28)
				{
					std::cout << "You spin the flax into bow string..." << std::endl;
					player->inventory->replace(new Item(30, 1), i);
					player->skills->addExperience(15, crafting);
					_sleep(300);
				}
			}
		}
	}
}

void Crafting::tan()
{
	//soft leather
	while (player->inventory->hasAmount(516) >= 1 && player->inventory->hasItem(448))
	{
		std::cout << "The cowhide is tanned into leather..." << std::endl;
		_sleep(100);

		player->inventory->removeItem(516, 1);
		player->inventory->removeItem(448);
		player->inventory->add(new Item(450, 1));
	}

	//hard leather
	while (player->inventory->hasAmount(516) >= 3 && player->inventory->hasItem(448))
	{
		std::cout << "The cowhide is tanned into hard leather..." << std::endl;
		_sleep(100);

		player->inventory->removeItem(516, 3);
		player->inventory->removeItem(448);
		player->inventory->add(new Item(452, 1));
	}

	//green dragonleather
	while (player->inventory->hasAmount(516) >= 20 && player->inventory->hasItem(474))
	{
		std::cout << "The green dragonhide is tanned into green dragon leather..." << std::endl;
		_sleep(100);

		player->inventory->removeItem(516, 20);
		player->inventory->removeItem(474);
		player->inventory->add(new Item(482, 1));
	}

	//blue dragonleather
	while (player->inventory->hasAmount(516) >= 20 && player->inventory->hasItem(476))
	{
		std::cout << "The blue dragonhide is tanned into blue dragon leather..." << std::endl;
		_sleep(100);

		player->inventory->removeItem(516, 20);
		player->inventory->removeItem(476);
		player->inventory->add(new Item(484, 1));
	}

	//red dragonleather
	while (player->inventory->hasAmount(516) >= 20 && player->inventory->hasItem(478))
	{
		std::cout << "The red dragonhide is tanned into red dragon leather..." << std::endl;
		_sleep(100);

		player->inventory->removeItem(516, 20);
		player->inventory->removeItem(478);
		player->inventory->add(new Item(486, 1));
	}

	//black dragonleather
	while (player->inventory->hasAmount(516) >= 20 && player->inventory->hasItem(480))
	{
		std::cout << "The black dragonhide is tanned into black dragon leather..." << std::endl;
		_sleep(100);

		player->inventory->removeItem(516, 20);
		player->inventory->removeItem(480);
		player->inventory->add(new Item(488, 1));
	}
}

void Crafting::craft(int slotOne, int slotTwo)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;

	system("CLS");
	player->inventory->displayInv();

	if (player->inventory->getSlot(slotOne)->getId() == 514 && player->inventory->hasItem(515)) //Needle && Thread
	{
		if (player->inventory->getSlot(slotTwo)->getId() == 450)
		{
			int input, amount;

			std::cout << "\b [1] Gloves [2] Boots [3] Cowl [4] Vambs [5] Body [6] Chaps [7] Coif   >";

			while (!(std::cin >> input) || (input < 1 || input > 7))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			system("CLS");
			player->inventory->displayInv();
			std::cout << "\b [1] Gloves [2] Boots [3] Cowl [4] Vambs [5] Body [6] Chaps [7] Coif   >" << input << "   >";

			while (!(std::cin >> amount) || amount < 1)
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			do
			{
				switch (input)
				{
				case 1: //Leather gloves
					if (player->skills->getEffect(crafting) >= 1)
					{
						player->inventory->removeItem(450);
						player->inventory->add(new Item(454, 1));
						player->skills->addExperience(14, crafting);
					}
					else
						return;
					break;
				case 2: //Leather boots
					if (player->skills->getEffect(crafting) >= 7)
					{
						player->inventory->removeItem(450);
						player->inventory->add(new Item(456, 1));
						player->skills->addExperience(17, crafting);
					}
					else
						return;
					break;
				case 3: //Leather cowl
					if (player->skills->getEffect(crafting) >= 9)
					{
						player->inventory->removeItem(450);
						player->inventory->add(new Item(458, 1));
						player->skills->addExperience(19, crafting);
					}
					else
						return;
					break;
				case 4: //Leather vambraces
					if (player->skills->getEffect(crafting) >= 11)
					{
						player->inventory->removeItem(450);
						player->inventory->add(new Item(460, 1));
						player->skills->addExperience(22, crafting);
					}
					else
						return;
					break;
				case 5: //Leather body
					if (player->skills->getEffect(crafting) >= 14)
					{
						player->inventory->removeItem(450);
						player->inventory->add(new Item(462, 1));
						player->skills->addExperience(25, crafting);
					}
					else
						return;
					break;
				case 6: //Leather chaps
					if (player->skills->getEffect(crafting) >= 18)
					{
						player->inventory->removeItem(450);
						player->inventory->add(new Item(464, 1));
						player->skills->addExperience(27, crafting);
					}
					else
						return;
					break;
				case 7: //Coif
					if (player->skills->getEffect(crafting) >= 38)
					{
						player->inventory->removeItem(450);
						player->inventory->add(new Item(468, 1));
						player->skills->addExperience(37, crafting);
					}
					else
						return;
				default:
					return;
				}

				if (rand() % 2)
					player->inventory->removeItem(515, 1);

				if (!player->inventory->hasItem(450))
					return;

				amount--;
			} while (amount && player->inventory->hasItem(515));
			return;
		}
		else if (player->inventory->getSlot(slotTwo)->getId() == 452)
		{
			int input, amount;

			std::cout << "\b [1] Vambs [2] Chaps [3] Body   >";

			while (!(std::cin >> input) || (input < 1 || input > 3))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			system("CLS");
			player->inventory->displayInv();
			std::cout << "\b [1] Vambs [2] Chaps [3] Body   >";

			while (!(std::cin >> amount) || amount < 1)
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			do
			{
				switch (input)
				{
				case 1:
					if (player->skills->getEffect(crafting) >= 28)
					{
						player->inventory->removeItem(452);
						player->inventory->add(new Item(466, 1));
						player->skills->addExperience(28, crafting);
					}
					else
						return;
					break;
				case 2:
					if (player->skills->getEffect(crafting) >= 41)
					{
						player->inventory->removeItem(452);
						player->inventory->add(new Item(470, 1));
						player->skills->addExperience(40, crafting);
					}
					else
						return;
					break;
				case 3:
					if (player->skills->getEffect(crafting) >= 44)
					{
						player->inventory->removeItem(452);
						player->inventory->add(new Item(472, 1));
						player->skills->addExperience(42, crafting);
					}
					else
						return;
					break;
				default:
					break;
				}

				if (rand() % 2)
					player->inventory->removeItem(515, 1);

				if (!player->inventory->hasItem(452))
					return;

				amount--;
			} while (amount && player->inventory->hasItem(515));
			return;
		}
		else if (player->inventory->getSlot(slotTwo)->getId() == 482)
		{
			int input, amount;

			std::cout << "\b [1] Vambs [2] Chaps [3] Body   >";

			while (!(std::cin >> input) || (input < 1 || input > 3))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			system("CLS");
			player->inventory->displayInv();
			std::cout << "\b [1] Vambs [2] Chaps [3] Body   >";

			while (!(std::cin >> amount) || amount < 1)
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			do
			{
				switch (input)
				{
				case 1:
					if (player->skills->getEffect(crafting) >= 57)
					{
						player->inventory->removeItem(482);
						player->inventory->add(new Item(490, 1));
						player->skills->addExperience(62, crafting);
					}
					else
						return;
					break;
				case 2:
					if (player->skills->getEffect(crafting) >= 60)
					{
						if (player->inventory->hasAmount(482) >= 2)
						{
							player->inventory->removeItem(482, 2);
							player->inventory->add(new Item(492, 1));
							player->skills->addExperience(124, crafting);
						}
					}
					else
						return;
					break;
				case 3:
					if (player->skills->getEffect(crafting) >= 63)
					{
						if (player->inventory->hasAmount(482) >= 3)
						{
							player->inventory->removeItem(482, 3);
							player->inventory->add(new Item(494, 1));
							player->skills->addExperience(186, crafting);
						}
					}
					else
						return;
					break;
				default:
					return;
				}

				if (rand() % 2)
					player->inventory->removeItem(515, 1);

				if (!player->inventory->hasItem(482))
					return;

				amount--;
			} while (amount && player->inventory->hasItem(515));
			return;
		}
		else if (player->inventory->getSlot(slotTwo)->getId() == 484)
		{
			int input, amount;

			std::cout << "\b [1] Vambs [2] Chaps [3] Body   >";

			while (!(std::cin >> input) || (input < 1 || input > 3))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			system("CLS");
			player->inventory->displayInv();
			std::cout << "\b [1] Vambs [2] Chaps [3] Body   >";

			while (!(std::cin >> amount) || amount < 1)
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			do
			{
				switch (input)
				{
				case 1:
					if (player->skills->getEffect(crafting) >= 66)
					{
						player->inventory->removeItem(484);
						player->inventory->add(new Item(496, 1));
						player->skills->addExperience(70, crafting);
					}
					else
						return;
					break;
				case 2:
					if (player->skills->getEffect(crafting) >= 68)
					{
						if (player->inventory->hasAmount(484) >= 2)
						{
							player->inventory->removeItem(484, 2);
							player->inventory->add(new Item(498, 1));
							player->skills->addExperience(140, crafting);
						}
					}
					else
						return;
					break;
				case 3:
					if (player->skills->getEffect(crafting) >= 71)
					{
						if (player->inventory->hasAmount(484) >= 3)
						{
							player->inventory->removeItem(484, 3);
							player->inventory->add(new Item(500, 1));
							player->skills->addExperience(210, crafting);
						}
					}
					else
						return;
					break;
				default:
					return;
				}

				if (rand() % 2)
					player->inventory->removeItem(515, 1);

				if (!player->inventory->hasItem(484))
					return;

				amount--;
			} while (amount && player->inventory->hasItem(515));
			return;
		}
		else if (player->inventory->getSlot(slotTwo)->getId() == 486)
		{
			int input, amount;

			std::cout << "\b [1] Vambs [2] Chaps [3] Body   >";

			while (!(std::cin >> input) || (input < 1 || input > 3))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			system("CLS");
			player->inventory->displayInv();
			std::cout << "\b [1] Vambs [2] Chaps [3] Body   >";

			while (!(std::cin >> amount) || amount < 1)
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			do
			{
				switch (input)
				{
				case 1:
					if (player->skills->getEffect(crafting) >= 73)
					{
						player->inventory->removeItem(486);
						player->inventory->add(new Item(502, 1));
						player->skills->addExperience(78, crafting);
					}
					else
						return;
					break;
				case 2:
					if (player->skills->getEffect(crafting) >= 75)
					{
						if (player->inventory->hasAmount(486) >= 2)
						{
							player->inventory->removeItem(486, 2);
							player->inventory->add(new Item(504, 1));
							player->skills->addExperience(156, crafting);
						}
					}
					else
						return;
					break;
				case 3:
					if (player->skills->getEffect(crafting) >= 77)
					{
						if (player->inventory->hasAmount(486) >= 3)
						{
							player->inventory->removeItem(486, 3);
							player->inventory->add(new Item(506, 1));
							player->skills->addExperience(234, crafting);
						}
					}
					else
						return;
					break;
				default:
					return;
				}

				if (rand() % 2)
					player->inventory->removeItem(515, 1);

				if (!player->inventory->hasItem(486))
					return;

				amount--;
			} while (amount && player->inventory->hasItem(515));
			return;
		}
		else if (player->inventory->getSlot(slotTwo)->getId() == 488)
		{
			int input, amount;

			std::cout << "\b [1] Vambs [2] Chaps [3] Body   >";

			while (!(std::cin >> input) || (input < 1 || input > 3))
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			system("CLS");
			player->inventory->displayInv();
			std::cout << "\b [1] Vambs [2] Chaps [3] Body   >";

			while (!(std::cin >> amount) || amount < 1)
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

			do
			{
				switch (input)
				{
				case 1:
					if (player->skills->getEffect(crafting) >= 73)
					{
						player->inventory->removeItem(488);
						player->inventory->add(new Item(508, 1));
						player->skills->addExperience(86, crafting);
					}
					else
						return;
					break;
				case 2:
					if (player->skills->getEffect(crafting) >= 75)
					{
						if (player->inventory->hasAmount(488) >= 2)
						{
							player->inventory->removeItem(488, 2);
							player->inventory->add(new Item(510, 1));
							player->skills->addExperience(156, crafting);
						}
					}
					else
						return;
					break;
				case 3:
					if (player->skills->getEffect(crafting) >= 77)
					{
						if (player->inventory->hasAmount(488) >= 3)
						{
							player->inventory->removeItem(488, 3);
							player->inventory->add(new Item(512, 1));
							player->skills->addExperience(258, crafting);
						}
					}
					else
						return;
					break;
				default:
					return;
				}

				if (rand() % 2)
					player->inventory->removeItem(515, 1);

				if (!player->inventory->hasItem(486))
					return;

				amount--;
			} while (amount && player->inventory->hasItem(515));
			return;
		}
		else
			return;
	}
	else if (player->inventory->getSlot(slotOne)->getId() == 258)
	{
		switch (player->inventory->getSlot(slotTwo)->getId())
		{
		case 842:
			if (player->skills->getEffect(crafting) >= 8)
			{
				player->inventory->remove(slotOne);
				player->inventory->replace(new Item(856, 1), slotTwo);
				player->skills->addExperience(40, crafting);
				return;
			}
			else
				return;
			break;
		case 844:
			if (player->skills->getEffect(crafting) >= 24)
			{
				player->inventory->remove(slotOne);
				player->inventory->replace(new Item(858, 1), slotTwo);
				player->skills->addExperience(115, crafting);
				return;
			}
			else
				return;
			break;
		case 846:
			if (player->skills->getEffect(crafting) >= 31)
			{
				player->inventory->remove(slotOne);
				player->inventory->replace(new Item(860, 1), slotTwo);
				player->skills->addExperience(138, crafting);
				return;
			}
			else
				return;
			break;
		case 848:
			if (player->skills->getEffect(crafting) >= 50)
			{
				player->inventory->remove(slotOne);
				player->inventory->replace(new Item(862, 1), slotTwo);
				player->skills->addExperience(170, crafting);
				return;
			}
			else
				return;
			break;
		case 850:
			if (player->skills->getEffect(crafting) >= 70)
			{
				player->inventory->remove(slotOne);
				player->inventory->replace(new Item(864, 1), slotTwo);
				player->skills->addExperience(208, crafting);
				return;
			}
			else
				return;
			break;
		case 852:
			if (player->skills->getEffect(crafting) >= 80)
			{
				player->inventory->remove(slotOne);
				player->inventory->replace(new Item(866, 1), slotTwo);
				player->skills->addExperience(258, crafting);
				return;
			}
			else
				return;
			break;
		case 854:
			if (player->skills->getEffect(crafting) >= 90)
			{
				player->inventory->remove(slotOne);
				player->inventory->replace(new Item(868, 1), slotTwo);
				player->skills->addExperience(333, crafting);
				return;
			}
			else
				return;
			break;
		default:
			return;
			break;
		}
	}
}