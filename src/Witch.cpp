//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Witch.h"

Witch::Witch(std::string name, int closeDamage, int distanceDamage, std::string noise, int mana)
: Monster(name, closeDamage, distanceDamage, noise)
{
    canCastSpells = true;
    this->mana = mana;
}

Witch::~Witch()
{
    delete [] spells;
}

// Get the type of the entity
std::string Witch::getType() { return std::string("Witch"); }
