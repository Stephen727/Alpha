#include <string>

class Skills;
class Inventory;
class Equipment;
class PrayerBook;
class Prayer;
class Magic;
class Slayer;
class Food;
class Potion;
class UseItem;

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player();

	Player(std::string);

	~Player();

	Skills *skills;
	Inventory *inventory;
	Equipment *equipment;
	PrayerBook *prayerBook;
	Prayer *prayer;
	Magic *magic;
	Slayer *slayer;
	Food* food;
	Potion* potion;
	UseItem* useItem;

private:
	std::string username;
	int combatDelay, foodDelay, potionDelay;
	int combatStance;
	bool autoCast;

public:
	void setName(std::string str) { username = str; }
	void tickDelay();
	void eatDelay();
	void drinkDelay();
	void resetDelay() { combatDelay = 0; foodDelay = 0; potionDelay = 0; }
	void setCombatStance(int);
	void toggleAutoCast() { autoCast = !autoCast; }
	void setAutoCast(bool b) { autoCast = b; }

	std::string getName() const { return username; }
	bool hasEatDelay() const { return foodDelay > 0; }
	bool hasDrinkDelay() const { return potionDelay > 0; }
	int getCombatDelay() const { return combatDelay; }
	int getAttackStyle() const;
	int getCombatStance() const { return combatStance; }
	bool getAutoCast() const { return autoCast; }
};

#endif