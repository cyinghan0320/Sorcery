#ifndef deck_hpp
#define deck_hpp
#include <vector>
#include <fstream>

using namespace std;


class deck {
private:
    vector<Card*> allCards;
public:
    Deck(); // need to implant using input file stream
    ~Deck();
    void shuffle();
}
#endif
