//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Vampire.h"

Vampire::Vampire(std::string name, int closeDamage, int distanceDamage, int health, std::string noise, int gold, int fullness)
: Monster(name, closeDamage, distanceDamage, health, noise, gold)
{
    canCastSpells = false;
    this->fullness = fullness;
}

// Steal life from an entity
void Vampire::stealLife(Entity &e)
{
    std::cout << monsterNoise << std::endl;
    e.takeDamage(fullness%10);
    addHealth(fullness%10);
    std::cout << name << " the Vampire steals " << fullness%10 << " HP from " << e.getName();
    std::cout << "!" << std::endl;
    fullness += (fullness%10) + 1;
}

// Get the type of the entity
std::string Vampire::getType() { return std::string("Vampire"); }

void Vampire::castSpell(Entity &e){}
void Vampire::doot(Entity &e){}
void Vampire::howl(Entity &e){}

