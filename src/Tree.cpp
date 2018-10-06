//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Tree.h"

Tree::Tree(std::string name, int closeDamage, int distanceDamage, int health, std::string noise, int gold, int mana)
: Monster(name, closeDamage, distanceDamage, health, noise, gold)
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

// Cast a spell
void Tree::castSpell(Entity &e)
{
    // Pick a random spell and cast it
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 1);
    spells[distribution(generator)]->castSpell(e);
}

void Tree::doot(Entity &e){}
void Tree::howl(Entity &e){}
void Tree::stealLife(Entity &e){}
