//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef ROGUE_H
#define ROGUE_H

#include "Adventurer.h"

class Rogue : public Adventurer
{
public:
    Rogue(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0,
          bool canCastSpells = false, int age = 20, int thiefSkill = 0);
    int stealGold(Entity &e);

private:
    int thievingAbility;
};

#endif