#ifndef WARRIOR_H
#define WARRIOR_H

#include "Adventurer.h"

class Warrior : public Adventurer
{
public:
    Warrior();
    void beChivalrous(Entity e);

private:
    int chivalryFactor;
};

#endif
