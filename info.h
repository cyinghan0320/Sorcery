#ifndef Info_h
#define Info_h
#include <vector>
#include "card.h"
#include <string>
using namespace std;

struct Info {
	string name, des, type;
	int summonCost, abilityCost;
	string ability;
	bool trigger;
	int action, attack, health;
	vector<string> enchantVec;
};

 #endif
