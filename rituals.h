#ifndef RITUAL_H
#define RITUAL_H
#include "ascii_graphics.h"
#include "card.h"
#include <string>
using namespace std;

class Board;

class Ritual : public Card {
	int charge;
public:
	Ritual(std::string name, std::string description, int summonCost, std::string ability, int abilityCost, int charge);
	void draw();
	void useCard(Board &t);
	void recharge(int count);
	card_template_t display();
};

#endif
