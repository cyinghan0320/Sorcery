#include "rituals.h"

using namespace std;

Ritual::Ritual(string name, string description, int cost, int charge) :
	name{name}, description{description}, cost{cost}, charge{charge}{
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
