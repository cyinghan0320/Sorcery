#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include "ascii_graphics.h"

class Card {
	std::string name;
	std::string des;
	std::string type;
	int cost;
public:
	virtual useCard() = 0;
	virtual void draw() = 0;
	virtual std::string showType() = 0;
	virtual std::string getName() = 0;
	virtual std::string getDescription() = 0;
	virtual card_template_t display();
};

#endif
