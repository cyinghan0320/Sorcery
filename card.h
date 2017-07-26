#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include "ascii_graphics.h"

class Info;

class Card {
protected:
	std::string name;
	std::string des;
	std::string type;
	std::string ability;
	int abilityCost;
	int summonCost;
public:
	Card();
	virtual void draw() = 0;
	std::string showType(){
		return type;
	}
	std::string getName(){
		return name;
	}
	virtual Info getStat() = 0;
	std::string getDescription(){
		return des;
	}
	virtual card_template_t display();
	std::string getAbility(){
		return ability;
	}
	int getCost(){
		return abilityCost;
	}
};

#endif
