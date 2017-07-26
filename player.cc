

#include "player.h"

using namespace std;
Player::Player(string name, Hand* hand, int num) : name{name},hand{hand}, num{num}{
}




Player::~Player(){
	delete hand;
}

bool Player::useMagic(int cost){
	if(cost >= magic){
		magic -= cost;
		return true;
	} else {
	return false;
	}
}


void Player::getMagic(){
	++magic;
}


card_template_t Player::display(){
	return display_player_card(num, name, health, magic);
}


void Player::takeCard(){
	if (hand->emptyDeck() == true)
		return;
	else{
		hand->getCard(hand->getTop());
		hand->removeDeck();
	}
}

void Player::useSkill(){
}                         //implant what skills

void Player::setName(string name){
	this->name = name;
}

void Player::takeDmg(int dmg) {
	health -= dmg;
	if(health < 1) {
		cout <<"player "<< name <<" defeated" << endl;
	}
}


string Player::getName(){
	return name;
}


Hand* Player::getHand(){
	return hand->getHand();
}

bool dead(){
	if(health <= 0) {
		return true;
	}
	return false;
}
