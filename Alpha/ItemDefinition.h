#include <string>

#ifndef ITEMDEFINITION_H
#define ITEMDEFINITION_H

class ItemDefinition
{
public:
	ItemDefinition(){};

	ItemDefinition(std::string _name, int _id, bool _stackable, bool _note, int _noteId, int _alchemyPrice, int _generalPrice)
	{
		name = _name;
		id = _id;
		stackable = _stackable;
		note = _note;
		noteId = _noteId;
		alchemyPrice = _alchemyPrice;
		generalPrice = _generalPrice;
	};

	~ItemDefinition(){};

private:
	std::string name;
	int id;
	bool stackable,
		note;
	int noteId,
		alchemyPrice,
		generalPrice;

public:
	std::string getName() { return name; }
	int getId() { return id; }
	bool isStackable() { return stackable; }
	bool isNote() { return note; }
	int getNoteId() { return noteId; }
	int getAlchemyPrice() { return alchemyPrice; }
	int getGeneralPrice() { return generalPrice; }
};

#endif