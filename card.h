#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
	std::string name;
	std::string description;
	std::string type;
	int cost;
public:
	virtual useCard() = 0;
	virtual draw() = 0;
	virtual std::string showType() = 0;
	virtual std::string getName() = 0;
	virtual std::string getDescription() = 0;
};

#endif
