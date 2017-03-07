#include "Cooking.h"
#include "Player.h"

#include <random>
#include <ctime>

std::default_random_engine randGen((unsigned)time(NULL));
std::uniform_int_distribution<int> chance(0, 99);


const std::vector<int> rawFood = { 131, 133, 135, 137, 139, 141, 143, 145, 147, 149, 151, 153, 155, 157, 159, 161, 208, 210 };
const std::vector<int> cookReq = { 1, 1, 5, 1, 10, 15, 18, 20, 25, 30, 40, 43, 45, 62, 80, 90, 1, 1 };
const std::vector<int> cookExp = { 30, 40, 50, 30, 60, 70, 75, 80, 90, 100, 120, 130, 140, 150, 210, 215, 30, 40 };
const std::vector<int> cookedFood = { 163, 165, 167, 169, 171, 173, 175, 177, 179, 181, 183, 185, 187, 189, 191, 193, 212, 214 };

Cooking::Cooking()
{
}


Cooking::Cooking(Player *p)
{
	player = p;
}


Cooking::~Cooking()
{
}

void Cooking::cook(int slot)
{
	if (player->inventory->getSlot(slot) == nullptr)
		return;

	for (int i = 0; i < rawFood.size(); i++)
	{
		if (player->inventory->getSlot(slot)->getId() == rawFood[i])
		{
			if (player->skills->getEffect(cooking) >= cookReq[i])
			{
				int rate = (int)std::round((((double)player->skills->getEffect(cooking) * 50.0) - ((double)cookReq[i] * 15.0)) / (double)cookReq[i] / 3.0 * 4.0);
				int roll = chance(randGen);

				_sleep(300);

				if (rate >= roll)
				{

					player->inventory->remove(slot);
					player->inventory->add(new Item(cookedFood[i], 1));
					player->skills->addExperience(cookExp[i], cooking);
					std::cout << " You successfully cook the " << Item(rawFood[i], 1).getItemDefinition()->getName() << "." << std::endl;
					return;
				}
				else
				{
					player->inventory->remove(slot);
					player->inventory->add(new Item(216, 1));
					std::cout << " You burn the " << Item(rawFood[i], 1).getItemDefinition()->getName() << "." << std::endl;
					return;
				}
			}
		}
	}
}