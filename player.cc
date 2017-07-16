

#include "player.h"


Player(String name, Hand* hand, string ability) : name {name} hand {hand}, ability {ability} {}

~Player(){
	delete hand;
}

void useSkill(){
}                 //implant what skills



void takeDmg(int dmg) {
	health -= dmg;
	if(health < 1) {
		cout <<"player "<< name <<" defeated" << endl;
	}
}
