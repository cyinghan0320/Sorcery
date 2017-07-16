//
#ifndef Board_hpp
#define Board_hpp

#include "minion.h"
#include "ritual.h"
#include "player.h"
#include "graveyard.h"
#include <vector>

using namespace std;

class Board {
private:
    GraveYard* grave1;
    GraveYard* grave2;
    Player* player1;
    Player* player2;
    vector <Minions*> minions1;
    vector <Minions*> minions2;
    Ritual* ritual1;
    Ritual* ritual2;
    int turn;
public:
    Board(GraveYard* grave1, GraveYard* grave2, Player* player1,
          Player* player2, Ritual* ritual1, Ritual* ritual2);
    ~Board();
    void showboard();
    void attack(int i);
    void attack(int i, int j);
    void use(int i);
    void use(int i, int p, int t);
}



#endif
