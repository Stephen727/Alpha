#include <string>
#include <vector>

#ifndef SHOPDEFINITION_H
#define SHOPDEFINITION_H

#include "Item.h"

class ShopDefinition
{
public:
	ShopDefinition() {};

	ShopDefinition(std::string _name, std::vector<Item> _stock)
	{
		name = _name;
		stock = _stock;
	};

	~ShopDefinition() {};

private:
	std::string name;
	std::vector<Item> stock;

public:
	std::string getName() { return name; }
	std::vector<Item> getStock() { return stock; }
};

#endif