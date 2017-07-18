#ifndef graveyard_h
#define graveyard_h

#include <vector>
#include "card.h"
#include <string>

class Graveyard {
private:
    vector <Card*> stack;
public:
    Graveyard();
    ~Graveyard();
    string getTop();     //gets the name of the card and deletes the pointer
}



#endif /* graveyard_hpp */
