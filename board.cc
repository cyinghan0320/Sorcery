#include "board.h"
//need to implant showboard
Board::Board(Player* player1, Player* player2)
	: grave1{new Graveyard}, grave2{new Graveyard}, player1{player1}, player2{player2}, turn{1} {
}


Board::~Board(){
	delete grave1;
	delete grave2;
	delete player1;
	delete player2;
	delete ritual1;
	delete ritual2;
	for(int i = 0; i < minions1.size(); i++) {
		delete minions1[i];
	}
	for(int j = 0; j < minions2.size(); j++) {
		delete minions2[j];
	}
}


void Board::showboard(){
	vector <card_template_t> line1;
	vector <card_template_t> line2;
	vector <card_template_t> line3;
	vector <card_template_t> line4;
	vector <card_template_t> line5;
	line1.emplace_back(ritual1->display());
	line1.emplace_back(CARD_TEMPLATE_BORDER);
	line1.emplace_back(player1->display());
	line1.emplace_back(CARD_TEMPLATE_BORDER);
	line1.emplace_back(grave1->display());
// not finished



} //need implamentation

void Board::playerHand(){
	if(turn%2 == 1) {
		player1->hand->showhand();
	} else{
		player2->hand->showhand();
	}
}


void Board::attack(int i){
	if(turn%2 == 1 && minions1[i]->getAction()) {
		player2->takeDmg(minions1[i]->showAttack());  //make a attack fun or make attack public for minion,
		minions1[i]->useAttack();
	} else if(turn%2 == 0 && minions2[i]->getAction()) {
		player1->takeDmg(minions2[i]->showAttack());
		minions2[i]->useAttack();
	} else{
		cout << "cannot attack opponent." << endl;
	}
}


void Board::attack(int i, int j){
	if(turn%2 == 1 && minions1[i]->getAction()) {
		minions1[i]->takeDmg(minions2[j]->showAttack());
		minions2[j]->takeDmg(minions1[i]->showAttack());
		minions1[i]->useAttack();
	} else if(turn%2 == 0 && minions2[i]->getAction()) {
		minions1[j]->takeDmg(minions2[i]->showAttack());
		minions2[i]->takeDmg(minions1[j]->showAttack());
		minions2[i]->useAttack();
	} else{
		cout << "cannot attack opponent." << endl;
	}

}




void Board::play(int i) {
	if(turn%2 == 1) {
		auto field = minions1;
		auto ritual = ritual1;
		(0 <= i && i < 5) ? auto object = player1->onHand[i] : Null;
	} else{
		auto field = minions2;
		auto ritual = ritual2;
		(0 <= i && i < 5) ? auto object = player2->onHand[i] : Null;
	}
	if(object->getStat().type == "minion") {
		field.push_back(object);
	} else if(object->getStat().type == "spell") {
		object->useCard();
	} else if(object->getStat().type == "ritual") {
		delete ritual;
		ritual = object;
	}
}


void Board::play(int i, int p, int t) {
	if(turn%2 == 1) {
		auto object = player1->onHand[i];
	} else{
		auto object = player2->onHand[i];  //need to implant getType
	}
	if(p == 1) {
		(t == 'r') ? auto target = ritual1 : Null;
		(0 <= t && t < 5) ? auto target = minions1[t] : Null;
	} else{
		(t == 'r') ? auto target = ritual2 : Null;
		(0 <= t && t < 5) ? auto target = minions2[t] : Null;
	}
	object->useCard(target);
}


void Board::use(int i){
	if(turn%2 == 1) {
		(i == 'r') ? auto object = ritual1 : Null;
		(0 <= i && i < 5) ? auto object = minions1[t] : Null;
	} else{
		(i == 'r') ? auto object = ritual2 : Null;
		(0 <= i && i < 5) ? auto object = minions2[t] : Null;
	}
	object->useCard();
}


void Board::use(int i, int p, int t){
	if(turn%2 == 1) {
		(i == 'r') ? auto object = ritual1 : Null;
		(0 <= i && i < 5) ? auto object = minions1[t] : Null;
	} else{
		(i == 'r') ? auto object = ritual2 : Null;
		(0 <= i && i < 5) ? auto object = minions2[t] : Null;
	}
	if(p == 1) {
		(t == 'r') ? auto target = ritual1 : Null;
		(0 <= t && t < 5) ? auto target = minions1[t] : Null;
	} else{
		(t == 'r') ? auto target = ritual2 : Null;
		(0 <= t && t < 5) ? auto target = minions2[t] : Null;
	}
	object->useCard(target);
}





void Board::end(){
	turn++;
}


int Board::getTurn() {
	return turn;
}


void Board::updateMinion() {
	for(int i = 0; i < minions1.size(); i++) {
		if(minions1[i]->defeated()) {
			Minion* holder = new Minion;
			holder(minions1[i]->getStat().name);
			grave1->addMinion(holder);
			minions1.erase(i);
		}
	}
	for(int j = 0; j < minions2.size(); j++) {
		if(minions2[j]->defeated()) {
			Minion* holder = new Minion;
			holder(minions2[j]->getStat().name);
			grave2->addMinion(holder);
			minions2.erase(j);
		}
	}
}

void Board::refreshAllAttack(){
	for(int i = 0; i < minions1.size(); i++) {
		minions1[i]->refreshAttack();
	}
	for(int i = 0; i < minions2.size(); i++) {
		minions2[i]->refreshAttack();
	}
}
