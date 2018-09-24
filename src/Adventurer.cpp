//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Adventurer.h"

// Constrcutor
Adventurer::Adventurer(std::string name, int closeDamage, int distanceDamage, bool canCastSpells, int age)
: Entity(name, closeDamage, distanceDamage, canCastSpells)
{
    this->age = age;
    deathHour = 0;
    killedBy = "";
}

// Make a ranged attack at an entity
void Adventurer::rangedAttack(Entity &e)
{
    std::cout << "Attacking " << e.getName() << " at range." << std::endl;
    e.takeDamage(distanceDamage * damageMultiplier);
    std::cout << distanceDamage * damageMultiplier << " damage was done!" << std::endl;
    std::cout << e.getHealth() << " HP remaining." << std::endl;
}

// Make a close attack at an entity
void Adventurer::closeAttack(Entity &e)
{
    std::cout << "Attacking " << e.getName() << " in close quarters." << std::endl;
    e.takeDamage(closeRangeDamage * damageMultiplier);
    std::cout << closeRangeDamage * damageMultiplier << " damage was done!" << std::endl;
    std::cout << e.getHealth() << " HP remaining." << std::endl;
}

int Adventurer::die(Entity &e, int deathHour)
{
    killedBy = e.getName();
    this->deathHour = deathHour;

    std::cout << name << " was killed by " << killedBy << ". RIP." << std::endl;
    std::cout << "They had " << gold << " gold coin(s)." << std::endl;

    int goldRemaining = gold;
    gold = 0;
    return goldRemaining;
}

void Adventurer::fullyHeal() { currentHealth = maximumHealth; }
