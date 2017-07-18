#ifndef SPELL_H
#define SPELL_H


class spell : public Card {
	std::string name;
	std::string description;
	int cost;
public:
	void draw();
	spell(std::string name,std::string description,int cost);
};

#endif
