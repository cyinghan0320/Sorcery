#include <fstream>
#include <boolean>
#include <cstdlib>
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

int testmode = 1;
int main() {

	int turn  = 1;// track the number of the turn
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
		
		if (turn != 1 && turn != 2 && turn == Game->getTurn()) { // not the first round of player1 or player2
			activePlayer->getMagic(); // add one magic
			activePlayer->takeCard(); // take one card if possibile
			Game->refreshAllAttack();
			++turn;
		}
		cout << "at the start of "<<activePlayer->getName()  + "'s turn" << endl;

		//sorting commands and executions
		if(command == "end") {
			Game->end();
		} else if (command == "quit") {
			cout << "quitting game" << endl;
			break;
		} else if (command == "draw" && testMode == 1) {  //testing mode only, need to modify
			activePlayer->takeCard();
		} else if (command == "discard" && testMode == 1) { //testing mode only, need to modify
			activePlayer->discard();
		} else if (command == "attack") {  //these takes various number of inputs need to implant
			int index;
			cin >> index;
			int choice;
			if (isdigit(cin.peek())) {
				cin >> choice;
				Game->attack(index, choice);
			} else {
				Game->attack(index);
			}
		} else if (command == "play") { //these takes various number of inputs need to implant
			int index;
			cin >> index;
			int player;
			if (isdigit(cin.peek())) {
				cin >> player;
				int target;
				if (isdigit(cin.peek())) {
					cin >> target;
				} else{
					cerr << "invalid input" < endl;
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
					cerr << "invalid input" << endl;
				}
			} else {
				int skill = activePlayer->getSkill(index);
			}
		} else if (command == "inspect") {
			int which;
			cin >> which;
			activePlayer->getHand()->inspect(which);
		} else if (command == "hand") {
			Game->playerHand();
		} else if (command == "board") {
			Game->showboard();
		} else {
			cout << "invalid command, please try again." << endl;
		}

		Game->updateMinion();
	}

	delete Game;
	return 0;
}
