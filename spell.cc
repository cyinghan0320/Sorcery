#include "spell.h"

using namespace std;

Spell::Spell(string name, string description, int cost, string ability) :
	name {name}, des {description}, summonCost {cost}, type {"spell"} {
}

card_template_t Spell::display(){
	return display_spell(name, cost, description);
}

int Spell::getCost(){
	return cost;
}

string Spell::getDes(){
	return description;
}

void Spell::draw(){
	card_template_t out = display();
	for (auto e: out) {
		cout << e << endl;
	}
}
