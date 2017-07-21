#ifndef SPELL_H
#define SPELL_H

#include "card.h"
#include "ascii_graphics.h"

class spell : public Card {
	std::string type = "spell";
public:
	void draw();
	spell(std::string name,std::string description,int cost, std::string type = "spell");
	int getCost();
	std::string getDes();
	card_template_t display();
};

#endif
