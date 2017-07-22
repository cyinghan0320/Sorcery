#include "rituals.h"

using namespace std;

class ability;

Ritual::Ritual(string name, string description, int summonCost, string ability, int abilityCost, int charge)
	name{name},des{description}, ability{ability} ,
	abilityCost{abilityCost}, summonCost{summonCost},charge{charge}, type{"ritual"};
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
