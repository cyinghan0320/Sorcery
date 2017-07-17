#include "hand.h"

Hand::Hand(Deck* myDeck):myDeck{myDeck}{}


Hand::~Hand(){
    for(int i = 0; i < onHand.size(); i++){
        delete onHand[i];
    }
}


void Hand::showhand(){} //to be implanted



void Hand::discard(int i) {
    onHand.erase(i);
}


void Hand::draw() {
    Card newCard = myDeck.allCards.back;
    myDeck.allCards.resize(myDeck.size() - 1);
    onHand.push_back(newCard);
}
