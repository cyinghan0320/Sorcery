#ifndef hand_hpp
#define hand_hpp

#include <vector>
#include "card.h"
#include "deck.h"
using namespace std;

class Hand {
private:
	vector <Card*> onHand;
	Deck* myDeck;
	int num;

public:
	Hand(Deck* myDeck, int num);
	~Hand();
	void showhand();
	void discard(int i);
	void draw();
};

#endif
