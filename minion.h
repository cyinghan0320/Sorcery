#ifndef MINION_H
#define MINION_H

#include <iostream>
#include <string>
#include <vector>

class Minion : public Card {
std::string name;
int summonCost;
int abilityCost;
int attack;
int health;
vector<Card*> enchantVec;

public:
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
