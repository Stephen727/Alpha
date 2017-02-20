#include "DefinitionLoader.h"

#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
	Item();

	Item(int, int);

	~Item();

	friend std::istream& operator >> (std::istream& in, Item& obj);
	friend std::ostream& operator << (std::ostream& in, const Item& obj);

private:
	int id,
		amount;

public:
	int getId() { return id; }
	int getAmount() { return amount; }

	void setId(int i) { id = i; }
	void setAmount(int i) { amount = i; }

	void add() { amount++; }
	void add(int am) { amount += am; }
	void remove() { amount--; }
	void remove(int am) { amount -= am; }
	void note();
	void unNote();

	ItemDefinition* getItemDefinition();
	EquipmentDefinition* getEquipmentDefinition();
	ItemBonusDefinition* getItemBonusDefinition();
	FoodDefinition* getFoodDefinition();
	PotionDefinition* getPotionDefinition();
	RangedDefinition* getRangedDefinition();
	WeaponDefinition* getWeaponDefinition();
};

#endif