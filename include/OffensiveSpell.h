//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef OFFENSIVESPELL_H
#define OFFENSIVESPELL_H

#include "Entity.h"
#include "Spell.h"

class OffensiveSpell : public Spell
{
public:
    OffensiveSpell(std::string name = "AAA", int cost = 1, double damage = 10, int numCanAffect = 1);
    void castSpell(Entity* e);

private:
    int damage;
    int numEntitiesCanDamage;
};

#endif
