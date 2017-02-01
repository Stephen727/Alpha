#include <string>

#include "Aura.h"

class Player;

#ifndef PRAYERBOOK_H
#define PRAYERBOOK_H

class PrayerBook
{
public:
	PrayerBook();

	PrayerBook(Player*);

	~PrayerBook();

private:
	Player *player;
	bool activated[20];

	bool canToggle(int);

public:
	void toggle(int);
	void toggleAll() { for (int i = 0; i < 20; i++) activated[i] = false; }
	
	bool getActivated(int);
	double getPrayerDrain();

	void displayPrayerBook();
};

#endif