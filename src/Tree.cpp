//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Tree.h"

Tree::Tree(std::string name, int closeDamage, int distanceDamage, int health, std::string noise, int mana)
: Monster(name, closeDamage, distanceDamage, health, noise)
{
    this-> mana = mana;
    canCastSpells = true;
}

Tree::~Tree()
{
    delete [] spells;
}

// Return the type of the entity
std::string Tree::getType() { return std::string("Tree"); }

// Add a spell to a tree's list of spells
void Tree::addSpell(int index, Spell* spell)
{
    spells[index] = spell;
}
