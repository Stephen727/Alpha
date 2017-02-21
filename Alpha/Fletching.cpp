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

	int input,
		logs[6] = { 0, 2, 4, 6, 8, 10 };

	for (int i = 0; i < 6; i++)
	{
		if (player->inventory->getSlot(slotTwo)->getId() == logs[i])
			break;

		return;
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

	//Fletch arrow shafts
	if (input == 1)
	{
		switch (player->inventory->getSlot(slotTwo)->getId())
		{
		case 0:
			if (player->skills->getEffect(fletching) >= 1)
			{
				player->inventory->remove(slotTwo);
				player->inventory->add(new Item(56, 15));
				player->skills->addExperience(5, fletching);
				return;
			}
			break;
		case 2:
			if (player->skills->getEffect(fletching) >= 15)
			{
				player->inventory->remove(slotTwo);
				player->inventory->add(new Item(56, 30));
				player->skills->addExperience(10, fletching);
				return;
			}
			break;
		case 4:
			if (player->skills->getEffect(fletching) >= 30)
			{
				player->inventory->remove(slotTwo);
				player->inventory->add(new Item(56, 45));
				player->skills->addExperience(15, fletching);
				return;
			}
			break;
		case 6:
			if (player->skills->getEffect(fletching) >= 45)
			{
				player->inventory->remove(slotTwo);
				player->inventory->add(new Item(56, 60));
				player->skills->addExperience(20, fletching);
				return;
			}
			break;
		case 8:
			if (player->skills->getEffect(fletching) >= 60)
			{
				player->inventory->remove(slotTwo);
				player->inventory->add(new Item(56, 75));
				player->skills->addExperience(25, fletching);
				return;
			}
			break;
		case 10:
			if (player->skills->getEffect(fletching) >= 75)
			{
				player->inventory->remove(slotTwo);
				player->inventory->add(new Item(56, 90));
				player->skills->addExperience(30, fletching);
				return;
			}
			break;
		default:
			break;
		}
	}

	//Fletch unstrung shortbow
	if (input == 2)
	{
		switch (player->inventory->getSlot(slotTwo)->getId())
		{
		case 0:
			if (player->skills->getEffect(fletching) >= 5)
			{
				player->inventory->replace(new Item(32, 1), slotTwo);
				player->skills->addExperience(5, fletching);
				return;
			}
			break;
		case 2:
			if (player->skills->getEffect(fletching) >= 20)
			{
				player->inventory->replace(new Item(34, 1), slotTwo);
				player->skills->addExperience(17, fletching);
				return;
			}
			break;
		case 4:
			if (player->skills->getEffect(fletching) >= 35)
			{
				player->inventory->replace(new Item(36, 1), slotTwo);
				player->skills->addExperience(34, fletching);
				return;
			}
			break;
		case 6:
			if (player->skills->getEffect(fletching) >= 50)
			{
				player->inventory->replace(new Item(38, 1), slotTwo);
				player->skills->addExperience(50, fletching);
				return;
			}
			break;
		case 8:
			if (player->skills->getEffect(fletching) >= 65)
			{
				player->inventory->replace(new Item(40, 1), slotTwo);
				player->skills->addExperience(68, fletching);
				return;
			}
			break;
		case 10:
			if (player->skills->getEffect(fletching) >= 80)
			{
				player->inventory->replace(new Item(42, 1), slotTwo);
				player->skills->addExperience(84, fletching);
				return;
			}
			break;
		default:
			break;
		}
	}

	//Fletch crossbow stock
	if (input == 3)
	{
		switch (player->inventory->getSlot(slotTwo)->getId())
		{
		case 0:
			if (player->skills->getEffect(fletching) >= 9)
			{
				player->inventory->replace(new Item(71, 1), slotTwo);
				player->skills->addExperience(6, fletching);
				return;
			}
			break;
		case 2:
			if (player->skills->getEffect(fletching) >= 24)
			{
				player->inventory->replace(new Item(73, 1), slotTwo);
				player->skills->addExperience(27, fletching);
				return;
			}
			break;
		case 4:
			if (player->skills->getEffect(fletching) >= 39)
			{
				player->inventory->replace(new Item(75, 1), slotTwo);
				player->skills->addExperience(32, fletching);
				return;
			}
			break;
		case 6:
			if (player->skills->getEffect(fletching) >= 54)
			{
				player->inventory->replace(new Item(77, 1), slotTwo);
				player->skills->addExperience(41, fletching);
				return;
			}
			break;
		case 8:
			if (player->skills->getEffect(fletching) >= 69)
			{
				player->inventory->replace(new Item(79, 1), slotTwo);
				player->skills->addExperience(50, fletching);
				return;
			}
			break;
		default:
			break;
		}
	}
}

void Fletching::stringShortbow(int slotOne, int slotTwo)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;

	switch (player->inventory->getSlot(slotTwo)->getId())
	{
	case 32:
		if (player->skills->getEffect(fletching) >= 5)
		{
			player->inventory->remove(slotOne);
			player->inventory->replace(new Item(44, 1), slotTwo);
			player->skills->addExperience(5, fletching);
			return;
		}
		break;
	case 34:
		if (player->skills->getEffect(fletching) >= 20)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->replace(new Item(46, 1), slotTwo);
			player->skills->addExperience(17, fletching);
			return;
		}
		break;
	case 36:
		if (player->skills->getEffect(fletching) >= 35)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->replace(new Item(48, 1), slotTwo);
			player->skills->addExperience(34, fletching);
			return;
		}
		break;
	case 38:
		if (player->skills->getEffect(fletching) >= 50)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->replace(new Item(50, 1), slotTwo);
			player->skills->addExperience(50, fletching);
			return;
		}
		break;
	case 40:
		if (player->skills->getEffect(fletching) >= 65)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->replace(new Item(52, 1), slotTwo);
			player->skills->addExperience(68, fletching);
			return;
		}
		break;
	case 42:
		if (player->skills->getEffect(fletching) >= 80)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->replace(new Item(84, 1), slotTwo);
			return;
		}
		break;
	default:
		break;
	}
}

void Fletching::stringCrossbow(int slotOne, int slotTwo)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;

	switch (player->inventory->getSlot(slotTwo)->getId())
	{
	case 93:
		if (player->skills->getEffect(fletching) >= 9)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->remove(slotTwo, 1);
			player->inventory->add(new Item(105, 1));
			player->skills->addExperience(6, fletching);
			return;
		}
		break;
	case 95:
		if (player->skills->getEffect(fletching) >= 39)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->remove(slotTwo, 1);
			player->inventory->add(new Item(107, 1));
			player->skills->addExperience(22, fletching);
			return;
		}
		break;
	case 97:
		if (player->skills->getEffect(fletching) >= 46)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->remove(slotTwo, 1);
			player->inventory->add(new Item(109, 1));
			player->skills->addExperience(24, fletching);
			return;
		}
		break;
	case 99:
		if (player->skills->getEffect(fletching) >= 54)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->remove(slotTwo, 1);
			player->inventory->add(new Item(111, 1));
			player->skills->addExperience(32, fletching);
			return;
		}
		break;
	case 101:
		if (player->skills->getEffect(fletching) >= 61)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->remove(slotTwo, 1);
			player->inventory->add(new Item(113, 1));
			player->skills->addExperience(41, fletching);
			return;
		}
		break;
	case 103:
		if (player->skills->getEffect(fletching) >= 69)
		{
			player->inventory->remove(slotOne, 1);
			player->inventory->remove(slotTwo, 1);
			player->inventory->add(new Item(115, 1));
			player->skills->addExperience(50, fletching);
			return;
		}
		break;
	default:
		break;
	}
}

void Fletching::fletchBolt(int slotOne, int slotTwo)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;

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
					return;
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
				return;
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
					return;
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
				return;
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
					return;
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
				return;
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
					return;
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
				return;
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
					return;
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
				return;
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
					return;
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
				return;
			}
		}
		break;
	default:
		break;
	}
}

void Fletching::fletchArrow(int slotOne, int slotTwo)
{
	if (player->inventory->getSlot(slotOne) == NULL)
		return;
	else if (player->inventory->getSlot(slotTwo) == NULL)
		return;

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
					return;
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
				return;
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
						return;
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
					return;
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
						return;
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
					return;
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
						return;
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
					return;
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
						return;
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
					return;
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
						return;
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
					return;
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
						return;
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
					return;
				}
			}
			break;
		default:
			fletchBolt(slotOne, slotTwo);
			break;
		}
	}
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

	//String shortbow
	if (player->inventory->getSlot(slotOne)->getId() == 30)
	{
		stringShortbow(slotOne, slotTwo);
		return;
	}

	//String crossbow
	if (player->inventory->getSlot(slotOne)->getId() == 30)
	{
		stringCrossbow(slotOne, slotTwo);
		return;
	}

	//Fletch arrows / bolts
	if (player->inventory->getSlot(slotOne)->getId() == 57 || player->inventory->getSlot(slotOne)->getId() == 58)
	{
		fletchArrow(slotOne, slotTwo);
		return;
	}

	//Make crossbow unstrung
	makeCrossbow(slotOne, slotTwo);
}