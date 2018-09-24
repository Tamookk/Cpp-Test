//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef DEFENSIVESPELL_H
#define DEFENSIVESPELL_H

#include "Entity.h"
#include "Spell.h"

class DefensiveSpell : public Spell
{
public:
    DefensiveSpell(std::string name = "AAA", int cost = 1, double dmgReduction = 0.01, int numCanAffect = 1);
    void castSpell(Entity* e);

private:
    double damageReduction;
    int numFriendliesCanHelp;
};

#endif
