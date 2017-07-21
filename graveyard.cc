
#include "graveyard.h"


Graveyard::Graveyard(){
}



Graveyard::~Graveyard(){
	for(int i = 0; i < stack.size(); i++) {
		delete stack[i];
	}
}


string Graveyard::getTop(){
	string temp = stack[stack.size() - 1];
	stack.pop_back();
	return temp;
}


bool Graveyard::isEmpty() {
	if(stack.size() == 0) {
		return true;
	}else{
		return false;
	}
}

card_template_t graveyard::display(){
	return stack.back()->display();
}

void addMinion(Minion min){
	stack.push_back(min);
}
