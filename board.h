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
	Ritual* ritual1 = nullptr;
	Ritual* ritual2 = nullptr;
	int turn;
public:
	Board(Player* player1, Player* player2);
	~Board();
	void showboard();
	void playerHand();
	void attack(int i);
	void attack(int i, int j);
	void use(int i);
	void use(int i, int p, int t);
	void play(int i);
	void play(int i, int p, int t);
	void setRitual(Ritual* ritual);
	void end();
	int getTurn();
};



#endif
