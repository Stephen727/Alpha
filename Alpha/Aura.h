#include <string>

#ifndef AURA_H
#define AURA_H

enum AuraType {ATTACK, STRENGTH, DEFENSE, COMBAT, MAGE_RANGE, OVER_HEAD};

class Aura
{
public:
	Aura(std::string, int, double, AuraType);

	~Aura();

private:
	std::string name;
	int level;
	double drainRate;
	AuraType auraType;

public:
	std::string getName() { return name; }
	int getLevel() { return level; }
	double getDrainRate() { return drainRate; }
	AuraType getAuraType() { return auraType; }
};

extern Aura *aura[20];

#endif