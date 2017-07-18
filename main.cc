#include <fstream>
#include "card.h"
#include "board.h"
#include "graveyard.h"
#include "player.h"
#include "display.h"
#include "deck.h"
#include "minions.h"
#include "spell.h"
#include "ritual.h"
#include "enchantment.h"
#include "hand.h"

using namespace std;


int main() {
    
    
    //initializing the entire board
    string name1;
    string name2;
    cin >> name1 >> name2;
    Hand* hand1 = new Hand;
    Hand* hand2 = new Hand;
    Player* p1 = new Player;
    Player* p2 = new Player;
    p1(name1, hand1);
    p2(name2, hand2);
    Board* Game = new Board;
    Game(p1, p2);
    
    //while game is in session loop
    string command;
    
    while(cin >> command) {
        
        //declaring turn
        Player* activePlayer = p1;
        if(game.getTurn() == 2) {
            activePlayer = p2;
        }
        cout << activePlayer->getName()  + "'s turn" << endl;
        
        //sorting commands and executions
        if(command == "end"){
            Game->end();
        } else if (command == "quit"){
            cout << "quitting game" << endl;
            break;
        } else if (command == "draw"){  //testing mode only, need to modify
            
        } else if (command == "discard"){ //testing mode only, need to modify
            
        } else if (command == "attack"){  //these takes various number of inputs need to implant
            
        } else if (command == "play"){ //these takes various number of inputs need to implant
            
        } else if (command == "use"){ //these takes various number of inputs need to implant
            
        } else if (command == "inspect"){
            cin >> which;
            activePlayer->getHand()->inspect(which);
        } else if (command == "hand"){
            Game->playerHand();
        } else if (command == "board"){
            Game->showboard();
        } else {
            cout << "invalid command, please try again."
        }
    }
    
    
}
