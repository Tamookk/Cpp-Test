#ifndef DEFENSIVEMAGE_H
#define DEFENSIVEMAGE_H

#include "Adventurer.h"
#include "DefensiveSpell.h"

class DefensiveMage : public Adventurer
{
public:
    DefensiveMage();
    ~DefensiveMage();

private:
    int mana;
    DefensiveSpell* spells[];
};

#endif
