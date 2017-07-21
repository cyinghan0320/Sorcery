#ifndef MINION_H
#define MINION_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "ascii_graphics.h"
#include "info.h"

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
	int health;
	vector<Card*> enchantVec;

public:

	card_template_t display(){
		if (ability == -1)
			return display_minion_no_ability(name, summonCost, attack, health);
		else if (trigger == true)
			return display_minion_triggered_ability(name, summonCost, attack, health, des);
		else
			return display_minion_activated_ability(name, summonCost, attack, health, abilityCost, des);
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

#endif
