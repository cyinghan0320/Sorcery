#ifndef Enchantment_hpp
#define Enchantment_hpp
#include "minion.h"
#include "info.h"
#include <string>
using namespace std;

class Enchantment : public Minion {
protected:
	Minion* minion;
	string enchantDes;
public:
	Enchantment(){
	}
	~Enchantment(){
		delete minion;
	}
	virtual Minion* assign(Minion* &min);
	vector <string> getEnchantVec(){
		return enchantVec;
	}
	Minion* removeEnchant(){
		return minion;
	}
	
	void deleteMinion(){
		minion = nullptr;
		delete this;
	}
};


class GiantStrength : public Enchantment {
public:
	GiantStrength() {
		name = "Giant Strength";
		enchantDes ="";
		summonCost = 1;
		attack = 2;
		health = 2;
	}
	Minion* assign(Minion* &min){
		Info info;
		minion= min;
		info = min->getStat(info);
		minion = min;
		name = info.name;
		des = info.des;
		type = "minion";
		summonCost = info.summonCost;
		abilityCost = info.abilityCost;
		ability = info.ability;
		trigger = info.trigger;
		action = info.action;
		attack = info.attack + 2;
		health = info.health + 2;
		enchantVec = info.enchantVec;
		enchantVec.push_back(name);
	}
};


class MagicFatigue : public Enchantment {
public:
	MagicFatigue() {
		name = "Magic Fatigue";
		enchantDes ="Enchanted minion's activated ability costs 2 more";
		summonCost = 0;
	}
	Minion* assign(Minion* &min){
		Info info;
		info = min->getStat(info);
		minion = min;
		name = info.name;
		des = info.des;
		type = "minion";
		summonCost = info.summonCost;
		abilityCost = info.abilityCost + 2;
		ability = info.ability;
		trigger = info.trigger;
		action = info.action;
		attack = info.attack;
		health = info.health;
		enchantVec = info.enchantVec;
		enchantVec.push_back(name);
	}

};


class Silence : public Enchantment {
public:
	Silence() {
		name = "Silence";
		enchantDes="Enchanted minion cannot use ability";
		summonCost = 1;
	}
	Minion* assign(Minion* &min){
		Info info;
		minion = min;
		name =info.name;
		des =info.des;
		type = "minion";
		summonCost = info.summonCost;
		abilityCost = info.abilityCost;
		ability = "";
		trigger =info.trigger;
		action = info.action;
		attack = info.attack;
		health = info.health;
		enchantVec = info.enchantVec;
		enchantVec.push_back(name);
	}

};




#endif
