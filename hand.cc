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
		GiantStrength* cardptr = new GiantStrength(); 
	} else if(name == "Magic Fatigue"){
		MagicFatigue* cardptr = new MagicFatigue(); 
	} else if(name == "Silence"){
		Silence* cardptr = new Silence(); 
	} else if(name == "Dark Ritual"){
		Ritual* cardptr = new Ritual(name, "At the start of your turn, gain 1 magic" , 0, 5);
	} else if(name == "Aura of Power"){
		Ritual* cardptr = new Ritual(name, "Whenever a minion enters play under your control, it gains +1/+1" , 1, 4);
	} else if(name == "Standstill"){
		Ritual* cardptr = new Ritual(name, "Whenever a minion enters play, destroy it" , 3, 4);
	} else if(name == "Banish"){
		Spell* cardptr = Spell(name,2,"Destroy target minion or ritual");
	} else if(name == "Unsummon"){
		Spell* cardptr = Spell(name,1,"Put target minion on the bottom of its owner's deck");
	} else if(name == "Recharge"){
		Spell* cardptr = Spell(name,1,"Your ritual gains 3 charges");
	} else if(name == "Disenchant"){
		Spell* cardptr = Spell(name,1,"Destroy the top enchantment on target minion");
	} else if(name == "Raise Dead"){
		Spell* cardptr = Spell(name,1,"Resurrect the top minion in your graveyard");
	} else ifname == "Blizzard"){
		Spell* cardptr = Spell(name,3,"Deal 2 damage to all minions");
	} else{
		Minion* cardptr = new Minion(name);
	}
	return cardptr;
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
	Card* newCard = createCard(newCardName);
	onHand.push_back(newCard);
}
