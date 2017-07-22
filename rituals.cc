#include "rituals.h"

using namespace std;

class ability;

Ritual::Ritual(string name, string description, int cost, int charge) :
	Card(name, description,"Ritual", cost), charge{charge}{
}

card_template_t Ritual::display(){
	return display_ritual(name, 1, summonCost, des, charge);
}

void Ritual::draw(){
	card_template_t out = display();
	for (auto e: out) {
		cout << e << endl;
	}
}

void Ritual::useCard(Board &t){
	ability a;
	a.chooseAbility(t, index);
}
