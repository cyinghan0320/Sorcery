

#ifndef player_hpp
#define player_hpp
#include <string>
#include "hand.h"
#include "ascii_graphics.h"
#include <boolean>
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
	bool dead();
	card_template_t display();
};
#endif
