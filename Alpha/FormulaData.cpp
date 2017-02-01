#include "FormulaData.h"
#include <random>
#include <time.h>


std::uniform_real_distribution<> dist(0, 1);
std::default_random_engine generator(time(NULL));


FormulaData::FormulaData()
{
}


FormulaData::~FormulaData()
{
}


double FormulaData::getChance(double attack, double defence)
{
	double A = attack,
		D = defence;

	double chance = A < D ? (A - 1.0) / (2.0 * D) : 1.0 - (D + 1.0) / (2.0 * A);
	chance = chance > 0.9999 ? 0.9999 : chance < 0.0001 ? 0.0001 : chance;

	return chance;
}

bool FormulaData::isAccurateHit(double attack, double defense)
{
	double chance = getChance(attack, defense);
	return dist(generator) <= chance;
}