#include "Player.h"

#include "Skills.h"
#include "Inventory.h"
#include "Equipment.h"
#include "PrayerBook.h"
#include "Prayer.h"
#include "Magic.h"
#include "Slayer.h"
#include "Food.h"
#include "Potion.h"
#include "UseItem.h"


Player::Player()
{
}

Player::Player(std::string _username)
{
	username = _username;
	combatDelay = 0, foodDelay = 0, potionDelay = 0;
	combatStance = 0;
	autoCast = false;

	skills = new Skills(this);
	inventory = new Inventory(this);
	equipment = new Equipment(this);
	prayerBook = new PrayerBook(this);
	prayer = new Prayer(this);
	magic = new Magic(this);
	slayer = new Slayer(this);
	food = new Food(this);
	potion = new Potion(this);
	useItem = new UseItem(this);
}

Player::~Player()
{
	delete skills;
	delete inventory;
	delete equipment;
	delete prayerBook;
	delete prayer;
	delete magic;
	delete slayer;
	delete food;
	delete potion;
	delete useItem;
}

void Player::tickDelay()
{
	if (combatDelay > 0)
		combatDelay--;
	else
	{
		if (this->equipment->getItem(3) != nullptr)
			combatDelay = this->equipment->getItem(3)->getWeaponDefinition()->getSpeed();
		else
			combatDelay = 5;
	}

	if (foodDelay > 0)
		foodDelay--;
	if (potionDelay > 0)
		potionDelay--;
}

void Player::eatDelay()
{
	combatDelay += 3 - potionDelay;
	foodDelay = 3;
}

void Player::drinkDelay()
{
	combatDelay += 3 - foodDelay;
	potionDelay = 3;
}

int Player::getAttackStyle() const
{
	if (autoCast)
		return 2;
	else if (this->equipment->getItem(3) != nullptr)
	{
		if (this->equipment->getItem(3)->getRangedDefinition() != nullptr)
			return 1;
	}
	return 0;
}

void Player::setCombatStance(int stance)
{
	switch (getAttackStyle())
	{
	case 0:
		combatStance = stance;
		break;
	case 1:
		if (stance == 1) combatStance = 5;
		else if (stance == 2) combatStance = 6;
		break;
	case 2:
		if (stance == 1) combatStance = 7;
		break;
	default:
		break;
	}
}