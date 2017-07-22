#include "spell.h"

using namespace std;

spell::spell(string name, string description, int cost, string ability) :
	name{name}, des{description}, int abilityCost{abilityCost}, summonCost{cost}, type{"spell"}{
}

card_template_t spell::display(){
	return display_spell(name, cost, description);
}
spell(std::string name,std::string description,int cost,
	      ,std::string ability, int abilityCost, std::string type = "spell");
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
