#ifndef RITUAL_H
#define RITUAL_H
#include "ascii_graphics.h"
#include "ability.h"
#include "card.h"
#include <string>
using namespace std;

class Board;

class Ritual : public Card {
	std::string name;
	std::string des;
	int charge;
	int index;
public:
	Ritual(std::string name, std::string description,int cost, int charge);
	void draw();
	void useCard(Board &t);
	card_template_t display();
};

#endif
