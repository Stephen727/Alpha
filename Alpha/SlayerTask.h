#include <string>
#include <vector>

#ifndef SLAYERTASK_H
#define SLAYERTASK_H

class SlayerTask
{
public:
	SlayerTask();

	SlayerTask(std::string, int, std::vector<int>);

	~SlayerTask();

private:
	std::string name;
	int level;
	std::vector<int> id;

public:
	std::string getName() { return name; }
	int getLevel() { return level; }
	std::vector<int> getId() { return id; }
};

extern std::vector<SlayerTask*> turael, mazchna, vannaka, chaeldar, nieve, duradel;

#endif