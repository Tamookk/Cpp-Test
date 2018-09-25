//
// Created by Joshua Sutton
// 24/09/2018.
//

#include "../include/Rogue.h"

Rogue::Rogue(std::string name, int closeDamage, int distanceDamage, bool canCastSpells, int age, int thiefSkill)
: Adventurer(name, closeDamage, distanceDamage, canCastSpells, age)
{
    thievingAbility = thiefSkill;
}

int Rogue::stealGold(Entity &e)
{
    // The amount of gold the rogue steals is dependent on their theiving ability
    std::cout << name << " attempts to steal gold from " << e.getName() << "..." << std::endl;
    int gold = 0;
    if(thievingAbility > e.getGold())
    {
        gold = e.getGold();
        e.removeGold(gold);
    }
    else
    {
        gold = e.getGold()%thievingAbility;
        e.removeGold(gold);
    }
    std::cout << "Adventurer stole " << gold << " gold!" << std::endl;
    return gold;
}