//
#ifndef Board_hpp
#define Board_hpp

#include "minion.h"
#include "rituals.h"
#include "player.h"
#include "graveyard.h"
#include "spell.h"
#include "ascii_graphics.h"
#include <vector>

using namespace std;

class Ritual;

class Board {
private:
	Graveyard* grave1;
	Graveyard* grave2;
	Player* player1;
	Player* player2;
	vector <Minion*> minions1;
	vector <Minion*> minions2;
	Ritual* ritual1 = nullptr;
	Ritual* ritual2 = nullptr;
	int turn;
public:
	Board(Player* player1, Player* player2);
	~Board();
	void showboard();
	void playerHand();
	void attack(int i, int j);
	void use(int i, int p, int t);
	void play(int i, int p, int t);
	void inspect(int i);
	void end();
	int getTurn();
	int getMinSize(int side);
	void updateMinion();
	void refreshAllAttack();
	Minion* findMinion(int p, int t);
	void replaceMinion(Minion* min, int p, int t);
	Minion* attachMinion(Enchantment* enchant, Minion* min);
};





#endif
