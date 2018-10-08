//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Monster.h"

// Constructor
Monster::Monster(std::string name, int closeDamage, int distanceDamage, int health, std::string noise, int gold)
: Entity(name, closeDamage, distanceDamage, health)
{
    monsterNoise = noise;
    this->gold = gold;
}

// Make a ranged attack at an entity
void Monster::rangedAttack(Entity &e)
{
    // Move the monster if they are in the wrong location
    if(location == "close")
        move("far");

    std::cout << getType() << " " << name << " is attacking " << e.getType();
    std::cout << " " << e.getName() << " at range." << std::endl;
    e.takeDamage(distanceDamage * damageMultiplier);
    std::cout << (int)(distanceDamage * damageMultiplier * e.getDefenceMultiplier()) << " damage was done!" << std::endl;
    std::cout << e.getHealth() << " HP remaining.\n" << std::endl;
}

// Make a close attack at an entity
void Monster::closeAttack(Entity &e)
{
    // Move the monster if they are in the wrong location
    if(location == "far")
        move("close");

    std::cout << getType() << " " << name << " is attacking " << e.getType();
    std::cout << " " << e.getName() << " in close quarters." << std::endl;
    e.takeDamage(closeRangeDamage * damageMultiplier);
    std::cout << (int)(closeRangeDamage * damageMultiplier * e.getDefenceMultiplier()) << " damage was done!" << std::endl;
    std::cout << e.getHealth() << " HP remaining.\n" << std::endl;
}
