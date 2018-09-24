//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/OffensiveMage.h"

// Constructor
OffensiveMage::OffensiveMage(std::string name, int closeDamage, int distanceDamage, bool canCastSpells, int age)
: Adventurer(name, closeDamage, distanceDamage, canCastSpells, age)
{
    mana = 10;
}

// Destructor
OffensiveMage::~OffensiveMage()
{
    delete [] spells;
}
