

#ifndef player_hpp
#define player_hpp
#include <string>
#include "hand.h"
using namespace std;


class Player {
private:
    string name;
    int health = 20;
    int magic;
    Hand* hand;
public:
    Player(String name, Hand* hand);
    ~Player();
    void useSkill();
    void takeDmg(int dmg);
    string getName();
    Hand getHand();
}
#endif
