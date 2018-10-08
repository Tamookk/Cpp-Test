//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Adventurer.h"

// Constructor
Adventurer::Adventurer(std::string name, int closeDamage, int distanceDamage, int health, int age)
: Entity(name, closeDamage, distanceDamage, health)
{
    this->age = age;
    deathHour = 0;
    killedBy = "";
}

// Make a ranged attack at an entity
void Adventurer::rangedAttack(Entity &e)
{
    // Move the adventurer if they are in the wrong location
    if(location == "close")
        move("far");

    std::cout << getType() << " " << name << " is attacking " << e.getType();
    std::cout << " " << e.getName() << " at range." << std::endl;
    e.takeDamage(distanceDamage * damageMultiplier);
    std::cout << round(distanceDamage * damageMultiplier * e.getDefenceMultiplier()) << " damage was done!" << std::endl;
    std::cout << e.getHealth() << " HP remaining.\n" << std::endl;
}

// Make a close attack at an entity
void Adventurer::closeAttack(Entity &e)
{
    // Move the adventurer if they are in the wrong location
    if(location == "far")
        move("close");

    std::cout << getType() << " " << name << " is attacking " << e.getType();
    std::cout << " " << e.getName() << " in close quarters." << std::endl;
    e.takeDamage(closeRangeDamage * damageMultiplier);
    std::cout << round(closeRangeDamage * damageMultiplier * e.getDefenceMultiplier()) << " damage was done!" << std::endl;
    std::cout << e.getHealth() << " HP remaining.\n" << std::endl;
}

// Return the killer of the adventurer
std::string Adventurer::getKiller() { return killedBy; }

// Return the hour the adventurer died
int Adventurer::getHourKilled() { return deathHour; }
