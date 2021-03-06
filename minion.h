#ifndef MINION_H
#define MINION_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "ascii_graphics.h"
#include "info.h"

class Minion : public Card {
protected:
	std::string type = "minion";
	bool trigger;
	int action = 1;
	int attack;
	int health;
	vector<std::string> enchantVec;

public:
	Minion();
	card_template_t display(){
		if (ability == "")
			return display_minion_no_ability(name, summonCost, attack, health);
		else if (trigger == true)
			return display_minion_triggered_ability(name, summonCost, attack, health, des);
		else
			return display_minion_activated_ability(name, summonCost, attack, health, abilityCost, des);
	}

int getCost(){
	return abilityCost;
}
	void heal(int count){
		health += count;	
	}
	
	void increaseStat(int attack, int health){
		attack += attack;
		health += health;
	}
	
	Info getStat(Info& information){
		information.name = name;
		information.des = des;
		information.type = "minion";
		information.summonCost = summonCost;
		information.abilityCost = abilityCost;
		information.ability = ability;
		information.trigger = trigger;
		information.action = action;
		information.attack = attack;
		information.health = health;
		information.enchantVec = enchantVec;
		return information;
	}

	void addEnchant(string name){
		enchantVec.push_back(name);
	}

	void removeEnchant(){
		return;
	}

	void useAttack(){
		action--;
	}

	void refreshAttack(){
		action = 1;
	}

	int getAction() {
		return action;
	}

	string getAbility(){
		return ability;
	}


	std::string showName(){
		return name;
	}

	int showAttack(){
		return attack;
	}

	int showHealth(){
		return health;
	}


	int showCost (){
		return summonCost;
	}

	std::string showDescription (){
		return des;
	}

	void takeDmg(int damage){
		health -= damage;
	}

	bool defeated(){
		if (health < 1)
			return true;
		return false;
	}

	Minion(std::string s) :  type{"minion"}{
		name = s;
		if(s == "Leech"){
			summonCost = 1;
			attack = 2;
			health = 4;
			abilityCost = 2;
			ability = "Heal";
			des = "health self by 1";
		} else if(s == "Hell Hound"){
			summonCost = 4;
			attack = 5;
			health = 4;
			abilityCost = 0;
		} else if(s == "Air Elemental") {
			summonCost = 0;
			abilityCost = 0;
			attack = 1;
			health = 1;
		} else if (s == "Earth Elemental") {
			summonCost = 3;
			abilityCost = 0;
			attack = 4;
			health = 4;
		} else if (s == "Fire Elemental") {
			summonCost = 2;
			ability = "enter play 1 dmg";
			abilityCost = 0;
			attack = 2;
			health = 2;
			des = "Whenever an opponent's minion enters the play, deal 1 damage to it.";
		} else if (s == "Potion Seller") {
			summonCost = 2;
			ability = "heal all";
			abilityCost = 0;
			attack = 1;
			health = 3;
			des = "at the end of your turn, all your minions gain +0/+1";
		} else if (s == "Novice Pyromancer") {
			summonCost = 1;
			ability = "deal 1 dmg";
			abilityCost = 1;
			attack = 0;
			health = 1;
			des = "Deal 1 damage to target minion";
		} else if (s == "Apprentice Summoner") {
			summonCost = 1;
			ability = "summon 1 air";
			abilityCost = 1;
			attack = 1;
			health = 1;
			des = "Summon a 1/1 air elemental";
		} else if (s == "Master Summoner") {
			summonCost = 3;
			ability = "summon 3 air";
			abilityCost = 2;
			attack = 2;
			health = 2;
			des = "Summon up to three 1/1 air elementals";
		} else{
			cerr << "No such minion exists." << endl;
		}
	}
};

#endif
