#ifndef graveyard_h
#define graveyard_h
#include <vector>
#include "card.h"
#include <string>
#include "ascii_graphics.h"

class Graveyard {
private:
	std::vector<Minion*> stack;
public:
	Graveyard();
	~Graveyard();
	std::string getTop();     //gets the name of the card and deletes the pointer
	bool isEmpty();
	void addMinion(Minion* ptr);
	card_template_t display();

};



#endif /* graveyard_hpp */
