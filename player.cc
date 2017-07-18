

#include "player.h"


Player::Player(String name, Hand* hand):name{name} hand{hand}{}

Player::~Player(){
    delete hand;
}

void Player::useSkill(){} //implant what skills

void Player::takeDmg(int dmg) {
    health -= dmg;
    if(health < 1){
        cout <<"player "<< name <<" defeated" << endl;
    }
}


string Player::getName(){
    return name;
};


Hand Player::getHand(){
    return hand;
};
