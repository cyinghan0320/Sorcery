#include "deck.h"
#include <cstdlib>

using namespace std;

void randomize(int i, int j, vector<string>& set){
	string temp = set[i];
	set[i] = set[j];
	set[j] = temp;
}

void Deck::removeTop(){
	allCards.pop_back();
}
//
// Deck::Deck(vector<string> a) :
//  allCards{a}{
// }

void Deck::Dshuffle() {
	for(int i = 0; i < allCards.size(); i++) {
		int randValue = rand() % allCards.size();
		randomize(i, randValue, allCards);
	}
}


void Deck::addCard(string name){
	allCards.push_back(name);
}


void Deck::addFront(string name){
	allCards.insert(name, 0);
}
