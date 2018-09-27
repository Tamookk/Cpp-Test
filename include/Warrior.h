#ifndef WARRIOR_H
#define WARRIOR_H

#include "Adventurer.h"

class Warrior : public Adventurer
{
public:
    Warrior(std::string name = "AAA", int closeDamage = 0, int distanceDamage = 0, int age = 20, int chivalryFactor = 0);
    void beChivalrous(Entity &e);

private:
    int chivalryFactor;
};

#endif
