#ifndef RITUAL_H
#define RITUAL_H
#include "ascii_graphics.h"
#include "ability.h"
#include "card.h"
#include <string>
using namespace std;

class Board;

class Ritual : public Card {
	int charge;
public:
	Ritual(std::string name, std::string description, int summonCost, std::string ability, int abilityCost, int charge)
	name{name},des{description}, ability{ability} ,
	abilityCost{abilityCost}, summonCost{summonCost},charge{charge}, type{"ritual"};
	void draw();
	void useCard(Board &t);
	card_template_t display();
};

#endif
