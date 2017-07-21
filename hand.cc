#include "hand.h"
#include "minion.h"
#include "spell.h"
#include "ritual.h"
#include "enchantment"
#include "ascii_graphics.h"
#include <iostream>
#include <vector>
#include <boolean>
#include <string>



Card* createCard(string name){
	if(name == "Giant Strength"){
		Ritual* cardptr = new GiantStrength(); 
	} else if(name == "Magic Fatigue"){
		Ritual* cardptr = new MagicFatigue(); 
	} else if(name == "Silence"){
		Ritual* cardptr = new Silence(); 
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else if(){
	} else{
		Minion(name);
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
