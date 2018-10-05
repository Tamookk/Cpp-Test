//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/DefensiveMage.h"

// Constructor
DefensiveMage::DefensiveMage(std::string name, int closeDamage, int distanceDamage, int health, int age, int mana)
: Adventurer(name, closeDamage, distanceDamage, health, age)
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
void DefensiveMage::addSpell(int index, Spell* spell)
{
    spells[index] = spell;
}

// Cast a spell
void DefensiveMage::castSpell(Entity &e)
{
    // Pick a random spell and cast it
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 1);
    spells[distribution(generator)]->castSpell(e);
}

int DefensiveMage::stealGold(Entity &e){ return 0; };
void DefensiveMage::beChivalrous(Entity &e){};
