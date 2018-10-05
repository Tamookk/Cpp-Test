//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Warrior.h"

Warrior::Warrior(std::string name, int closeDamage, int distanceDamage, int age, int chivalryFactor)
: Adventurer(name, closeDamage, distanceDamage, age)
{
    this->chivalryFactor = chivalryFactor;
    canCastSpells = false;
}

void Warrior::beChivalrous(Entity &e)
{
    std::cout << "Warrior " << name << " was chivalrous to " << e.getName() << "." << std::endl;
    std::cout << e.getName() << " gains " << chivalryFactor << " HP!\n" << std::endl;
    e.addHealth(chivalryFactor);
}

// Get the type of the entity
std::string Warrior::getType() { return std::string("Warrior"); }

void Warrior::castSpell(Entity &e){}
int Warrior::stealGold(Entity &e){}
