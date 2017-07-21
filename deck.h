#ifndef deck_hpp
#define deck_hpp
#include <vector>
#include <fstream>
#include "card.h"

using namespace std;


class Deck : public Card {
private:
	std::vector<string> allCards;
public:
	Deck(); // need to implant using input file stream
	~Deck();
	void removeTop();
	void shuffle();
};
#endif
