#include "board.h"
#include "hand.h"
//need to implant showboard

class Enchantment;

Board::Board(Player* player1, Player* player2)
: grave1{new Graveyard}, grave2{new Graveyard}, player1{player1}, player2{player2}, turn{1} {
}


Board::~Board(){
    delete grave1;
    delete grave2;
    delete player1;
    delete player2;
    delete ritual1;
    delete ritual2;
    for(int i = 0; i < minions1.size(); i++) {
        delete minions1[i];
    }
    for(int j = 0; j < minions2.size(); j++) {
        delete minions2[j];
    }
}


void Board::inspect(int i){
<<<<<<< HEAD
	Minion* chosen;
	if (i >= 0 && i < minions1.size())
		chosen = minions1[i];
	else
		cerr << "Inspection: No minion at that position" <<  endl;
	if(turn%2 == 0) {
		if (i < minions2.size())
			chosen = minions2[i];
		else
			cerr << "Inspection: No minion at that position" <<  endl;
	}
	// print the minions card first
	//dont know if createCard() will be available here
	vector <Enchantment*> stack;//create an array of Enchantment pointers, need to print them
	for(name: chosen->getEnchantVec()) {
		Minion* temp = player1->getHand2()->createCard(name);
		stack.push_back(temp);
	}
	//implant display for enchantment here !!!!!!!!!!!!!!!!!!!!!!!
	//the description for enchantment is enchantDes

	for(int i = 0; i < stack.size(); i++) {
		stack.pop_back();
	}
=======
    Minion* chosen;
    if (i >= 0 && i < minions1.size())
        chosen = minions1[i];
    else
        cerr << "Inspection: No minion at that position" <<  endl;
    if(turn%2 == 0) {
        if (i < minions2.size())
            chosen = minions2[i];
        else
            cerr << "Inspection: No minion at that position" <<  endl;
    }
    // print the minions card first
    //dont know if createCard() will be available here
    vector <Enchantment*> stack;//create an array of Enchantment pointers, need to print them
    for(name: chosen->getEnchantVec()) {
        Enchantment* temp = player1->getHand()->createCard(name);
        stack.push_back(temp);
    }
    //implant display for enchantment here !!!!!!!!!!!!!!!!!!!!!!!
    //the description for enchantment is enchantDes
    
    for(int i = 0; i < stack.size(); i++) {
        stack.pop_back();
    }
>>>>>>> eceaaee1cfa766e0f130538b76175ddf0b4b1e34
}

void Board::showboard(){
    vector <card_template_t> line1;
    vector <card_template_t> line2;
    vector <card_template_t> line3;
    vector <card_template_t> line4;
    vector <card_template_t> line5;
    line1.emplace_back(ritual1->display());
    line1.emplace_back(CARD_TEMPLATE_BORDER);
    line1.emplace_back(player1->display());
    line1.emplace_back(CARD_TEMPLATE_BORDER);
    line1.emplace_back(grave1->display());
    for (int i = 0; i < minions1.size(); ++i) {
        line2.emplace_back(minions1[i]);
    }
    if (minions1.size() < 5) {
        int diff = 5 - minions1.size();
        for (int i=0; i < diff; ++i) {
            line2.emplace_back(CARD_TEMPLATE_BORDER);
        }
    }
    line3.emplace_back(CENTRE_GRAPHIC);
    for (int i = 0; i < minions2.size(); ++i) {
        line4.emplace_back(minions2[i]);
    }
    if (minions2.size() < 5) {
        int diff = 5 - minions2.size();
        for (int i=0; i < diff; ++i) {
            line4.emplace_back(CARD_TEMPLATE_BORDER);
        }
    }
    line5.emplace_back(ritual2->display());
    line5.emplace_back(CARD_TEMPLATE_BORDER);
    line5.emplace_back(player2->display());
    line5.emplace_back(CARD_TEMPLATE_BORDER);
    line5.emplace_back(grave2->display());
    int length = line1[0].size();
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < line1.size(); ++i) {
            cout << line1[i][j];
        }
        cout << endl;
    }
    length = line2[0].size();
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < line2.size(); ++i) {
            cout << line2[i][j];
        }
        cout << endl;
    }
    length = line3[0].size();
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < line3.size(); ++i) {
            cout << line3[i][j];
        }
        cout << endl;
    }
    length = line4[0].size();
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < line3.size(); ++i) {
            cout << line4[i][j];
        }
        cout << endl;
    }
    length = line5[0].size();
    for (int j = 0; j < length; ++j) {
        for (int i = 0; i < line3.size(); ++i) {
            cout << line5[i][j];
        }
        cout << endl;
    }
} //need implamentation

void Board::playerHand(){
    if(turn%2 == 1) {
        player1->getHand2()->showhand();
    } else{
        player2->getHand2()->showhand();
    }
}


void Board::attack(int i){
    if (i < 1 || 5 < i) {
        cerr << "out of bound" << endl;
        return;
    }
    
    if(turn%2 == 1 && minions1[i]->getAction()) {
        player2->takeDmg(minions1[i]->showAttack());  //make a attack fun or make attack public for minion,
        minions1[i]->useAttack();
    } else if(turn%2 == 0 && minions2[i]->getAction()) {
        player1->takeDmg(minions2[i]->showAttack());
        minions2[i]->useAttack();
    } else{
        cout << "cannot attack opponent." << endl;
    }
}


void Board::attack(int i, int j){
    if ((i < 1 || 5 < i) || (j < 1 || 5 < j)) {
        cerr << "out of bound" << endl;
        return;
    }
    if (turn%2 == 1 && minions1[i]->getAction()) {
        minions1[i]->takeDmg(minions2[j]->showAttack());
        minions2[j]->takeDmg(minions1[i]->showAttack());
        minions1[i]->useAttack();
    } else if(turn%2 == 0 && minions2[i]->getAction()) {
        minions1[j]->takeDmg(minions2[i]->showAttack());
        minions2[i]->takeDmg(minions1[j]->showAttack());
        minions2[i]->useAttack();
    } else{
        cout << "cannot attack opponent." << endl;
    }
    
}




<<<<<<< HEAD



void Board::use(intd i, int p, int t){
	Card* object;
	if (p == -1 && t == -1) {
		if (i < 1 || 5 < i) {
			cerr << "out of bound" << endl;
			return;
		}
		vector<Card*> field = minions1;
		Ritual* ritual = ritual1;
		Card* object;
		if (0 <= i && i < 5)
			object = player1->getHand()[i];
=======
void Board::playSolo(int i) {
    
    Card* field = minions1;
    Card* ritual = ritual1;
    Card* object;
    if (0 <= i && i < 5)
        object = player1->getHand()[i];
    
    if(turn%2 == 0) {
        field = minions2;
        ritual = ritual2;
        if (0 <= i && i < 5)
            object = player2->getHand()[i];
    }
    
    if(object->getStat().type == "minion") {
        if(field.size() 5 >=) {
            cerr << "Field is full!" << endl;
            return;
        }
        field.push_back(object);
    } else if(object->getStat().type == "spell") {
        object->useCard();
    } else if(object->getStat().type == "ritual") {
        delete ritual;
        ritual = object;
    }
}
>>>>>>> eceaaee1cfa766e0f130538b76175ddf0b4b1e34

		if(turn%2 == 0) {
			field = minions2;
			ritual = ritual2;
			if (0 <= i && i < 5)
				object = player2->getHand()[i];
		}

<<<<<<< HEAD
		if(object->getStat().type == "minion") {
			if(field.size() >= 5) {
				cerr << "Field is full!" << endl;
				return;
			}
			field.push_back(object);
		} else if(object->getStat().type == "spell") {
			Spell &t = *object;
			t.useCard();
		} else if(object->getStat().type == "ritual") {
			delete ritual;
			ritual = object;
		}
	}


	void Board::play (int i, int p, int t) {
		Card* target;
		Card* object;
		vector<Minion*> fieldOpponent;
		vector<Minion*> field;
		Graveyard* grave;
		Ritual myRitual;
		if (i < 1 || 5 < i) {
			cerr << "out of bound" << endl;
			return;
		}
		if(turn%2 == 1) {
			object = player1->getHand()[i];
			field = player1->getHand();
			fieldOpponent = player2->getHand();
			grave = grave1;
			myRitual = ritual1;
		} else{
			object = player2->getHand()[i];  //need to implant getType
			field = player2->getHand();
			fieldOpponent = player1->getHand();
			grave = grave2;
			myRitual = ritual2;
		}
		if(p == 1) {
			if (t == 'r')
				target = ritual1;
			else if (0 <= t && t < 5)
				target = minions1[t];
		} else{
			if (t == 'r')
				target = ritual2;
			else if (0 <= t && t < 5)
				target = minions2[t];
		}
		if(object->getStat().type == "enchantment") {
			Enchantment &t = *object;
			t.assign(target);
		} else if(object->getStat().type == "spell") {
			string abil = object->getAbility(); //spell implementation
			if(abil == "destroy") {
				if(target->showType() == "minion ") {
					target->takeDmg(999);
				}  else {
					delete target;
					target = nullptr;
				}
			} else if(abil == "unsummon") {
				string unsum = target->getName();
				hand* deck = player1->getHand()->sendToBottom(unsum);
				if(target->showType() == "minion") {
					field.erase(t);
				}else{
					delete target;
					target = nullptr;
				}
			} else if(abil == "recharge") {
				myRitual->recharge(3);
			} else if(abil == "disenchant") {
				target->disenchant();
			} else if(abil == "revive") {
				if(field.size() >= 5) {
					cerr << "full field, no minion can be summoned " << endl;
					return;
				}
				string top = grave->getTop();
				createCard(top)
			} else if(abil == "blizzard") {
				for(int i = 0; i < fieldOpponent.size(); i++) {
					fieldOpponent[i]->takeDmg(2);
				}
			}
		}
	}
	if  (!((i < 0 && 4 < i) || (i == 'r'))) {
		cerr << "invalid input";
		return;
	}
	if(turn%2 == 1) {
		if (i == 'r')
			object = ritual1;
		else if (0 <= i && i < 5)
			object = minions1[i];
	} else{
		if (i == 'r')
			object = ritual2:Null;
		else if (0 <= i && i < 5)
			object = minions2[i];
	}
	object->useCard();
}
=======
void Board::play(int i, int p = 0, int t = 0) {
    if ((i < 0 || 4 < i) || (t < 0 || t < i)){
        cerr << "out of bound" << endl;
        return;
    } else if(p == 0){
        playSolo(i);
    } else {
        Card* target;
        Card* object;
        vector<Minion*> fieldOpponent;
        vector<Minion*> field;
        Graveyard* grave;
        Ritual myRitual;
        if(turn%2 == 1) {
            object = player1->getHand()[i];
            field = player1->getHand();
            fieldOpponent = player2->getHand();
            grave = grave1;
            myRitual = ritual1;
        } else{
            object = player2->getHand()[i];  //need to implant getType
            field = player2->getHand();
            fieldOpponent = player1->getHand();
            grave = grave2;
            myRitual = ritual2;
        }
        if(p == 1) {
            if (t == 'r')
                target = ritual1;
            else if (0 <= t && t < 5)
                target = minions1[t];
        } else{
            if (t == 'r')
                target = ritual2;
            else if (0 <= t && t < 5)
                target = minions2[t];
        }
        if(object->getStat().type == "enchantment") {
            object->assign(target);
        } else if(object->getStat().type == "spell") {
            string abil = object->getAbility(); //spell implementation
            if(abil == "destroy"){
                if(target->showType() == "minion"){
                    target->takeDmg(999);
                }  else {
                    delete target;
                    target = nullptr;
                }
            } else if(abil == "unsummon"){
                string unsum = target->getName();
                hand* deck = player1->getHand()->sendToBottom(unsum);
                if(target->showType() == "minion"){
                    field.erase(t);
                }else{
                    delete target;
                    *target = Null;
                }
            } else if(abil == "recharge"){
                myRitual->recharge(3);
            } else if(abil == "disenchant"){
                if(p == 1){
                    minions1[t] = target->removeEnchant();
                } else {
                    minions2[t] = target->removeEnchant();
                }
                target->deleteEnchant();
            } else if(abil == "revive"){
                if(field.size() >= 5) {
                    cerr << "full field, no minion can be summoned" << endl;
                    return;
                }
                string top = grave->getTop();
                createCard(top)
            } else if(abil == "blizzard"){
                for(int i = 0; i < fieldOpponent.size(); i++){
                    fieldOpponent[i]->takeDmg(2);
                }
            }
            
        }
    }
}


>>>>>>> eceaaee1cfa766e0f130538b76175ddf0b4b1e34


void Board::use(int i, int p = 0, int t = 0){
    Card* target;
    Card* object;
    vector<Minion*> fieldOpponent;
    vector<Minion*> field;
    Graveyard* grave;
    Ritual myRitual;
    Player player;
    if ((i < 0 || 4 < i) || (t < 0 || t < i)){
        cerr << "out of bound" << endl;
        return;
    }
    if(turn%2 == 1) {
        player = player1;
        field = minions1;
        if (i == 'r')
            object = ritual1;
        else if (0 <= i && i < 5)
            object = minions1[i];
    } else{
        player = player2;
        field = minions2;
        if (i == 'r')
            object = ritual2;
        else if (0 <= i && i < 5)
            object = minions2[i];
    }
    if(p == 1) {
        if (t == 'r')
            target = ritual1;
        else if (0 <= t && t < 5)
            target = minions1[t];
    } else{
        if (t == 'r')
            target = ritual2;
        else if (0 <= t && t < 5)
            target = minions2[t];
    }
    vector<Minion*> field = minion1;
    if(turn%2 == 0)
        field = minion2;
    string abil = object->getAbility();
    if(abil == "enter play 1 dmg" || "deal 1 dmg") {
        target->takeDmg(1);
    }else if(abil ==  "heal all") {
        for(int i = 0; i < field.size(); i++) {
            field[i]->heal(1);
        }
    }else if(abil == "summon 1 air") {
        if(field.size() < 5) {
            Minion* holder = createCard("Air Elemental")
            field.push_back(holder);
        }
    }else if(abil == "summon 3 air") {
        for(int i = 3; i > 0; i--) {
            if(field.size() < 5) {
                Minion* holder = createCard("Air Elemental")
                field.push_back(holder);
            }
        }
    }else if("gain 1 magic at start") {
        player->getMagic()
    }else if("+1/+1 enter play") {
        field[field.size() - 1]->increaseStat(1,1);
    }else if("destroy enter play") {
        field[field.size() - 1]->takeDmg(999);
    }else{
        cerr << "no ability" << endl;
        return;
    }
}





void Board::end(){
    turn++;
}


int Board::getTurn() {
    return turn;
}


void Board::updateMinion() {
    for(int i = 0; i < minions1.size(); i++) {
        if(minions1[i]->defeated()) {
            Minion* holder = new Minion(minions1[i]->getStat().name);
            grave1->addMinion(holder);
            minions1.erase(i);
	    i--;
        }
    }
    for(int j = 0; j < minions2.size(); j++) {
        if(minions2[j]->defeated()) {
            Minion* holder = new Minion(minions2[j]->getStat().name);
            grave2->addMinion(holder);
            minions2.erase(j);
	    j--;
        }
    }
}

void Board::refreshAllAttack(){
    for(int i = 0; i < minions1.size(); i++) {
        minions1[i]->refreshAttack();
    }
    for(int i = 0; i < minions2.size(); i++) {
        minions2[i]->refreshAttack();
    }
}
