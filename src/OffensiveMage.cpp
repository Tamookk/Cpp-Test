//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/OffensiveMage.h"

// Constructor
OffensiveMage::OffensiveMage(std::string name, int closeDamage, int distanceDamage, int age, int mana)
: Adventurer(name, closeDamage, distanceDamage, age)
{
    this->mana = mana;
    canCastSpells = true;
}

// Destructor
OffensiveMage::~OffensiveMage()
{
    delete [] spells;
}

// Get the type of the entity
std::string OffensiveMage::getType() { return std::string("Offensive Mage"); }
