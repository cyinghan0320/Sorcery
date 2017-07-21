#include <ifstream>
#include <cstdlib>
#include "card.h"
#include "board.h"
#include "graveyard.h"
#include "player.h"
#include "display.h"
#include "deck.h"
#include "minions.h"
#include "spell.h"
#include "rituals.h"
#include "enchantment.h"
#include "hand.h"
#include "ability.h"

void createDeck(Deck* deck, string infile) {
    ifstream ifs;
    ifs.open(infile.c_str(), in);
    string temp;
    while(ifs >> temp){
        deck->addCard(temp);
    }
    ifs.close();
}

using namespace std;

int testmode = 1;
int main() {
	//initializing the entire board
	string filename1 = "default.deck";
	string filename2 = "default.deck";
	
	Deck* deck1 = new Deck;
	Deck* deck2 = new Deck;
	createDeck(deck1, filename1), deck1.shuffle();
	createDeck(deck2, filename2), deck2.shuffle();
	
	string name1;
	string name2;
	cin >> name1 >> name2;
	Hand* hand1 = new Hand(deck1,0);
	Hand* hand2 = new Hand(deck2,0);
	for(int i = 0; i < 5; i++){
		hand1.draw();
		hand2.draw();
	}
	Player* p1 = new Player;
	Player* p2 = new Player;
	p1(name1, hand1,1);
	p2(name2, hand2,2);
	Board* Game = new Board;
	Game(p1, p2);

	//while game is in session loop
	string command;

	cout << "What is your name, my warrior player1? " << endl;
	getline(cin, name1);
	p1->setName(name1);
	cout << p1->getName() <<" is a nice name!"  << endl;
	cout << "What is your name, my warrior player2? " << endl;
	getline(cin, name2);
	p1->setName(name2);
	cout << p2->getName() << " is a nice name!"  << endl;

	while(cin >> command) {

		//declaring turn
		Player* activePlayer = p1;
		if(Game->getTurn()%2 == 0) {
			activePlayer = p2;
		}

		if (Game->getTurn() != 1 && Game->getTurn() != 2) { // not the first round of player1 or player2
			activePlayer->getMagic(); // add one magic
			activePlayer->takeCard(); // take one card if possibile
			Game->refreshAllAttack();
		}
		cout << "at the start of "<<activePlayer->getName()  + "'s turn" << endl;

		//sorting commands and executions
		if(command == "end") {
			Game->end();
		} else if (command == "quit") {
			cout << "quitting game" << endl;
			break;
		} else if (command == "draw" && testMode == 1) { 
			activePlayer->takeCard();
		} else if (command == "discard" && testMode == 1) { 
			activePlayer->discard();
		} else if (command == "attack") { 
			int index;
			cin >> index;
			int choice;
			if (isdigit(cin.peek())) {
				cin >> choice;
				Game->attack(index, choice);
			} else {
				Game->attack(index);
			}
		} else if (command == "play") {
			int index;
			cin >> index;
			int player;
			if (isdigit(cin.peek())) {
				cin >> player;
				int target;
				if (isdigit(cin.peek())) {
					cin >> target;
				} else{
					cerr << "invalid input to play" < endl;
					continue;
				}
				Game->play(index, player, target);
			} else {
				Game->play(index);
			}
		} else if (command == "use") { //these takes various number of inputs need to implant
			int index;
			cin >> index;
			// then we need to modify the ability class
			if(isdigit(cin.peek())) {
				int player;
				cin >> player;
				if(isdigit(cin.peek())) {
					int target;
					cin >> target;
					int skill = activePlayer->getSkill(index, player, target);
				} else {
					cerr << "invalid input to use" << endl;
				}
			} else {
				int skill = activePlayer->getSkill(index);
			}
		} else if (command == "inspect") {
			int which;
			cin >> which;
			if(turn%2 == 1){
				
			} else{
			}
		} else if (command == "hand") {
			Game->playerHand();
		} else if (command == "board") {
			Game->showboard();
		} else {
			cout << "invalid command, please try again." << endl;
		}

		Game->updateMinion();
		if(player1->dead() && player2->dead()){
			cout << "It is a tie" <<endl;
		} else if(p1->dead()){
			cout << p2->getName() << "wins" <<endl;
		} else if(player2->dead()){
			cout <<  p1->getName() << "wins" <<endl;
		}
	}

	delete Game;
	return 0;
}
