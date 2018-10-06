//
// Created by Joshua Sutton
// 24/09/2018.
//

#ifndef WARRIOR_H
#define WARRIOR_H

#include "Adventurer.h"

class Warrior : public Adventurer
{
public:
    Warrior(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int health = 100, int age = 20, int chivalryFactor = 0);
    void beChivalrous(Entity &e);
    // Not in UML
    std::string getType();
    void castSpell(Entity &e);
    int stealGold(Entity &e);

private:
    int chivalryFactor;
};

#endif
