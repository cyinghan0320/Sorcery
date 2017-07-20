#ifndef SPELL_H
#define SPELL_H


class spell : public Card {
	std::string name;
	std::string description;
	int cost;
	std::string type = "spell";
public:
	void draw();
	spell(std::string name,std::string description,int cost);
	int getCost();
	std::string getDes();
};

#endif
