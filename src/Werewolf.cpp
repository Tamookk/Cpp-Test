//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Werewolf.h"

Werewolf::Werewolf(std::string name, int closeDamage, int distanceDamage, int health, std::string noise, int loudness, int gold)
: Monster(name, closeDamage, distanceDamage, health, noise, gold)
{
    this->loudness = loudness;
    canCastSpells = false;
}

void Werewolf::howl(Entity &e)
{
    std::cout << monsterNoise << std::endl;
    std::cout << "Werewolf " << name << " howls at " << e.getName() << std::endl;
    std::cout << e.getName() << " takes " << loudness << " damage!" << std::endl;
    e.takeDamage(loudness);
}

// Get the type of the entity
std::string Werewolf::getType() { return std::string("Werewolf"); }
