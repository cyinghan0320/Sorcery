#include "spell.h"

using namespace std;

spell::spell(string name, string description, int cost) :
	name{name}, description{description}, cost{cost}{
}

card_template_t spell::display(){
	return display_spell(name, cost, description);
}

int spell::getCost(){
	return cost;
}

string spell::getDes(){
	return description;
}

void spell::draw(){
	card_template_t out = display();
	for (auto e: out) {
		cout << e << endl;
	}
}
