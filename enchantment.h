#ifndef Enchantment_hpp
#define Enchantment_hpp
#include "minion.h"
#include "info.h"
using namespace std;

class Enchantment : public Minion {
protected:
    Minion* minion;
public:
    Enchantment(Minion &min): minion{min} {}
    ~Enchantment(){
        delete minion;
    }
    virtual Minion* assign(Minion* &min);
}


class GiantStrength : public Enchantment {
public:
    Minion* assign(Minion* &min){
        name = min->getStat().name;
        des = min->getStat().des;
        type = "minion";
        summonCost = min->getStat().summonCost;
        abilityCost = min->getStat().abilityCost;
        ability = min->getStat().ability;
        trigger = min->getStat().trigger;
        action = min->getStat().action;
        attack = min->getStat().attack + 2;
        health = min->getStat().health + 2;
    }
}


class MagicFatigue : public Enchantment {
public:
    Minion* assign(Minion* &min){
        name = min->getStat().name;
        des = min->getStat().des;
        type = "minion";
        summonCost = min->getStat().summonCost;
        abilityCost = min->getStat().abilityCost + 2;
        ability = min->getStat().ability;
        trigger = min->getStat().trigger;
        action = min->getStat().action;
        attack = min->getStat().attack;
        health = min->getStat().health;
    }
}


class Silence : public Enchantment {
public:
    Minion* assign(Minion* &min){
        name = min->getStat().name;
        des = min->getStat().des;
        type = "minion";
        summonCost = min->getStat().summonCost;
        abilityCost = min->getStat().abilityCost;
        ability = "";
        trigger = min->getStat().trigger;
        action = min->getStat().action;
        attack = min->getStat().attack;
        health = min->getStat().health;
    };
}




#endif
