#include <vector>

#ifndef RANGEDDEFINITION_H
#define RANGEDDEFINITION_H

class RangedDefinition
{
public:
	RangedDefinition() {};

	RangedDefinition(int _id, bool _type, std::vector<int> _ammo)
	{
		id = _id;
		type = _type;
		ammo = _ammo;
	};

	~RangedDefinition() {};

private:
	int id;
	bool type; //Shot or thrown
	std::vector<int> ammo;

public:
	int getId() { return id; }
	bool getType() { return type; }
	std::vector<int> getAmmo() { return ammo; }
};

#endif