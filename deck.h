#ifndef deck_hpp
#define deck_hpp
#include <vector>
#include <fstream>
// #include "card.h"
#include <string>



class Deck {
private:
	std::vector<std::string> allCards;
public:
	void removeTop();
	void Dshuffle();
	void addCard(std::string str);
};


#endif
