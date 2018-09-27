//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Tree.h"

Tree::Tree(std::string name, int closeDamage, int distanceDamage, std::string noise, int mana)
: Monster(name, closeDamage, distanceDamage, noise)
{
    this-> mana = mana;
}

Tree::~Tree()
{
    delete [] spells;
}

// Return the type of the entity
std::string Tree::getType() { return std::string("Tree"); }
