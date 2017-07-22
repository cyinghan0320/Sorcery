#ifndef RITUAL_H
#define RITUAL_H
#include "ascii_graphics.h"
#include "board.h"
#include "card.h"
#include <string>
using namespace std;

class Board;

class Ritual : public Card {
	int charge;
	int index;
public:
	void draw();
	void useCard(Board &t);
	card_template_t display();
};

#endif
