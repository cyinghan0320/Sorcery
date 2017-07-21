#ifndef Info_h
#define Info_h
#include <vector>
#include "card.h"
using namespace std;

struct Info {
	string name, des, type;
	int summonCost, abilityCost;
	string ability;
	bool trigger;
	int action, attack, health;
	vector<Card*> enchantVec;
};

 #endif
