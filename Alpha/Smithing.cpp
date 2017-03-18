#include "Smithing.h"
#include "Player.h"


std::vector<std::pair<int, int>> bar = { { 252, 13 }, { 254, 25 }, { 256, 38 }, { 260, 50 }, { 262, 63 }, { 264, 75 } };
std::vector<std::pair<int, int>> dagger = { { 268, 1 }, { 298, 15 }, { 328, 30 }, { 358, 50 }, { 388, 70 }, { 418, 85 } };
std::vector<std::pair<int, int>> hatchet = { { 12, 1 }, { 14, 16 }, { 16, 31 }, { 20, 51 }, { 22, 71 }, { 24, 86 } };
std::vector<std::pair<int, int>> mace = { { 270, 2 }, { 300, 17 }, { 330, 32 }, { 360, 52 }, { 390, 72 }, { 420, 87 } };
std::vector<std::pair<int, int>> medHelm = { { 272, 2 }, { 302, 18 }, { 332, 33 }, { 362, 53 }, { 392, 73 }, { 422, 88 } };
std::vector<std::pair<int, int>> bolt = { { 117, 3 }, { 118, 18 }, { 119, 33 }, { 120, 53 }, { 121, 73 }, { 122, 88 } };
std::vector<std::pair<int, int>> sword = { { 274, 4 }, { 304, 19 }, { 334, 34 }, { 364, 54 }, { 394, 74 }, { 424, 89 } };
std::vector<std::pair<int, int>> arrowtip = { { 59, 5 }, { 60, 20 }, { 61, 35 }, { 62, 55 }, { 63, 75 }, { 64, 90 } };
std::vector<std::pair<int, int>> scimitar = { { 276, 5 }, { 306, 20 }, { 336, 35 }, { 366, 55 }, { 396, 75 }, { 426, 90 } };
std::vector<std::pair<int, int>> cbowLimb = { { 81, 6 }, { 83, 23 }, { 85, 36 }, { 87, 56 }, { 89, 76 }, { 91, 91 } };
std::vector<std::pair<int, int>> longsword = { { 278, 6 }, { 308, 21 }, { 338, 36 }, { 368, 56 }, { 398, 76 }, { 428, 91 } };
std::vector<std::pair<int, int>> fullHelm = { { 280, 7 }, { 310, 22 }, { 340, 37 }, { 370, 57 }, { 400, 77 }, { 430, 92 } };
std::vector<std::pair<int, int>> knife = { { 835, 7 }, { 836, 22 }, { 837, 37 }, { 838, 57 }, { 839, 77 }, { 840, 92 } };
std::vector<std::pair<int, int>> sqShield = { { 282, 8 }, { 312, 23 }, { 342, 38 }, { 372, 58 }, { 402, 78 }, { 432, 93 } };
std::vector<std::pair<int, int>> warhammer = { { 284, 9 }, { 314, 24 }, { 344, 39 }, { 374, 59 }, { 404, 79 }, { 434, 94 } };
std::vector<std::pair<int, int>> battleaxe = { { 286, 10 }, { 316, 25 }, { 346, 40 }, { 376, 60 }, { 406, 80 }, { 436, 95 } };
std::vector<std::pair<int, int>> chainbody = { { 288, 11 }, { 318, 26 }, { 348, 41 }, { 378, 61 }, { 408, 81 }, { 438, 96 } };
std::vector<std::pair<int, int>> kiteshield = { { 290, 12 }, { 320, 27 }, { 350, 42 }, { 380, 62 }, { 410, 82 }, { 440, 97 } };
std::vector<std::pair<int, int>> twohand = { { 292, 14 }, { 322, 29 }, { 352, 44 }, { 382, 64 }, { 412, 84 }, { 442, 99 } };
std::vector<std::pair<int, int>> plateleg = { { 294, 16 }, { 324, 31 }, { 354, 46 }, { 384, 66 }, { 414, 86 }, { 444, 99 } };
std::vector<std::pair<int, int>> platebody = { { 296, 18 }, { 326, 33 }, { 356, 48 }, { 386, 68 }, { 416, 88 }, { 446, 99 } };


Smithing::Smithing()
{
}

Smithing::Smithing(Player *p)
{
	player = p;
}

Smithing::~Smithing()
{
}


void Smithing::smelt(std::vector<Item> items, int newId, int exp)
{
	while (player->inventory->hasItems(items))
	{
		for (int i = 0; i < items.size(); i++)
			player->inventory->removeItem(items[i].getId(), items[i].getAmount());

		std::cout << "You smelt ores in the furnace..." << std::endl;
		_sleep(300);

		player->inventory->add(new Item(newId, 1));
		player->skills->addExperience(exp, smithing);
		if (newId == 258) player->skills->addExperience(30, crafting); //Gold bar
	}
}

void Smithing::smelt(int id)
{
	switch (id)
	{
	case 0: //bronze bar (copper + tin)
		if (player->skills->getEffect(smithing) >= 1)
			smelt({ { 220, 1 }, { 222, 1 } }, 252, 7);
		break;
	case 1: //iron bar (iron)
		if (player->skills->getEffect(smithing) >= 15)
		{
			while (player->inventory->hasItem(224, 1))
			{
				player->inventory->removeItem(224, 1);

				std::cout << "You smelt ores in the furnace..." << std::endl;
				_sleep(300);

				if (rand() % 2)
				{
					player->inventory->add(new Item(254, 1));
					player->skills->addExperience(13, smithing);
				}
			}
		}
		break;
	case 2: //steel bar (iron + 2 coal)
		if (player->skills->getEffect(smithing) >= 30)
			smelt({ { 224, 1 }, { 226, 2 } }, 256, 18);
		break;
	case 3: //gold bar (gold)
		if (player->skills->getEffect(smithing) >= 40)
			smelt({ { 228, 1 } }, 258, 23);
		break;
	case 4: //mithril bar (mithril + 4 coal)
		if (player->skills->getEffect(smithing) >= 50)
			smelt({ { 230, 1 }, { 226, 4 } }, 260, 30);
		break;
	case 5: //adamant bar (adamant + 6 coal)
		if (player->skills->getEffect(smithing) >= 70)
			smelt({ { 232, 1 }, { 226, 6 } }, 262, 38);
		break;
	case 6: //rune bar (rune + 8 coal)
		if (player->skills->getEffect(smithing) >= 85)
			smelt({ { 234, 1 }, { 226, 8 } }, 264, 50);
		break;
	default:
		break;
	}
}

void Smithing::smith(int id, int tier)
{
	if (!player->inventory->hasItem(266))
	{
		system("CLS");
		std::cout << "You stare at the anvil. Then the metal bar." << std::endl;
		std::cout << "You could try moulding it with your hands," << std::endl;
		std::cout << "but a hammer might work better..." << std::endl;
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		std::cin.ignore();
		return;
	}

	system("CLS");
	std::cout << " ---Anvil---" << std::endl;
	std::cout << " Hammer..." << std::endl;
	_sleep(300);
	std::cout << "   Hammer..." << std::endl;
	_sleep(300);
	std::cout << "     Hammer..." << std::endl;
	_sleep(300);

	switch (id)
	{
	case 0:
		if (player->skills->getEffect(smithing) >= dagger[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 1))
			{
				player->inventory->removeItem(bar[tier].first, 1);
				player->inventory->add(new Item(dagger[tier].first, 1));
				player->skills->addExperience(bar[tier].second, smithing);

				std::cout << "You smith a dagger!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 1:
		if (player->skills->getEffect(smithing) >= hatchet[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 1))
			{
				player->inventory->removeItem(bar[tier].first, 1);
				player->inventory->add(new Item(hatchet[tier].first, 1));
				player->skills->addExperience(bar[tier].second, smithing);

				std::cout << "You smith a hatchet!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 2:
		if (player->skills->getEffect(smithing) >= mace[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 1))
			{
				player->inventory->removeItem(bar[tier].first, 1);
				player->inventory->add(new Item(mace[tier].first, 1));
				player->skills->addExperience(bar[tier].second, smithing);

				std::cout << "You smith a mace!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 3:
		if (player->skills->getEffect(smithing) >= medHelm[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 1))
			{
				player->inventory->removeItem(bar[tier].first, 1);
				player->inventory->add(new Item(medHelm[tier].first, 1));
				player->skills->addExperience(bar[tier].second, smithing);

				std::cout << "You smith a med helm!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 4:
		if (player->skills->getEffect(smithing) >= bolt[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 1))
			{
				player->inventory->removeItem(bar[tier].first, 1);
				player->inventory->add(new Item(bolt[tier].first, 10));
				player->skills->addExperience(bar[tier].second, smithing);

				std::cout << "You smith some bolts!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 5:
		if (player->skills->getEffect(smithing) >= sword[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 1))
			{
				player->inventory->removeItem(bar[tier].first, 1);
				player->inventory->add(new Item(sword[tier].first, 1));
				player->skills->addExperience(bar[tier].second, smithing);

				std::cout << "You smith a sword!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 6:
		if (player->skills->getEffect(smithing) >= arrowtip[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 1))
			{
				player->inventory->removeItem(bar[tier].first, 1);
				player->inventory->add(new Item(arrowtip[tier].first, 15));
				player->skills->addExperience(bar[tier].second, smithing);

				std::cout << "You smith some arrow tips!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 7:
		if (player->skills->getEffect(smithing) >= scimitar[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 2))
			{
				player->inventory->removeItem(bar[tier].first, 2);
				player->inventory->add(new Item(scimitar[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 2, smithing);

				std::cout << "You smith a scimitar!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 8:
		if (player->skills->getEffect(smithing) >= cbowLimb[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 1))
			{
				player->inventory->removeItem(bar[tier].first, 2);
				player->inventory->add(new Item(cbowLimb[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 2, smithing);

				std::cout << "You smith a c'bow limb!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 9:
		if (player->skills->getEffect(smithing) >= longsword[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 2))
			{
				player->inventory->removeItem(bar[tier].first, 2);
				player->inventory->add(new Item(longsword[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 2, smithing);

				std::cout << "You smith a longsword!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 10:
		if (player->skills->getEffect(smithing) >= fullHelm[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 2))
			{
				player->inventory->removeItem(bar[tier].first, 2);
				player->inventory->add(new Item(fullHelm[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 2, smithing);

				std::cout << "You smith a full helm!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 11:
		if (player->skills->getEffect(smithing) >= knife[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 1))
			{
				player->inventory->removeItem(bar[tier].first, 1);
				player->inventory->add(new Item(knife[tier].first, 5));
				player->skills->addExperience(bar[tier].second * 1, smithing);

				std::cout << "You smith some knives!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 12:
		if (player->skills->getEffect(smithing) >= sqShield[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 2))
			{
				player->inventory->removeItem(bar[tier].first, 2);
				player->inventory->add(new Item(sqShield[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 2, smithing);

				std::cout << "You smith a sq shield!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 13:
		if (player->skills->getEffect(smithing) >= warhammer[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 3))
			{
				player->inventory->removeItem(bar[tier].first, 3);
				player->inventory->add(new Item(warhammer[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 3, smithing);

				std::cout << "You smith a warhammer!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 14:
		if (player->skills->getEffect(smithing) >= battleaxe[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 3))
			{
				player->inventory->removeItem(bar[tier].first, 3);
				player->inventory->add(new Item(battleaxe[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 3, smithing);

				std::cout << "You smith a battleaxe!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 15:
		if (player->skills->getEffect(smithing) >= chainbody[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 3))
			{
				player->inventory->removeItem(bar[tier].first, 3);
				player->inventory->add(new Item(chainbody[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 3, smithing);

				std::cout << "You smith a chainbody!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 16:
		if (player->skills->getEffect(smithing) >= kiteshield[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 3))
			{
				player->inventory->removeItem(bar[tier].first, 3);
				player->inventory->add(new Item(kiteshield[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 3, smithing);

				std::cout << "You smith a kiteshield!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 17:
		if (player->skills->getEffect(smithing) >= twohand[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 3))
			{
				player->inventory->removeItem(bar[tier].first, 3);
				player->inventory->add(new Item(twohand[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 3, smithing);

				std::cout << "You smith a 2h sword!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 18:
		if (player->skills->getEffect(smithing) >= plateleg[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 3))
			{
				player->inventory->removeItem(bar[tier].first, 3);
				player->inventory->add(new Item(plateleg[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 3, smithing);

				std::cout << "You smith some platelegs!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	case 19:
		if (player->skills->getEffect(smithing) >= platebody[tier].second)
		{
			if (player->inventory->hasItem(bar[tier].first, 5))
			{
				player->inventory->removeItem(bar[tier].first, 5);
				player->inventory->add(new Item(platebody[tier].first, 1));
				player->skills->addExperience(bar[tier].second * 5, smithing);

				std::cout << "You smith a platebody!" << std::endl;
			}
			else return;
		}
		else return;
		break;
	default:
		return;
		break;
	}

	std::cout << std::endl << " >";

	std::cin.clear();
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	std::cin.ignore();
}