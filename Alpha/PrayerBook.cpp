#include "PrayerBook.h"
#include "Player.h"
#include "Skills.h"
#include "Equipment.h"


PrayerBook::PrayerBook()
{
	for (int i = 0; i < 20; i++)
		activated[i] = false;
}


PrayerBook::PrayerBook(Player* _player)
{
	player = _player;

	for (int i = 0; i < 20; i++)
		activated[i] = false;
}


PrayerBook::~PrayerBook()
{
	player = nullptr;
	delete player;
}


bool PrayerBook::canToggle(int slot)
{
	if (!player->skills->getEffect(prayer))
		return false;
	else if (slot < 0 || slot > 20)
		return false;

	if (aura[slot]->getLevel() <= player->skills->getLevel(prayer))
		return true;
	else
		return false;
}

void PrayerBook::toggle(int slot)
{
	if (canToggle(slot))
	{
		if (!activated[slot])
		{
			if (aura[slot]->getAuraType() == COMBAT)
			{
				for (int i = 0; i < 20; i++)
				{
					if (aura[i]->getAuraType() != OVER_HEAD)
						activated[i] = false;
				}
			}
			else if (aura[slot]->getAuraType() != OVER_HEAD)
			{
				for (int i = 0; i < 20; i++)
				{
					if (aura[i]->getAuraType() == aura[slot]->getAuraType() || aura[i]->getAuraType() == COMBAT)
						activated[i] = false;
				}
			}
			else
				for (int i = 0; i < 20; i++)
					if (aura[i]->getAuraType() == OVER_HEAD)
						activated[i] = false;
		}
		activated[slot] = !activated[slot];
	}
}

bool PrayerBook::getActivated(int slot)
{
	if (slot < 0 || slot > 20)
		return false;
	else
		return activated[slot];
}

double PrayerBook::getPrayerDrain()
{
	double prayerDrain = 0;

	for (int i = 0; i < 20; i++)
		if (activated[i])
			prayerDrain += 1 / aura[i]->getDrainRate();

	if (prayerDrain)
		prayerDrain *= 1.0 - ((double)player->equipment->getBonus(7) / 61.0);

	return prayerDrain;
}

void PrayerBook::displayPrayerBook()
{
	std::cout << "   ---Prayer Book---" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		std::cout << " [" << i + 1 << "] ";
		if (activated[i]) std::cout << "<";
		std::cout << aura[i]->getName();
		if (activated[i]) std::cout << ">";
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl << ">";
}