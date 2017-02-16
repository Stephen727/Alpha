#include <string>
#include <vector>

#ifndef CITYDEFINITION_H
#define CITYDEFINITION_H

class CityDefinition
{
public:
	CityDefinition() {};

	CityDefinition(int _id, std::string _name, std::vector<int> _dungeonId)
	{
		id = _id;
		name = _name;
		dungeonId = _dungeonId;
	}

	~CityDefinition() {};

private:
	int id;
	std::string name;
	std::vector<int> dungeonId;

public:
	int getId() const { return id; }
	std::string getName() const { return name; }
	std::vector<int> getDungeonId() const { return dungeonId; }
};

#endif