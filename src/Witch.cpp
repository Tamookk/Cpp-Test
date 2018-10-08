//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Witch.h"

Witch::Witch(std::string name, int closeDamage, int distanceDamage, int health, std::string noise, int gold, int mana)
: Monster(name, closeDamage, distanceDamage, health, noise, gold)
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
void Witch::addSpell(int index, Spell* spell)
{
    spells[index] = spell;
}

// Cast a spell
void Witch::castSpell(Entity &e)
{
    // Pick a random spell and cast it
    static std::default_random_engine generator(time(0));
    static std::uniform_int_distribution<int> distribution(0, 1);
    std::cout << "Witch " << name;
    spells[distribution(generator)]->castSpell(e);
}

void Witch::doot(Entity &e){}
void Witch::howl(Entity &e){}
void Witch::stealLife(Entity &e){}
