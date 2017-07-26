#include "board.h"
#include "hand.h"
//need to implant showboard

class Enchantment;

//checked
Board::Board(Player* player1, Player* player2)
	: grave1{new Graveyard}, grave2{new Graveyard}, player1{player1}, player2{player2}, turn{1} {
}

//checked
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
	// Minion* chosen = nullptr;
	// if (i >= 0 && i < minions1.size())
	//  chosen = minions1[i];
	// else
	//  cerr << "Inspection: No minion at that position" <<  endl;
	// if(turn%2 == 0) {
	//  if (i < minions2.size())
	//      chosen = minions2[i];
	//  else
	//      cerr << "Inspection: No minion at that position" <<  endl;
	// }
	// print the minions card first
	//dont know if createCard() will be available here
	// vector <Card*> stack;//create an array of Card pointers, need to print them
	// for(auto name: chosen->getEnchantVec()) {
	//  Card* temp = player1->getHand2()->createCard(name);
	//  stack.push_back(temp);
	// }
	//implant display for enchantment here !!!!!!!!!!!!!!!!!!!!!!!
	//the description for enchantment is enchantDe
}

void Board::showboard(){
//  vector <card_template_t> line1;
//  vector <card_template_t> line2;
//  vector <card_template_t> line3;
//  vector <card_template_t> line4;
//  vector <card_template_t> line5;
//  line1.emplace_back(ritual1->display());
//  line1.emplace_back(CARD_TEMPLATE_BORDER);
//  line1.emplace_back(player1->display());
//  line1.emplace_back(CARD_TEMPLATE_BORDER);
//  line1.emplace_back(grave1->display());
//  for (int i = 0; i < minions1.size(); ++i) {
//      line2.emplace_back(minions1[i]);
//  }
//  if (minions1.size() < 5) {
//      int diff = 5 - minions1.size();
//      for (int i=0; i < diff; ++i) {
//          line2.emplace_back(CARD_TEMPLATE_BORDER);
//      }
//  }
//  line3.emplace_back(CENTRE_GRAPHIC);
//  for (int i = 0; i < minions2.size(); ++i) {
//      line4.emplace_back(minions2[i]);
//  }
//  if (minions2.size() < 5) {
//      int diff = 5 - minions2.size();
//      for (int i=0; i < diff; ++i) {
//          line4.emplace_back(CARD_TEMPLATE_BORDER);
//      }
//  }
//  line5.emplace_back(ritual2->display());
//  line5.emplace_back(CARD_TEMPLATE_BORDER);
//  line5.emplace_back(player2->display());
//  line5.emplace_back(CARD_TEMPLATE_BORDER);
//  line5.emplace_back(grave2->display());
//  int length = line1[0].size();
//  for (int j = 0; j < length; ++j) {
//      for (int i = 0; i < line1.size(); ++i) {
//          cout << line1[i][j];
//      }
//      cout << endl;
//  }
//  length = line2[0].size();
//  for (int j = 0; j < length; ++j) {
//      for (int i = 0; i < line2.size(); ++i) {
//          cout << line2[i][j];
//      }
//      cout << endl;
//  }
//  length = line3[0].size();
//  for (int j = 0; j < length; ++j) {
//      for (int i = 0; i < line3.size(); ++i) {
//          cout << line3[i][j];
//      }
//      cout << endl;
//  }
//  length = line4[0].size();
//  for (int j = 0; j < length; ++j) {
//      for (int i = 0; i < line3.size(); ++i) {
//          cout << line4[i][j];
//      }
//      cout << endl;
//  }
//  length = line5[0].size();
//  for (int j = 0; j < length; ++j) {
//      for (int i = 0; i < line3.size(); ++i) {
//          cout << line5[i][j];
//      }
//      cout << endl;
//  }
// } //need implamentation
//
}


void Board::playerHand(){
	// if(turn%2 == 1) {
	//  player1->getHand2()->showhand();
	// } else{
	//  player2->getHand2()->showhand();
	// }
}
//
//checked
void Board::attack(int i, int j) {
	if (j == -1) {
		if (i < 0 || 4 < i) {
			cerr << "out of bound" << endl;
			return;
		}
		if(turn % 2 == 1 && minions1[i]->getAction() >= 1) {
			player2->takeDmg(minions1[i]->showAttack());     //make a attack fun or make attack public for minion,
			minions1[i]->useAttack();
		} else if(turn%2 == 0 && minions2[i]->getAction() >= 1) {
			player1->takeDmg(minions2[i]->showAttack());
			minions2[i]->useAttack();
		}
		else{
			cout << "cannot attack opponent." << endl;
		}
	}
	else{
		if ((i < 0 || 4 < i) || (j < 0 || 4 < j)) {
			cerr << "out of bound" << endl;
			return;
		}
		if (turn % 2 == 1 && minions1[i]->getAction() >= 1) {
			minions1[i]->takeDmg(minions2[j]->showAttack());
			minions2[j]->takeDmg(minions1[i]->showAttack());
			minions1[i]->useAttack();
		} else if(turn % 2 == 0 && minions2[i]->getAction() >= 1) {
			minions1[j]->takeDmg(minions2[i]->showAttack());
			minions2[i]->takeDmg(minions1[j]->showAttack());
			minions2[i]->useAttack();
		} else{
			cout << "cannot attack opponent." << endl;
		}
	}
}
//

// void Board::playSolo(int i) {
//  vector<Card*> field;
//  Card* ritual;
//  Card* object;
//
//  if (0 <= i && i < 5)
//      object = player1->getHand()[i];
//
//  if(turn % 2 == 0) {
//      field = minions2;
//      ritual = ritual2;
//      if (0 <= i && i < 5)
//          object = player2->getHand()[i];
//  }
//
//  if(object->getStat().type == "minion") {
//      if(field.size()  >= 5) {
//          cerr << "Field is full!" << endl;
//          return;
//      }
//      field.push_back(object);
//  } else if(object->getStat().type == "spell") {
//      object->useCard();
//  } else if(object->getStat().type == "ritual") {
//      delete ritual;
//      ritual = object;
//  }
// }

Player* Board::getPlayer(int p){
    if(p == 1)
        return player1;
    return player2;
}

void Board::use(int i, int p, int t){
    if ((i < 0 || 5 < i) || (t < 1 || t > 5)) {
        cerr << "out of bound" << endl;
        return;
    }
    Minion* target = findMinion(p,t);
    Minion* object = findMinion(1 + (turn + 1)%2,t);
    vector<Minion*> fieldOpponent = getField(2 - (turn + 1)%2);
    vector<Minion*> field = getField(turn%2);
    Graveyard* grave = getGrave(turn%2);
    Ritual* myRitual = getRitual(turn%2);
    Player* player = getPlayer(p);
	Player* myPlayer = getPlayer(1 + (turn + 1)%2);
    
    string abil = object->getAbility();
	if(! myPlayer->useMagic(object->getCost())){
		cout << "no enough magic" << endl;
		return;
	}
    if(abil == "heal"){
	    object->heal(1);
    }else if(abil == "enter play 1 dmg" || abil == "deal 1 dmg") {
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








void Board::setActive(int num){
	activePlayer = num;
}


void Board::useAbility(string ability){
	 	vector<Minion*> fieldOpponent = minions2;
	 	vector<Minion*> field = minions1; 
	 	Graveyard* grave = grave1;
	 	Ritual* myRitual = ritual1;
	 	Player player = p1;
	if(turn%2 == 0){
	 	fieldOpponent = minions1;
	 	field = minions2;
	 	grave = grave2;
	 	myRitual ritual2;
	 	player = p2;
	}
	if ((i < 0 || 4 < i) || (t < 0 || t < i)) {
		cerr << "out of bound" << endl;
		return;
	} 
	if(abil ==  "heal all") {
		for(int i = 0; i < field.size(); i++) {
			field[i]->heal(1);
	  	}
	}else if(abil == "summon 1 air") {
	  	if(field.size() < 5) {
	      		Minion* holder = createCard("Air Elemental");
	               	field.push_back(holder);
	  	}
	}else if(abil == "summon 3 air") {
		for(int i = 3; i > 0; i--) {
	     		if(field.size() < 5) {
	         		Minion* holder = createCard("Air Elemental");
	            		field.push_back(holder);
	    		}
		}
	}else if("gain 1 magic at start") {
	  	player->getMagic();
	}else if("+1/+1 enter play") {
	 	field[field.size() - 1]->increaseStat(1,1);
	}else if("destroy enter play") {
	  	field[field.size() - 1]->takeDmg(999);
	}else{
	 	cerr << "no ability" << endl;
	  	return;
	}
}




void Board::triggerAbility(int t, string ability, int p){
	Card* targe†;
	vector<Minion*> field = getField(p);
	vector<Minion*> fieldOpponent = getField(2 - (p + 1)%2);
	if(target == 'r'){
		target = getRitual(p,t);
	} else if(0 < t && t < 6 ) {
		target = findMinion(p,t);
	} else{
		cout << "target do not exists" << endl; 
	}
if(ability == "assassinate"){
	Player* targetPlayer = getPlayer(p);
	targetPlayer->takeDmg(4);
}else if(ability == "frenzy"){
		Minion* min = findMinion(t,p);
	min->increaseStat(3, -2);
	}else if(ability == "destroy") {
	          if(target->showType() == "minion") {
	              dynamic_cast <Minion*> (target)->takeDmg(999);
	          }  else {
	              delete target;
	              target = nullptr;
	          }
	      } else if(ability == "unsummon") {
	          string unsum = target->getName();
	          Hand* deck = player1->returnHand()->sendToBottom(unsum);
	          if(target->showType() == "minion") {
	              if (turn % 2 == 1)
	                  minions1.erase(t);
	              else
	                  minions2.erase(t);
	          }else{
	             delete target;
	              target = nullptr;
	          }
	      } else if(aabilitybil == "recharge") {
         		myRitual->recharge(3);
	      } else if(ability == "disenchant") {
	          if(p == 1) {
	              minions1[t] = dynamic_cast <Minion*> (target)->removeEnchant();
	          } else {
	              minions2[t] = dynamic_cast <Minion*> (target)->removeEnchant();
	          }
	          target->deleteEnchant();
	      } else if(ability == "revive") {
	        	if(field.size() >= 5) {
	                	cerr << "full field, no minion can be summoned" << endl;
	              		return;
             		}
	        }
             	string top = grave->getTop();
              	field.push_back(createCard(top));
          } else if(abil == "blizzard") {
                  for(int i = 0; i < fieldOpponent.size(); i++) {
                      fieldOpponent[i]->takeDmg(2);
          }
}
  }
}


//Added Code July 24
//==================================================================================================
Minion* Board::findMinion(int p, int t){
	if(p == 1){
		return minions1[t - 1];
	} else{
		return minions2[t - 1];
	}
}

void Board::replaceMinion(Minion* object, int p, int t){
	if(p == 1){
		minions1[t - 1] = object;
	} else{
		minions2[t - 1] = object;
	}
}

Ritual* Board::getRitual(int p, int t){
	if(p == 1){
		return ritual1;
	} else{
		return ritual2;
	}
}

vector<Minion*>& Board::getField(p){
	vector <Minion*> temp = minions2;
	if(p == 1){
		temp = minions1;
	}
	return temp
}


Minion* Board::attachEnchant(Enchantment* enchant, Minion* min){
	enchant->assign(min);
	return enchant;
}

//==================================================================================================


void Board::play(int i, int p, int t) {
	Player* myPlayer  = getPlayer(1 + (turn + 1)%2); 
	if ((i < 1 || 5 < i) || (t < 1 || 5 < t)) {
		cerr << "out of bound" << endl;
		return;
	}
	if (p == 0 && t == 0) {
		if (activePlayer == 1) {
			Card* object = player1->getCard(i);
			if (object->showType() == "minion") {
				minions1.emplace_back(dynamic_cast <Minion*> (player1->getCard(i)));
			}
			else if (object->showType() == "ritual") {
				delete ritual1;
				Ritual* copy = createCard(player1->getCard(i)->getName());
				player1->returnHand()->getHand.erase(i - 1);
				ritual1 = copy;
			}
			else if (object->showType() == "spell") {
				if(! myPlayer->useMagic(object->getCost())){
				cout << "no enough magic" << endl;
				return;
	}
				useAbility( dynamic_cast <Spell*> (player1->getCard(i ))->getAbility()); // use spell
			}
		} else { 
			Card* object = player2->getCard(i);
			if (object->showType() == "minion") {
				minions2.emplace_back(dynamic_cast <Minion*> (player2->getCard(i)));
			}
			else if (object->showType() == "ritual") {
				delete ritual2;
				Ritual* copy = createCard(player2->getCard(i)->getName());
				player2->returnHand()->getHand.erase(i - 1);
				ritual2 = copy;
			}
			else if (object->showType() == "spell") {
				if(! myPlayer->useMagic(object->getCost())){
				cout << "no enough magic" << endl;
				return;
	}
				useAbility( dynamic_cast <Spell*> (player2->getCard(i))->getAbility()); // use spell
			}
		}
	} else {

		if (t > 5 || t < 1) {
			cerr << "out of bounds" << endl;
			return;
		}

		if (turn % 2 == 1) {
			if (t == 'r') {
				
			}
			else if (player1->getCard(i)->showType() == "spell") {
				if(! myPlayer->useMagic(object->getCost())){
				cout << "no enough magic" << endl;
				return;
	}
				triggerAbility(t, dynamic_cast <Spell*>(player1->getCard(i))->getAbility(), p);
			}
			else if (player1->getCard(i)->showType() == "enchantment") {
				if(! myPlayer->useMagic(player2->getCard(i)->getCost())){
				cout << "no enough magic" << endl;
				return;
	}
				if (p == 1) {
          				Enchantment* enchant = createCard(player1->getCard(i)->getName());
					player1->returnHand()->getHand().erase(i - 1);
					Minion* target = findMinion(p,t);
					replaceMinion(attachEnchant(enchant, target), p, t);	
				} else if(p == 2 ){
					Enchantment* enchant = createCard(player1->getCard(i)->getName());
					player1->returnHand()->getHand().erase(i - 1);
					Minion* target = findMinion(p,t);
					replaceMinion(attachEnchant(enchant, target), p, t);	
				}
			}
		}
		else{
			if (t == 'r') {
				
			}
			else if (player2->getCard(i)->showType() == "spell") {
				if(! myPlayer->useMagic(object->getCost())){
				cout << "no enough magic" << endl;
				return;
	}
				triggerAbility(p, t, dynamic_cast <Spell*>(player2->getCard(i))->getAbility());
			}
			else if (player2->getCard(i)->showType() == "enchantment") {
				if(! myPlayer->useMagic(player2->getCard(i)->getCost())){
				cout << "no enough magic" << endl;
				return;
	}
				if (p == 1) {
          				Enchantment* enchant = createCard(player2->getCard(i)->getName());
					player2->returnHand()->getHand().erase(i - 1);
					Minion* target = findMinion(p,t);
					replaceMinion(attachEnchant(enchant, target), p, t);
				} else if(p == 2) {
					Enchantment* enchant = createCard(player2->getCard(i)->getName());
					player2->returnHand()->getHand().erase(i - 1);
					Minion* target = findMinion(p,t);
					replaceMinion(attachEnchant(enchant, target), p, t);
				}
		}
	}
	// else {
	//  Card* target;
	//  Card* object;
	//  vector<Minion*> fieldOpponent;
	//  vector<Minion*> field;
	//  Graveyard* grave;
	//  Ritual* myRitual;
	//  if(turn % 2 == 1) {
	//      object = player1->getCard(i);
	//      grave = grave1;
	//      myRitual = ritual1;
	//  } else{
	//      object = player2->getCard(i); //need to implant getType
	//      grave = grave2;
	//      myRitual = ritual2;
	//  }
	//
	//  // if(p == 1) {
	//  //  if (t == 'r')
	//  //      *target = *ritual1;
	//  //  else if (1 <= t && t <= 5)
	//  //      *target = *(minions1[t-1]);
	//  // } else{
	//  //  if (t == 'r')
	//  //      *target = *ritual2;
	//  //  else if (1 <= t && t <= 5)
	//  //      *target = *(minions2[t-1]);
	//  // }
	//
	//  if(object->getStat().type == "enchantment") {
	//      dynamic_cast <Enchantment*> (object)->assign(dynamic_cast <Minion*> (target));
	//  } else if(object->getStat().type == "spell") {
	//      string abil = dynamic_cast <Spell*> (object)->getAbility(); //spell implementation
	//      if(abil == "destroy") {
	//          if(target->showType() == "minion") {
	//              dynamic_cast <Minion*> (target)->takeDmg(999);
	//          }  else {
	//              delete target;
	//              target = nullptr;
	//          }
	//      } else if(abil == "unsummon") {
	//          string unsum = target->getName();
	//          Hand* deck = player1->returnHand()->sendToBottom(unsum);
	//          if(target->showType() == "minion") {
	//              if (turn % 2 == 1)
	//                  minions1.erase(t);
	//              else
	//                  minions2.erase(t);
	//          }else{
	//              delete target;
	//              target = nullptr;
	//          }
	//      } else if(abil == "recharge") {
	//          myRitual->recharge(3);
	//      } else if(abil == "disenchant") {
	//          if(p == 1) {
	//              minions1[t] = dynamic_cast <Minion*> (target)->removeEnchant();
	//          } else {
	//              minions2[t] = dynamic_cast <Minion*> (target)->removeEnchant();
	//          }
	//          target->deleteEnchant();
	//      } else if(abil == "revive") {
	//          if (turn % 2 == 1) {
	//              if(minions1.size() >= 5) {
	//                  cerr << "full field, no minion can be summoned" << endl;
	//                  return;
	//              }
	//          }
	//          else {
	// if(minions2.size() >= 5) {
//                      cerr << "full field, no minion can be summoned" << endl;
//                      return;
//                  }
//              }
//              string top = grave->getTop();
//              createCard(top)
//          } else if(abil == "blizzard") {
//              if (turn % 2 == 1) {
//                  for(int i = 0; i < minions1.size(); i++) {
//                      minions1[i]->takeDmg(2);
//                  }
//              }
//              else {
//                  for(int i = 0; i < minions2.size(); i++) {
//                      minions2[i]->takeDmg(2);
//                  }
//              }
//          }
//      }
//  }
}



void Board::end(){
	turn++;
}


int Board::getTurn() {
	return turn;
}

void Board::updateMinion() {
	// for(int i = 0; i < minions1.size(); i++) {
	//  if(minions1[i]->defeated()) {
	//      Minion* holder = new Minion(minions1[i]->getStat().name);
	//      grave1->addMinion(holder);
	//      minions1.erase(i);
	//  }
	// }
	// for(int j = 0; j < minions2.size(); j++) {
	//  if(minions2[j]->defeated()) {
	//      Minion* holder = new Minion (minions2[j]->getStat().name);
	//      grave2->addMinion(holder);
	//      minions2.erase(j);
	//  }
	// }
}

void Board::refreshAllAttack(){
	for(int i = 0; i < minions1.size(); i++) {
		minions1[i]->refreshAttack();
	}
	for(int i = 0; i < minions2.size(); i++) {
		minions2[i]->refreshAttack();
	}
}
