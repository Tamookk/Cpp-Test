//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Monster.h"

// Constructor
Monster::Monster(std::string name, int closeDamage, int distanceDamage, bool canCastSpells, std::string noise)
: Entity(name, closeDamage, distanceDamage, canCastSpells)
{
    monsterNoise = noise;
}

// Make a ranged attack at an entity
void Monster::rangedAttack(Entity &e)
{
    std::cout << "Attacking " << e.getName() << " at range." << std::endl;
    e.takeDamage(distanceDamage * damageMultiplier);
    std::cout << distanceDamage * damageMultiplier << " damage was done!" << std::endl;
    std::cout << e.getHealth() << " HP remaining." << std::endl;
}

// Make a close attack at an entity
void Monster::closeAttack(Entity &e)
{
    std::cout << "Attacking " << e.getName() << " in close quarters." << std::endl;
    e.takeDamage(closeRangeDamage * damageMultiplier);
    std::cout << closeRangeDamage * damageMultiplier << " damage was done!" << std::endl;
    std::cout << e.getHealth() << " HP remaining." << std::endl;
}
