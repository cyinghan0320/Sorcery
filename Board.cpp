#include "Board.hpp"

//need to implant showboard
Board::Board(GraveYard* grave1, GraveYard* grave2, Player* player1,
             Player* player2, Ritual* ritual1, Ritual* ritual2)
: grave1{grave1}, grave2{grave2}, player1{player1}, player2{player2},
ritual1{ritual1}, ritual2{ritual2}, turn{1} {}


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


void Board::showboard(){}


void Board::attack(int i){
    if(minions2.size() == 0 && turn == 1) {
        player2.takeDmg(minions1[i].attack);  //make a attack fun or make attack public for minion,
    } else if(minions1.size() == 0 && turn == 2) {
        player1.takeDmg(minions2[i].attack);  //make a attack fun or make attack public for minion or friend,
    } else{
        cout << "cannot attack opponent." << endl;
    }
}


void Board::attack(int i, int j){
    int m1 = i;
    int m2 = j;
    if(turn == 2){
        m1 = j;
        m2 = i;
    }
    minions1[m1].health -= minions2[m2].attack;
    minions2[m2].health -= minions1[m1].attack;
}

void Board::use(int i){
    if(turn == 1){
        minion1.use();
    } else {
        minion2.use();
    }
}


void Board::use(int i, int p, int t){
    if(turn == 1){
        if(p == 1 && t != 'r'){
            minion1.use(minion1[t]);
        } else if p == 2 && t != 'r'{
            minion1.use(minion2[t]);
        } else if(p == 1 && t == 'r'){
            minion1.use(*ritual1);
        } else if(p == 2 && t == 'r'){
            minion1.use(*ritual2);
        }
    } else {
        if(p == 1 && t != 'r'){
            minion2.use(minion1[t]);
        } else if p == 2 && t != 'r'{
            minion2.use(minion2[t]);
        } else if(p == 1 && t == 'r'){
            minion2.use(*ritual1);
        } else if(p == 2 && t == 'r'){
            minion2.use(*ritual2);
        }
    }
}
