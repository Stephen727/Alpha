#include "Player.h"

#include "Skills.h"
#include "Inventory.h"
#include "Equipment.h"
#include "Bank.h"
#include "PrayerBook.h"
#include "Prayer.h"
#include "Magic.h"
#include "Slayer.h"
#include "Fishing.h"
#include "Cooking.h"
#include "Mining.h"
#include "Smithing.h"
#include "Woodcutting.h"
#include "Fletching.h"
#include "Crafting.h"
#include "Runecrafting.h"
#include "Food.h"
#include "Potion.h"
#include "UseItem.h"


Player::Player()
{	
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
	fishing = new Fishing(this);
	cooking = new Cooking(this);
	mining = new Mining(this);
	smithing = new Smithing(this);
	woodcutting = new Woodcutting(this);
	fletching = new Fletching(this);
	crafting = new Crafting(this);
	runecrafting = new Runecrafting(this);
	food = new Food(this);
	potion = new Potion(this);
	useItem = new UseItem(this);
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
	fishing = new Fishing(this);
	cooking = new Cooking(this);
	mining = new Mining(this);
	smithing = new Smithing(this);
	woodcutting = new Woodcutting(this);
	fletching = new Fletching(this);
	crafting = new Crafting(this);
	runecrafting = new Runecrafting(this);
	food = new Food(this);
	potion = new Potion(this);
	useItem = new UseItem(this);

	//Starting Items
	inventory->add(new Item(516, 30)); //Coins
	inventory->add(new Item(268, 1)); //Bronze dagger
	inventory->add(new Item(282, 1)); //Bronze sq shield
	inventory->add(new Item(44, 1)); //Shortbow
	inventory->add(new Item(65, 25)); //Bronze arrows
	inventory->add(new Item(539, 30)); //Air runes
	inventory->add(new Item(540, 30)); //Mind runes
	inventory->add(new Item(163, 1)); //Shrimp
	inventory->add(new Item(163, 1)); //Shrimp
	inventory->add(new Item(163, 1)); //Shrimp
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
	delete fishing;
	delete cooking;
	delete mining;
	delete smithing;
	delete woodcutting;
	delete fletching;
	delete crafting;
	delete runecrafting;
	delete food;
	delete potion;
	delete useItem;
}

void Player::create()
{
	do
	{
		system("CLS");
		std::cout << "Please enter a username: ";

		std::getline(std::cin, username);

		if (username.length() < 1 || username.length() > 15)
		{
			std::cout << "Username must be between 1 and 15 characters in length." << std::endl;
			system("PAUSE");
		}
	} while (username.length() < 1 || username.length() > 15);
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

void Player::respawn()
{
	this->inventory->clear();
	this->equipment->clear();
	this->skills->reset();
}

void Player::save()
{
	std::ofstream outFile("save.txt");

	outFile << username << std::endl << std::endl;
	this->slayer->save();
	this->skills->save();
	this->inventory->save();
	this->equipment->save();
	this->bank->save();

	outFile.close();
}

void Player::load()
{
	std::ifstream infile("save.txt");

	std::getline(infile, username);
	this->slayer->load();
	this->skills->load();
	this->inventory->load();
	this->equipment->load();
	this->bank->load();

	infile.close();
}