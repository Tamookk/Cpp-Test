//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/DefensiveSpell.h"

// Constructor
DefensiveSpell::DefensiveSpell(std::string name, int cost, double dmgReduction, int numCanAffect)
: Spell(name, cost)
{
    damageReduction = dmgReduction;
    numFriendliesCanHelp = numCanAffect;
}

// Cast a spell
void DefensiveSpell::castSpell(Entity* e)
{
    for(int i = 0; i < numFriendliesCanHelp; i++)
    {
        (e + i)->setDamageMultiplier(1 - damageReduction);
    }
}
