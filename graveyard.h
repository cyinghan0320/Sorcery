#ifndef graveyard_h
#define graveyard_h
#include <vector>
#include "Card.h"
#include <string>
#include "ascii_graphics.h"

class Graveyard {
private:
	std::vector<Card*> stack;
public:
	Graveyard();
	~Graveyard();
	std::string getTop();     //gets the name of the card and deletes the pointer
	bool isEmpty();
	void addMinion();
	card_template_t display();

};



#endif /* graveyard_hpp */
