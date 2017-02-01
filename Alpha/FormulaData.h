#ifndef FORMULADATA_H
#define FORMULADATA_H

class FormulaData
{
public:
	FormulaData();

	~FormulaData();

private:
	double getChance(double, double);
	
public:
	bool isAccurateHit(double, double);
};

#endif