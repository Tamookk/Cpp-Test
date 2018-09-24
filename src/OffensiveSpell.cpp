//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/OffensiveSpell.h"

// Constructor
OffensiveSpell::OffensiveSpell(std::string name, int cost, double damage, int numCanAffect)
: Spell(name, cost)
{
    this->damage = damage;
    numEntitiesCanDamage = numCanAffect;
}

// Cast a spell
void OffensiveSpell::castSpell(Entity* e)
{
    for(int i = 0; i < numEntitiesCanDamage; i++)
    {
        (e + i)->takeDamage(damage);
    }
}
