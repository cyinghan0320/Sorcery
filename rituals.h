#ifndef RITUAL_H
#define RITUAL_H

class Ritual : public Card {
	std::string name;
	std::string description;
	int cost;
public:
	void draw();
	Ritual(std::string name, std::string description, int cost);
	void useCard();
};

#endif
