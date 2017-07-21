#include "rituals.h"
#include "ability.h"

using namespace std;

Ritual::Ritual(string name, string description, int cost, int index) :
	name{name}, description{description}, cost{cost}, index{index}{
}

card_template_t Ritual::display(){
	return display_ritual(name, 1, cost, description, charge);
}

void Ritual::draw(){
	card_template_t out = display();
	for (auto e: out) {
		cout << e << endl;
	}
}

void Ritual::useCard(Board &t){
	chooseAbility(t, index);
}
