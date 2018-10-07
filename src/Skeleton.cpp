//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Skeleton.h"

Skeleton::Skeleton(std::string name, int closeDamage, int distanceDamage,
                   int health, std::string noise, int gold, int dootAbility)
: Monster(name, closeDamage, distanceDamage, health, noise, gold)
{
    canCastSpells = false;
    this->dootAbility = dootAbility;
}

void Skeleton::doot(Entity &e)
{
    std::cout << "doot" << std::endl;
    std::cout << e.getName() << " has been dooted. ";
    std::cout << "They take " << dootAbility << " damage." << std::endl << std::endl;
    e.takeDamage(dootAbility);
}

// Get the type of the entity
std::string Skeleton::getType() { return std::string("Skeleton"); }

void Skeleton::castSpell(Entity &e){}
void Skeleton::howl(Entity &e){}
void Skeleton::stealLife(Entity &e){}
