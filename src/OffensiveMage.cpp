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

// Cast a spell
void OffensiveMage::castSpell(Entity &e)
{
    // Pick a random spell and cast it
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 1);
    spells[distribution(generator)]->castSpell(e);
}

int OffensiveMage::stealGold(Entity &e){}
void OffensiveMage::beChivalrous(Entity &e){}
