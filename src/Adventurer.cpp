//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Adventurer.h"

// Constructor
Adventurer::Adventurer(std::string name, int closeDamage, int distanceDamage, int age)
: Entity(name, closeDamage, distanceDamage)
{
    this->age = age;
    deathHour = 0;
    killedBy = "";
}

// Make a ranged attack at an entity
void Adventurer::rangedAttack(Entity &e)
{
    std::cout << name << " is attacking " << e.getName() << " at range." << std::endl;
    e.takeDamage(distanceDamage * damageMultiplier);
    std::cout << distanceDamage * damageMultiplier << " damage was done!" << std::endl;
    std::cout << e.getHealth() << " HP remaining.\n" << std::endl;
}

// Make a close attack at an entity
void Adventurer::closeAttack(Entity &e)
{
    std::cout << name << " is attacking " << e.getName() << " in close quarters." << std::endl;
    e.takeDamage(closeRangeDamage * damageMultiplier);
    std::cout << closeRangeDamage * damageMultiplier << " damage was done!" << std::endl;
    std::cout << e.getHealth() << " HP remaining.\n" << std::endl;
}
