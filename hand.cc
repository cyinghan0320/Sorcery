#include "hand.h"
#include "ascii_graphics.h"
#include <iostream>
#include <vector>
#include <boolean>
#include <string>



bool isSpell(string name){
	for(int i = 0; i < ){
		
	} 
}


Hand::Hand(Deck* myDeck, int num) : myDeck{myDeck}, num {num}{
}


Hand::~Hand(){
	for(int i = 0; i < onHand.size(); i++) {
		delete onHand[i];
	}
}

bool Hand::emptyDeck(){
	if (myDeck == nullptr)
		return true;
	return false;
}


Card* Hand::getTop(){
	return myDeck->back();
}

void Hand::removeDeck(){
	myDeck->removeTop();
}

void Hand::getCard(Card *t){
	onHand.push_back(t);
}


void Hand::showhand(){
	vector<card_template_t> out;
	for (auto e: onHand) {
		out.emplace_back(e->display());
	}
	int sz = out[0].size();
	for (int j =0; j < sz; ++j) {
		for (int i=0; i < out.size(); ++i) {
			cout << out[i][j];
		}
		cout << endl;
	}
}

void Hand::discard(int i) {
	onHand.erase(i);
}


void Hand::draw() {
	string newCardName = myDeck->allCards.pop_back();
	Card* newCard;
	if() {
	} else if(){
	} else if(){
	
	} else if(){
	}
		
	onHand.push_back(newCard);
}
