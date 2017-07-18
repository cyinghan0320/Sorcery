#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
	string name;
	string description;
public:
	virtual useCard() = 0;
	virtual draw() = 0;
	virtual string getName() = 0;
	virtual string getDescription() = 0;
};

#endif CARD_H
