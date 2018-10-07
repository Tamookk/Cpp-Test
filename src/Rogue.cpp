//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Rogue.h"

Rogue::Rogue(std::string name, int closeDamage, int distanceDamage, int health, int age, int thiefSkill)
: Adventurer(name, closeDamage, distanceDamage, health, age)
{
    thievingAbility = thiefSkill;
    canCastSpells = false;
}

int Rogue::stealGold(Entity &e)
{
    // The amount of gold the rogue steals is dependent on their theiving ability
    std::cout << name << " attempts to steal gold from " << e.getName() << "..." << std::endl;
    int gold = 0;
    if(thievingAbility > e.getGold())
    {
        gold = e.getGold();
        e.addGold(-gold);
    }
    else
    {
        gold = e.getGold()%thievingAbility;
        e.addGold(-gold);
    }
    std::cout << "They stole " << gold << " gold!\n" << std::endl;
    return gold;
}

// Get the type of the entity
std::string Rogue::getType() { return std::string("Rogue"); }

void Rogue::castSpell(Entity &e){}
void Rogue::beChivalrous(Entity &e){}
void Rogue::getSpellInfo(){}
