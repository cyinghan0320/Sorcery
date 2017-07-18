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
#include "ability.h"

using namespace std;


int main() {

	int turn  = 0;// track the number of the turn
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

	cout << "What is your name, my warrior player1? " << endl;
	getline(cin, name1);
	p1->setName(name1);
	cout << p1->getName() <<" is a nice name!"  << endl;
	cout << "What is your name, my warrior player1? " << endl;
	getline(cin, name2);
	p1->setName(name2);
	cout << p2->getName() << " is a nice name!"  << endl;

	while(cin >> command) {

		//declaring turn
		Player* activePlayer = p1;
		if(game.getTurn() == 2) {
			activePlayer = p2;
		}
		++turn;
		if (turn != 1 && turn != 2) { // not the first round of player1 or player2
			activePlayer->getMagic(); // add one magic
			activePlayer->takeCard(); // take one card if possibile
		}
		cout << "at the start of "<<activePlayer->getName()  + "'s turn" << endl;

		//sorting commands and executions
		if(command == "end") {
			Game->end();
		} else if (command == "quit") {
			cout << "quitting game" << endl;
			break;
		} else if (command == "draw") {  //testing mode only, need to modify

		} else if (command == "discard") { //testing mode only, need to modify

		} else if (command == "attack") {  //these takes various number of inputs need to implant
			int index;
			cin >> index;
			int choice;
			if (cin >> choice) {
				Game->attack(index, choice);
			}
			Game->attack(index);
		} else if (command == "play") { //these takes various number of inputs need to implant

		} else if (command == "use") { //these takes various number of inputs need to implant
			int index;
			cin >> index;
			int skill = activePlayer.getSkill(index);
			// then we need to modify the ability class
		} else if (command == "inspect") {
			cin >> which;
			activePlayer->getHand()->inspect(which);
		} else if (command == "hand") {
			Game->playerHand();
		} else if (command == "board") {
			Game->showboard();
		} else {
			cout << "invalid command, please try again."
		}
	}


}
