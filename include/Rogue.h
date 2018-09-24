#ifndef ROGUE_H
#define ROGUE_H

#include "Adventurer.h"

class Rogue : public Adventurer
{
public:
    Rogue();
    int stealGold(Entity e);

private:
    int thievingAbility;
};

#endif
