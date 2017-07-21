#ifndef RITUAL_H
#define RITUAL_H
#include "ascii_graphics.h"
#include "card.h"
#include <string>
using namespace std;

class Ritual : public Card {
	string type = "ritual";
	int charge;
public:
	void draw();
	Ritual(std::string name, std::string description, int cost, int charge);
	void useCard();
	card_template_t display();
};

#endif
