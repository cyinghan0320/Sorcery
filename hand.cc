#include "hand.h"
#include "ascii_graphics.h"
#include <iostream>
#include <vector>

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

void drawLine(int num){
	for (int i = 0; i < num; ++i) {
		cout << "|";
		for (int j = 0; j < 20; ++j) {
			cout << "-";
		}
	}
}




void Hand::showhand(){
	vector<card_template_t> out;
	for (auto e: onHand) {
		string ty  = e->showType();
		if (ty == "minion") {
			if (e->getAbility() == -1)
				out.emplace_back(display_minion_no_ability(e->getName(), e->showCost(), e->showAttack(), e->showDefence()));
			else if (e->trigger())
				out.emplace_back(display_minion_no_ability(e->getName(), e->showCost(), e->showAttack(), e->showDefence(), e->showDescription()));
			else
				out.emplace_back(display_minion_no_ability(e->getName(), e->showCost(), e->showAttack(), e->showDefence(), e->showCost(),e->showDescription()));
		}
		else if (ty == "spell") {
			out.emplace_back(display_spell(e->getName(),e->getCost(), e->getDes()));
		}
		else if (ty == "ritual") {
			out.emplace_back(display_ritual(e->getName(), 1, e->getCost(), e->getDes(), e->getCharge()));
		}
		else if (ty == "enchantment") {
			out.emplace_back(display_ritual(e->getName(), e->getCost(), e->getDes()));
		}
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
	Card newCard = myDeck.allCards.back;
	myDeck.allCards.resize(myDeck.size() - 1);
	onHand.push_back(newCard);
}
