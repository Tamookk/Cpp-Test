//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Functions.h"
#include "../include/OffensiveMage.h"

// Constructor
OffensiveMage::OffensiveMage(std::string name, int closeDamage, int distanceDamage, int health, int age, int mana)
: Adventurer(name, closeDamage, distanceDamage, health, age)
{
    this->mana = mana;
    canCastSpells = true;
    for(int i = 0; i < 2; i++)
        spells[i] = generateSpell("offensive");
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

// Get info on mage's spells
void OffensiveMage::getSpellInfo()
{
    for(int i = 0; i < 2; i++)
        spells[i]->printInfo();
}

int OffensiveMage::stealGold(Entity &e){ return 0; }
void OffensiveMage::beChivalrous(Entity &e){}
