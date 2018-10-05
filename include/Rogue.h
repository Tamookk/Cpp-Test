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
    Rogue(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int age = 20, int thiefSkill = 0);
    // not in uml
    std::string getType();
    void castSpell(Entity &e);
    int stealGold(Entity &e);
    void beChivalrous(Entity &e);

private:
    int thievingAbility;
};

#endif
