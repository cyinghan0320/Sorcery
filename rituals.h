#ifndef RITUAL_H
#define RITUAL_H
#include "ascii_graphics.h"
#include "board.h"
#include "card.h"

class Ritual : public Card {
	std::string name;
	std::string description;
	Board &t;
	int cost;
	int charge;
	int index;
public:
	void draw();
	Ritual(std::string name, std::string description, int cost, int index);
	void useCard();
	card_template_t display();
};

#endif
