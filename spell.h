#ifndef SPELL_H
#define SPELL_H

#include "card.h"
#include "ascii_graphics.h"
#include "board.h"

class Spell : public Card {
public:
	void draw();
	Spell(std::string name,std::string description,int cost,
	      ,std::string ability, int abilityCost);
	int getCost();
	std::string getDes();
	card_template_t display();
};

#endif
