

#include "player.h"


Player::Player(String name, Hand* hand) : name{name} hand{hand}{
}

Player::~Player(){
	delete hand;
}

void Player::getMagic(){
	++magic;
}

int Player::getSkill(int index){
	return onHand[index]->getAbility();
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
};


Hand Player::getHand(){
	return hand;
};
