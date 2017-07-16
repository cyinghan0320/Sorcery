#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
	string name;
public:
	virtual useCard() = 0;
	virtual draw() = 0;
};

#endif CARD_H
