#include "hand.h"
#include
#include <iostream>

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

// void drawDescription(string description, int limit){
//  int len = description.length();
//  int max = len / limit;
//  int rem = len % limit;
//  int counter = 0;
//  while (counter != max) {
//      for (int i =0; i < limit; ++i) {
//          cout << description.at(counter*limit + i);
//      }
//      ++counter;
//  }
//  if (rem != 0) {
//      for (int i = 0; i < rem; ++i) {
//          cout << description.at(max * limit + i);
//      }
//  }
// }



void Hand::showhand(){


	// drawLine(num);
	// cout << "|";
	// cout << "|" << endl;
	// for (int v = 0; v < 5; ++v) {
	//  cout << "|";
	//  for (int i = 0; i < 3; ++i) {
	//      cout << " ";
	//  }
	//  cout << onHand[v]->getName();
	//  for (int i = 0; i < 9; ++i) {
	//      cout << " ";
	//  }
	//  cout << "|";
	//  for (int i = 0; i < 2; ++i) {
	//      cout << " ";
	//  }
	//  cout << "1 "; // need to modify later
	// }
	// cout << endl;
	//
	// drawLine (num);
	//
	// cout << "|" << endl;
	// for (int v = 0; v < 5; ++v) {
	//  cout << "|";
	//  for(int i =0; i < 15; ++i) {
	//      cout << " ";
	//  }
	//  cout << "type ";
	// }
	// cout << "|" << endl;
	// drawLine(num);
	// cout << "|" <<endl;
	// int counter = 0;
	// for (int i =0; i < 5; ++i) {
	//  int limit = 20;
	//  for (int j= 0; j < limit - 1; ++j) {
	//      int len = onHand[i]->getDescription().length();
	//      if (counter * (limit - 1) + j < len)
	//          cout << onHand[i]->getDescription().at(counter*(limit- 1) + j);
	//      else
	//          cout << " ";
	//  }
	//  cout << " |";
	//  ++counter;
	// }
	// cout << "|" << endl;

	//it is not finished since still need the attack and mana i guess
}



void Hand::discard(int i) {
	onHand.erase(i);
}


void Hand::draw() {
	Card newCard = myDeck.allCards.back;
	myDeck.allCards.resize(myDeck.size() - 1);
	onHand.push_back(newCard);
}
