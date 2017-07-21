#ifndef RITUAL_H
#define RITUAL_H
#include "ascii_graphics.h"
#include "card.h"

class Ritual : public Card {
	std::string name;
	std::string description;
	int cost;
	int charge;
public:
	void draw();
	Ritual(std::string name, std::string description, int cost);
	void useCard();
	card_template_t display();
};

#endif
