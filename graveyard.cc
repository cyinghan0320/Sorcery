
#include "graveyard.h"


Graveyard::Graveyard(){}



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
