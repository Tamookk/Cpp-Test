#ifndef DEFENSIVESPELL_H
#define DEFENSIVESPELL_H

#include "Spell.h"
#include "Entity.h"

class DefensiveSpell : public Spell
{
public:
    DefensiveSpell();
    void castSpell(Entity e);

private:
    int damageReduction;
    int numFriendliesCanHelp;
};

#endif
