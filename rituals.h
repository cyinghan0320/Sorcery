#ifndef RITUAL_H
#define RITUAL_H
#include "ascii_graphics.h"
#include "card.h"
#include <string>
using namespace std;

class Ritual : public Card {
	std::string name;
	std::string description;
	string type = "ritual";
	int cost;
	int charge;
public:
	void draw();
	Ritual(std::string name, std::string description, int cost);
	void useCard();
	card_template_t display();
};

#endif
