//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Witch.h"

Witch::Witch(std::string name, int closeDamage, int distanceDamage, std::string noise, int mana)
: Monster(name, closeDamage, distanceDamage, noise)
{
    this->mana = mana;
    canCastSpells = true;
}

Witch::~Witch()
{
    delete [] spells;
}

// Get the type of the entity
std::string Witch::getType() { return std::string("Witch"); }

// Add a spell to a witch's list of spells
void Witch::addSpell(int index, Spell spell)
{
    spells[index] = spell;
}
