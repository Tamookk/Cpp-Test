//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/DefensiveMage.h"
#include "../include/Functions.h"

// Constructor
DefensiveMage::DefensiveMage(std::string name, int closeDamage, int distanceDamage, int health, int age, int mana)
: Adventurer(name, closeDamage, distanceDamage, health, age)
{
    this->mana = mana;
    maxMana = mana;
    canCastSpells = true;
    for(int i = 0; i < 2; i++)
        spells[i] = generateSpell("defensive");
}

// Destructor
DefensiveMage::~DefensiveMage()
{
    delete [] spells;
}

// Get the type of the entity
std::string DefensiveMage::getType() { return std::string("Defensive Mage"); }

// Cast a spell
void DefensiveMage::castSpell(Entity &e)
{
    // Pick a random spell and cast it
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 1);
    int spellNum = distribution(generator);

    // Check if the mage has enough mana to cast the spell
    if(mana < spells[spellNum]->getCost())
    {
        std::cout << getType() << " " << name << " tries to cast a spell, but fails!\nThey don't have enough mana.\n" << std::endl;
    }
    else
    {
        std::cout << "Defensive Mage " << name;
        spells[spellNum]->castSpell(e);
        mana -= spells[spellNum]->getCost();
    }
}

// Get info on mage's spells
void DefensiveMage::getSpellInfo()
{
    for(int i = 0; i < 2; i++)
        spells[i]->printInfo();
}

// Add mana to the mage
void DefensiveMage::addMana(int amt)
{
    mana += amt;
    if(mana > maxMana)
        mana = maxMana;
}

int DefensiveMage::stealGold(Entity &e){ return 0; };
void DefensiveMage::beChivalrous(Entity &e){};
