#include <vector>

#ifndef EQUIPMENTDEFINITION_H
#define EQUIPMENTDEFINITION_H

class EquipmentDefinition
{
public:

	struct SkillData
	{
		SkillData(int _skillId, int _skillReq)
		{
			skillId = _skillId;
			skillReq = _skillReq;
		}

		int skillId,
			skillReq;
	};

	EquipmentDefinition() {};

	EquipmentDefinition(int _id, int _slot, std::vector<SkillData> _requirements)
	{
		id = _id;
		slot = _slot;
		requirements = _requirements;
	};

	~EquipmentDefinition() {};

private:
	int id,
		slot;
	std::vector<SkillData> requirements;

public:
	int getId() { return id; }
	int getSlot() { return slot; }
	std::vector<SkillData> getReq() { return requirements; }
};

#endif