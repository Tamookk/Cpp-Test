//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/DefensiveMage.h"

// Constructor
DefensiveMage::DefensiveMage(std::string name, int closeDamage, int distanceDamage, int age, int mana)
: Adventurer(name, closeDamage, distanceDamage, age)
{
    this->mana = mana;
    canCastSpells = true;
}

// Destructor
DefensiveMage::~DefensiveMage()
{
    delete [] spells;
}

// Get the type of the entity
std::string DefensiveMage::getType() { return std::string("Defensive Mage"); }

// Add a spell to a mage's list of spells
void DefensiveMage::addSpell(int index, Spell spell)
{
    spells[index] = spell;
}
