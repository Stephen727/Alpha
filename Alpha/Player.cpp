#include "Player.h"

#include "Skills.h"
#include "Inventory.h"
#include "Equipment.h"
#include "Bank.h"
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
	bank = new Bank(this);
	prayerBook = new PrayerBook(this);
	prayer = new Prayer(this);
	magic = new Magic(this);
	slayer = new Slayer(this);
	food = new Food(this);
	potion = new Potion(this);
	useItem = new UseItem(this);

	//Starting Items
	inventory->add(new Item(78, 1)); //Wooden sword
	inventory->add(new Item(80, 1)); //Wooden shield
	inventory->add(new Item(66, 1)); //Shortbow
	inventory->add(new Item(52, 25)); //Bronze arrows
	inventory->add(new Item(0, 30)); //Air runes
	inventory->add(new Item(1, 30)); //Mind runes
	inventory->add(new Item(31, 1)); //Peach
}

Player::~Player()
{
	delete skills;
	delete inventory;
	delete equipment;
	delete bank;
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