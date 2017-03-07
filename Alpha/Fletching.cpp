#include "Fletching.h"
#include "Player.h"

Fletching::Fletching()
{
}

Fletching::Fletching(Player *p)
{
	player = p;
}

Fletching::~Fletching()
{
}


void Fletching::knifeOnLog(int slotOne, int slotTwo)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;

	int input, amount,
		logs[6] = { 0, 2, 4, 6, 8, 10 },
		id = player->inventory->getSlot(slotTwo)->getId();

	for (int i = 0; i < 6; i++)
	{
		if (player->inventory->getSlot(slotTwo)->getId() == logs[i])
			break;

		if (i == 6) return;
	}

	std::cout << "\b [1] Shafts   [2] Shortbow(u)   [3] Stock   >";

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
	std::cout << "\b [1] Shafts   [2] Shortbow(u)   [3] Stock   >" << input << "   >";

	while (!(std::cin >> amount) || amount < 1)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	//Fletch arrow shafts
	if (input == 1)
	{
		do
		{
			switch (id)
			{
			case 0:
				if (player->skills->getEffect(fletching) >= 1)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(56, 15));
					player->skills->addExperience(5, fletching);
				}
				break;
			case 2:
				if (player->skills->getEffect(fletching) >= 15)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(56, 30));
					player->skills->addExperience(10, fletching);
				}
				break;
			case 4:
				if (player->skills->getEffect(fletching) >= 30)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(56, 45));
					player->skills->addExperience(15, fletching);
				}
				break;
			case 6:
				if (player->skills->getEffect(fletching) >= 45)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(56, 60));
					player->skills->addExperience(20, fletching);
				}
				break;
			case 8:
				if (player->skills->getEffect(fletching) >= 60)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(56, 75));
					player->skills->addExperience(25, fletching);
				}
				break;
			case 10:
				if (player->skills->getEffect(fletching) >= 75)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(56, 90));
					player->skills->addExperience(30, fletching);
				}
				break;
			default:
				return;
				break;
			}
			amount--;
		} while (amount && player->inventory->hasItem(id));
		return;
	}

	//Fletch unstrung shortbow
	if (input == 2)
	{
		do
		{
			switch (id)
			{
			case 0:
				if (player->skills->getEffect(fletching) >= 5)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(32, 1));
					player->skills->addExperience(5, fletching);
				}
				break;
			case 2:
				if (player->skills->getEffect(fletching) >= 20)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(34, 1));
					player->skills->addExperience(17, fletching);
				}
				break;
			case 4:
				if (player->skills->getEffect(fletching) >= 35)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(36, 1));
					player->skills->addExperience(34, fletching);
				}
				break;
			case 6:
				if (player->skills->getEffect(fletching) >= 50)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(38, 1));
					player->skills->addExperience(50, fletching);
				}
				break;
			case 8:
				if (player->skills->getEffect(fletching) >= 65)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(40, 1));
					player->skills->addExperience(68, fletching);
					return;
				}
				break;
			case 10:
				if (player->skills->getEffect(fletching) >= 80)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(42, 1));
					player->skills->addExperience(84, fletching);
				}
				break;
			default:
				return;
				break;
			}
			amount--;
		} while (amount && player->inventory->hasItem(id));
		return;
	}

	//Fletch crossbow stock
	if (input == 3)
	{
		do
		{
			switch (id)
			{
			case 0:
				if (player->skills->getEffect(fletching) >= 9)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(71, 1));
					player->skills->addExperience(6, fletching);
				}
				break;
			case 2:
				if (player->skills->getEffect(fletching) >= 24)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(73, 1));
					player->skills->addExperience(27, fletching);
				}
				break;
			case 4:
				if (player->skills->getEffect(fletching) >= 39)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(75, 1));
					player->skills->addExperience(32, fletching);
				}
				break;
			case 6:
				if (player->skills->getEffect(fletching) >= 54)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(77, 1));
					player->skills->addExperience(41, fletching);
				}
				break;
			case 8:
				if (player->skills->getEffect(fletching) >= 69)
				{
					player->inventory->removeItem(id);
					player->inventory->add(new Item(79, 1));
					player->skills->addExperience(50, fletching);
				}
				break;
			default:
				return;
				break;
			}
			amount--;
		} while (amount && player->inventory->hasItem(id));
		return;
	}
}

void Fletching::stringShortbow(int slotOne, int slotTwo)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;

	int amount, id = player->inventory->getSlot(slotTwo)->getId();

	std::cout << "Amount: ";

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
		switch (id)
		{
		case 32:
			if (player->skills->getEffect(fletching) >= 5)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(44, 1));
				player->skills->addExperience(5, fletching);
			}
			break;
		case 34:
			if (player->skills->getEffect(fletching) >= 20)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(46, 1));
				player->skills->addExperience(17, fletching);
			}
			break;
		case 36:
			if (player->skills->getEffect(fletching) >= 35)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(48, 1));
				player->skills->addExperience(34, fletching);
			}
			break;
		case 38:
			if (player->skills->getEffect(fletching) >= 50)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(50, 1));
				player->skills->addExperience(50, fletching);
			}
			break;
		case 40:
			if (player->skills->getEffect(fletching) >= 65)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(52, 1));
				player->skills->addExperience(68, fletching);
			}
			break;
		case 42:
			if (player->skills->getEffect(fletching) >= 80)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(54, 1));
			}
			break;
		default:
			stringCrossbow(slotOne, slotTwo, amount);
			break;
		}
		amount--;
	} while (amount && (player->inventory->hasItem(30) && player->inventory->hasItem(id)));
}

void Fletching::stringCrossbow(int slotOne, int slotTwo, int amount)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;

	int id = player->inventory->getSlot(slotTwo)->getId();

	do
	{
		switch (id)
		{
		case 93:
			if (player->skills->getEffect(fletching) >= 9)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(105, 1));
				player->skills->addExperience(6, fletching);
			}
			break;
		case 95:
			if (player->skills->getEffect(fletching) >= 39)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(107, 1));
				player->skills->addExperience(22, fletching);
			}
			break;
		case 97:
			if (player->skills->getEffect(fletching) >= 46)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(109, 1));
				player->skills->addExperience(24, fletching);
			}
			break;
		case 99:
			if (player->skills->getEffect(fletching) >= 54)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(111, 1));
				player->skills->addExperience(32, fletching);
			}
			break;
		case 101:
			if (player->skills->getEffect(fletching) >= 61)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(113, 1));
				player->skills->addExperience(41, fletching);
			}
			break;
		case 103:
			if (player->skills->getEffect(fletching) >= 69)
			{
				player->inventory->removeItem(30);
				player->inventory->removeItem(id);
				player->inventory->add(new Item(115, 1));
				player->skills->addExperience(50, fletching);
			}
			break;
		default:
			return;
			break;
		}
	} while (amount && (player->inventory->hasItem(30) && player->inventory->hasItem(id)));
}

void Fletching::fletchBolt(int slotOne, int slotTwo, int amount)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;

	do
	{
		switch (player->inventory->getSlot(slotTwo)->getId())
		{
		case 117:
			if (player->skills->getEffect(fletching) >= 9)
			{
				if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
				{
					if (player->inventory->getFreeSlots())
					{
						player->inventory->remove(slotOne, 15);
						player->inventory->remove(slotTwo, 15);
						player->inventory->add(new Item(123, 15));
						player->skills->addExperience(5, fletching);
					}
				}
				else
				{
					int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
					player->inventory->remove(slotOne, amount);
					player->inventory->remove(slotTwo, amount);
					Item* temp = new Item(123, amount);
					player->inventory->add(temp);
					player->skills->addExperience(amount * 0.333, fletching);
				}
			}
			break;
		case 118:
			if (player->skills->getEffect(fletching) >= 39)
			{
				if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
				{
					if (player->inventory->getFreeSlots())
					{
						player->inventory->remove(slotOne, 15);
						player->inventory->remove(slotTwo, 15);
						player->inventory->add(new Item(124, 15));
						player->skills->addExperience(15, fletching);
					}
				}
				else
				{
					int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
					player->inventory->remove(slotOne, amount);
					player->inventory->remove(slotTwo, amount);
					Item* temp = new Item(124, amount);
					player->inventory->add(temp);
					player->skills->addExperience(amount, fletching);
				}
			}
			break;
		case 119:
			if (player->skills->getEffect(fletching) >= 46)
			{
				if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
				{
					if (player->inventory->getFreeSlots())
					{
						player->inventory->remove(slotOne, 15);
						player->inventory->remove(slotTwo, 15);
						player->inventory->add(new Item(125, 15));
						player->skills->addExperience(35, fletching);
					}
				}
				else
				{
					int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
					player->inventory->remove(slotOne, amount);
					player->inventory->remove(slotTwo, amount);
					Item* temp = new Item(125, amount);
					player->inventory->add(temp);
					player->skills->addExperience(amount * 2.333, fletching);
				}
			}
			break;
		case 120:
			if (player->skills->getEffect(fletching) >= 54)
			{
				if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
				{
					if (player->inventory->getFreeSlots())
					{
						player->inventory->remove(slotOne, 15);
						player->inventory->remove(slotTwo, 15);
						player->inventory->add(new Item(126, 15));
						player->skills->addExperience(50, fletching);
					}
				}
				else
				{
					int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
					player->inventory->remove(slotOne, amount);
					player->inventory->remove(slotTwo, amount);
					Item* temp = new Item(126, amount);
					player->inventory->add(temp);
					player->skills->addExperience(amount * 3.333, fletching);
				}
			}
			break;
		case 121:
			if (player->skills->getEffect(fletching) >= 61)
			{
				if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
				{
					if (player->inventory->getFreeSlots())
					{
						player->inventory->remove(slotOne, 15);
						player->inventory->remove(slotTwo, 15);
						player->inventory->add(new Item(127, 15));
						player->skills->addExperience(70, fletching);
					}
				}
				else
				{
					int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
					player->inventory->remove(slotOne, amount);
					player->inventory->remove(slotTwo, amount);
					Item* temp = new Item(127, amount);
					player->inventory->add(temp);
					player->skills->addExperience(amount * 4.666, fletching);
				}
			}
			break;
		case 122:
			if (player->skills->getEffect(fletching) >= 69)
			{
				if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
				{
					if (player->inventory->getFreeSlots())
					{
						player->inventory->remove(slotOne, 15);
						player->inventory->remove(slotTwo, 15);
						player->inventory->add(new Item(128, 15));
						player->skills->addExperience(100, fletching);
					}
				}
				else
				{
					int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
					player->inventory->remove(slotOne, amount);
					player->inventory->remove(slotTwo, amount);
					Item* temp = new Item(128, amount);
					player->inventory->add(temp);
					player->skills->addExperience(amount * 6.666, fletching);
				}
			}
			break;
		default:
			return;
			break;
		}
		if (player->inventory->getSlot(slotOne) == NULL)
			return;
		else if (player->inventory->getSlot(slotTwo) == NULL)
			return;
		amount--;
	} while (amount);
}

void Fletching::fletchArrow(int slotOne, int slotTwo)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;
	
	int input, amount;

	std::cout << "\b [1] Make 1   [2]   Make 5   [3] Make 10   > ";

	while (!(std::cin >> input) || (input < 1 || input > 3))
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	switch (input)
	{
	case 1:
		amount = 1;
		break;
	case 2:
		amount = 5;
		break;
	case 3:
		amount = 10;
		break;
	default:
		return;
		break;
	}

	do
	{
		if (player->inventory->getSlot(slotTwo)->getId() == 56)
		{
			if (player->skills->getEffect(fletching) >= 1)
			{
				if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
				{
					if (player->inventory->getFreeSlots())
					{
						player->inventory->remove(slotOne, 15);
						player->inventory->remove(slotTwo, 15);
						player->inventory->add(new Item(58, 15));
						player->skills->addExperience(15, fletching);
					}
				}
				else
				{
					int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
					player->inventory->remove(slotOne, amount);
					player->inventory->remove(slotTwo, amount);
					Item* temp = new Item(58, amount);
					player->inventory->add(temp);
					player->skills->addExperience(amount, fletching);
				}
			}
		}
		else
		{
			switch (player->inventory->getSlot(slotTwo)->getId())
			{
			case 59:
				if (player->skills->getEffect(fletching) >= 1)
				{
					if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
					{
						if (player->inventory->getFreeSlots())
						{
							player->inventory->remove(slotOne, 15);
							player->inventory->remove(slotTwo, 15);
							player->inventory->add(new Item(65, 15));
							player->skills->addExperience(20, fletching);
						}
					}
					else
					{
						int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
						player->inventory->remove(slotOne, amount);
						player->inventory->remove(slotTwo, amount);
						Item* temp = new Item(65, amount);
						player->inventory->add(temp);
						player->skills->addExperience(amount * 1.333, fletching);
					}
				}
				break;
			case 60:
				if (player->skills->getEffect(fletching) >= 15)
				{
					if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
					{
						if (player->inventory->getFreeSlots())
						{
							player->inventory->remove(slotOne, 15);
							player->inventory->remove(slotTwo, 15);
							player->inventory->add(new Item(66, 15));
							player->skills->addExperience(38, fletching);
						}
					}
					else
					{
						int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
						player->inventory->remove(slotOne, amount);
						player->inventory->remove(slotTwo, amount);
						Item* temp = new Item(66, amount);
						player->inventory->add(temp);
						player->skills->addExperience(amount * 2.533, fletching);
					}
				}
				break;
			case 61:
				if (player->skills->getEffect(fletching) >= 30)
				{
					if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
					{
						if (player->inventory->getFreeSlots())
						{
							player->inventory->remove(slotOne, 15);
							player->inventory->remove(slotTwo, 15);
							player->inventory->add(new Item(67, 15));
							player->skills->addExperience(75, fletching);
						}
					}
					else
					{
						int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
						player->inventory->remove(slotOne, amount);
						player->inventory->remove(slotTwo, amount);
						Item* temp = new Item(67, amount);
						player->inventory->add(temp);
						player->skills->addExperience(amount * 5, fletching);
					}
				}
				break;
			case 62:
				if (player->skills->getEffect(fletching) >= 45)
				{
					if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
					{
						if (player->inventory->getFreeSlots())
						{
							player->inventory->remove(slotOne, 15);
							player->inventory->remove(slotTwo, 15);
							player->inventory->add(new Item(68, 15));
							player->skills->addExperience(113, fletching);
						}
					}
					else
					{
						int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
						player->inventory->remove(slotOne, amount);
						player->inventory->remove(slotTwo, amount);
						Item* temp = new Item(68, amount);
						player->inventory->add(temp);
						player->skills->addExperience(amount * 7.533, fletching);
					}
				}
				break;
			case 63:
				if (player->skills->getEffect(fletching) >= 60)
				{
					if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
					{
						if (player->inventory->getFreeSlots())
						{
							player->inventory->remove(slotOne, 15);
							player->inventory->remove(slotTwo, 15);
							player->inventory->add(new Item(69, 15));
							player->skills->addExperience(150, fletching);
						}
					}
					else
					{
						int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
						player->inventory->remove(slotOne, amount);
						player->inventory->remove(slotTwo, amount);
						Item* temp = new Item(69, amount);
						player->inventory->add(temp);
						player->skills->addExperience(amount * 10, fletching);
					}
				}
				break;
			case 64:
				if (player->skills->getEffect(fletching) >= 75)
				{
					if (player->inventory->getSlot(slotOne)->getAmount() > 15 && player->inventory->getSlot(slotTwo)->getAmount() > 15)
					{
						if (player->inventory->getFreeSlots())
						{
							player->inventory->remove(slotOne, 15);
							player->inventory->remove(slotTwo, 15);
							player->inventory->add(new Item(70, 15));
							player->skills->addExperience(188, fletching);
						}
					}
					else
					{
						int amount = player->inventory->getSlot(slotOne)->getAmount() < player->inventory->getSlot(slotTwo)->getAmount() ? player->inventory->getSlot(slotOne)->getAmount() : player->inventory->getSlot(slotTwo)->getAmount();
						player->inventory->remove(slotOne, amount);
						player->inventory->remove(slotTwo, amount);
						Item* temp = new Item(70, amount);
						player->inventory->add(temp);
						player->skills->addExperience(amount * 12.533, fletching);
					}
				}
				break;
			default:
				fletchBolt(slotOne, slotTwo, amount);
				return;
				break;
			}
		}
		if (player->inventory->getSlot(slotOne) == NULL)
			return;
		else if (player->inventory->getSlot(slotTwo) == NULL)
			return;
		amount--;
	} while (amount);
}

void Fletching::makeCrossbow(int slotOne, int slotTwo)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;


	switch (player->inventory->getSlot(slotOne)->getId())
	{
	case 71:
		if (player->skills->getEffect(fletching) >= 9)
		{
			if (player->inventory->getSlot(slotTwo)->getId() == 81)
			{
				player->inventory->replace(new Item(93, 1), slotOne);
				player->inventory->remove(slotTwo);
				player->skills->addExperience(12, fletching);
				return;
			}
		}
		if (player->skills->getEffect(fletching) >= 39)
		{
			if (player->inventory->getSlot(slotTwo)->getId() == 83)
			{
				player->inventory->replace(new Item(95, 1), slotOne);
				player->inventory->remove(slotTwo);
				player->skills->addExperience(44, fletching);
				return;
			}
		}
		break;
	case 73:
		if (player->skills->getEffect(fletching) >= 46)
		{
			if (player->inventory->getSlot(slotTwo)->getId() == 85)
			{
				player->inventory->replace(new Item(97, 1), slotOne);
				player->inventory->remove(slotTwo);
				player->skills->addExperience(54, fletching);
				return;
			}
		}
		break;
	case 75:
		if (player->skills->getEffect(fletching) >= 54)
		{
			if (player->inventory->getSlot(slotTwo)->getId() == 87)
			{
				player->inventory->replace(new Item(99, 1), slotOne);
				player->inventory->remove(slotTwo);
				player->skills->addExperience(64, fletching);
				return;
			}
		}
		break;
	case 77:
		if (player->skills->getEffect(fletching) >= 61)
		{
			if (player->inventory->getSlot(slotTwo)->getId() == 89)
			{
				player->inventory->replace(new Item(101, 1), slotOne);
				player->inventory->remove(slotTwo);
				player->skills->addExperience(82, fletching);
				return;
			}
		}
		break;
	case 79:
		if (player->skills->getEffect(fletching) >= 69)
		{
			if (player->inventory->getSlot(slotTwo)->getId() == 91)
			{
				player->inventory->replace(new Item(103, 1), slotOne);
				player->inventory->remove(slotTwo);
				player->skills->addExperience(100, fletching);
				return;
			}
		}
		break;
	default:
		break;
	}
}

void Fletching::fletch(int slotOne, int slotTwo)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;

	player->inventory->displayInv();

	//Use knife on logs
	if (player->inventory->getSlot(slotOne)->getId() == 129)
	{
		knifeOnLog(slotOne, slotTwo);
		return;
	}
	else if (player->inventory->getSlot(slotTwo)->getId() == 129)
	{
		knifeOnLog(slotTwo, slotOne);
		return;
	}

	//String shortbow or crossbow
	if (player->inventory->getSlot(slotOne)->getId() == 30)
	{
		stringShortbow(slotOne, slotTwo);
		return;
	}
	else if (player->inventory->getSlot(slotTwo)->getId() == 30)
	{
		stringShortbow(slotTwo, slotOne);
		return;
	}

	//Fletch arrows / bolts
	if (player->inventory->getSlot(slotOne)->getId() == 57 || player->inventory->getSlot(slotOne)->getId() == 58)
	{
		fletchArrow(slotOne, slotTwo);
		return;
	}
	else if (player->inventory->getSlot(slotTwo)->getId() == 57 || player->inventory->getSlot(slotTwo)->getId() == 58)
	{
		fletchArrow(slotTwo, slotOne);
		return;
	}

	//Make crossbow unstrung
	makeCrossbow(slotOne, slotTwo);
	makeCrossbow(slotTwo, slotOne);
}