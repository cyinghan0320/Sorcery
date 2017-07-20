#ifndef MINION_H
#define MINION_H

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

class Minion : public Card {
	std::string name;
	std::string des;
	std::string type = "minion";
	int summonCost;
	int abilityCost;
	int ability;
	bool trigger;
	int action;
	int attack;
	int defence;
	int health;
	vector<Card*> enchantVec;

public:

	card_template_t display(){
		if (ability == -1)
			return display_minion_no_ability(name, cost, attack, defence);
		else if (trigger == true)
			return display_minion_triggered_ability(name, cost, attack, defence, des);
		else
			return display_minion_activated_ability(name, cost, attack, defence, cost, des);
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

	int getAbility(){
		return ability;
	}

	bool trigger(){
		return trigger;
	}

	std::string showName(){
		return name;
	}

	int showAttack(){
		return attack;
	}

	int showDefence(){
		return defence;
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

	Minion(std::string s) : name(s) {
		if (s == "Air Elemental") {
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
			abilityCost = 0;
			attack = 2;
			health = 2;
		} else if (s == "Potion Seller") {
			summonCost = 2;
			abilityCost = 0;
			attack = 1;
			health = 3;
		} else if (s == "Novice Pyromancer") {
			summonCost = 1;
			abilityCost = 1;
			attack = 0;
			health = 1;
		} else if (s == "Apprentice Summoner") {
			summonCost = 1;
			abilityCost = 1;
			attack = 1;
			health = 1;
		} else if (s == "Master Summoner") {
			summonCost = 3;
			abilityCost = 2;
			attack = 2;
			health = 2;
		}
	}
};

#endif MINION_H
