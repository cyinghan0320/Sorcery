#include "hand.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Card* Hand::createCard(string name){

	if(name == "Giant Strength") {
		return new GiantStrength();
	} else if(name == "Magic Fatigue") {
		return new MagicFatigue();
	} else if(name == "Silence") {
		return new Silence();
	} else if(name == "Dark Ritual") {
		return new Ritual(name, "At the start of your turn, gain 1 magic", 0,"gain 1 magic at start", 1, 5);
	} else if(name == "Aura of Power") {
		return new Ritual(name, "Whenever a minion enters play under your control, it gains +1/+1", 1,"+1/+1 enter play", 1, 4);
	} else if(name == "Standstill") {
		return new Ritual(name, "Whenever a minion enters play, destroy it", 3, "destroy enter play", 2, 4);
	} else if(name == "Banish") {
		return new Spell(name,"Destroy target minion or ritual", 2, "destroy");
	} else if(name == "Unsummon") {
		return new Spell(name,"Put target minion on the bottom of its owner's deck",1, "unsummon");
	} else if(name == "Recharge") {
		return new Spell(name,"Your ritual gains 3 charges", 1,"recharge");
	} else if(name == "Disenchant") {
		return new Spell(name,"Destroy the top enchantment on target minion", 1, "disenchant");
	} else if(name == "Raise Dead") {
		// Spell* cardptr = new Spell(name,"Resurrect the top minion in your graveyard", 1,"revive");
	} else if(name == "Blizzard") {
		return new Spell(name,"Deal 2 damage to all minions", 3, "blizzard");
	} else if(name == "Assassinate"){
		return new Spell(name,"Deal 4 damage to player", 4, "assassinate")
	} else if(name == "Frenzy"){
		return new Spell(name,"Increase attack by 3 decrease health by 2", 2, "frenzy")
	} else{
		return new Minion(name);
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

vector<Card*>& Hand::getHand(){
	return onHand;
}


Card* Hand::getTop(){
	return myDeck->back();
}

void Hand::removeDeck(){
	myDeck->removeTop();
}

void Hand::inCard(Card *t){
	onHand.push_back(t);
}

Card* Hand::getCard(int i){
	return onHand[i];
}

void Hand::showHand(){
	vector<card_template_t> out;
	for (auto e: onHand) {
		out.emplace_back(e->display());
	}
	// int sz = out[0].size();
	// for (int j =0; j < sz; ++j) {
	//  for (int i=0; i < out.size(); ++i) {
	//      cout << out[i][j];
	//  }
	//  cout << endl;
	// }
}

void Hand::discard(int i) {
	// onHand.erase(i);
}


void Hand::draw() {
	// string newCardName = myDeck->allCards.pop_back();
	// Card* newCard = createCard(newCardName);
	// onHand.push_back(newCard);
}


void Hand::sendToBottom(string name){
	myDeck->addFront(name);
}
