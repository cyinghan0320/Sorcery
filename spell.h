#ifndef SPELL_H
#define SPELL_H


class spell : public Card {
	string name;
	string description;
public:
	void draw();
	spell(name,description);
};

#endif
