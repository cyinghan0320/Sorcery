#ifndef RITUAL_H
#define RITUAL_H

class Ritual : public Card {
	string name;
	string description;
	int cost;
public:
	void draw();
	Ritual(string name, string description);
	void useCard();
};

#endif
