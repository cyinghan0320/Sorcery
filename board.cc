#include "board.h"

//need to implant showboard
Board::Board(Player* player1, Player* player2)
: grave1{new Graveyard}, grave2{new Graveyard}, player1{player1}, player2{player2}, turn{1} {}


Board::~Board(){
    delete grave1;
    delete grave2;
    delete player1;
    delete player2;
    delete ritual1;
    delete ritual2;
    for(int i = 0; i < minions1.size(); i++){
        delete minions1[i];
    }
    for(int j = 0; j < minions2.size(); j++){
        delete minions2[j];
    }
}


void Board::showboard(){} //need implamentation

void Board::playerHand(){
    if(turn%2 == 1){
        player1.hand.showhand();
    } else{
        player2.hand.showhand();
    }
}


void Board::attack(int i){
    if(minions2.size() == 0 && turn%2 == 1) {
        player2.takeDmg(minions1[i].attack);  //make a attack fun or make attack public for minion,
    } else if(minions1.size() == 0 && turn%2 == 0) {
        player1.takeDmg(minions2[i].attack);  //make a attack fun or make attack public for minion or friend,
    } else{
        cout << "cannot attack opponent." << endl;
    }
}


void Board::attack(int i, int j){
    int m1 = j;
    int m2 = i;
    if(turn%2 == 1){
        m1 = i;
        m2 = j;
    }
    minions1[m1].health -= minions2[m2].attack;
    minions2[m2].health -= minions1[m1].attack;
    if(minions1[m1].defeated()){
        Minion* holder1 = new Minion;
        holder1(minions1[m1]->getStat().name);
        grave1->addMinion(holder1);
        minions1.erase(m1);
    } 
    if(minions2[m2].defeated()){
        Minion* holder2 = new Minion;
        holder2(minions2[m2]->getStat().name);
        grave2->addMinion(holder2);
        minions2.erase(m2);
    }
}

void Board::use(int i){
    if(turn%2 == 1){
        minion1[i]->use();
    } else {
        minion2[i]->use();
    }
}


void Board::use(int i, int p, int t){
    if(turn%2 == 1){
        if(p == 1){
            minion1[i]->use(minion1[t]);
        } else if(p == 2){
            minion1[i]->use(minion2[t]);
        }
    } else{
        if(p == 1){
            minion2[i]->use(minion1[t]);
        } else if(p == 2){
            minion2[i]->use(minion2[t]);
        }
    }
}


void Board::play(int i) {
    if(turn%2 == 1){
        player1->onHand[i]->useCard();
    } else{
        player2->onHand[i]->useCard();
    }
}


void Board::play(int i, int p, int t){
    if(turn%2 == 1){
        if(p == 1){
            player1->onHand[i]->useCard(minion1[t]);
        } else if(p == 2){
            player1->onHand[i]->useCard(minion2[t]);
        }
    } else {
        if(p == 1){
            player2->onHand[i]->useCard(minion1[t]);
        } else if(p == 2){
            player2->onHand[i]->useCard(minion2[t]);
        }
    }
}


void Board::setRitual(Ritual* ritual){
    if(turn%2 == 1){
        delete ritual1;
        ritual1 = ritual;
    } else {
        delete ritual2;
        ritual2 = ritual;
    }
}


void Board::playRitual(){
    if(turn%2 == 1){
        ritual1->useCard();
    } else{
        ritual2->useCard();
    }
}

void Board::end(){
    turn++;
}


int getTurn() {
    return turn;
}

