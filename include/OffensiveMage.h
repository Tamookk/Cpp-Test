#ifndef OFFENSIVEMAGE_H
#define OFFENSIVEMAGE_H

#include "Adventurer.h"
#include "OffensiveSpell.h"

class OffensiveMage : public Adventurer
{
public:
    OffensiveMage();
    ~OffensiveMage();

private:
    int mana;
    OffensiveSpell* spells[];
};

#endif
