//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Skeleton.h"

Skeleton::Skeleton(std::string name, int closeDamage, int distanceDamage,
                   std::string noise, int dootAbility)
: Monster(name, closeDamage, distanceDamage, noise)
{
    canCastSpells = false;
    this->dootAbility = dootAbility;
}

void Skeleton::doot(Entity &e)
{
    std::cout << "doot" << std::endl;
    std::cout << "Entity " << e.getName() << " has been dooted. ";
    std::cout << "They take " << dootAbility << " damage." << std::endl;
    e.takeDamage(dootAbility);
}

// Get the type of the entity
std::string Skeleton::getType() { std::string("Skeleton"); }
