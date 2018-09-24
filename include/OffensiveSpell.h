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
    void castSpell(Entity e);
    // Not in UML
    OffensiveSpell();

private:
    int damage;
    int numEntitiesCanDamage;
};

#endif
