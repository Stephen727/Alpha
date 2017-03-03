#include "Herblore.h"
#include "Player.h"


int requirement[] = { 1, 12, 22, 36, 38, 45, 55, 63, 66, 72, 76, 78, 81 };
int primary[] = { 595, 597,  599, 601, 599, 603, 605, 607, 609, 611, 613, 615, 617 };
int secondary[] = { 575, 577, 579, 581, 583, 575, 577, 585, 579, 587, 589, 591, 593  };
int product[] = { 623, 631, 639, 647, 655, 663, 671, 679, 687, 695, 703, 711, 719 };
int experience[] = { 28, 55, 83, 90, 95, 109, 136, 155, 163, 177, 186, 190, 200 };

Herblore::Herblore()
{
}


Herblore::Herblore(Player *p)
{
	player = p;
}


Herblore::~Herblore()
{
}


void Herblore::brew(int potionId)
{
	if ((potionId < 0 || potionId > 13) || !player->inventory->hasItem(573))
		return;
	else if (potionId == 13) //Super combat
	{
		if (player->skills->getEffect(herblore) >= 90)
		{
			if (player->inventory->hasItem(665) && player->inventory->hasItem(673) && player->inventory->hasItem(689))
			{
				player->inventory->removeItem(573); //Vial
				player->inventory->removeItem(665); //Super attack
				player->inventory->removeItem(673); //Super strength
				player->inventory->removeItem(689); //Super defense
				player->inventory->add(new Item(729, 1)); //Super combat
				player->skills->addExperience(150, herblore);

				std::cout << "You brew: " << Item(729, 1).getItemDefinition()->getName() << std::endl;
			}
		}
	}
	else
	{
		if (player->skills->getEffect(herblore) >= requirement[potionId])
		{
			if (player->inventory->hasItem(primary[potionId]) && player->inventory->hasItem(secondary[potionId]))
			{
				player->inventory->removeItem(573); //Vial
				player->inventory->removeItem(primary[potionId]);
				player->inventory->removeItem(secondary[potionId]);
				player->inventory->add(new Item(product[potionId], 1));
				player->skills->addExperience(experience[potionId], herblore);

				std::cout << "You brew: " << Item(product[potionId], 1).getItemDefinition()->getName() << std::endl;
			}
		}
	}
}

void Herblore::display()
{
	int input;

	system("CLS");
	std::cout << "    ---Brew---" << std::endl;
	std::cout << " [1] Attack potion" << std::endl;
	std::cout << " [2] Strength potion" << std::endl;
	std::cout << " [3] Defense potion" << std::endl;
	std::cout << " [4] Combat potion" << std::endl;
	std::cout << " [5] Prayer potion" << std::endl;
	std::cout << " [6] Super attack" << std::endl;
	std::cout << " [7] Super strength" << std::endl;
	std::cout << " [8] Super restore" << std::endl;
	std::cout << " [9] Super defense" << std::endl;
	std::cout << " [10] Ranging potion" << std::endl;
	std::cout << " [11] Magic potion" << std::endl;
	std::cout << " [12] Zamorak brew" << std::endl;
	std::cout << " [13] Saradomin brew" << std::endl;
	std::cout << " [14] Super combat" << std::endl;
	std::cout << std::endl << ">";

	while (!(std::cin >> input) || (input < 0 || input > 14))
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		}
	}

	if (input)
	{
		for (int i = 0; i < 6; i++)
			brew(input - 1);

		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		std::cin.ignore();
	}
}

bool Herblore::decant(int slotOne, int slotTwo)
{
	int oneDose[] = { 619, 627, 635, 643, 651, 659, 667, 675, 683, 691, 699, 707, 715, 723 },
		twoDose[] = { 621, 629, 637, 645, 653, 661, 669, 677, 685, 693, 701, 709, 717, 725 },
		threeDose[] = {623, 631, 639, 647, 655, 663, 671, 679, 687, 695, 703, 711, 719, 727 },
		fourDose[] = { 625, 633, 641, 649, 657, 665, 673, 681, 689, 697, 705, 713, 721, 729 };

	if (player->inventory->getSlot(slotOne) == nullptr || player->inventory->getSlot(slotTwo) == nullptr)
		return false;
	
	for (int i = 0; i < sizeof(oneDose) / sizeof(oneDose[0]); i++)
	{
		if (player->inventory->getSlot(slotOne)->getId() == oneDose[i])
		{
			if (player->inventory->getSlot(slotTwo)->getId() == oneDose[i])
			{
				player->inventory->replace(new Item(573, 1), slotOne);
				player->inventory->replace(new Item(twoDose[i], 1), slotTwo);
				return true;
			}
			else if (player->inventory->getSlot(slotTwo)->getId() == twoDose[i])
			{
				player->inventory->replace(new Item(573, 1), slotOne);
				player->inventory->replace(new Item(threeDose[i], 1), slotTwo);
				return true;
			}
			else if (player->inventory->getSlot(slotTwo)->getId() == threeDose[i])
			{
				player->inventory->replace(new Item(573, 1), slotOne);
				player->inventory->replace(new Item(fourDose[i], 1), slotTwo);
				return true;
			}
			else
				return false;
		}
	}

	for (int i = 0; i < sizeof(twoDose) / sizeof(twoDose[0]); i++)
	{
		if (player->inventory->getSlot(slotOne)->getId() == twoDose[i])
		{
			if (player->inventory->getSlot(slotTwo)->getId() == oneDose[i])
			{
				player->inventory->replace(new Item(573, 1), slotOne);
				player->inventory->replace(new Item(threeDose[i], 1), slotTwo);
				return true;
			}
			else if (player->inventory->getSlot(slotTwo)->getId() == twoDose[i])
			{
				player->inventory->replace(new Item(573, 1), slotOne);
				player->inventory->replace(new Item(fourDose[i], 1), slotTwo);
				return true;
			}
			else if (player->inventory->getSlot(slotTwo)->getId() == threeDose[i])
			{
				player->inventory->replace(new Item(oneDose[i], 1), slotOne);
				player->inventory->replace(new Item(fourDose[i], 1), slotTwo);
				return true;
			}
			else
				return false;
		}
	}

	for (int i = 0; i < sizeof(threeDose) / sizeof(threeDose[0]); i++)
	{
		if (player->inventory->getSlot(slotOne)->getId() == threeDose[i])
		{
			if (player->inventory->getSlot(slotTwo)->getId() == oneDose[i])
			{
				player->inventory->replace(new Item(573, 1), slotOne);
				player->inventory->replace(new Item(fourDose[i], 1), slotTwo);
				return true;
			}
			else if (player->inventory->getSlot(slotTwo)->getId() == twoDose[i])
			{
				player->inventory->replace(new Item(oneDose[i], 1), slotOne);
				player->inventory->replace(new Item(fourDose[i], 1), slotTwo);
				return true;
			}
			else if (player->inventory->getSlot(slotTwo)->getId() == threeDose[i])
			{
				player->inventory->replace(new Item(twoDose[i], 1), slotOne);
				player->inventory->replace(new Item(fourDose[i], 1), slotTwo);
				return true;
			}
			else
				return false;
		}
	}
}