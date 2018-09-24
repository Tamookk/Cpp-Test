//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef OFFENSIVESPELL_H
#define OFFENSIVESPELL_H

#include "Headers/Spell.h"


class OffensiveSpell : public Spell
{
private:
    int damage;
    int numEntitiesCanDamage;
public:
    void castSpell(Entity e);
    // Not in UML
    OffensiveSpell();
};

#endif // OFFENSIVESPELL_H
