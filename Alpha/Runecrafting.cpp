#include "Runecrafting.h"
#include "Player.h"


Runecrafting::Runecrafting()
{
}

Runecrafting::Runecrafting(Player* p)
{
	player = p;
}

Runecrafting::~Runecrafting()
{
}


void Runecrafting::runecraft(int id)
{
	system("CLS");

	switch (id)
	{
	case 0: //air runes
		if (player->inventory->hasItem(519))
		{
			std::cout << "You use the Air Altar..." << std::endl;

			if (player->skills->getEffect(runecrafting) >= 99)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(539, amount * 10));
				player->skills->addExperience(5 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 88)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(539, amount * 9));
				player->skills->addExperience(5 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 77)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(539, amount * 8));
				player->skills->addExperience(5 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 66)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(539, amount * 7));
				player->skills->addExperience(5 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 55)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(539, amount * 6));
				player->skills->addExperience(5 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 44)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(539, amount * 5));
				player->skills->addExperience(5 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 33)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(539, amount * 4));
				player->skills->addExperience(5 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 22)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(539, amount * 3));
				player->skills->addExperience(5 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 11)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(539, amount * 2));
				player->skills->addExperience(5 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 1)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(539, amount));
				player->skills->addExperience(5 * amount, runecrafting);
			}
		}
		else
			std::cout << "You need a talisman to enter here..." << std::endl;
		break;
	case 1: //mind runes
		if (player->inventory->hasItem(521))
		{
			std::cout << "You use the Mind Altar..." << std::endl;

			if (player->skills->getEffect(runecrafting) >= 98)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(540, amount * 8));
				player->skills->addExperience(6 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 84)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(540, amount * 7));
				player->skills->addExperience(6 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 70)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(540, amount * 6));
				player->skills->addExperience(6 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 56)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(540, amount * 5));
				player->skills->addExperience(6 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 42)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(540, amount * 4));
				player->skills->addExperience(6 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 28)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(540, amount * 3));
				player->skills->addExperience(6 * amount, runecrafting);
			}

			else if (player->skills->getEffect(runecrafting) >= 14)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(540, amount * 2));
				player->skills->addExperience(6 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 2)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(540, amount));
				player->skills->addExperience(6 * amount, runecrafting);
			}
			else
				std::cout << "You don't have the required skills here." << std::endl;
		}
		else
			std::cout << "You need a talisman to enter here..." << std::endl;
		break;
	case 2: //water runes
		if (player->inventory->hasItem(523))
		{
			std::cout << "You use the Water Altar..." << std::endl;

			if (player->skills->getEffect(runecrafting) >= 95)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(541, amount * 6));
				player->skills->addExperience(7 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 76)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(541, amount * 5));
				player->skills->addExperience(7 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 57)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(541, amount * 4));
				player->skills->addExperience(7 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 38)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(541, amount * 3));
				player->skills->addExperience(7 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 19)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(541, amount * 2));
				player->skills->addExperience(7 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 5)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(541, amount));
				player->skills->addExperience(7 * amount, runecrafting);
			}
			else
				std::cout << "You don't have the required skills here." << std::endl;
		}
		else
			std::cout << "You need a talisman to enter here..." << std::endl;
		break;
	case 3: //earth runes
		if (player->inventory->hasItem(525))
		{
			std::cout << "You use the Earth Altar..." << std::endl;

			if (player->skills->getEffect(runecrafting) >= 78)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(542, amount * 4));
				player->skills->addExperience(8 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 52)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(542, amount * 3));
				player->skills->addExperience(8 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 26)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(542, amount * 2));
				player->skills->addExperience(8 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 9)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(542, amount));
				player->skills->addExperience(8 * amount, runecrafting);
			}
			else
				std::cout << "You don't have the required skills here." << std::endl;
		}
		else
			std::cout << "You need a talisman to enter here..." << std::endl;
		break;
	case 4: //Fire runes
		if (player->inventory->hasItem(527))
		{
			std::cout << "You use the Fire Altar..." << std::endl;

			if (player->skills->getEffect(runecrafting) >= 70)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(543, amount * 3));
				player->skills->addExperience(9 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 35)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(543, amount * 2));
				player->skills->addExperience(9 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 14)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(543, amount));
				player->skills->addExperience(9 * amount, runecrafting);
			}
			else
				std::cout << "You don't have the required skills here." << std::endl;
		}
		else
			std::cout << "You need a talisman to enter here..." << std::endl;
		break;
	case 5: //Cosmic runes
		if (player->inventory->hasItem(529))
		{
			std::cout << "You use the Cosmic Altar..." << std::endl;

			if (player->skills->getEffect(runecrafting) >= 59)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(544, amount * 2));
				player->skills->addExperience(10 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 27)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(544, amount));
				player->skills->addExperience(10 * amount, runecrafting);
			}
			else
				std::cout << "You don't have the required skills here." << std::endl;
		}
		else
			std::cout << "You need a talisman to enter here..." << std::endl;
		break;
	case 6: //Chaos runes
		if (player->inventory->hasItem(531))
		{
			std::cout << "You use the Chaos Altar..." << std::endl;

			if (player->skills->getEffect(runecrafting) >= 74)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(545, amount * 2));
				player->skills->addExperience(11 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 35)
			{
				int amount = player->inventory->hasAmount(517);
				player->inventory->removeItem(517, amount);
				player->inventory->add(new Item(545, amount));
				player->skills->addExperience(11 * amount, runecrafting);
			}
			else
				std::cout << "You don't have the required skills here." << std::endl;
		}
		else
			std::cout << "You need a talisman to enter here..." << std::endl;
		break;
	case 7: //Nature runes
		if (player->inventory->hasItem(533))
		{
			std::cout << "You use the Nature Altar..." << std::endl;

			if (player->skills->getEffect(runecrafting) >= 91)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(546, amount * 2));
				player->skills->addExperience(12 * amount, runecrafting);
			}
			else if (player->skills->getEffect(runecrafting) >= 44)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(546, amount));
				player->skills->addExperience(12 * amount, runecrafting);
			}
			else
				std::cout << "You don't have the required skills here." << std::endl;
		}
		else
			std::cout << "You need a talisman to enter here..." << std::endl;
		break;
	case 8: //Death runes
		if (player->inventory->hasItem(535))
		{
			std::cout << "You use the Death Altar..." << std::endl;

			if (player->skills->getEffect(runecrafting) >= 65)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(547, amount));
				player->skills->addExperience(15 * amount, runecrafting);
			}
			else
				std::cout << "You don't have the required skills here." << std::endl;
		}
		else
			std::cout << "You need a talisman to enter here..." << std::endl;
		break;
	case 9: //Blood runes
		if (player->inventory->hasItem(537))
		{
			std::cout << "You use the Blood Altar..." << std::endl;

			if (player->skills->getEffect(runecrafting) >= 77)
			{
				int amount = player->inventory->hasAmount(218);
				player->inventory->removeItem(218, amount);
				player->inventory->add(new Item(548, amount));
				player->skills->addExperience(30 * amount, runecrafting);
			}
			else
				std::cout << "You don't have the required skills here." << std::endl;
		}
		else
			std::cout << "You need a talisman to enter here..." << std::endl;
		break;
	default:
		return;
	}

	std::cin.clear();
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	std::cin.ignore();
}