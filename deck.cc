#include "deck.h"
#include <cstdlib>

Deck::Deck() {
}


Deck::~Deck() {
    for(int i = 0; i < allCards.size(); i++){
        delete allCards[i];
    }
}

void randomize(int i, int j, vector <Card*>& set){
    Card* temp = set[i];
    set[i] = set[j];
    set[j] = temp;
}


void Deck::shuffle() {
    for(int i = 0; i < allCards.size(); i++){
        int randValue = rand() % allCards.size();
        randomize(i, randValue, allCards);
    }
}
