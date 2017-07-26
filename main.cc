#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include "card.h"
#include "board.h"
#include "graveyard.h"
#include "player.h"
#include "deck.h"
#include "minion.h"
#include "spell.h"
#include "rituals.h"
#include "enchantment.h"
#include "hand.h"

using namespace std;


void createDeck(Deck* deck, string infile) {
	ifstream ifs;
	ifs.open(infile.c_str());
	string temp;
	vector <string> tempVec;
	while(getline(ifs, temp)) {
		if (deck != nullptr) {
			tempVec.push_back(temp.substr(0, temp.length() -1));
		}
	}
	while (tempVec.size() != 0) {
		deck->addCard(tempVec.back());
		tempVec.pop_back();
	}
	ifs.close();
}

int testMode = 0;
string filename1 = "default.deck";
string filename2 = "default.deck";
string arg;
string filename3;
istream in = cin;
int main(int argc, char *argv[]) {
	for(int i = 0; i < argc) {
		arg = argv[i];
		if( arg == "-testing") {
			testMode = 1;
		} else if(arg == "-deck1") {
			filename1 = argv[++i];
		} else if(arg == "-deck2") {
			filename2 = argv[++i];
		}
		else if (arg == "-init") {
			filename3 = argv[++i];
			in = dynamic_cast<std::ifstream&> in;
			in.open(filename3.c_str());
		}
	}

	//initializing the entire board


	Deck* deck1 = new Deck;
	Deck* deck2 = new Deck;
	string name1;
	string name2;
	Hand* hand1= nullptr;
	Hand* hand2 = nullptr;
	Player* p1 = nullptr;
	Player* p2 = nullptr;
	Board* Game = nullptr;
	string command;
	createDeck(deck1, filename1);
	// deck1->Dshuffle();
	createDeck(deck2, filename2);
	// deck2->Dshuffle();
	hand1 = new Hand(deck1, 0);
	hand2 = new Hand(deck2, 0);
	for(int i = 0; i < 4; ++i) {
		hand1->draw();
		hand2->draw();
	}
	p1 = new Player(name1, hand1,1);
	p2 = new Player(name2, hand2,2);
	Game = new Board (p1, p2);

	//while game is in session loop

	cout << "What is your name, my warrior player1? " << endl;
	getline(in, name1);
	p1->setName(name1);
	cout << p1->getName() <<" is a nice name!"  << endl;
	cout << "What is your name, my warrior player2? " << endl;
	getline(in, name2);
	p2->setName(name2);
	cout << p2->getName() << " is a nice name!"  << endl;
	if (Game->getTurn() == 1) {
		cout << "at the start of "<< p1->getName()  + "'s turn" << endl;
	}

	string wholeLine;
	while(getline(in, wholeLine)) {
		istringstream is (wholeLine);
		is >> command;
		//declaring turn
		Player* activePlayer = p1;
		if(Game->getTurn() % 2 == 0) {
			activePlayer = p2;
		}

		if (Game->getTurn() != 1 && Game->getTurn() != 2) { // not the first round of player1 or player2
			activePlayer->getMagic(); // add one magic
			activePlayer->takeCard(); // take one card if possibile
			Game->refreshAllAttack();
		}
		// Game->showboard();
		//sorting commands and executions
		if(command == "end") {
			Game->end();
			if (activePlayer == p1) {
				activePlayer = p2;
			}
			else {
				activePlayer = p1;
			}
			cout << "at the start of "<< activePlayer->getName()  + "'s turn" << endl;
		} else if (command == "init") {

		}
		else if (command == "quit") {
			cout << "quitting game" << endl;
			break;
		} else if (command == "draw" && testMode == 1) {
			activePlayer->takeCard();
		} else if (command == "discard" && testMode == 1) {
			int choice;
			is >> choice;
			activePlayer->returnHand()->discard(choice);
		} else if (command == "attack") {
			int index;
			is >> index;
			int choice;
			if (is >> choice) {
				Game->attack(index, choice);
			} else {
				Game->attack(index, -1);
			}
		} else if (command == "play") {
			int index;
			is >> index;
			int player;
			int target;
			if (is >> player >> target) {
				Game->play(index, player, target);
			} else {
				Game->play(index, 0, 0);
			}
		} else if (command == "use") { //these takes various number of inputs need to implant
			int index;
			is >> index;
			int player, target;
			// then we need to modify the ability class
			if(is >> player >> target) {
				// int skill = activePlayer->getSkill(index, player, target); //bugs
			} else {
				cerr << "invalid input to use" << endl;
			}
		}
		else if (command == "inspect") {
			int which;
			is >> which;
			Game->inspect(which);
		} else if (command == "hand") {
			activePlayer->returnHand()->showHand();
		} else if (command == "board") {
			Game->showboard();
		} else {
			cout << "invalid command, please try again." << endl;
		}
		Game->updateMinion();

		if(p1->dead() && p2->dead()) {
			cout << "It is a tie" <<endl;
		} else if(p1->dead()) {
			cout << p2->getName() << " wins" <<endl;
		} else if(p2->dead()) {
			cout <<  p1->getName() << " wins" <<endl;
		}
	}

	delete Game;

	return 0;
}
