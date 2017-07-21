

#ifndef player_hpp
#define player_hpp
#include <string>
#include "hand.h"
#include "ascii_graphics.h"
using namespace std;


class Player {
private:
	std::string name;
	int health = 20;
	int magic;
	Hand* hand;
	int num;
public:
	Player(std::string name, Hand* hand, int num);
	~Player();
	void setName(string name);
	void useSkill();
	void takeDmg(int dmg);
	std::string getName();
	Hand getHand();
	void getMagic();
	void takeCard();
	int getSkill(int index);
	card_template_t display();
};
#endif
